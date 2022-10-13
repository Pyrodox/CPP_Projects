#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

vector<ll> nums(mx);

ll binpow(ll a, ll b) {
    ll res = 1;
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
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve();
    vector<multiset<ll>> primefactors(mx);
    set<ll> listofprimes;
    vector<ll> amtperprime(mx);  
    ll ogn = n;
    vector<ll> ogv;
    while (n--) {
        ll x;
        cin >> x;
        ogv.push_back(x);
        while (x != 1) {
            ll y = nums[x], c = 0;
            while (x % y == 0) {
                ++c;
                x /= y;
            }
            primefactors[y].insert(c);
            listofprimes.insert(y);
            ++amtperprime[y];
        }
    }
    ll ans = 1;
    for (ll a : listofprimes) {
        ll it = *primefactors[a].begin(), it2 = *(++primefactors[a].begin());
        if (amtperprime[a] == ogn) {
            ans *= binpow(a, it2);
        }
        else if (amtperprime[a] == ogn - 1) {
            ans *= binpow(a, it);
        }
    }
    if (ans == 1 && ogv.size() == 2) {
        for (ll a : ogv) {
            ans *= a;
        }
    }    
    cout << ans;
}