#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    unordered_map<string, ll> t;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        t[tmp]++;
    }
    for (auto val : s) {
        if (t[val] == 0) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
}