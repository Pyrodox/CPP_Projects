#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    fin >> n;
    vector<vector<char>> v(n);
    for (int i = 0; i < n; ++i) {
        string tmp;
        fin >> tmp;
        for (int j = 0; j < n; ++j) {
            v[i].push_back(tmp[j]);
        }
    }
    vector<vector<char>> idealv;
    for (int i = 0; i < n; ++i) {
        vector<char> tmp2;
        for (int j = 0; j < n; ++j) {
            tmp2.push_back('0');
        }
        idealv.push_back(tmp2);
    }
    int ans = 0;
    while (v != idealv) {
        bool flag = true;
        int x = 0, y = 0;
        for (int i = n - 1; i >= 0 && flag; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (v[i][j] == '1') {
                    x = i;
                    y = j;
                    flag = false;
                    break;
                }
            }
        }
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                if (v[i][j] == '0') {
                    v[i][j] = '1';
                }
                else {
                    v[i][j] = '0';
                }
            }
        }
        ++ans;        
    }
    fout << ans;
}