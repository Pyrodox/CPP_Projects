#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v(200001), dp(200001);
ll n, ans = 0;

ll findseq(ll it)
{
    if (dp[it]) {
        return dp[it];
    }
    ll cnt = 0;
    for (ll i = it - 1; i >= 0; --i) {
        ll a = findseq(i);
        if (v[i] < v[it]) {
            cnt = max(cnt, a);
        }
    }
    dp[it] = cnt + 1;
    ans = max(ans, dp[it]);

    return dp[it];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    findseq(n - 1);
    cout << ans;
}