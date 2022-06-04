#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
// List of all the components of the farm
vector<int> comps[MAX_N];
// Given a node, returns the index of the component it belongs to
int comp[MAX_N];

// DFS to find the connected components
void dfs(int cur, int c) {
	if (comp[cur] != -1) {
		return;
	}
	comp[cur] = c;
	for (int u : adj[cur]) {
		dfs(u, c);
	}
}

ll cost(int a, int b) {
	int dist = MAX_N;
	for (int u : comps[a]) {
		/*
		 * Finds the closest field in bs' connected
		 * component to field u and updates the minimum
		 * distance. The closest field is found by binary
		 * searching on a sorted array (bs' connected 
		 * component).
		 */
		int i = lower_bound(
			comps[b].begin(), comps[b].end(), u
		) - comps[b].begin();
		if (i > 0) {
			dist = min(dist, abs(comps[b][i - 1] - u));
		}
		if (i < comps[b].size()) {
			dist = min(dist, abs(comps[b][i] - u));
		}
	}
	/* 
	 * Returns the minimum cost of building a path 
	 * between the two components (aka dist^2)
	 */
	return (ll)dist * dist;
}

void solve() {
	int n, m;
	cin >> n >> m;

	// Resets our variables for each test case
	for (int i = 0; i < n; i++) {
		comp[i] = -1;
		adj[i].clear();
		comps[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}

	/* 
	 * Stores the number of connected components 
	 * (set to -1 so that we don't overcount)
	 */
	int cur = -1;
	// Uses DFS to find each connected component
	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			dfs(i, ++cur);
		}
	}

	/*
	 * Add each field to its connected component.
	 * Since we're iterating from 0...n-1, each
	 * connected component is guaranteed to be 
	 * in sorted order
	 */
	for (int i = 0; i < n; i++) {
		comps[comp[i]].push_back(i);
	}

	/*
	 * The initial answer is set to the cost of building
	 * a direct path between fields 1 and N. This also
	 * takes care of the case when fields 1 and N are in
	 * the same connected component.
	 */
	ll res = cost(comp[0], comp[n - 1]);
	for (int c = 1; c < cur; c++) {
		// Minimize the cost of building two paths
		res = min(res, cost(c, 0) + cost(c, comp[n - 1]));
	}
	cout << res << endl;
}

int main()
{
	int t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}