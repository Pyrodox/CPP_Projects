#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> n >> k;
    vector<ll> v(n);
    for (ll& i : v) {
        fin >> i;
    }
    sort(v.begin(), v.end());
    /*for (ll i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
        if (i == v.size() / 2) {
            cout << "mid";
        }
        cout << "\n";
    }*/
    ll l = 1, r = v[v.size() - 1] - v[0];
    while (l < r) {
        ll mid = l + (r - l) / 2, cows = k - 1, l1 = 0, r1 = 0;
        //cout << "testing mid for: " << mid << "\n";
        while (r1 != n) {
            //cout << v[r1] << " " << v[l1] << "\n";
            if (v[r1] - v[l1] <= 2 * mid) {
                ++r1;
            }
            else {
                --cows;
                l1 = r1;
            }
            if (cows < 0) {
                break;
            }
        }
        if (cows >= 0) {
            //cout << "r from " << r << " to " << mid << "\n";
            r = mid;
        }
        else {
            //cout << "l from " << l << " to " << mid << " + 1\n";
            l = mid + 1;
        }
    }
    fout << l;
}