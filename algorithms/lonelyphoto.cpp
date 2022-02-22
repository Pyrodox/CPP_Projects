#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size() - 2; ++i) {
        string tmp = s.substr(i, 3);
        if (count(tmp.begin(), tmp.end(), 'H') == 1) {
            //cout << tmp << "\n";
            ++ans;
            for (int j = i + 3; j < s.size(); ++j) {
                if (s[j] != 'H') {
                    ++ans;
                }
                else {
                    break;
                }
            }
        }
        else if (count(tmp.begin(), tmp.end(), 'G') == 1) {
            //cout << tmp << "\n";
            ++ans;
            for (int j = i + 3; j < s.size(); ++j) {
                if (s[j] != 'G') {
                    ++ans;
                }
                else {
                    break;
                }
            }
        }
        else if (tmp == "HHH") {
            for (int j = i + 3; j < s.size(); ++j) {
                if (s[j] == 'G') {
                    ++ans;
                    ll k = j + 1;
                    while (k < s.size() && s[k] != 'G') {
                        ++ans;
                        ++k;
                    }
                    break;
                }
            }
        }
        else if (tmp == "GGG") {
            bool flag = true;
            for (int j = i + 3; j < s.size(); ++j) {
                if (s[j] == 'H') {
                    ++ans;
                    ll k = j + 1;
                    while (k < s.size() && s[k] != 'H') {
                        ++ans;
                        ++k;
                    }
                    break;
                }
            }
        }
    }
    cout << ans;
}