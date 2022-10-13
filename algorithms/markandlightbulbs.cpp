#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n;
        vector<ll> s(n + 1), t(n + 1);
        string str;
        cin >> str;
        for (ll i = 0; i < n; ++i) {
            s[i + 1] = str[i] - '0';
        }
        cin >> str;
        for (ll i = 0; i < n; ++i) {
            t[i + 1] = str[i] - '0';
        }
        if (s[1] != t[1] || s[n] != t[n]) {
            cout << -1 << "\n";
            continue;
        }
        vector<pair<ll, ll>> groupS, groupT;
        for (ll i = 1; i <= n; ++i) {
            if (!s[i - 1] && s[i]) {
                ll left = i;
                while (i <= n && s[i]) {
                    ++i;
                }
                --i;
                groupS.push_back({left, i++});
            }
        }
        for (ll i = 1; i <= n; ++i) {
            if (!t[i - 1] && t[i]) {
                ll left = i;
                while (i <= n && t[i]) {
                    ++i;
                }
                --i;
                groupT.push_back({left, i++});
            }
        }
        if (groupS.size() != groupT.size()) {
            cout << -1 << "\n";
            continue;
        }
        ll ans = 0;
        for (ll i = 0; i < groupS.size(); ++i) {
            ans += abs(groupS[i].first - groupT[i].first) + abs(groupS[i].second - groupT[i].second);
        }
        cout << ans << "\n";
    }
}