#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t, w;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        ll halfweight = ceil((double) w / 2);
        vector<ll> v(n);
        bool flag = false;
        map<ll, vector<ll>> m;
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
            m[v[i]].push_back(i);
            if (v[i] >= halfweight && v[i] <= w) {
                cout << 1 << "\n" << i + 1 << "\n";
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ll totalweight = 0;
        vector<ll> outputvec;
        sort(v.begin(), v.end());
        for (ll i = 0; i < n; ++i) {
            totalweight += v[i];
            outputvec.push_back(m[v[i]][m[v[i]].size() - 1]);
            m[v[i]].pop_back();
            if (totalweight >= halfweight && totalweight <= w) {
                sort(outputvec.begin(), outputvec.end());
                cout << outputvec.size() << "\n";
                for (auto val : outputvec) {
                    cout << val + 1 << " ";
                }
                cout << "\n";
                break;
            }
            if (totalweight > w) {
                cout << -1 << "\n";
                break;
            }   
        }
    }
}