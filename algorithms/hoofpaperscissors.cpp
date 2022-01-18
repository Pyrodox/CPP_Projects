#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void wins(int h, int p, int s, int& ans, vector<vector<int>>& v)
{
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i][0] == h && v[i][1] == s) {
            ++cnt;
        }
        else if (v[i][0] == p && v[i][1] == h) {
            ++cnt;
        }
        else if (v[i][0] == s && v[i][1] == p) {
            ++cnt;
        }
    }
    ans = max(ans, cnt);
}


int main()
{
    int n, tmp;
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    fin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        fin >> tmp;
        v[i].push_back(tmp);
        fin >> tmp;
        v[i].push_back(tmp);
    }
    int ans = 0;
    wins(1, 2, 3, ans, v);
    wins(1, 3, 2, ans, v);
    wins(2, 1, 3, ans, v);
    wins(2, 3, 1, ans, v);
    wins(3, 1, 2, ans, v);
    wins(3, 2, 1, ans, v);
    fout << ans;
}