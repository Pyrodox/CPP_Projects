#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> ans;

ll search(ll x)
{
    ll l = 0, r = ans.size();
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (ans[mid][ans[mid].size() - 1] < x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    ans.push_back({s[0]});
    for (ll i = 1; i < n; ++i) {
        if (s[i] < ans[ans.size() - 1][ans[ans.size() - 1].size() - 1]) {
            ans.push_back({s[i]});
        }
        else {
            ans[search(s[i])].push_back(s[i]);
        }
    }
    for (auto val : ans) {
        for (ll i : val) {
            cout << i << " ";
        }
        cout << "\n";
    }
}