#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> ideal(n), current(n);
    for (ll i = 0; i < n; ++i) {
        cin >> ideal[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> current[i];
    }
    ll differences[n];
    for (ll i = 0; i < n; ++i) {
        differences[i] = ideal[i] - current[i];
    }
    ll ans = 0;
    while (ideal != current) {
        bool plus = true;
        ll left = 0;
        for (ll i = 0; i < n; ++i) {
            if (differences[i] < 0) {
                plus = false;
                left = i; 
                break;
            }
            else if (differences[i] > 0) {
                left = i;
                break;
            }
            ++left;
        }
        ll right = left;
        for (ll i = left + 1; right < n; ++i) {
            if (plus && differences[i] > 0) {
                ++right;
            }
            else if (!plus && differences[i] < 0) {
                ++right;
            }
            else {
                break;
            }
        }
        bool a = true;
        if (plus) {
            while (a) {
                for (ll i = left; i <= right; ++i) {
                    current[i]++;
                    differences[i]--;
                    if (current[i] == ideal[i]) {
                        a = false;
                    }
                }
                ++ans;
            }
        }
        else {
            while (a) {
                for (ll i = left; i <= right; ++i) {
                    current[i]--;
                    differences[i]++;
                    if (current[i] == ideal[i]) {
                        a = false;
                    }
                }
                ++ans;
            }
        }
    }
    cout << ans;
}