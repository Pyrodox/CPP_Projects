#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, tmp;
    vector<int> v;
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    fin >> n >> k;
    for (int i = 0; i < n; ++i) {
        fin >> tmp;
        v.push_back(tmp);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        vector<int> v1;
        v1.push_back(v[0]);
        for (int j = 1; j < n; ++j) {
            if (abs(v[0] - v[j]) <= k) {
                for (int k1 = 0; k1 < v1.size(); ++k1) {
                    if (abs(v[j] - v1[k1]) > k) {
                        break;
                    }
                    else if (k1 == v1.size() - 1) {
                        ++cnt;
                        v1.push_back(v[j]);
                        break;
                    }         
                }
            }
        }
        if (cnt > ans) {
            ans = cnt;
        }
        int tmp2 = v[0]; 
        reverse(v.begin(), v.end());
        v.pop_back();
        reverse(v.begin(), v.end());
        v.push_back(tmp2);
    }

    fout << ans;
}