#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll rect_num, paint_req;
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
	fin >> rect_num >> paint_req;
	vector<vector<ll>> barn(1001, vector<ll> (1001));
	for (ll i = 0; i < rect_num; i++) {
		ll start_x, start_y, end_x, end_y;
		fin >> start_x >> start_y >> end_x >> end_y;
		// Set up the prefix sums array with all the corners of the given rectangle
		barn[start_x][start_y]++;
		barn[start_x][end_y]--;
		barn[end_x][start_y]--;
		barn[end_x][end_y]++;
	}
	ll valid_area = 0;
	// Run 2D prefix sums on the array
	for (ll x = 0; x < 1000; x++) {
		for (ll y = 0; y < 1000; y++) {
			if (x > 0) barn[x][y] += barn[x - 1][y];
			if (y > 0) barn[x][y] += barn[x][y - 1];
			if (x > 0 && y > 0) barn[x][y] -= barn[x - 1][y - 1];
			valid_area += barn[x][y] == paint_req;
		}
	}
	fout << valid_area;
}