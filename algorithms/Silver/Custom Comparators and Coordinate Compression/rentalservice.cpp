#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const ll a, const ll b)
{
    return a > b;
}

bool cmp2(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] > b[1];
}

int main()
{
    ll n, m, r;
    ifstream cin("rental.in");
    ofstream cout("rental.out");
    cin >> n >> m >> r;
    vector<ll> cows(n), rentalv(r);
    vector<vector<ll>> milk(m, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> milk[i][0] >> milk[i][1];
    }
    for (ll i = 0; i < r; ++i) {
        cin >> rentalv[i];
    }
    sort(cows.begin(), cows.end(), cmp);
    sort(rentalv.begin(), rentalv.end(), cmp);
    sort(milk.begin(), milk.end(), cmp2);
    ll ans = 0, shopp = 0, rentp = 0, i = 0;
    while (i < n) {
        ll amt = cows[i], total = 0, curi = shopp, last = 0;
        while (curi < m) {
            ll rest = min(amt, milk[curi][0]);
            total += milk[curi][1] * rest;
            amt -= rest;
            if (amt == 0) {
                last = rest;
                break;
            }
            else {
                ++curi;
            }
        }
        if (rentp >= r || total > rentalv[rentp]) {
            ans += total;
            shopp = curi;
            if (shopp < m) {
                milk[shopp][0] -= last;
            }
            ++i;
        }
        else {
            ans += rentalv[rentp];
            --n;
            ++rentp;
        }
    }
    cout << ans;
}