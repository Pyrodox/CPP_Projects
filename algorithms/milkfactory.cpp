#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v[101];

void dfs(vector<vector<ll>>& v2, ll val, ll initialval)
{
    for (int i = 0; i < v[val].size(); ++i) {
        v2[initialval].push_back(v[val][i]);
        if (v[v[val][i]].size() != 0) {
            dfs(v2, v[val][i], initialval);
        }
    }

    return;
}

int main()
{
    ll n;
    ifstream fin("factory.in");
    ofstream fout("factory.out");
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        ll tmp, tmp2;
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
    }
    vector<vector<ll>> v2(n + 1);
    for (int i = 1; i <= n; ++i) {
        dfs(v2, i, i);
    }
    ll maxind = 1;
    for (int i = 2; i <= n; ++i) {
        if (v2[maxind].size() < v2[i].size()) {
            maxind = i;
        }
    }
    for (int i = 0; i < v2[maxind].size(); ++i) {
        bool a = true;
        for (int j = 1; j <= n; ++j) {
            if (v2[j].size() != 0 && find(v2[j].begin(), v2[j].end(), v2[maxind][i]) == v2[j].end()) {
                a = false;
                break;
            }
        }
        if (a) {
            cout << v2[maxind][i];

            return 0;
        }
    }
    cout << -1;
}