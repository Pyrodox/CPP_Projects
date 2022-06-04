#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main()
{
    ld n;
    cin >> n;
    vector<vector<ld>> v(n);
    for (ld i = 0; i < n; ++i) {
        ld a;
        cin >> a;
        v[i].push_back(a);
    }
    for (ld i = 0; i < n; ++i) {
        ld a;
        cin >> a;
        v[i].push_back(a);
    }
    sort(v.begin(), v.end());
    ld l = 0.0000000000000001, r = 9999999999999999;
    while (r - l > 0.0000001) {
        ld mid = l + (r - l) / 2;
        ld avg = ((double) v[0][0] + v[n - 1][0]) / 2, mn1 = 999999999999999, mx1 = 0;
        //cout << "testing mid: " << mid << " " << l << " " << r << " " << avg << "\n";
        for (ld i = 0; i < n; ++i) {
            if (v[i][0] < avg) {
                mn1 = min(mn1, v[i][0] + v[i][1] * mid);
                //cout << "less: " << v[i][0] + v[i][1] * mid << "\n"; 
            }
            else if (v[i][0] > avg) {
                mx1 = max(mx1, v[i][0] - v[i][1] * mid);
                //cout << "right: " << v[i][0] - v[i][1] * mid << "\n"; 
            }
        }
        if (mn1 >= mx1) {
            //cout << r << " r change\n";
            r = mid;
        }
        else {
            //cout << l << " l change\n";
            l = mid;
        }
    }
    cout << fixed << setprecision(12) << l;
}