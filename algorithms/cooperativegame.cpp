#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (a != 2) {
        cout << "next " << 0 << " " << 1 << "\n";
        cout.flush();
        cin >> a;
        for (ll i = 0; i < a; ++i) {
            cin >> s;
        }
        cout << "next " << 0 << "\n";
        cout.flush();
        cin >> a;
        for (ll i = 0; i < a; ++i) {
            cin >> s;
        } 
    }
    while (a != 1) {
        cout << "next ";
        for (ll i = 0; i <= 9; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        cout.flush();
        cin >> a;
        for (ll i = 0; i < a; ++i) {
            cin >> s;
        }
    }
    cout << "done";
}