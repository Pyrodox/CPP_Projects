#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    bitset<1000000001> bt;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        bt[a] = 1;
    }
    cout << bt.count();
}