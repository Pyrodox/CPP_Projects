#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> ansvec;
    ll coprime = 1;
    for (ll i = 1; i < n; ++i) {
        if (__gcd(n, i) == 1) {
            coprime = (coprime % n * i % n) % n;
            ansvec.push_back(i);
        }
    }
    vector<ll> newansvec;
    for (ll a : ansvec) {
        if (a != coprime || a == 1) {
            newansvec.push_back(a);
        }
    }
    cout << newansvec.size() << "\n";
    for (ll a : newansvec) {
        cout << a << " ";
    }
}