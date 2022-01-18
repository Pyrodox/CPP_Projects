#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        vector<int> v(3);
        for (int i = 0; i < 3; ++i) {
            cin >> v[i];
        }
        bool ok = false;
        for (int i = 0; i < 3; ++i) {
            ok |= v[i] == v[(i + 1) % 3] + v[(i + 2) % 3];
        }
        for (int i = 0; i < 3; ++i) {
            if (v[i] % 2 == 0) {
                ok |= v[(i + 1) % 3] == v[(i + 2) % 3];
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}