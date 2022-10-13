#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<pair<ll, ll>> ogorder1, ogorder2;

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    return a.first > b.first;
}

ll contrib(vector<pair<ll, ll>>& v)
{
    ll sum = 0;
    set<ll> s;
    for (ll i = 0; i < v.size(); ++i) {
        s.insert(v[i].second);
        //cout << v[i].second << "\n";
        auto it = s.find(v[i].second);
        /*cout << "set: ";
        for (ll val : s) {
            cout << val << " ";
        }
        cout << "\n";*/
        if (s.size() > 1 && v[i].second != n - 1 && ++it != s.end()) {
            sum += *it - v[i].second + 1;
            //cout << *it + 1 << " " << v[i].second + 1 << "\n";
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<ll, ll>> v(n), v2(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].first;
        v2[i].first = v[i].first;
        v[i].second = i;
        v2[i].second = n - 1 - i;
    }
    ogorder1 = v;
    ogorder2 = v2;
    sort(v.begin(), v.end(), cmp); //.first is the height of the cow, .second is the index or the reversed index of the cow
    sort(v2.begin(), v2.end(), cmp);
    cout << contrib(v) + contrib(v2);
}