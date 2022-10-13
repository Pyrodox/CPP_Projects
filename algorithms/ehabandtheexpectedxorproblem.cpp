#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<bool> check(pow(2, 18));
    vector<ll> v{0};
    check[0] = true;
    for (ll i = 1; i < pow(2, n); ++i) {
        if (!check[i ^ x]) {
            v.push_back(i);
            check[i] = true;
        }
    }
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "\n";
    cout << v.size() - 1 << "\n";
    for (ll i = 1; i < v.size(); ++i) {
        cout << (v[i] ^ v[i - 1]) << " ";
    }
}