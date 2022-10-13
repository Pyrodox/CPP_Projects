#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, m, cnt = 0;
vector<ll> perms(mx);
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

int main()
{
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    cin >> n >> m;
    DSU dsu(mx);
    set<vector<ll>> ab;
    ll flag = 1;
    for (ll i = 1; i <= n; ++i) {
        cin >> perms[i];
        if (i != perms[i]) {
            ab.insert({i, perms[i]});
        }
        if (i >= 2 && perms[i - 1] > perms[i]) {
            flag = 0;
        }
    }
    if (flag) { cout << -1; return 0; };
    for (ll i = 1; i <= m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (ll i = 0; i < edges.size(); ++i) {
        dsu.unite(edges[i][0], edges[i][1]);
        ll flag = 1;
        auto it = ab.begin();
        while (it != ab.end()) {
            if (dsu.same_set((*it)[0], (*it)[1])) {
                it = ab.erase(it);
            }
            else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << edges[i][2];
            break;
        }
    }
}