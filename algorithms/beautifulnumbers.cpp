#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll sysofeq(ll a, ll b, ll n, ll x)
{
    if ((x - n * a) % (b - a) == 0)
    return (x - n * a) / (b - a);

    return -1;
}

long long invert_mod(long long k, long long m)
{
    if (m == 0) return (k == 1 || k == -1) ? k : 0;
    if (m < 0) m = -m;
    k %= m;
    if (k < 0) k += m;
    int neg = 1;
    long long p1 = 1, p2 = 0, k1 = k, m1 = m, q, r, temp;
    while(k1 > 0) {
        q = m1 / k1;
        r = m1 % k1;
        temp = q*p1 + p2;
        p2 = p1;
        p1 = temp;
        m1 = k1;
        k1 = r;
        neg = !neg;
    }
    return neg ? m - p2 : p2;
}

// Preconditions: 0 <= k <= min(n,p-1); p > 1 prime
long long choose_mod_two(long long n, long long k, long long p)
{
    // reduce n modulo p
    n %= p;
    // Trivial checks
    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    // Now 0 < k < n, save a bit of work if k > n/2
    if (k > n/2) k = n-k;
    // calculate numerator and denominator modulo p
    long long num = n, den = 1;
    for(n = n-1; k > 1; --n, --k)
    {
        num = (num * n) % p;
        den = (den * k) % p;
    }
    // Invert denominator modulo p
    den = invert_mod(den,p);
    return (num * den) % p;
}


// Preconditions: 0 <= k <= n; p > 1 prime
long long choose_mod_one(long long n, long long k, long long p)
{
    // For small k, no recursion is necessary
    if (k < p) return choose_mod_two(n,k,p);
    long long q_n, r_n, q_k, r_k, choose;
    q_n = n / p;
    r_n = n % p;
    q_k = k / p;
    r_k = k % p;
    choose = choose_mod_two(r_n, r_k, p);
    // If the exponent of p in choose(n,k) isn't determined to be 0
    // before the calculation gets serious, short-cut here:
    /* if (choose == 0) return 0; */
    choose *= choose_mod_one(q_n, q_k, p);
    return choose % p;
}


long long factorial_exponent(long long n, long long p)
{
    long long ex = 0;
    do
    {
        n /= p;
        ex += n;
    }while(n > 0);
    return ex;
}

long long choose_mod(long long n, long long k, long long p)
{
    // We deal with the trivial cases first
    if (k < 0 || n < k) return 0;
    if (k == 0 || k == n) return 1;
    // Now check whether choose(n,k) is divisible by p
    if (factorial_exponent(n, p) > factorial_exponent(k, p) + factorial_exponent(n-k, p)) return 0;
    // If it's not divisible, do the generic work
    return choose_mod_one(n,k,p);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b;
    cin >> a >> b >> n;
    ll ans = 0, ea = a * n, eb = b * n;
    for (ll i = ea; i <= eb; ++i) {
        ll tmp = i;
        bool flag = true;
        while (tmp) {
            ll ta = tmp % 10;
            if (ta != a && ta != b) {
                flag = false;
                break;
            }
            tmp /= 10;
        }
        if (flag && sysofeq(a, b, n, i) != -1) {
            ans = ans % mod + (choose_mod(n, sysofeq(a, b, n, i), mod) % mod) % mod;
        }
    }
    cout << ans % mod;
}