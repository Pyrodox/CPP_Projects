#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector mark(n + 1, vector<bool>(n + 1))
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            if (l == r) {
                cout << l << " " << r << " " << l;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int d = l[i]; d <= r[i]; ++d) {
                if ((d == l[i] || mark[l[i]][d - 1]) && (d == r[i] || mark[d + 1][r[i]])) {
                    cout << l << " " << r << " " << d << "\n";
                    break;
                }
            }
        }
    }
}