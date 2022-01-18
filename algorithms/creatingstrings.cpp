#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
vector<string> permutations;
int charcnt[26];

void search(string cur)
{
    if (cur.size() == s.size()) {
        permutations.push_back(cur);
    }
    for (int i = 0; i < 26; ++i) {
        if (charcnt[i] > 0) {
            charcnt[i]--;
            search(cur + (char)('a' + i));
            charcnt[i]++;
        }
    }
}

int main()
{
    cin >> s;
    for (auto c : s) {
        charcnt[c - 'a']++;
    }
    search("");
    cout << permutations.size() << "\n";
    for (auto val : permutations) {
        cout << val << "\n";
    }
}