#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, counter1 = 0;
    cin >> t;
    while (t--) {
        int n, m, rb, cb, rd, cd;
        int dr = 1, dc = 1;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        while (rb != rd && cb != cd) {
            if (rb == n) {
                dr *= -1;
            }
            rb += dr;
            if (cb == m) {
                dc *= -1;
            }
            cb += dc;
            ++counter1;
        }
        cout << counter1 << "\n";
        counter1 = 0;
    }
}