#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    fin >> s;
    vector<char> v {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        int ind, index2;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == v[i]) {
                ind = j;
                break;
            }
        }
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == v[i] && ind != j) {
                index2 = j;
                break;
            }
        }
        unordered_map<char, int> m;
        for (int j = ind + 1; j < index2; ++j) {
            m[s[j]]++;
        }
        for (int j = ind + 1; j < index2; ++j) {
            if (m[s[j]] == 1) {
                ++cnt;
            }
        }
    }
    fout << cnt / 2;
}