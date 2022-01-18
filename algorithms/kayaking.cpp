#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 2000000, cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            vector<int> a = v;
            a[i] = 10000;
            a[j] = 10000;
            sort(a.begin(), a.end());
            a.pop_back();
            a.pop_back();
            for (int k = a.size() - 1; k > 0; k -= 2) {
                cnt += abs(a[k] - a[k - 1]);
            }
            if (cnt < ans) {
                ans = cnt;
            }
            cnt = 0;
        }
    }
    cout << ans;
}