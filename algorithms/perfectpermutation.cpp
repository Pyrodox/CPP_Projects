#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
        }
        else if (n % 2 == 0) {   
            for (ll i = 1; i <= n; ++i) {
                if (i % 2 == 1) {
                    cout << i + 1 << " ";
                }
                else {
                    cout << i - 1 << " ";
                }
            }
            cout << "\n";
        }
        else {
            for (ll i = 1; i < n; ++i) {
                if (i % 2 == 1) {
                    if (i == 1) {
                        cout << n << " ";
                    }
                    else 
                        cout << i + 1 << " ";
                }
                else {
                    if (i == 2) {
                        cout << 1 << " ";
                    }
                    else 
                        cout << i - 1 << " ";
                }
            }
            cout << 2 << "\n";
        }
    }
}