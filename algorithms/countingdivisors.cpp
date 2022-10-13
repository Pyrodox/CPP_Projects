#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

vector<vector<ll>> factors(mx);
vector<ll> nums(mx);

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
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve();    
    while (n--) {
        ll x;
        cin >> x;
        ll ans = 1;
        while (x != 1) {
            ll y = nums[x], c = 1;
            while (x % y == 0) {
                ++c;
                x /= y;
            }
            ans *= c;
        }
        cout << ans << "\n";
    }
}