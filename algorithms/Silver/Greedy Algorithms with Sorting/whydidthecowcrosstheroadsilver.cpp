#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }

    return a[1] < b[1];
}

int main()
{
    ll n, c;
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    fin >> c >> n;
    multiset<ll> cv;
    vector<vector<ll>> nv(n);
    for (ll i = 0; i < c; ++i) {
        ll a;
        fin >> a;
        cv.insert(a);
    }
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        fin >> a >> b;
        nv[i] = {a, b};
    }
    sort(nv.begin(), nv.end(), cmp);
    ll ans = 0;
    for (auto it = cv.begin(); it != cv.end(); ++it) {
        for (ll j = 0; j < nv.size(); ++j) {
            if (*it >= nv[j][0] && *it <= nv[j][1]) {
                ++ans;
                //cout << cv[i] << " " << nv[j][0] << " " << nv[j][1] << "\n";
                nv.erase(nv.begin() + j);
                break;
            }
        }
    }
    fout << ans;
}