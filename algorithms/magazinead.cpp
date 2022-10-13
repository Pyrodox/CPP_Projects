#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> k;
    getline(cin, s);
    getline(cin, s);
    vector<ll> v, pref;
    pref.push_back(0);
    ll lasti = 0, maxl = 0;
    bool flag = false;
    for (ll i = 0; i <= s.size(); ++i) {
        if (i == s.size() && lasti != 0) {
            v.push_back(i - lasti - 1);
            flag = true;
        }
        else if (i == s.size() && lasti == 0) {
            v.push_back(i - lasti);
            flag = true;
        }
        else if (s[i] == '-' || s[i] == ' ') {
            flag = true;
            v.push_back(i - lasti);
            if (lasti == 0) {
                v[v.size() - 1] = {i - lasti + 1};
            }
            lasti = i;
        }
        if (flag) {
            pref.push_back(pref[pref.size() - 1] + v[v.size() - 1]);
            flag = false;
            maxl = max(maxl, v[v.size() - 1]);
        }
    }
    ll l = max(maxl, (ll)ceil((double)s.size() / (double)k)), r = s.size();
    while (l < r) {
        ll mid = l + (r - l) / 2, lastval = 0, iter = 0, totalsum = 0, accum = 0;
        while (iter < k) {
            ll l1 = lastval + 1, r1 = pref.size();
            while (l1 < r1) {
                ll midforpref = l1 + (r1 - l1) / 2;
                if (pref[midforpref] - accum <= mid) {
                    l1 = midforpref + 1;
                }  
                else {
                    r1 = midforpref;
                }
            }
            --l1;
            totalsum += pref[l1] - accum;
            accum = pref[l1];
            lastval = l1;
            ++iter;
            if (totalsum == s.size()) {
                break;
            }
        }
        if (totalsum < s.size()) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << l;
}