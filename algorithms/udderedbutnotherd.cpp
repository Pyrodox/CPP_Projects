#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string s2;
    cin >> s2;
    int aindex = 0, count2 = 0;
    for (int i = 0; i < s2.size(); i += 0) {
        for (int j = 0; j < 26; ++j) {
            int tmp = 0;
            if (s2[i] == s[j]) {
                //cout << i << " " << j << "\n";
                ++i;
            }
            if (j == 25) {
                ++aindex;
            }
        }
    }
    cout << aindex;
}