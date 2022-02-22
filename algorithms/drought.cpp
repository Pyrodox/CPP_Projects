#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t, n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> vn(n);
        for (int i = 0; i < n; ++i) {
            cin >> vn[i];
        }
        ll ans = 0;
        if (n == 2 && vn[0] == vn[1]) {
            cout << 0 << "\n";
        }
        else if (n == 2) {
            cout << -1 << "\n";
        }
        else if (n != 1) {
            bool flag = true;
            while (flag) {
                ll indexof = 0;
                for (int i = 1; i < n; ++i) {
                    if (vn[indexof] < vn[i]) {
                        indexof = i;
                    }   
                }
                vn[indexof]--;
                if (vn[indexof] < 0) {
                    cout << -1 << "\n";
                    break;
                }
                if (indexof == 0) {
                    vn[1]--;
                    if (vn[1] < 0) {
                        cout << -1 << "\n";
                        break;
                    }
                }
                else if (indexof == n - 1) {
                    vn[n - 2]--;
                    if (vn[n - 2] < 0) {
                        cout << -1 << "\n";
                        break;
                    }
                }
                else {
                    ll secondindex = 0;
                    if (vn[indexof - 1] >= vn[indexof + 1]) {
                        secondindex = indexof - 1;
                    }
                    else {
                        secondindex = indexof + 1;
                    }
                    vn[secondindex]--;
                    if (vn[secondindex] < 0) {
                        cout << -1 << "\n";
                        break;
                    }
                }
                ans += 2;
                for (ll i = 0; i < vn.size() - 1; ++i) {
                    if (vn[i] != vn[i + 1]) {
                        break;
                    }
                    if (vn[i] == vn[i + 1] && i == vn.size() - 2) {
                        cout << ans << "\n";
                        flag = false;
                    }
                }
            }
        }
        else {
            cout << 0 << "\n";
        }
    }
}