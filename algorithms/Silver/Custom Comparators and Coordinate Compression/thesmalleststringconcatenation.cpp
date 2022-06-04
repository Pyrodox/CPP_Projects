#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const string& a, const string& b)
{
    return a + b < b + a;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for (auto val : v) {
        ans += val;
    }
    cout << ans;
}