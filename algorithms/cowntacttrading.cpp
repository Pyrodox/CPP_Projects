#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<bool> cowendsinfected(101);
vector<int> cowx(251), cowy(251);

bool consistent(int i, int k)
{
    vector<bool> infected(101);
    vector<int> handshakenum(101);
    infected[i] = true;
    for (int t = 0; t <= 250; ++t) {
        int x = cowx[t];
        int y = cowy[t];
        if (x > 0) {
            if (infected[x]) {
                ++handshakenum[x];
            }
            if (infected[y]) {
                ++handshakenum[y];
            }
            if (handshakenum[x] <= k && infected[x]) {
                infected[y] = true;
            }
            if (handshakenum[y] <= k && infected[y]) {
                infected[x] = true;
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        if (infected[j] != cowendsinfected[j]) {
            return false;
        }
    }

    return true;
}

int main()
{
    int t, tmp1, tmp2, tmp3;
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    string cases;
    fin >> n >> t >> cases;
    vector<vector<int>> v(t);
    for (int i = 0; i < t; ++i) {
        fin >> tmp1 >> tmp2 >> tmp3;
        cowx[tmp1] = tmp2;
        cowy[tmp1] = tmp3;
    }
    for (int i = 1; i <= n; ++i) {
        cowendsinfected[i] = cases[i - 1] == '1';
    }
    vector<bool> possiblei(101), possiblek(252);
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= 251; ++k) {
            if (consistent(i, k)) {
                possiblei[i] = true;
                possiblek[k] = true;
            }
        }
    }
    int lowerk = 251, upperk = 0, p = 0;
    for (int k = 0; k <= 251; ++k) {
        if (possiblek[k]) {
            upperk = k;
        }
    }
    for (int k = 251; k >= 0; --k) {
        if (possiblek[k]) {
            lowerk = k;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (possiblei[i]) {
            ++p;
        }
    }
    fout << p << " " << lowerk << " ";
    if (upperk == 251) {
        fout << "Infinity";
    }
    else {
        fout << upperk;
    }
}