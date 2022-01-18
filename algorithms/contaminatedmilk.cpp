#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, d, s;
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
    fin >> n >> m >> d >> s;
    vector<vector<int>> v(d);
    for (int i = 0; i < d; ++i) {
        vector<int> v2(3);
        fin >> v2[0] >> v2[1] >> v2[2];
        v[i].push_back(v2[0]);
        v[i].push_back(v2[1]);
        v[i].push_back(v2[2]);
    }
    int tmp, tmp2;
    vector<vector<int>> contam(s);
    for (int i = 0; i < s; ++i) {
        fin >> tmp >> tmp2;
        contam[i].push_back(tmp);
        contam[i].push_back(tmp2);
    }
    vector<set<int>> v3(n);
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < d; ++j) {
            if (contam[i][0] == v[j][0] && contam[i][1] > v[j][2]) { //first checks for same person and then checks if contamination time after time milk drank
                v3[v[j][0] - 1].insert(v[j][1]); //pushes back the milk for the specific person
            }
        }
    }
    vector<int> milks;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < v3.size(); ++j) {
            if (v3[j].size() != 0) {
                if (find(v3[j].begin(), v3[j].end(), i) == v3[j].end()) {
                    break;
                }
            }
            if (j == v3.size() - 1) {
                milks.push_back(i);
            }
        }
    }
    int maxval = 0;
    for (int i = 0; i < milks.size(); ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < v.size(); ++k) {
                if (v[k][0] == j && v[k][1] == milks[i]) {
                    ++cnt;
                    break;
                }
            }
        }
        maxval = max(maxval, cnt);
    }
    fout << maxval;
}