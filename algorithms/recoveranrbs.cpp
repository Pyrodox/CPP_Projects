#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll op = s.size() / 2, cl = s.size() / 2;
        vector<ll> qmarks;
        for (ll i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                --op;
            }
            else if (s[i] == ')') {
                --cl;
            }
            else {
                qmarks.push_back(i);
            }
        }
        for (ll i = 0; i < qmarks.size(); ++i) {
            if (i < op) {
                s[qmarks[i]] = '(';
            }
            else {
                s[qmarks[i]] = ')';
            }
        }
        ll flag = 1;
        if (op > 0 && cl > 0) {
            swap(s[qmarks[op - 1]], s[qmarks[op]]);
            ll bal = 0;
            for (ll i = 0; i < s.size(); ++i) {
                if (s[i] == '(') {
                    ++bal;
                }
                else if (s[i] == ')') {
                    --bal;
                }
                if (bal < 0) {
                    flag = 1;
                    break;
                }
            }
            if (!bal) {
                flag = 0;
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}