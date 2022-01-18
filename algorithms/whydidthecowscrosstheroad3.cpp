#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    fin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        fin >> v[i].first;
        fin >> v[i].second;
    }
    vector<bool> v2(n);
    int nxtavailabletime = 0;
    for (int i = 0; i < n; ++i) {
        int nxtenter = -1;
        for (int j = 0; j < n; ++j) {
            if (!v2[j] && (nxtenter == -1 || v[j].first < v[nxtenter].first)) {
                nxtenter = j;
            }
        }
        v2[nxtenter] = true;
        if (v[nxtenter].first > nxtavailabletime) {
            nxtavailabletime = v[nxtenter].first + v[nxtenter].second;
        }
        else {
            nxtavailabletime += v[nxtenter].second;
        }
    }
    fout << nxtavailabletime;
}