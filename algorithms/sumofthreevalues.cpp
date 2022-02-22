#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<ll>> m(n);
    vector<ll> a = v;
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (v[i] == a[j]) {
                m[i].push_back(j);
            }
        }
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll l = i + 1, r = n - 1;
        while (l < r) {
            if (v[l] + v[r] + v[i] < x) {
                ++l;
            }
            else if (v[l] + v[r] + v[i] > x) {
                --r;
            }
            else if (v[l] + v[r] + v[i] == x) {
                if (m[i] == m[l] && m[l] == m[r]) {
                    cout << m[i][0] + 1 << " " << m[l][1] + 1 << " " << m[r][2] + 1;
                }
                else if (m[i] == m[l]) {
                    cout << m[i][0] + 1 << " " << m[l][1] + 1 << " " << m[r][0] + 1;
                }
                else if (m[l] == m[r]) {
                    cout << m[i][0] + 1 << " " << m[l][0] + 1 << " " << m[r][1] + 1;
                }
                else if (m[i] == m[r]) {
                    cout << m[i][0] + 1 << " " << m[r][1] + 1 << " " << m[l][0] + 1;
                }
                else {
                    cout << m[i][0] + 1 << " " << m[l][0] + 1 << " " << m[r][0] + 1;
                }
                return 0;
            }
            else {
                ++l;
            }
        }
    }
    cout << "IMPOSSIBLE";
}