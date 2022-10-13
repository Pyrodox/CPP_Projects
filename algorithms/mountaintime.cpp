#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1001;

ll n, m;
vector<vector<ll>> grid(mx, vector<ll>(mx));
vector<vector<ll>> nof(mx * mx);
vector<ll> nodes(mx * mx);
vector<ll> ans(mx * mx);
vector<ll> bigvis(mx * mx);

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    ll mna = min(nodes[a[0]], nodes[a[1]]), mxa = max(nodes[a[0]], nodes[a[1]]);
    ll mnb = min(nodes[b[0]], nodes[b[1]]), mxb = max(nodes[b[0]], nodes[b[1]]);
    if (mna == mnb) {
        return mxa > mxb;
    }

    return mna > mnb;
}

struct DSU {
	vector<int> e, mxnode, mnnode;
	DSU(int N) { 
        e = vector<int>(N, -1); 
        mxnode = vector<int>(N, 0);
        mnnode = vector<int>(N, -1); 
    };

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
        ll ta = x, tb = y;
		x = get(x), y = get(y);
        nof[x].push_back(ta);
        nof[y].push_back(tb);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
        mxnode[x] = max(mxnode[y], max(mxnode[x], (int)max(nodes[x], nodes[y])));
        if (mnnode[x] == -1) {
            mnnode[x] = 99999999;
        }
        if (mnnode[y] == -1) {
            mnnode[y] = 99999999;
        }
        mnnode[x] = min(mnnode[y], min(mnnode[x], (int)min(nodes[x], nodes[y])));
		e[x] += e[y]; e[y] = x;
        for (ll a : nof[y]) {
            nof[x].push_back(a);
            if (bigvis[a] && mxnode[x] > nodes[a]) {
                ans[a] = abs(mnnode[x] - nodes[a]);
            }
        }
		return true;
	}
};

bool cmp2(ll a, ll b)
{
    if (nodes[a] == nodes[b]) {
        return a > b;
    }
    return nodes[a] > nodes[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ll big = 0;
    vector<vector<ll>> edges;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            big = max(big, grid[i][j]);
            nodes[i * m + j] = grid[i][j];
            if (i - 1 >= 0) {
                edges.push_back({(i - 1) * m + j, i * m + j});
            }
            if (j - 1) {
                edges.push_back({i * m + j - 1, i * m + j});
            }
        }
    }
    //set<ll, decltype(&cmp2)> checknodes(&cmp2);
    ll it = 0, fcn = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (grid[i][j] == big) {
            }
            else if (i > 0 && grid[i - 1][j] > grid[i][j] || j >= 1 && grid[i][j - 1] > grid[i][j] 
            || i < n - 1 && grid[i + 1][j] > grid[i][j] || j < m && grid[i][j + 1] > grid[i][j]) {
            }
            else {
                bigvis[it + 1] = 1;
            }
            ++it;
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(mx * mx);
    ll cnt = 0;
    for (auto val : edges) {
        dsu.unite(val[0], val[1]);
    }
    it = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (grid[i][j] == big) {
                cout << big << " ";
                ++it;
            }
            else {
                cout << ans[it++] << " ";
            }
        }
        cout << "\n";
    }
}