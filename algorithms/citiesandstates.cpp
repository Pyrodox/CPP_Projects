#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream cin("citystate.in");
    ofstream cout("citystate.out");
    cin >> n;
    map<string, int> mp;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        string ct, st;
        cin >> ct >> st;
        mp[st + ct.substr(0, 2)]++;
        if (mp[ct.substr(0, 2) + st] && st != ct.substr(0, 2)) {
            ans += mp[ct.substr(0, 2) + st];
        } 
    }
    cout << ans;
}