#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e2 + 1;

ll x, y, m, k, ans;

void bfs()
{
    vector<vector<ll>> depth(mx, vector<ll>(mx, -1));
    depth[0][0] = 0;
    queue<pair<ll, ll>> que;
    que.push({0, 0});
    while (que.size()) {
        ll b1 = que.front().first, b2 = que.front().second;
        que.pop();
        if (depth[b1][b2] + 1 <= k) {
            if (depth[0][b2] < 0) {
                ans = min(ans, abs(m - b2));
                depth[0][b2] = depth[b1][b2] + 1;
                que.push({0, b2});
            }
            if (depth[b1][0] < 0) {
                ans = min(ans, abs(m - b1));
                depth[b1][0] = depth[b1][b2] + 1;
                que.push({b1, 0});
            }
            if (depth[b1][y] < 0) {
                ans = min(ans, abs(m - (b1 + y)));
                depth[b1][y] = depth[b1][b2] + 1;
                que.push({b1, y});
            }
            if (depth[x][b2] < 0) {
                ans = min(ans, abs(m - (x + b2)));
                depth[x][b2] = depth[b1][b2] + 1;
                que.push({x, b2});
            }
            if (y - b2 > b1 && depth[0][b2 + b1] < 0) {
                ans = min(ans, abs(m - (b2 + b1)));
                depth[0][b2 + b1] = depth[b1][b2] + 1;
                que.push({0, b2 + b1});
            }
            if (y - b2 <= b1 && depth[b1 - (y - b2)][y] < 0) {
                ans = min(ans, abs(m - (y + b1 - (y - b2))));
                depth[b1 - (y - b2)][y] = depth[b1][b2] + 1;
                que.push({b1 - (y - b2), y});
            }
            if (x - b1 > b2 && depth[b1 + b2][0] < 0) {
                ans = min(ans, abs(m - (b1 + b2)));
                depth[b1 + b2][0] = depth[b1][b2] + 1;
                que.push({b1 + b2, 0});
            }
            if (x - b1 <= b2 && depth[x][b2 - (x - b1) < 0]) {
                ans = min(ans, abs(m - (x + b2 - (x - b1))));
                depth[x][b2 - (x - b1)] = depth[b1][b2] + 1;
                que.push({x, b2 - (x - b1)});
            }
        }
    }
}

int main()
{
    ifstream cin("pails.in");
    ofstream cout("pails.out");
    cin >> x >> y >> k >> m;
    ans = m;
    bfs();
    cout << ans;
}