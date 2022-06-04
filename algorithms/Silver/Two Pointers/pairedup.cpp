#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    fin >> n;
    unordered_map<ll, ll> m;
    vector<ll> avail;
    ll ttl = 0;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        fin >> a >> b; 
        m[b] = a;
        avail.push_back(b);
        ttl += a;
    }
    sort(avail.begin(), avail.end());
    ll mx = 0;
    ll a = 0, b = avail.size() - 1, c = 0, d = 0;
    while (b >= 0 && a < avail.size()) {
        if (c < m[avail[a]] && d < m[avail[b]]) {
            mx = max(mx, avail[a] + avail[b]);
            ll tmp = c;
            c += min(m[avail[a]] - c, m[avail[b]] - d);
            d += min(m[avail[a]] - tmp, m[avail[b]] - d);
        }
        if (c >= m[avail[a]]) {
            ++a;
            c = 0;
        }
        if (d >= m[avail[b]]) {
            --b;
            d = 0;  
        }
    }
    fout << mx;
}