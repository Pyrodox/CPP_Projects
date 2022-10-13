#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream cin("homework.in");
    ofstream cout("homework.out");
    cin >> n;
    ll avg = 0;
    vector<ll> v(n + 1);
    set<pair<ll, ll>> s;
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        avg += v[i];
        s.insert({v[i], i});
    }
    double mx = (double)max(v[n - 1], v[n]);
    vector<ll> ans;
    for (ll i = 1; i <= n - 2; ++i) {
        s.erase({v[i], i});
        ll mn = s.begin()->first;
        avg -= v[i];
        if (((double)(avg - mn)) / (n - i - 1) == mx) {
            ans.push_back(i);
        }
        else if (((double)(avg - mn)) / (n - i - 1) > mx) {
            ans.clear();
            ans.push_back(i);
            mx = ((double)(avg - mn)) / (n - i - 1);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll a : ans) {
        cout << a << "\n";
    }
}