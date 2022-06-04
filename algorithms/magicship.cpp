#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x1, y1, x2, y2, n;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
    vector<vector<ll>> v(n + 1);
    v[0] = {0, 0};
    for (ll i = 1; i <= s.size(); ++i) {
        if (s[i - 1] == 'U') {
            v[i].push_back(v[i - 1][0]);
            v[i].push_back(v[i - 1][1] + 1);
        }
        else if (s[i - 1] == 'D') {
            v[i].push_back(v[i - 1][0]);
            v[i].push_back(v[i - 1][1] - 1);
        }
        else if (s[i - 1] == 'R') {
            v[i].push_back(v[i - 1][0] + 1);
            v[i].push_back(v[i - 1][1]);
        }
        else {
            v[i].push_back(v[i - 1][0] - 1);
            v[i].push_back(v[i - 1][1]);
        }
    }
    ll l = 1, r = 999999999999999, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2, a = 0, tmpx1 = x1, tmpy1 = y1;
        if (mid <= n) {
            tmpx1 += v[mid][0];
            tmpy1 += v[mid][1];
        }
        else {
            tmpx1 += v[v.size() - 1][0] * (mid / n) + v[mid % n][0];
            tmpy1 += v[v.size() - 1][1] * (mid / n) + v[mid % n][1];
        }
        ll dif = abs(y2 - tmpy1) + abs(x2 - tmpx1);
        if (dif <= mid) {
            ans = mid;
            if (r == mid) {
                break;
            }
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (ans == -1) {
        cout << -1;
    }
    else {
        cout << l;
    }
}