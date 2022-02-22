#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    fin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
    }
    vector<int> idealv = v;
    sort(idealv.begin(), idealv.end());
    int cnt = 0;
    bool flag = true;
    while (flag) {
        for (int i = n - 1; i > 0 && flag; --i) {
            for (int j = 0; j < i && flag; ++j) {
                if (v[i] < v[j]) {
                    swap(v[i], v[j]);
                    ++cnt;
                    if (v == idealv) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    fout << cnt;
}