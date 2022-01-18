#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, start, end;
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    fin >> n;
    vector<vector<int>> v(n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        fin >> start >> end;
        for (int j = start + 1; j <= end; ++j) {
            v[i].push_back(j);
            m[j]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> m2 = m;
        int cnt = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            m2[v[i][j]]--;
        }
        for (int j = 1; j <= 1000; ++j) {
            if (m2[j] > 0) {
                ++cnt;
            }
        }
        if (cnt > ans) {
            ans = cnt;
        }
    }
    fout << ans;
}