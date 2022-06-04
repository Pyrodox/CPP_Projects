#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<ll> applicants(n), apartments(m);
    for (ll i = 0; i < n; ++i) {
        cin >> applicants[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    ll ans = 0, l = 0, r = 0;
    while (l < applicants.size() && r < apartments.size()) {
        if (abs(applicants[l] - apartments[r]) <= k) {
            ++ans;
            ++l;
            ++r;
        }
        else if (applicants[l] >= apartments[r]) {
            ++r;
        }
        else {
            ++l;
        }
        //cout << l << " " << r << "\n";
    }
    cout << ans;
}