#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x;
    ll l = 0, r = 33;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (x % (ll)(pow(2, mid)) == 0) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << pow(2, max((ll)0, l - 1));
}