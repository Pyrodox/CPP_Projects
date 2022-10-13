#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    string st;
    ifstream cin("cowcode.in");
    ofstream cout("cowcode.out");
    cin >> st >> n;
    ll s = st.size();
    if (n <= s) {
        cout << st[n - 1];
        return 0;
    }
    ll l = 1, r = 64;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (n > ((ll)1 << mid) * s) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    //cout << l << "\n";
    ll k = l, ogk = l, ogn = n;
    n -= ((ll)1 << (k - 1)) * s + 1;
    while (n > s) {
        ll l = 1, r = k;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (((ll)1 << mid) * s + 1 > n) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }   
        k = l;
        n -= ((ll)1 << (k - 1)) * s + 1;
    }
    if (n) {
        cout << st[n - 1];
    }
    else {
        n = ogn - 1;
        if (n <= s) {
            cout << st[n - 1];
            return 0;
        }
        ll l = 1, r = ogk + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (n > ((ll)1 << mid) * s) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        k = l;
        n -= ((ll)1 << (k - 1)) * s + 1;
        //cout << n << "\n";
        while (n > s) {
            ll l = 1, r = k;
            while (l < r) {
                ll mid = l + (r - l) / 2;
                if (((ll)1 << mid) * s + 1 > n) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }   
            k = l;
            n -= ((ll)1 << (k - 1)) * s + 1;
        }
        cout << st[n - 1];
    }
}