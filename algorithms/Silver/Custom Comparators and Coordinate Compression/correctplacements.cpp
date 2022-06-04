#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] > b[0];
}
 
bool cmp2(const vector<ll>& a, const vector<ll>& b)
{
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
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
        vector<vector<ll>> originalv(n), height(n), width(n);
        for (ll i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            originalv[i] = {a, b};
            height[i] = {a, b, i};
            width[i] = {a, b, i};
        }
        sort(height.begin(), height.end(), cmp);
        sort(width.begin(), width.end(), cmp2);
        vector<ll> ans(n), avail(n);
        vector<vector<ll>> leastwidth(n, vector<ll>(2)), leastheight(n, vector<ll>(2));
        leastwidth[n - 1][0] = height[n - 1][1];
        leastwidth[n - 1][1] = height[n - 1][2];
        for (ll i = n - 2; i >= 0; --i) {
            if (height[i][1] < leastwidth[i + 1][0]) {
                leastwidth[i][1] = height[i][2];
            }
            else {
                leastwidth[i][1] = leastwidth[i + 1][1];
            }
            leastwidth[i][0] = min(height[i][1], leastwidth[i + 1][0]);
        }
        leastheight[0][0] = width[0][0];
        leastheight[0][1] = width[0][2];
        for (ll i = 1; i < n; ++i) {
            if (width[i][0] < leastheight[i - 1][0]) {
                leastheight[i][1] = width[i][2];
            }
            else {
                leastheight[i][1] = leastheight[i - 1][1];
            }
            leastheight[i][0] = min(width[i][0], leastheight[i - 1][0]);
        }
        for (ll i = 0; i < n && n != 1; ++i) {
            ll l = -1, r = n, mid;
            while (r > l + 1) {
                mid = (l + r) / 2;
                if (width[mid][1] < height[i][0]) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            if (l + 1 != 0 && width[l][1] < height[i][0] && (l + 1 == n || width[l + 1][1] >= height[i][0])) {
                if (leastheight[l][0] < height[i][1]) {
                    ans[height[i][2]] = leastheight[l][1];
                    avail[height[i][2]] = true;
                }
            }
        }
        map<ll, ll> mp;
        ll cur = height[0][0];
        for (ll i = 0; i < n; ++i) {
            if (height[i][0] != cur) {
                mp[height[i][0]] += mp[cur];
                cur = height[i][0];
            }
            mp[cur]++;
        }
        for (ll i = 0; i < n; ++i) {
            if (leastwidth[min(n - 1, mp[height[i][0]])][0] < height[i][1] && height[i][0] != originalv[leastwidth[min(n - 1, mp[height[i][0]])][1]][0]) {
                ans[height[i][2]] = leastwidth[min(n - 1, mp[height[i][0]])][1];
                avail[height[i][2]] = true;
            }
        }
        for (ll i = 0; i < n; ++i) {
            if (avail[i]) { cout << ans[i] + 1 << " "; }
            else { cout << -1 << " "; }
        }
        cout << "\n";
    }
}