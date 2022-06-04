#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");
    ll n;
    cin >> n;
    vector<vector<ll>> v;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 1, i});
        v.push_back({b, -1, i});
    }
    sort(v.begin(), v.end());
    vector<ll> oneamt(n);
    set<ll> currentis;
    ll currenti, amountcovering = 0, startval, timecovered = 0;
    for (ll i = 0; i < 2 * n; ++i) {
        if (i >= 1 && v[i - 1][0] != -1 && amountcovering != 0) {
            timecovered += v[i][0] - v[i - 1][0];
        }
        if (amountcovering == 1) {
            oneamt[currenti] += v[i][0] - startval;
        }
        if (v[i][1] == 1) {
            ++amountcovering;
            currentis.insert(v[i][2]);
        }
        else if (v[i][1] == -1) {
            --amountcovering;
            currentis.erase(v[i][2]);
        }
        if (amountcovering == 1) {
            currenti = *currentis.begin();
            startval = v[i][0];
        }
    }
    sort(oneamt.begin(), oneamt.end());
    cout << timecovered - oneamt[0];
}