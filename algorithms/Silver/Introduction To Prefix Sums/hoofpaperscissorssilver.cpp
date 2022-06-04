#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    ll n;
    cin >> n;
    vector<vector<ll>> v(n + 1, vector<ll>(3));
    for (ll i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'P') {
            v[i + 1][0]++;
        }
        else if (c == 'H') {
            v[i + 1][1]++;
        }
        else {
            v[i + 1][2]++;
        }
        v[i + 1][0] += v[i][0];
        v[i + 1][1] += v[i][1];
        v[i + 1][2] += v[i][2]; 
    }
    v.push_back(v[v.size() - 1]);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans = max(ans, v[i][0] + v[n + 1][1] - v[i - 1][1]);
        ans = max(ans, v[i][0] + v[n + 1][2] - v[i - 1][2]);
        ans = max(ans, v[i][1] + v[n + 1][0] - v[i - 1][0]);
        ans = max(ans, v[i][1] + v[n + 1][2] - v[i - 1][2]);
        ans = max(ans, v[i][2] + v[n + 1][0] - v[i - 1][0]);
        ans = max(ans, v[i][2] + v[n + 1][1] - v[i - 1][1]);
    }
    cout << ans;
}