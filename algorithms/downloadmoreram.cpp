#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n, k;
    vector<int> output;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> v;
        vector<int> tmp(n), tmp2(n);
        for (int i = 0; i < n; ++i) {
            cin >> tmp[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> tmp2[i];
        }
        for (int i = 0; i < n; ++i) {
            v.push_back({tmp[i], tmp2[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (v[i][0] <= k) {
                k += v[i][1];
            }
            else {
                break;
            }
        }
        output.push_back(k);
    }
    for (auto val : output) {
        cout << val << "\n";
    }
}