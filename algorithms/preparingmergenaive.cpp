#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    set<ll> indices;
    for (ll i = 0; i < n; ++i) {
        indices.insert(i);
    }
        ll iter = 0, iter2 = 0;
        //cout << "testing mid: " << mid << " " << l << " " << r << "\n";
        vector<vector<ll>> an;
        auto stmp = s;
        while (indices.size() > 0) {
            //cout << "iter2: " << iter2 << "\n";
            an.push_back({});
            ll curmax = 0;
            auto a2 = indices.begin();
            while (indices.size() > 0 && iter < stmp.size()) {
                if (stmp[iter] > curmax) {
                    //cout << "iter: " << iter << " " << stmp[iter] << "\n";
                    an[iter2].push_back(stmp[iter]);
                    curmax = stmp[iter];
                    ++a2;
                    indices.erase(indices.find(iter));
                    /*for (auto val : indices) {
                        cout << val << " ";
                    }*/
                    iter = *a2;
                    //cout << "\n";
                }
                else {
                    //cout << "else: " << iter << " " << stmp[iter] << "\n";
                    ++a2;
                    iter = *a2;
                }
            }
            ++iter2;
            iter = *indices.begin();
            a2 = indices.begin();
        }
    for (auto v : an) {
        for (ll i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}