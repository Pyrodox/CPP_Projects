#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0, mxval = 0;
        map<ll, ll> mp;
        vector<ll> v(n);
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
            mp[v[i]]++;
            mxval = max(mxval, v[i]);
        }
        if (mp[v[0]] == n) {
            cout << 0 << "\n";
        }
        else {
            for (ll i = n; i >= 1; --i) {
                double search = (double) sum / i;
                if (search == floor(search) && mxval <= search) {
                    ll l = 0, r = 0, cnt = 0, ttl = v[0], ans = 0;
                    while (r < n) {
                        if (ttl < search) {
                            //cout << l << " " << r << "\n";
                            ++r;
                            ttl += v[r];
                            ++ans;
                        }
                        else if (ttl == search) {
                            //cout << l << " " << r << " a\n";
                            ++cnt;
                            if (r + 1 < n) {
                                ++r;
                                l = r;
                                ttl = v[l];
                            }
                            else {
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    if (cnt == i) {
                        cout << ans << "\n";
                        break;
                    }
                }
            }
        }
    }
}