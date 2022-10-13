#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t >> q;
    vector<ll> charamnt1(18), charamnt2(18);
    for (char c : s) {
        charamnt1[c - 'a']++;
    }
    for (char c : t) {
        charamnt2[c - 'a']++;
    }
    vector<vector<ll>> check(18, vector<ll>(18));
    for (ll i = 0; i < 18; ++i) {
        if (charamnt1[i] == charamnt2[i]) {
            check[i][i] = 1;
        }
    }
    for (ll i = 0; i < 17; ++i) {
        for (ll j = i + 1; j < 18; ++j) {
            string tmps = "", tmpt = "";
            for (char c : s) {
                if (c == i + 'a' || c == j + 'a') {
                    tmps += c;
                }
            }
            for (char c : t) {
                if (c == i + 'a' || c == j + 'a') {
                    tmpt += c;
                }
            }
            if (tmps == tmpt) {
                check[i][j] = 1;
                check[j][i] = 1;
            }
        }
    }
    while (q--) {
        string qstr;
        cin >> qstr;
        vector<ll> found;
        bool flag = false;
        for (ll i = 0; i < qstr.size() && !flag; ++i) {
            found.push_back(qstr[i] - 'a');
            for (ll a : found) {
                if (!check[a][qstr[i] - 'a']) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            cout << "N";
        }
        else {
            cout << "Y";
        }
    }
}