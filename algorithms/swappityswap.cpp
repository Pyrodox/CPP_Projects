#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k, a1, a2, b1, b2;
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    fin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector<ll> v(n);
    iota(v.begin(), v.end(), 1);
    vector<ll> sortd = v;
    ll cyclecnt = 0;
    for (int i = 0; i < k; ++i) {
        reverse(v.begin() + a1 - 1, v.begin() + a2);
        reverse(v.begin() + b1 - 1, v.begin() + b2);
        if (v == sortd) {
            cyclecnt = i + 1;
            break;
        }
    }
    if (cyclecnt < k && cyclecnt != 0) {
        for (int i = 0; i < k % cyclecnt; ++i) {
            reverse(sortd.begin() + a1 - 1, sortd.begin() + a2);
            reverse(sortd.begin() + b1 - 1, sortd.begin() + b2);
        }
        for (auto val : sortd) {
            fout << val << "\n";
        }
    }
    else {
        for (auto val : v) {
            fout << val << "\n";
        }
    }
}