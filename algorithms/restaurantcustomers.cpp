#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> e(n), l(n), v;
    unordered_map<ll, ll> em, lm;
    for (int i = 0; i < n; ++i) {
        cin >> e[i] >> l[i];
        em[e[i]]++;
        lm[l[i]]++;
        v.push_back(e[i]);
        v.push_back(l[i]);
    }
    sort(v.begin(), v.end());
    ll ans = 0, cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (em[v[i]] > 0 && lm[v[i]] == 0) {
            ++cnt;
            ans = max(ans, cnt);
        }
        else if (lm[v[i]] > 0 && em[v[i]] == 0) {
            --cnt;
        }
    }
    cout << ans;
}