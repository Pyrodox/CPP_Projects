#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    fin >> n;
    set<ll> bessie, elsie;
    for (ll i = 1; i <= 2 * n; ++i) {
        bessie.insert(i);
    }
    for (ll i = 0; i < n; ++i) {
        ll val;
        fin >> val;
        elsie.insert(val);
        bessie.erase(bessie.find(val));
    }
    ll ans = 0;
    auto start = elsie.begin();
    for (ll i = 0; i < n; ++i) {
        //cout << "start: " << *start << "\n";
        auto it = bessie.upper_bound(*start);
        //cout << "it: " << *it << "\n";
        if (it != bessie.end()) {
            ++ans;
            bessie.erase(*it);
            ++start;
        }
        else {
            break;
        }
    }
    fout << ans;
}