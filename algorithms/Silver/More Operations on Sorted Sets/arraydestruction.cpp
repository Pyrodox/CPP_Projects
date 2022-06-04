#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<ll> ms;
        unordered_map<ll, ll> m;
        bool flag = true;
        for (ll i = 0; i < 2 * n; ++i) {
            ll a;
            cin >> a;
            ms.insert(a);
            m[a]++;
        }
        ll largest = *ms.rbegin();
        //cout << largest << "\n";
        for (auto it = ms.begin(); it != ms.end(); ++it) {
            ll x = largest + *it;
            ll oldx = x;
            //cout << x << "\n";
            vector<vector<ll>> tmp;
            multiset<ll> ms2 = ms;
            for (ll i = 0; i < n; ++i) {
                    //cout << "a " << ms2.size() << "\n";
                    auto it3end = ms2.end();
                    --it3end;
                    auto ittmp = ms2.find(x - *it3end);
                    if (ittmp != ms2.end() && (ittmp != it3end || m[*it3end] > 1)) {
                        x = max(*ittmp, *it3end);
                        //cout << x << "\n";
                        tmp.push_back({*it3end, *ittmp});
                        m[*it3end]--;
                        m[*ittmp]--;
                        ms2.erase(ms2.find(*it3end));
                        ms2.erase(ms2.find(*ittmp));
                    }
                    else if (ittmp == ms2.end()) {
                        break;
                    }
            }
            if (ms2.empty()) {
                cout << "YES\n" << oldx << "\n";
                for (auto val : tmp) {
                    cout << val[0] << " " << val[1] << "\n";
                }
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        }
    }
}