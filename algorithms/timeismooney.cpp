#include <bits/stdc++.h>
using namespace std;

const int MAX_DAYS = 1000;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	int n, m, c;
	cin >> n >> m >> c;

	vector<int> earn(n);
	for (int i = 0; i < n; i++) {
		cin >> earn[i];
	}

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].push_back(--v);
	}

	vector<vector<int>> dp(MAX_DAYS + 1, vector<int>(n, -1));
	dp[0][0] = 0;
	
	int ans = 0;
	for (int d = 0; d < MAX_DAYS; d++) {
		for (int i = 0; i < n; i++) {
			if (dp[d][i] != -1) {
				for (int u : adj[i]) {
					dp[d + 1][u] = max(dp[d + 1][u], dp[d][i] + earn[u]);
				}
			}
		}
		ans = max(ans, (dp[d][0] - (c * d * d)));
	}
	cout << ans << "\n";
}