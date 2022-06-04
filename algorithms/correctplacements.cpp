#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp1(const vector<ll>& a, const vector<ll>& b)
{
    return a[0] < b[0];
}

bool cmp2(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] < b[1];
}

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<ll>> v, height(n, vector<ll>(3)), width(n, vector<ll>(3));
        for (ll i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            v.push_back({a, b});
            height[i] = {a, b, i};
            width[i] = {a, b, i};
        }
        sort(height.begin(), height.end(), cmp1);
        sort(width.begin(), width.end(), cmp2);
        vector<ll> ans(n);
        for (ll i = 0; i < n; ++i) {
            ll l = 0, r = n;
            bool flag = false;
            while (l < r) {
                ll mid = l + (r - l) / 2;
                if (height[mid][0] < v[i][0] && height[mid][1] < v[i][1]) {
                    ans[i] = height[mid][2];
                    flag = true;
                    break;
                }
                r = mid - 1;
            }
            if (!flag) {
                cout << -1 << " ";
            }
            else {
                cout << ans[i];
            }
        }
    }
}