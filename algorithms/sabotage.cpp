#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX_N 100000

ll n, S[MAX_N];

ll round3(double x)
{
    return (ll)(1000.0 * x + 0.5); 
}

ll possible(double guess)
{
    ll i, total = 0;
    double best, current;
    for (i = 0; i < n; ++i) {
        total += S[i];
    }
    best = current = S[1] - guess;
    for (i = 2; i < n - 1; ++i) {
        if (current < 0) {
            current = 0;
        }
        current += S[i] - guess;
        if (current > best) {
            best = current;
        }
    }

    return best >= total - guess * n;
}

double solve()
{
    double low = 1.0, high = MAX_N * 10000.0;
    while (round3(low) != round3(high)) {
        if (possible((low + high) / 2)) {
            high = (low + high) / 2;
        }
        else {
            low = (low + high) / 2;
        }
    }

    return low;
}

int main()
{
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    scanf("%d", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    printf("%.3lf\n", solve());
}