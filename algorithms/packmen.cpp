#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    string s = "";
    vector<ll> packmen, asts;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'P') {
            packmen.push_back(i);
        }
        else if (c == '*') {
            asts.push_back(i);
        }
        s += c;
    }
    ll l = 0, r = n + n / 2;
    while (l < r) {
        ll mid = l + (r - l) / 2, it = 0;
        for (ll i = 0; i < packmen.size() && it < asts.size(); ++i) {
            ll move = abs(asts[it] - packmen[i]);
            if (asts[it] < packmen[i]) {
                if (move > mid) {
                    break;
                }
                ll canaffordright1 = packmen[i] + mid - move * 2, canaffordright2 = packmen[i] + (mid - move) / 2;
                while (it < asts.size() && (asts[it] <= canaffordright1 || asts[it] <= canaffordright2)) {
                    ++it;
                }
            }
            else {
                if (move > mid) {
                    continue;
                }
                while (it < asts.size() && asts[it] <= packmen[i] + mid) {
                    ++it;
                }
            }
        }
        if (it >= asts.size()) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}