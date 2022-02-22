#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    fin >> n;
    vector<ll> v(n);
    ll prefix[n + 1];
    prefix[0] = 0;
    ll ans = 0;
    vector<ll> mod(8); 
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
        prefix[i + 1] = (prefix[i] + v[i]) % 7;
        mod[prefix[i + 1]]++; 
    }
    for (ll i = 0; i < 8; ++i) {
        if (mod[i] >= 1) {
            ll index1, index2 = 0;
            for (int j = 1; j <= n; ++j) {
                if (prefix[j] == i) {
                    index1 = j;
                    break;
                }
            }
            for (int j = n; j >= 1; --j) {
                if (prefix[j] == i) {
                    index2 = j;
                    break;
                }
            }
            ans = max(ans, index2 - index1);
            if (index2 - index1 == 0) {
                ans = max(ans, (ll) 1);
            }
        }
    }
    fout << ans;
}