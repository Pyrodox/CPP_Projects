#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> cities(n), towers(m);
    for (ll& i : cities) {
        cin >> i;
    }
    for (ll& i : towers) {
        cin >> i;
    }
    ll l = 0, r = max(towers[towers.size() - 1], cities[cities.size() - 1]) - min(towers[0], cities[0]);
    while (l < r) {
        ll mid = l + (r - l) / 2, cpointer = 0, tpointer = 0;
        //cout << "testing mid: " << mid << "\n";
        while (cpointer < n && tpointer < m) {
            ll range1 = towers[tpointer] - mid, range2 = towers[tpointer] + mid;
            if (cities[cpointer] >= range1 && cities[cpointer] <= range2) {
                ++cpointer;
            }
            else {
                ++tpointer;
            }
        }
        //cout << cpointer << " " << tpointer << "\n";
        if (cpointer == n) {
            //cout << "r: " << r << " " << mid << "\n";
            r = mid;
        }
        else {
            //cout << "l: " << l << " " << mid << " + 1\n";
            l = mid + 1;
        }
    }
    cout << l;
}