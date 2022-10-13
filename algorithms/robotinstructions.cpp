#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#pragma GCC optimize("O3","unroll-loops")

bool cmp(vector<ll>& a, ll va)
{
    return a[0] < va;
}

bool cmp2(ll va, vector<ll>& a)
{
    return a[0] > va;
}

void subset(vector<vector<ll>>& subs, vector<vector<ll>>& v)
{
    subs = {{{0, 0, 0}}};
    for (ll i = 0; i < v.size(); ++i) {
        ll sz = subs.size();
        for (ll j = 0; j < sz; ++j) {
            subs.push_back({subs[j][0] + v[i][0], subs[j][1] + v[i][1], subs[j][2] + 1});
        }
    }
}

int main()
{
    ll n, xg, yg;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> xg >> yg;
    vector<vector<ll>> v1(n / 2, vector<ll>(2)), v2((n + 1) / 2, vector<ll>(2));
    for (ll i = 0; i < n / 2; ++i) {
        cin >> v1[i][0] >> v1[i][1];
    }
    for (ll i = n / 2; i < n; ++i) {
        cin >> v2[i - n / 2][0] >> v2[i - n / 2][1];
    }
    vector<vector<ll>> subset1, subset2;
    subset(subset1, v1);
    subset(subset2, v2);
    sort(subset1.begin(), subset1.end());
    sort(subset2.begin(), subset2.end());
    reverse(subset2.begin(), subset2.end());
    /*for (auto val : subset1) {
        cout << val[0] << " " << val[1] << " " << val[2] << "\n";
    }
    cout << "\n";
    for (auto val : subset2) {
        cout << val[0] << " " << val[1] << " " << val[2] << "\n";
    }*/
    vector<ll> ans(n + 1);
    ll rstprev = 1e18, rstprevy = 1e18;
    ll it = 0;
    vector<ll> numadd;
    for (auto val : subset1) {
        ll rst = xg - val[0];
        if (rstprev != rst || rstprevy != yg - val[1]) {
            rstprev = rst, rstprevy = yg - val[1];
            //cout << rst << " " << yg - val[1] << "\n";
            numadd = vector<ll>(n - n / 2 + 1);
            for (; it < subset2.size() && subset2.at(it)[0] > rst && subset2.at(it)[1] > yg - val[1]; ++it);
            for (; it < subset2.size() && subset2.at(it)[0] == rst && subset2.at(it)[1] == yg - val[1]; ++it) {
                ++numadd.at(subset2.at(it)[2]);
            }
        }
        for (ll i = 0; i < numadd.size(); ++i) {
            ans[i + val[2]] += numadd[i];
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
}