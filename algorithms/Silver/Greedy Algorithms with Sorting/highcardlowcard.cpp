#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    fin >> n;
    set<ll> bessie, elsie1, elsie2;
    for (ll i = 1; i <= 2 * n; ++i) {
        bessie.insert(i);
    }
    for (ll i = 0; i < n; ++i) {
        ll a;
        fin >> a;
        bessie.erase(a);
        if (i < n / 2) {
            elsie1.insert(a);
        }
        else {
            elsie2.insert(a);
        }
    }
    /*for (auto val : bessie) {
        cout << val << " ";
    }
    cout << "\n";
    for (auto val : elsie1) {
        cout << val << " ";
    }
    cout << "\n";
    for (auto val : elsie2) {
        cout << val << " ";
    }
    cout << "\n";*/
    ll ans = 0;
    auto it1 = elsie1.end();
    auto ita = bessie.end();
    --it1;
    --ita;
    for (ll i = 0; i < n / 2; ++i) {
        //cout << *ita << " " << *it1 << "\n";
        if (*ita > *it1) {
            ++ans;
            //bessie.erase(ita);
            --ita;
        }
        --it1;
    }
    auto it2 = bessie.end();
    --it2;
    for (ll i = 0; i < bessie.size(); ++i) {
        //cout << *it2 << " \n";
        auto it = elsie2.upper_bound(*it2);
        if (it != elsie2.end()) {
            ++ans;
            elsie2.erase(it);
        }
        --it2;
    }
    fout << ans;
}