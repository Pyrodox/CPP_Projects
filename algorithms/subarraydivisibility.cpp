#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n);
    ll prefix = 0, ans = 0;
    unordered_map<ll, ll> m;
    m[0] = 1; 
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        prefix += v[i];
        m[(prefix % n + n) % n]++;
    }
    for (auto val : m) {
        ans += (val.second * (val.second - 1)) / 2;
    }
    cout << ans;
}