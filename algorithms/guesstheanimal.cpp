#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> characteristics(100);

int common(int i, int j)
{
    int cnt = 0;
    vector<string> v1 = characteristics[i], v2 = characteristics[j];
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            if (v1[i] == v2[j]) { 
                ++cnt;
            }
        }
    }
  
    return cnt;
}

int main()
{
    int n;
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    fin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        int k;
        fin >> s >> k;
        for (int j = 0; j < k; ++j) {
            fin >> s;
            characteristics[i].push_back(s);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, common(i, j));
        }
    }
    fout << ans + 1;
}