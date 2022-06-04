#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 21;

ll n;
char ch1, ch2;
vector<vector<char>> grid(mx, vector<char>(mx));
vector<vector<bool>> vis;

pair<char, char> hastwocolors(ll r1, ll c1, ll r2, ll c2)
{
    unordered_map<char, ll> mp;
    ll cnt = 0;
    char char1, char2;
    for (ll i = r1; i <= r2 && cnt <= 2; ++i) {
        for (ll j = c1; j <= c2 && cnt <= 2; ++j) {
            if (cnt == 0) {
                char1 = grid[i][j];
            }
            else if (cnt == 1) {
                char2 = grid[i][j];
            }
            if (mp[grid[i][j]] == 0) {
                ++cnt;
            }
            mp[grid[i][j]]++;
        }
    }
    if (cnt == 2) {
        return {char1, char2};
    }

    return {'0', '0'};
}

void floodfill(ll r, ll c, char ch, ll b1, ll b2, ll b3, ll b4)
{
    if (r < b1 || r > b3 || c < b2 || c > b4 || vis[r][c] || grid[r][c] != ch) {
        return;
    }
    vis[r][c] = true;
    floodfill(r - 1, c, ch, b1, b2, b3, b4);
    floodfill(r + 1, c, ch, b1, b2, b3, b4);
    floodfill(r, c - 1, ch, b1, b2, b3, b4);
    floodfill(r, c + 1, ch, b1, b2, b3, b4);
}

bool ispcl(ll b1, ll b2, ll b3, ll b4)
{
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = b1; i <= b3; ++i) {
        for (ll j = b2; j <= b4; ++j) {
            if (!vis[i][j]) {
                if (grid[i][j] == ch1) {
                    ++cnt1;
                }
                else if (grid[i][j] == ch2) {
                    ++cnt2;
                }
                floodfill(i, j, grid[i][j], b1, b2, b3, b4);
            }
        }
    }

    return (cnt1 == 1 && cnt2 >= 2) || (cnt1 >= 2 && cnt2 == 1);
}

int main()
{
    ifstream fin("where.in");
    ofstream fout("where.out");
    fin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            char c;
            fin >> c;
            grid[i][j] = c;
        }
    }
    vector<vector<ll>> pclvec;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            for (ll k = i; k <= n; ++k) {
                for (ll l = j; l <= n; ++l) {
                    if (k - i + l - j + 2 >= 3) {
                        auto ap = hastwocolors(i, j, k, l);
                        if (ap.first != '0') {
                            ch1 = ap.first; ch2 = ap.second;
                            vis = vector<vector<bool>>(mx, vector<bool>(mx));
                            if (ispcl(i, j, k, l)) {
                                pclvec.push_back({i, j, k, l});
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = pclvec.size();
    map<ll, bool> skipmp;
    for (ll i = 0; i < pclvec.size(); ++i) {
        if (skipmp[i]) {
            continue;
        }
        for (ll j = 0; j < pclvec.size(); ++j) {
            if (skipmp[j]) {
                continue;
            }
            if (i != j && pclvec[i][0] >= pclvec[j][0] && pclvec[i][2] <= pclvec[j][2] && pclvec[i][1] >= pclvec[j][1] && pclvec[i][3] <= pclvec[j][3]) {
                --ans;
                skipmp[i] = true;
                break;
            }
        }
    }
    fout << ans;
}