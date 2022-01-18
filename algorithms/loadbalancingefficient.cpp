#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, b, tmp, tmp2;
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    fin >> n >> b;
    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> tmp >> tmp2;
        v[i].push_back(tmp);
        v[i].push_back(tmp2);
    }
    ll m = 100000000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = v[i][0] + 1;
            int y = v[j][1] + 1;
            ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (ll k = 0; k < v.size(); ++k) {
                if (v[k][0] > x && v[k][1] > y) {
                    ++q1;
                }
                else if (v[k][0] < x && v[k][1] > y) {
                    ++q2;
                }
                else if (v[k][0] < x && v[k][1] < y) {
                    ++q3;
                }
                else {
                    ++q4;
                }
            }
            m = min(m, max(max(q1, q2), max(q3, q4)));
        }
    }
    fout << m;
}