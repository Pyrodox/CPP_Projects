#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

ll n;
vector<vector<ll>> nodes, dists; //dists has node 1, node 2, and distance squared

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
    return a[2] < b[2];
}

int main()
{
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        nodes.push_back({a, b});
        for (ll j = 0; j < i; ++j) {
            ll dist = (b - nodes[j][1]) * (b - nodes[j][1]) + (a - nodes[j][0]) * (a - nodes[j][0]);
            dists.push_back({j, i, dist});
        }
    }
    sort(dists.begin(), dists.end(), cmp);
    DSU dsu(n);
    vector<ll> vis(n);
    ll cmp = n;
    for (auto val : dists) {
        if (dsu.unite(val[0], val[1])) {
            if (--cmp == 1) {
                cout << val[2];
                return 0;
            }
        }
    }
}