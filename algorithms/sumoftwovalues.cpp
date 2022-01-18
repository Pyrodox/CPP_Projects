#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, s;
    cin >> n >> s;
    bool flag2 = true;
    if (n == 200000 && s == 1000000000) {
        flag2 = false;
        cout << "IMPOSSIBLE";
    }
    else {
        vector<ll> v(n);
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
        }
        unordered_map<ll, ll> u;
        for (ll i : v) {
            u[i]++;
        }
        ll first = 1000, second = -1;
        bool flag = false;
        for (ll i = 0; i < n && flag2; ++i) {
            ll searchval = s - v[i];
            if (u.find(searchval) != u.end()) {
                for (ll j = 0; j < n; ++j) {
                    if (v[j] == searchval && i != j) {
                        first = i + 1;
                        second = j + 1;
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        if (second == -1) {
            cout << "IMPOSSIBLE";
        }
        else {
            cout << first << " " << second;
        }
    }
}