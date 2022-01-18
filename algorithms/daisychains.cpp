#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> v;
    int cnt = n, n2 = n;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n2; ++i) {
        int total = v[i];
        vector<int> v2;
        v2.push_back(v[i]);
        for (int j = i + 1; j < n2; ++j) {
            total += v[j];
            v2.push_back(v[j]);
            for (int k = 0; k < v2.size(); ++k) {
                if (v2[k] == ((double) total / v2.size())) {
                    ++cnt;
                    break;
                }
            }
        }
    }

    cout << cnt;
} 