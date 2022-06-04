#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, y, k, m;
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> x >> y >> k >> m;
    ll tmpx = x;
    x = min(x, y);
    y = max(y, tmpx);
    ll minval = m;
    minval = min(minval, abs(m - x));
    minval = min(minval, abs(m - y));
    if (k >= 2) {
        minval = min(minval, abs(m - (x + y)));
        ll val = y;
        if (k >= 3) {
            for (ll i = k - 1; i > 0; i -= 2) {
                val -= min(val, x);
                if (val <= 0) {
                    break;
                }
                minval = min(minval, abs(m - val));
            }
            val = y;
            for (ll i = k - 1; i > 0; i -= 3) {
                val -= min(val, x);
                if (val <= 0 && i > 0) {
                    break;
                }
                minval = min(minval, abs(m - (val + x)));
                minval = min(minval, abs(m - val));
            }
        }
        ll bucketa = 0, bucketb = 0;
        for (ll i = 0; i < k; ++i) {
            if (bucketa == 0) {
                bucketa += x;
            }
            else if (bucketb + bucketa <= y) {
                bucketb += bucketa;
                bucketa = 0;
            }
            else if (bucketb < y) {
                bucketa -= y - bucketb;
                bucketb = y;
            }
            else {
                bucketb = 0;
            }
            minval = min(minval, abs(m - (bucketa + bucketb)));
        }
        bucketa = 0, bucketb = 0;
        for (ll i = 0; i < k; ++i) {
            if (bucketb == 0) {
                bucketb = y;
            }
            else if (bucketa == x) {
                bucketa = 0;
            }
            else if (bucketb - x >= 0) {
                bucketb -= x - bucketa;
                bucketa = x;
            }
            else if (bucketb - x < 0) {
                bucketa = bucketb;
                bucketb = 0;
            }
            minval = min(minval, abs(m - (bucketa + bucketb)));
        }
    }
    fout << minval;
}