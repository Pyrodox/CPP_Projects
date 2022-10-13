#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 501;

ll n;
vector<vector<ll>> grid(mx, vector<ll>(mx)), edges;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    return a[2] < b[2];
}

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main()
{
    ifstream cin("tractor.in");
    ofstream cout("tractor.out");
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> grid[i][j];
            if (i - 1 >= 0) {
                edges.push_back({(i - 1) * n + j, i * n + j, abs(grid[i - 1][j] - grid[i][j])});
            }
            if (j - 1 >= 1) {
                edges.push_back({i * n + j - 1, i * n + j, abs(grid[i][j - 1] - grid[i][j])});
            }
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    ll quota = (n * n + 1) / 2;
    DSU dsu(mx * mx);
    for (auto val : edges) {
        dsu.unite(val[0], val[1]);
        if (dsu.size(val[0]) >= quota) {
            cout << val[2];
            return 0;
        }
    }
}