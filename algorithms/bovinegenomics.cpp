#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    string tmp;
    fin >> n >> m;
    vector<string> spotty, plain;
    for (int i = 0; i < n; ++i) {
        fin >> tmp;
        spotty.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        fin >> tmp;
        plain.push_back(tmp);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                if (spotty[k][i] == plain[j][i]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            ++cnt;
        }
    }
    fout << cnt;
}