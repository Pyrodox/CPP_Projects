#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t, k;
    cin >> n >> t >> k;
    ll l = 1, r = n, zeroamnt = 0;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        cout << "? " << l << " " << mid << "\n";
        cout.flush();
        ll amt;
        cin >> amt;
        if (k > zeroamnt + mid - l + 1 - amt) {
            zeroamnt += mid - l + 1 - amt;
            l = mid + 1;
            //cout << "a " << k << " " << zeroamnt << " " << mid - l + 1 - amt << "\n";
        }
        else {
            //cout << "b\n";
            r = mid;
        }
    }
    cout << "! " << l;
    cout.flush();
}