#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll cnt = 1, ans = 0;
    while (n / pow(5, cnt)) {
        ans += n / pow(5, cnt);
        ++cnt;
    }
    cout << ans;
}