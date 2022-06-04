#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, mn = 1e5, mx = 0;
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin >> n >> m;
    vector<vector<ll>> ranges(m);
    for (ll i = 0; i < m; ++i) {
        ll a1, a2;
        fin >> a1 >> a2;
        mn = min(mn, a1);
        mx = max(mx, a2);
        ranges[i] = {a1, a2 - a1};
    }
    //cout << mn << " " << mx << "\n";
    sort(ranges.begin(), ranges.end());
    ll l = 1, r = (mx - mn + 1) / 2 + 1;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        //cout << "testing mid: " << mid << "\n";
        ll current = 0, cowposition = 0, cownumber = 1;
        while (cownumber <= n && current < m) {
            if (cowposition >= ranges[current][0] && cowposition <= ranges[current][0] + ranges[current][1]) {
                //cout << "1: " << cowposition << " " << cownumber << "\n";
                cowposition += mid;
                ++cownumber;
            }
            else if (cowposition < ranges[current][0]) {
                //cout << "2\n";
                cowposition = ranges[current][0] + mid;
                ++cownumber;
            }
            else {
                //cout << "3\n";
                ++current;
            }
        }
        if (cownumber == n + 1) {
            //cout << "l: " << l << " to " << mid << "\n";
            l = mid;
        }
        else {
            //cout << "r: " << r << " to " << mid << " - 1\n";
            r = mid - 1;
        }
    }
    fout << l;
}