#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

map<string, ll> dp, found;

void recurs(string s)
{
    if (s.size() <= 1) {
        return;
    }
    for (ll i = 0; i < s.size() - 1; ++i) {
        string s1 = s.substr(0, i + 1), s2 = s.substr(i + 1);
        if (!found[s1]) {
            recurs(s1);
        }
        if (!dp[s1]) {
            continue;
        }
        if (!found[s2]) {
            recurs(s2);
        }
        //cout << s << " " << s1 << " " << s2 << "\n";
        //cout << dp[s] << " " << dp[s1] << " " << dp[s2] << "\n";
        dp[s] = (dp[s] + dp[s1] * dp[s2] % mod) % mod;
    }
    found[s] = 1;
}

int main()
{
    ll n;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (ll i = 0; i < n; ++i) {
        string ss; ll amt;
        cin >> ss >> amt;
        dp[ss] = amt;
    }
    recurs(s);
    cout << dp[s] % mod;
}