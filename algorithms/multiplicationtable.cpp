#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

ll numberofvalslessthanx(ll x)
{
    ll total = 0;
    for (ll i = 1; i <= n; ++i) {
        total += min(n, x / i);
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll l = 1, r = n * n;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (numberofvalslessthanx(mid) >= (n * n + 1) / 2) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}