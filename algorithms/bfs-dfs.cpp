#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<ll, ll>> ans;
    vector<ll> bfsv(n), dfsv(n);
    for (ll i = 0; i < n; ++i) {
        cin >> bfsv[i];
        if (bfsv[i] != 1) {
            ans.push_back({1, bfsv[i]});
        }
    }
    for (ll i = 0; i < n; ++i) {
        cin >> dfsv[i];
        if (i > 1) {
            ans.push_back({dfsv[i - 1], dfsv[i]});
        }
    }
    if (dfsv[1] != bfsv[1]) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << "\n";
    for (auto val : ans) {
        cout << val.first << " " << val.second << "\n";
    }
}