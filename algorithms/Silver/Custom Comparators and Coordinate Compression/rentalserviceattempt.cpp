#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    //ifstream cin("rental.in");
    //ofstream cout("rental.out");
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> cows(n), rentals(r), rentalsprefix(r + 1), milkprefix(m + 1), milkprefix2(m + 1), milkprefixvals(m + 1);
    vector<vector<ll>> milkbuy(m, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {cin >> cows[i];}
    for (ll i = 0; i < m; ++i) {cin >> milkbuy[i][0] >> milkbuy[i][1];}
    for (ll i = 0; i < r; ++i) {cin >> rentals[i];}
    sort(cows.begin(), cows.end(), [](ll a, ll b) {return a > b;});
    sort(rentals.begin(), rentals.end());
    sort(milkbuy.begin(), milkbuy.end(), [](vector<ll>& a, vector<ll>& b) {return a[1] > b[1];});
    
    for (ll i = 1; i <= r; ++i) {rentalsprefix[i] += rentalsprefix[i - 1] + rentals[i - 1];}
    for (ll i = 1; i <= m; ++i) {
        milkprefix[i] += milkprefix[i - 1] + milkbuy[i - 1][0];
        milkprefix2[i] = milkbuy[i - 1][1];
        milkprefixvals[i] += milkprefixvals[i - 1] + milkbuy[i - 1][1] * milkbuy[i - 1][0];
    }

    ll ans = 0, mi = 0, ri = 0, amounttaken = 0, amnt = 0;
    for (ll i = 0; i < n; ++i) {
        ll totalmilk = 0, l = mi, rp = m, mi2 = mi, tmpamounttaken = amounttaken, tmpamnt = amnt;
        while (l < rp) {
            ll mid = l + (rp - l) / 2;
            if (milkprefix[mid - 1] - amounttaken < cows[i] && milkprefix[mid] - amounttaken >= cows[i]) {
                mi2 = mid;
                totalmilk = max((ll) 0, milkprefixvals[mid - 1] - amnt) + (cows[i] - max((ll) 0, milkprefix[mid - 1] - amounttaken)) * milkprefix2[mid];
                tmpamounttaken += cows[i];
                tmpamnt += totalmilk;
                if (milkprefix[mid] <= 0) {
                    milkprefix[mid] = 0;
                }
                break;
            }
            else if (milkprefix[mid] - amounttaken >= cows[i]) {
                rp = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (ri > 0 && ri <= r && totalmilk <= rentals[ri - 1]) { 
            ans += rentalsprefix[r] - rentalsprefix[ri - 1];
            break;
        }
        else {
            ans += totalmilk;
            mi = mi2;
            amounttaken = tmpamounttaken;
            amnt = tmpamnt;
        }
        ++ri;
    }
    cout << ans;
}