#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    unordered_map<ll, ll> m;
    for (ll i = 0; i < 4 * n - 1; ++i) {
        ll tmp;
        cin >> tmp;
        m[tmp]++;
    }
    for (auto val : m) {
        if (val.second == 3) {
            cout << val.first;
        }
    }
}