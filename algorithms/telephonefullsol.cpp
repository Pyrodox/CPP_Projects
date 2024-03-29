#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	bool adj[51][51];
	int cows[50001];
	for (int i = 1; i <= n; i++)
	{
		cin >> cows[i];
	}
	char c;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			cin >> c;
			adj[i][j] = (c == '1');
		}
		//remember the cows that can transmit to cow N
		adj[i][0] = adj[i][cows[n]];
	}
	//set cow N to a fake breed 0
	cows[n] = 0;
	vector<int> dist[51];
	for (int i = 0; i <= k; i++)
	{
		dist[i].resize(n + 1);
		for (int j = 0; j <= n; j++)
		{
			dist[i][j] = -1;
		}
	}
	deque<pair<int, int>> q; //sender's breed, location
	q.push_back({cows[1], 1});
	dist[cows[1]][1] = 0;
	while (!q.empty())
	{
		int breed = q.front().first, loc = q.front().second;
		q.pop_front();
		//move left one cow
		if (loc - 1 >= 1 && dist[breed][loc - 1] == -1)
		{
			dist[breed][loc - 1] = dist[breed][loc] + 1;
			q.push_back({breed, loc - 1});
		}
		//move right one cow
		if (loc + 1 <= n && dist[breed][loc + 1] == -1)
		{
			dist[breed][loc + 1] = dist[breed][loc] + 1;
			q.push_back({breed, loc + 1});
		}
		//transmit to the cow at the current location
		if (adj[breed][cows[loc]] && dist[cows[loc]][loc] == -1)
		{
			dist[cows[loc]][loc] = dist[breed][loc];
			q.push_front({cows[loc], loc});
		}
	}
	cout << dist[0][n] << endl;
	return 0;
}