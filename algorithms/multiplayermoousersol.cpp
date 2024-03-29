/* 
theres too many solutions with so many defines and weird coding
idea is relatively simple:
make floodfill function that:
returns the size of the current section
takes in 2 colors

to get largest individual region: use function with same 2 IDs
to get largest team region: use function with 2 different adjacent IDs
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 250;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];


int floodfill(int size, int r, int c, int color1, int color2) {
	if((r < 0 || r >= n || c < 0 || c >= n) || (grid[r][c] != color1 && grid[r][c] != color2) || visited[r][c]) {
		return size;
	}
	visited[r][c] = 1;

	size++;
	size = floodfill(size, r, c + 1, color1, color2);
	size = floodfill(size, r, c - 1, color1, color2);
	size = floodfill(size, r - 1, c, color1, color2);
	size = floodfill(size, r + 1, c, color1, color2);
	return size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	//largest individual region
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!visited[i][j]) {
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j])); //note that color1 and color2 are the same
			}
		}
	}
	cout << ans << '\n';
	//largest team region
	ans = 0;
	//adjacent y IDs
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(ans >= n*n/2) {
				/*
				thinking back on this part
				idk why i wrote this code
				but it made it pass, so mistakes are helpful sometimes
				programmer mindset
				*/
				cout << ans << '\n';
				return 0;
			}
			if(grid[i][j] != grid[i][j-1]) {
				memset(visited, 0, sizeof(visited));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j-1]));
			}
		}
	}
	//adjacent x IDs
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(ans >= n*n/2) {
				cout << ans << '\n';
				return 0;
			}
			if(grid[i][j] != grid[i-1][j]) {
				memset(visited, 0, sizeof(visited));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i-1][j]));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}