#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<char> flats(n);
    unordered_set<char> types;
    for (char&p : flats) {
        cin >> p;
        types.insert(p);
    }

    ll sinterval = 1000000000;
    unordered_map<char, int> curr;
    ll l = 0;
    for (ll r = 0; r < n; ++r) {
        curr[flats[r]]++;
        while (l + 1 <= r && curr.count(flats[l]) && curr[flats[l]] > 1) {
            curr[flats[l]]--;
            ++l;
        }
        if (curr.size() == types.size()) {
            sinterval = min(sinterval, r - l + 1);
        } 
    }
    cout << sinterval;
}