#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
pair<ll, char> v[50 * 50 + 1][2]; //0 is right, 1 is down
bool visited[50 * 50 + 1];
vector<string> sv;

void dfs(pair<ll, char> node, string s)
{
    visited[0] = true;
    visited[node.first] = true;
    for (int i = 0; i < 2; ++i) {
        if (node.first == n * n) {
            sv.push_back(s);
        }
        if (!visited[v[node.first][i].first]) {
            if (v[node.first][i].second == 'H') {
                s = "";
            }
            else if (i == 0 && v[node.first][0].first != 0) {
                s += "R";
                //cout << "R " << node.first << " " << v[node.first][i].first << "\n";
                dfs(v[node.first][i], s);
            }
            else if (v[node.first][1].first != 0) {
                s += "D";
                //cout << "D " << node.first << " " << v[node.first][i].first << "\n";
                dfs(v[node.first][i], s);
            }
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    vector<ll> output(t);
    pair<ll, char> v2[50 * 50 + 1][2]; //0 is right, 1 is down
    bool visited2[50 * 50 + 1];
    while (t--) {
        cin >> n >> k;
        vector<char> a[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char tmp;
                cin >> tmp;
                a[i].push_back(tmp);
            }
        }
        if (k == 1) {
            int cnt = 2;
            for (int i = 0; i < n; ++i) {
                if (a[i][0] == 'H') {
                    --cnt;
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (a[0][i] == 'H') {
                    --cnt;
                    break;
                }
            }
            output.push_back(cnt);
        }
        else if (k == 2) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j + 2 <= n) { 
                        v[i * n + j + 1][0] = {i * n + j + 2, a[i][j + 1]};
                    }
                    if (i + 2 <= n) {
                        v[i * n + j + 1][1] = {i * n + j + 4, a[i + 1][j]};
                    }
                }
            }
            int cnt = 1;
            for (int i = 1; i < 10; ++i) {
                cout << cnt << " ";
                for (int j = 0; j < 2; ++j) {
                    cout << v[i][j].first << " " << v[i][j].second << "\n";
                    if (v[i][j].first == 0) {
                        cout << "cant move there\n";
                    }
                }
                ++cnt;
            }
            dfs({1, '.'}, "");
        }
        for (auto val : sv) {
            cout << val << "\n";
        }
        sv.clear();
    }
}