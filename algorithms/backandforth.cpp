#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<ll> barn1(10), barn2(10);
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    for (ll i = 0; i < 10; ++i) {
        fin >> barn1[i];
    }
    for (ll i = 0; i < 10; ++i) {
        fin >> barn2[i];
    }
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 0; i < barn1.size(); ++i) {
        ll ans1 = 0;
        vector<ll> barn2tmp = barn2;
        vector<ll> barn1a = barn1;
        ans1 -= barn1[i];
        barn2tmp.push_back(barn1[i]);
        barn1a.erase(barn1a.begin() + i);
        for (ll j = 0; j < barn2tmp.size(); ++j) {
            ll ans2 = ans1;
            ans2 += barn2tmp[j];
            vector<ll> barn1tmp = barn1a;
            barn1tmp.push_back(barn2tmp[j]);
            vector<ll> tired = barn2tmp;
            tired.erase(tired.begin() + j);
            for (ll k = 0; k < barn1tmp.size(); ++k) {
                ll ans3 = ans2;
                ans3 -= barn1tmp[k];
                vector<ll> barn2tmp2 = tired;
                barn2tmp2.push_back(barn1tmp[k]);
                for (ll l = 0; l < barn2tmp2.size(); ++l) {
                    ll ans4 = ans3;
                    ans4 += barn2tmp2[l];
                    if (mp[ans4] == 0) {
                        ++ans;
                    }
                    mp[ans4]++;
                }
            }
        }
    }
    fout << ans;
}