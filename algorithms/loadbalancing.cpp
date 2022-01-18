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
    //ll minx = v[0][0], maxx = v[0][0];
    //ll miny = v[0][1], maxy = v[0][1];
    ll maxx = v[0][0], maxy = v[0][1];
    for (auto val : v) {
        if (val[0] > maxx) {
            maxx = val[0];
        }
        if (val[1] > maxy) {
            maxy = val[1];
        }
    }
    ll cntx = 0, cnty = 0;
    for (auto val : v) {
        cntx += val[0];
        cnty += val[1];
    }
    cntx /= n;
    cnty /= n;
    cntx -= 20;
    cnty -= 20;
    if (cntx % 2 != 0) {
        --cntx;
    }
    if (cnty % 2 != 0) {
        --cnty;
    }
    if (cntx < 2) {
        cntx = 2;
    }
    if (cnty < 2) {
        cnty = 2;
    }
    ll m = 10000000;
    for (ll i = cntx; i <= cntx + 10000; i += 2) {
        if (i > maxx) {
            break;
        }
        for (ll j = cnty; j <= cnty + 10000; j += 2) {
            if (j > maxy) {
                break;
            }
            ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (ll k = 0; k < v.size(); ++k) {
                if (v[k][0] > i && v[k][1] > j) {
                    ++q1;
                }
                else if (v[k][0] < i && v[k][1] > j) {
                    ++q2;
                }
                else if (v[k][0] < i && v[k][1] < j) {
                    ++q3;
                }
                else {
                    ++q4;
                }
            }
            //cout << q1 << " " << q2 << " " << q3 << " " << q4 << "\n";
            m = min(m, max(max(q1, q2), max(q3, q4)));
        }
    }
    fout << m;
}