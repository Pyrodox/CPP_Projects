#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

vector<vector<ll>> factors(mx);
vector<ll> nums(mx);

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void sieve()
{      
    for (ll i = 2; i * i < mx; ++i) {
        if (nums[i] == i) {
            for (ll j = i * i; j < mx; j += i) {
                if (nums[j] == j) {
                    nums[j] = i;
                }
            }
        }
    }
}

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve();
    map<ll, pair<ll, ll>> mp;
    vector<ll> v;
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ll ans = 1, counterans = 1;
        while (x != 1) {
            ll y = nums[x], power = 0;
            while (x % y == 0) {
                ++power;
                x /= y;
            }
            ans *= binpow(y, power % k);
            counterans *= binpow(y, (k - (power % k)) % k);
        }
        mp[ans] = {counterans, mp[ans].second + 1};
        v.push_back(ans);
    }
    ll answer = 0;
    for (ll i = 0; i < v.size(); ++i) {
        if (mp[v[i]].first == v[i]) {
            answer += (mp[v[i]].second - 1) * mp[v[i]].second / 2;
        }
        else {
            answer += mp[v[i]].second * mp[mp[v[i]].first].second;
        }
        mp[v[i]].second = 0, mp[mp[v[i]].first].second = 0;
    }
    cout << answer;
}