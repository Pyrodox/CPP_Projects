#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 800;
vector<string> field(MAX_N);
int n, s;

bool valid_sq(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n
		&& (field[x][y] == 'G' || field[x][y] == 'M');
}

bool mecho_reached(int mecho_dis, int bees_dis){
	return mecho_dis / s < bees_dis;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}
	
	vector<pair<int, int>> hives;
	int mechox, mechoy, home_x, home_y;
	// find x and y coordinates for for Mecho, the bees and the cave
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 'M') {
				mechox = i;
				mechoy = j;
			} else if (field[i][j] == 'H') {
				hives.push_back({i, j});
			} else if (field[i][j] == 'D') {
				home_x = i;
				home_y = j;
			}
		}
	}

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, -1, 0, 1};

	// binary search on waiting time
	int l = 0;
	int r = n * n;
	while (l <= r) {
		vector<vector<bool>> bees_visited(n, vector<bool>(n));
		vector<vector<bool>> mecho_visited(n, vector<bool>(n));
		vector<vector<int>> bees_time(n, vector<int>(n));
		vector<vector<int>> mecho_time(n, vector<int>(n));
		queue<pair<int, int>> q;
		
		int eating_time = (l + r) / 2;

		// move bees
		for (auto i : hives) {
			q.push({i.first, i.second});
			bees_visited[i.first][i.second] = true;
		}
		
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (valid_sq(nx, ny) && !bees_visited[nx][ny]) {
					bees_time[nx][ny] = bees_time[x][y] + 1;    
					q.push({nx, ny});
					bees_visited[nx][ny] = true;
				}
			}
		}
		
		
		// move Mecho
		q.push({mechox, mechoy});
		mecho_visited[mechox][mechoy] = true;
		if (bees_time[mechox][mechoy] <= eating_time) {
			q.pop();
		}

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				/* 
				 * check if mecho reaces node[x][y] before the bees
				 * divide the time mecho takes to reach a node by s, since 
				 * mecho walks s steps at a time.
				 * substract the eating time from the time taken for the 
				 * bees to reach the node, because that time was used by 
				 * mecho for eating
				*/
				if (valid_sq(nx, ny) && !mecho_visited[nx][ny] && 
					mecho_reached(mecho_time[x][y] + 1, bees_time[nx][ny]
					- eating_time)) {
						mecho_visited[nx][ny] = true;
						q.push({nx, ny});
						mecho_time[nx][ny] = mecho_time[x][y] + 1;
				}
			}
		}
		

		// check if mecho reached a node surrounding his cave before the bees
		bool reached = false;
		for (int i = 0; i < 4; i++) {
			int nx = home_x + dx[i], ny = home_y + dy[i];
			if (valid_sq(nx, ny) && mecho_reached(mecho_time[nx][ny], 
				bees_time[nx][ny] - eating_time) && mecho_visited[nx][ny]) {
					reached = true;
				}
		}
		if (reached) {
			l = eating_time + 1;
		} else {
			r = eating_time - 1;
		}
	}

	cout << l - 1 << '\n';
}