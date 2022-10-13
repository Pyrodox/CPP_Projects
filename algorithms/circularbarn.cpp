#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sumn2(ll a)
{
    return a * (a + 1) * (2 * a + 1) / 6;
}

int main()
{
    ll n;
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");
    cin >> n;
    vector<ll> startingcows(n);
    for (ll i = 0; i < n; ++i) {
        cin >> startingcows[i];
    }
    vector<ll> occupiedhereby(n), currentstate = startingcows, ogcowmap(n), lead(n);
    ll cnt = 0, it = 0, ogcows = 0;
    for (ll i = 0; i < n; ++i) {
        if (startingcows[i]) {
            occupiedhereby[i] = ogcows++;
            ogcowmap[ogcows - 1] = startingcows[i];
            lead[ogcows - 1] = i;
        }
    }
    vector<ll> totalmoves(ogcows);
    while (cnt < n) {
        if (currentstate[(it + 1) % n]) {
            ++it;
            ++cnt;
            continue;
        }
        ll it1 = it + 1;
        for (; it1 % n != it % n; ++it1) {
            if (currentstate[(it1 + 1) % n] != 0) {
                break;
            }
        }
        if (lead[occupiedhereby[it % n]] == it % n) {
            totalmoves[occupiedhereby[it % n]] += (it1 - it + n) % n;
            lead[occupiedhereby[it % n]] = (it1 + n) % n;
        }
        ll a = occupiedhereby[it % n], b = currentstate[it % n];
        for (ll i = 0; i < min((it1 - it + n) % n, b); ++i) {
            currentstate[(it1 - i + n) % n] = 1;
            --currentstate[it % n];
            occupiedhereby[(it1 - i + n) % n] = a; 
        }
        if (!currentstate[it % n]) {
            occupiedhereby[it % n] = 0;
        }
        ++it;
        cnt = 0;
    }
    ll ans = 0;
    for (ll i = 0; i < totalmoves.size(); ++i) {
        ans += sumn2(totalmoves[i]) - sumn2(totalmoves[i] - min(ogcowmap[i], totalmoves[i]));
    }
    cout << ans;
}