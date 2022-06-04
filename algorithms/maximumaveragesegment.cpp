#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main()
{
    ld n, d, tot = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    vector<ld> v(n);
    for (ld i = 0; i < n; ++i) {
        cin >> v[i];
        tot += v[i];
    }
    ld l = 0, r = 999999999999999999, ans1, ans2;
    while (r - l > 0.000000001) {
        ld mid = l + (r - l) / 2;
        //cout << "testing mid: " << mid << "\n";
        vector<ld> prefix(n + 1);
        for (ld i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + v[i] - mid;
        }
        /*cout << "prefix: ";
        for (auto val : prefix) {
            cout << val << " ";
        }
        cout << "\n";*/
        vector<ld> minprefix;
        minprefix.push_back(0);
        minprefix.push_back(prefix[1]);
        for (ld i = 2; i <= n; ++i) {
            minprefix.push_back(min(prefix[i], minprefix[i - 1]));
        }
        /*for (auto val : minprefix) {
            cout << val << " ";
        }
        cout << "\n";*/
        bool check = false;
        for (ld r2 = d + 1; r2 <= n; ++r2) {
            if (minprefix[r2 - d] <= prefix[r2]) {
                ans1 = r2 - d, ans2 = r2;
                check = true;
                break;
            }
        }
        if (check) {
            //cout << "changing l: " << l << " to " << mid << "\n";
            l = mid;
        }
        else {
            //cout << "changing r: " << r << " to " << mid << "\n";
            r = mid;
        }
    }
    ld avg = 0, mxind = 1, maxavg = 0;
    for (ld i = 0; i < ans1; ++i) {
        avg += v[i];
        if (avg / (i + 1) > maxavg) {
            mxind = i + 1;
            maxavg = avg / (i + 1);
        }
    }
    cout << mxind << " " << ans2;
}