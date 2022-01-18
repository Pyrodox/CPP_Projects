#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    fin >> n;
    string s;
    fin >> s;
    vector<string> v;
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - i + 1; ++j) {
            v.push_back(s.substr(j, i));
        }
        unordered_set<string> s2 {v.begin(), v.end()};
        if (s2.size() == v.size()) {
            k = i;
            break;
        }
        v.clear();
    }
    fout << k;
}