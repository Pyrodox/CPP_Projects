#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binaryupper(vector<double>& v, double p2tmp)
{
    ll l = 0, r = v.size() - 1;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        if (v[mid] <= p2tmp) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    return l;
}

ll binarylower(vector<double>& v, double p1tmp)
{
    ll l = 0, r = v.size() - 1;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] >= p1tmp) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return l;
}

int main()
{
    ll n;
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> n;
    vector<double> v(n);
    for (double& i : v) {
        fin >> i;
    }
    sort(v.begin(), v.end());
    double l = 1, r = (v[0] + v[n - 1]) / 2;
    while (r - l > 0.06) {
        double mid = l + (r - l) / 2, a = mid - floor(mid), b = mid - floor(mid);
        ll lp = 0, rp = n - 1;
        while (a < mid && lp < n - 1) {
            lp = binaryupper(v, v[lp] + a);
            if (a >= v[lp + 1] - v[lp]) {
                ++a;
            }
            else {
                a = v[lp + 1] - v[lp] + mid - floor(mid);
            }
        }
        while (b < mid && rp > lp) {
            rp = binarylower(v, v[rp] - b);
            if (b >= v[rp] - v[rp - 1]) {
                ++b;
            }
            else {
                b = v[rp] - v[rp - 1] + mid - floor(mid);
            }
        }
        if (v[lp] + mid >= v[rp] - mid) {
            r = mid;
        }
        else {
            l = mid; 
        }
    }
    fout << fixed << setprecision(1) << static_cast<int>(l * 10 + 0.5) / 10.0;
}