#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> q;
    while (q--) {
        ll m; char c; cin >> m >> c;
        ll l = 0, r = 0, koyomity = 0;
        while (l < n && r < n) {
            while (r < n) {
                if (s[r] != c) {
                    if (m == 0) {
                        break;
                    }
                    --m;
                }
                ++r;
            }
            koyomity = max(koyomity, r - l);
            if (s[l++] != c) {
                ++m;
            }
        }
        cout << koyomity << "\n";
    }
}