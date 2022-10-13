#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e7 + 1;

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

ll totalPrimeFactors(ll n)         
{         
    // To keep track of count         
    ll count = 0;         
    // 2s that divide n         
    if (!(n%2))         
    {         
    count++;         
    while (!(n%2))         
    n /= 2;         
    }         
    // n must be odd at this poll. So we can skip         
    // one element (Note i = i +2)         
    for (ll i = 3; i*i <= n; i = i+2)         
    {         
    // i divides n         
    if (!(n%i))         
    {         
    count++;         
    while (!(n%i))         
    n /= i;         
    }         
    }         
    // This condition is to handle the case when n         
    // is a prime number greater than 2         
    if (n>2)         
    count++;         
    return count;         
}         
// C++ function to count number         
// of pair with given GCD and LCM         
ll countPairs(ll G, ll L)         
{         
    if (L % G != 0)         
    return 0;         
    ll div = L/G;         
    // answer is 2^totalPrimeFactors(L/G)         
    return (1<<totalPrimeFactors(div));         
}      

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Finds such x and y, that a * x + b * y = gcd(a, b)
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0; 
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Solves equation a * x + b * y = c, writes answer to x and y
ll solveDiophantine(ll a, ll b, ll c, ll &x, ll &y) {
    ll g = extended_gcd(a, b, x, y);

    if (c % g != 0) {
        //puts("Impossible");
        return 0;
    }

    c /= g;

    x = x * c; y = y * c;

    return 1;
}

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

ll a, b, c;
ll x, y;
ll g;

int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve(); 
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        b *= -1;
        // Find any solution
        if (!solveDiophantine(a, b, c, x, y)) {
            cout << 0 << "\n";
            continue;
        }

        // In this problem we search for solution with minimum x >= 0
        // a * x + b * y = gcd(a, b)
        // now for any lleger k: a * (x + k * b / g) + b * (y - k * a / g) = gcd(a, b)

        g = gcd(a, b);

        ll add = b / g;
        ll num = 0;
        if (add < 0) 
            num = (ll) floor(1.0 * -x / add);
        else
            num = (ll) ceil(1.0 * -x / add);

        x = x + b / g * num;
        y = y - a / g * num;

        //cout << x << " " << y << "\n";
        ll ans = 0, gcdnum = gcd(a, b), ogc = c;
        vector<ll> current{1}, appears(mx);
        vector<ll> abc;
        while (c != 1) {
            ll sb = nums[c], cnt = 0;
            while (c % sb == 0) {
                c /= sb;
                ++cnt;
                ll tmp = current.size();
                for (ll i = 0; i < tmp; ++i) {
                    if (!appears[current[i] * sb]) {
                        current.push_back(current[i] * sb);
                        //cout << ogc << " " << b << " " << current[i] << " " << sb << "\n";
                        if ((ogc - b * current[i] * sb) % a == 0) {
                            abc.push_back(current.size() - 1);
                            //cout << "push " << i << "\n";
                        }
                        appears[current[i] * sb] = 1;
                    }
                }
            }
        }
        /*for (ll i = -1000; i <= 1000; ++i) {
            if (x + i * b / gcdnum > 0 && y - i * a / gcdnum > 0 && (x + i * b / gcdnum) % (y - i * a / gcdnum) == 0) {
                cout << (x + i * b / gcdnum) << " " << (y - i * a / gcdnum) << "\n";
                ans += countPairs((y - i * a / gcdnum), (x + i * b / gcdnum));
            }
        }*/
        /*for (ll a : current) {
            cout << a << ", \n";
        }*/
        abc.push_back(0);
        for (ll i = 0; i < abc.size(); ++i) {
            if ((ogc - b * current[abc[i]]) % a == 0) {
                //cout << current[abc[i]] << " " << (ogc - b * current[abc[i]]) / a << "\n";
                ans += countPairs(current[abc[i]], (ogc - b * current[abc[i]]) / a);
            }
        }

        cout << ans << "\n";
    }
}