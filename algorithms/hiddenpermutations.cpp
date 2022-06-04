#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(ll a)
{
    cout << "? " << a << "\n";
    cout.flush();
    ll b;
    cin >> b;

    return b;
}

int main()
{
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> ans(n + 1, -1);
        for (ll i = 1; i <= n; ++i) {
            if (ans[i] == -1) {
                vector<ll> cycle;
                ll answer = ask(i), x = ask(i);
                cycle.push_back(x);
                while (x != answer) {
                    x = ask(i);
                    cycle.push_back(x);
                }
                for (ll j = 0; j < cycle.size(); ++j) {
                    ans[cycle[j]] = cycle[(j + 1) % cycle.size()];
                }
            }
        }
        cout << "! ";
        for (ll i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout.flush();
        cout << "\n";
    }
}