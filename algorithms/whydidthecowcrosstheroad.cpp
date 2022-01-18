#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, tmp, temp2;
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    fin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        fin >> tmp >> temp2;
        v[tmp - 1].push_back(temp2);
    }
    int cnt = 0;
    /*for (auto val : v) {
        for (auto vl : val) {
            cout << vl << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i < n; ++i) {
        if (v[i].size() != 0) {
            for (int j = 0; j < v[i].size() - 1; ++j) {
                if (v[i][j] != v[i][j + 1]) {
                    //cout << j + 1 << " " << v[i][j] << "\n";
                    ++cnt;
                }
            }
        }
    }
    fout << cnt;
}