#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, q;
vector<vector<ll>> edges;

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

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    return a[2] > b[2];
}

bool cmp2(const vector<ll>& a, const vector<ll>& b)
{
    return a[0] > b[0];
}

int main()
{
    ifstream cin("mootube.in");
    ofstream cout("mootube.out");
    cin >> n >> q;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v, r;
        cin >> u >> v >> r;
        edges.push_back({u, v, r});
    }
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        queries.push_back({a, b, i});
    }
    DSU dsu = DSU(n + 1);
    ll iter = 0;
    vector<ll> ans(q);
    sort(edges.begin(), edges.end(), cmp);
    sort(queries.begin(), queries.end(), cmp2);
    
    for (auto val : queries) {
        ll k = val[0], node = val[1];
        while (iter < edges.size() && edges[iter][2] >= k) {
            dsu.unite(edges[iter][0], edges[iter][1]);
            ++iter;
        }
        ans[val[2]] = dsu.size(node) - 1;
    }
    for (ll a : ans) {
        cout << a << "\n";
    }
}