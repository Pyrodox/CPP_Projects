#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    vector<int> v1;
    while (t--) {
        cin >> n;
        vector<int> v2(n);
        for (int i = 0; i < n; ++i) {
            cin >> v2[i];
        }
        int total = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            int x = -1 * v2[i];
            int cnt = count(v2.begin(), v2.end(), x) + 1;
            if (x == 0 && flag) {
                total += min(cnt, 1);
                flag = false;
            }
            else if (x != 0) {
                total += min(cnt, 2);
            }
        }
        v1.push_back(total);
    }
    for (auto val : v1) {
        cout << val << "\n";
    }
}