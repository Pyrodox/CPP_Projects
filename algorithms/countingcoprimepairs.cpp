#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

vector<ll> nums(mx), inarray(mx);

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
    vector<ll> v;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll a; cin >> a;
        inarray[a]++;
        if (inarray[a] == 1 && a != 1) {
            v.push_back(a);
        }
        if (a == 1) {
            ans += n - 1;
        }
    }
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve();
    auto ogv = v;
    vector<ll> stuff(mx);
    vector<vector<ll>> bigv(mx);
    for (ll i = 0; i < v.size(); ++i) {
        ll og = v[i];
        while (v[i] != 1) {
            ll y = nums[v[i]], c = 0;
            while (v[i] % y == 0) {
                ++c;
                v[i] /= y;
            }
            stuff[y] += inarray[og];
            bigv[og].push_back(y);
        }
    }
    for (ll i = 0; i < ogv.size(); ++i) {
        ll a = 0;
        for (ll j = 0; j < bigv[ogv[i]].size(); ++j) {
            a += stuff[bigv[ogv[i]][j]];
            //cout << ogv[i] << " " << a << "\n";
        }
        ans += inarray[ogv[i]] * (n - a + bigv[ogv[i]].size() - 1);
        //cout << inarray[ogv[i]] << "\n";
        //cout << inarray[ogv[i]] * (n - a + bigv[ogv[i]].size() - 1) << "\n";
    }

    cout << ans / 2;
}