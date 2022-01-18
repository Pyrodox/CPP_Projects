#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    fin >> n;
    map<string, int> m;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        fin >> s1 >> s2;
        if (s1.substr(0, 2) != s2) {
            m[s1.substr(0, 2) + s2]++;
        }
    }
    int cnt = 0;
    for (auto v : m) {
        if (m.count(v.first.substr(2, 2) + v.first.substr(0, 2)) > 0) {
            cnt += m[v.first.substr(2, 2) + v.first.substr(0, 2)] * m[v.first];
        }
    }
    
    fout << cnt / 2;
}