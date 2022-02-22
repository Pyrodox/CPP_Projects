#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    vector<vector<ll>> possfaces;
    for (int i = 1; i <= 10; ++i) {
        vector<ll> tmp;
        for (int j = i; j <= 10; ++j) {
            for (int k = j; k <= 10; ++k) {
                for (int l = k; l <= 10; ++l) {
                    tmp = {i, j, k, l};
                    possfaces.push_back(tmp);
                    tmp.clear();
                }
            }
        }
    }
    while (t--) {
        vector<ll> a(4), b(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3];
        bool flag = true;
        vector<ll> idealv = {1, 1, 1};
        for (int i = 0; i < possfaces.size() && flag; ++i) {
            do {
                ll cnta = 0, cntb = 0, cntc = 0;
                vector<ll> check(3);
                bool agreaterb = true;
                for (int l = 0; l < 4; ++l) {
                    for (int j = 0; j < 4; ++j) {
                        if (a[l] > b[j]) {
                            ++cnta;
                        }
                        else if (b[j] > a[l]) {
                            ++cntb;
                        }
                    }
                }
                if (cnta > cntb) {
                    check[0] = 1;
                    //cout << "HERE1";
                }
                else {
                    agreaterb = false;
                    check[0] = 1;
                }
                cnta = 0;
                for (int l = 0; l < 4; ++l) {
                    for (int j = 0; j < 4; ++j) {
                        if (a[l] > possfaces[i][j]) {
                            ++cnta;
                        }
                        else if (possfaces[i][j] > a[l]) {
                            ++cntc;
                        }
                    }
                }
                if (cnta < cntc && agreaterb) {
                    //cout << "HERE2";
                    check[2] = 1;
                }
                else if (cnta > cntc && !agreaterb) {
                    check[2] = 1;
                }
                cntb = 0;
                cntc = 0;
                for (int l = 0; l < 4; ++l) {
                    for (int j = 0; j < 4; ++j) {
                        if (b[l] > possfaces[i][j]) {
                            ++cntb;
                        }
                        else if (possfaces[i][j] > b[l]) {
                            ++cntc;
                        }
                    }
                }
                if (cntb < cntc && !agreaterb) {
                    check[1] = 1;
                }
                else if (cntb > cntc && agreaterb) {
                    //cout << "HERE1";
                    check[1] = 1;
                }
                if (check == idealv) {
                    cout << "yes\n";
                    flag = false;
                    break;
                }
            } while (next_permutation(possfaces[i].begin(), possfaces[i].end()));
            if (i == possfaces.size() - 1 && flag) {
                cout << "no\n";
                break;
            }
        }
    }
}