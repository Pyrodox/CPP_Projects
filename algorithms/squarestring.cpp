#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    vector<string> v;
    while (t--) {
        cin >> s;
        if (s.size() % 2 == 1) {
            v.push_back("NO\n");
        }
        else {
            int hlf = s.size() / 2;
            if (s.substr(0, hlf) == s.substr(hlf, hlf)) {
                v.push_back("YES\n");
            }
            else {
                v.push_back("NO\n");
            }
        }
    }
    for (auto val : v) {
        cout << val;
    }
}