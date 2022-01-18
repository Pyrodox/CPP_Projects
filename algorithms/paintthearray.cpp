#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> v, dvc;
    while (t--) {
        int n, d = 0, tmp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            v.push_back(tmp);
        }
        vector<int> v2;
        for (int i = 0; i < v.size(); i += 2) {
            v2.push_back(v[i]);
        }
        vector<int> v3 = v2;
        sort(v3.begin(), v3.end());
        int mx = v3[v3.size() - 1];
        for (int i = 2; i <= mx; ++i) {
            bool flag = true;
            for (int j = 0; j < v2.size(); ++j) {
                if (v2[j] % i != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int j = 1; j < v.size(); j += 2) {
                    if (v[j] % i == 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    dvc.push_back(i);
                    d = i;
                    break;
                }
            }
        }
        if (d == 0) {
            v2.clear();
            for (int i = 1; i < v.size(); i += 2) {
                v2.push_back(v[i]);
            }
            vector<int> v3 = v2;
            sort(v3.begin(), v3.end());
            mx = v3[v3.size() - 1];
            for (int i = 2; i <= mx; ++i) {
                bool flag1 = true;
                for (int j = 0; j < v2.size(); ++j) {
                    if (v2[j] % i != 0) {
                        flag1 = false;
                        break;
                    }
                }
                if (flag1) {
                    for (int j = 0; j < v.size(); j += 2) {
                        if (v[j] % i == 0) {
                            flag1 = false;
                        }
                    }
                    if (flag1) {
                        dvc.push_back(i);
                        d = i;
                        break;
                    }
                }
            }
            if (d == 0) {
                dvc.push_back(0);
            }
        }
        v.clear();
    }
    for (auto val : dvc) {
        cout << val << "\n";
    }
}