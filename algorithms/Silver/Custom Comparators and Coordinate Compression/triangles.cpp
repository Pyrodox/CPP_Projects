#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e4 + 2;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] < b[1];
}

int main()
{
    ll n;
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    cin >> n;
    vector<vector<ll>> inputssortedbyx, inputssortedbyy;
    vector<vector<vector<ll>>> rows(mx), cols(mx);
    vector<ll> rowsavail, colsavail;
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        inputssortedbyx.push_back({x + 10000, y + 10000, i});
        inputssortedbyy.push_back({x + 10000, y + 10000, i});
    }
    sort(inputssortedbyx.begin(), inputssortedbyx.end());
    sort(inputssortedbyy.begin(), inputssortedbyy.end(), cmp);
    vector<bool> mprows(mx), mpcols(mx);
    for (ll i = 0; i < n; ++i) {
        rows[inputssortedbyx[i][1]].push_back({inputssortedbyx[i][0], inputssortedbyx[i][2]});
        if (!mprows[inputssortedbyx[i][1]]) {
            rowsavail.push_back(inputssortedbyx[i][1]);
            mprows[inputssortedbyx[i][1]] = true;
        }
        cols[inputssortedbyy[i][0]].push_back({inputssortedbyy[i][1], inputssortedbyy[i][2]});
        if (!mpcols[inputssortedbyy[i][0]]) {
            colsavail.push_back(inputssortedbyy[i][0]);
            mpcols[inputssortedbyy[i][0]] = true;
        }
    }
    vector<vector<ll>> ansv(n, vector<ll>(2));
    for (ll i = 0; i < rowsavail.size(); ++i) {
        ll y = rowsavail[i];
        for (ll j = 1; j < rows[y].size(); ++j) {
            ansv[rows[y][0][1]][0] += rows[y][j][0] - rows[y][0][0];
        }
        for (ll j = 1; j < rows[y].size(); ++j) {
            ansv[rows[y][j][1]][0] += ansv[rows[y][j - 1][1]][0] - (rows[y].size() - 1 - j) * (rows[y][j][0] - rows[y][j - 1][0]) + (j - 1) * (rows[y][j][0] - rows[y][j - 1][0]);
        }
    }
    for (ll i = 0; i < colsavail.size(); ++i) {
        ll x = colsavail[i];
        for (ll j = 1; j < cols[x].size(); ++j) {
            ansv[cols[x][0][1]][1] += cols[x][j][0] - cols[x][0][0];
        }
        for (ll j = 1; j < cols[x].size(); ++j) {
            ansv[cols[x][j][1]][1] += ansv[cols[x][j - 1][1]][1] - (cols[x].size() - 1 - j) * (cols[x][j][0] - cols[x][j - 1][0]) + (j - 1) * (cols[x][j][0] - cols[x][j - 1][0]);
        }
    }
    const ll mod = 1e9 + 7;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += ansv[i][0] * ansv[i][1];
    }
    cout << ans % mod;
}