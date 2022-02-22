#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k, b;
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    fin >> n >> k >> b;
    unordered_map<ll, ll> m;
    for (ll i = 0; i < b; ++i) {
        ll tmp;
        fin >> tmp;
        m[tmp]++;
    }
    vector<ll> fixed(n + 1), broken(n + 1);
    for (ll i = 0; i < n; ++i) {
        fixed[i + 1] += fixed[i];
        broken[i + 1] += broken[i];
        if (m[i + 1] == 0) {
            fixed[i + 1] += 1;
        }
        else {
            broken[i + 1] += 1;
        }
    }
    ll ans = 200000000;
    for (int i = 1; i <= n - k + 1; ++i) {
        ans = min(ans, broken[i + k - 1] - broken[i - 1]);
    }   
    fout << ans;
}