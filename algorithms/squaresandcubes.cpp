#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<int> v;
    unordered_map<int, int> m {};
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        int cnt = 1;
        long long int a = 2, b = 2;
        while (pow(a, 2) <= n || pow(b, 3) <= n) {
            if (pow(a, 2) <= n) {
                if (m.count(pow(a, 2)) == 0) {
                    m[pow(a, 2)] = 1;
                    ++cnt;
                }
                ++a;
            }
            if (pow(b, 3) <= n) {
                m[pow(b, 3)] = 1;
                ++cnt;
                ++b;
            }
        }
        v.push_back(cnt);
        m.clear();
    }
    for (auto val : v) {
        cout << val << "\n";
    }
}