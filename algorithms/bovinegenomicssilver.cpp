#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<string> spotty(500), plain(500);
int S[500][50], P[500][50], A[64];

bool testloc(int j1, int j2, int j3)
{
    bool gd = true;
    for (int i = 0; i < n; ++i) {
        A[S[i][j1] * 16 + S[i][j2] * 4 + S[i][j3]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (A[P[i][j1] * 16 + P[i][j2] * 4 + P[i][j3]]) {
            gd = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        A[S[i][j1] * 16 + S[i][j2] * 4 + S[i][j3]] = 0;
    }

    return gd;
}

int main()
{
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    fin >> n >> m;
    for (int i = 0; i < n; ++i) {
        fin >> spotty[i];
        for (int j = 0; j < m; ++j) {
            if (spotty[i][j] == 'A') {
                S[i][j] = 0;
            }
            else if (spotty[i][j] == 'C') {
                S[i][j] = 1;
            }
            else {
                S[i][j] = spotty[i][j] == 'G' ? 2 : 3;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        fin >> plain[i];
        for (int j = 0; j < m; ++j) {
            if (plain[i][j] == 'A') {
                P[i][j] = 0;
            }
            else if (plain[i][j] == 'C') {
                P[i][j] = 1;
            }
            else {
                P[i][j] = plain[i][j] == 'G' ? 2 : 3;
            }
        }
    }
    int ans = 0;
    for (int j1 = 0; j1 < m; ++j1) {
        for (int j2 = j1 + 1; j2 < m; ++j2) {
            for (int j3 = j2 + 1; j3 < m; ++j3) {
                if (testloc(j1, j2, j3)) {
                    ++ans;
                }
            }
        }
    }
    fout << ans;
}