#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
bool pieces[11][8][8];
vector<int> s[11];

bool check(int piece, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && pieces[piece][x][y];
}

int main()
{
    int k;
    ifstream fin("bcs.in");
    ofstream fout("bcs.out");
    fin >> n >> k;
    char c;
    int left, right, top, bottom;
    for (int i = 0; i <= k; ++i) {
        left = n - 1;
        right = 0;
        top = n - 1;
        bottom = 0;
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                fin >> c;
                pieces[i][j][l] = (c == '#');
                if (pieces[i][j][l]) {
                    bottom = max(bottom, j);
                    top = min(top, j);
                    right = max(right, l);
                    left = min(left, l);
                }
            }
        }
        s[i] = {left, right, top, bottom};
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            for (int idx = s[i][3] - n + 1; idx <= s[i][0]; ++idx) {
                for (int idy = s[i][1] - n + 1; idy <= s[i][0]; ++idy) {
                    for (int jdx = s[j][3] - n + 1; jdx <= s[j][2]; ++jdx) {
                        for (int jdy = s[j][1] - n + 1; jdy <= s[j][0]; ++jdy) {
                            bool good = true;
                            for (int x = 0; x < n; ++x) {
                                for (int y = 0; y < n; ++y) {
                                    bool ipiece = check(i, x + idx, y + idy);
                                    bool jpiece = check(j, x + jdx, y + jdy);
                                    if (ipiece && jpiece) {
                                        good = false;
                                        break;
                                    }
                                    if (pieces[0][x][y] != (ipiece || jpiece)) {
                                        good = false; break;
                                    }
                                }
                                if (!good) {
                                    break;
                                }
                            }
                            if (good) {
                                fout << i << " " << j << "\n";
                                
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}