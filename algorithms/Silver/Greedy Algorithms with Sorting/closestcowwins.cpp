#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> m >> n;
    map<ll, ll> patches;
    vector<ll> patchesvec(k);
    for (ll i = 0; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        patches[a] = b;
        patchesvec[i] = a;
    }
    vector<ll> nhojcows(m);
    map<ll, ll> callmp;
    ll cnt = 0;
    for (ll& i : nhojcows) {
        cin >> i;
        callmp[i] = cnt;
        ++cnt;
    } 
    sort(nhojcows.begin(), nhojcows.end());
    map<ll, vector<vector<ll>>> mp;
    vector<vector<ll>> leftandright(m); //leftandright[callmp[nhojcows value]] [0] or [1]
}