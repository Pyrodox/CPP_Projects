#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*bool cmp(const ll a, const ll b)
{
    return a > b;
}*/

ll case1(vector<ll> atk, vector<ll> def, multiset<ll> v)
{
    for (auto &i : def) {
        auto it = v.upper_bound(i);
        if (it == v.end()) {
            return 0;
        }
        v.erase(it);
    }
    ll ans = 0;
    for (auto &i : atk) {
        auto it = v.lower_bound(i);
        if (it == v.end()) {
            return 0;
        }
        ans += *it - i;
        v.erase(it);
    }
    for (auto &i : v) {
        ans += i;
    }

    return ans;
}

ll case2(vector<ll> atk, multiset<ll> v)
{
    ll ans = 0;
    for (auto &i : atk) {
        if (!v.size()) {
            return ans;
        }
        auto it = prev(v.end());
        if (*it <= i) {
            break;
        }
        ans += *it - i;
        v.erase(it);
    }

     return ans;
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> jatk, jdef;
    multiset<ll> ciel;
    for (ll i = 0; i < n; ++i) {
        string s;
        ll a;
        cin >> s >> a;
        if (s == "ATK") {
            jatk.push_back(a);
        }
        else {
            jdef.push_back(a);
        }
    }
    //ll atkpower = 0;
    for (ll i = 0; i < m; ++i) {
        ll a;
        cin >> a;
        ciel.insert(a);
        //atkpower += ciel[i];
    }
    sort(jatk.begin(), jatk.end());
    sort(jdef.begin(), jdef.end());
    //sort(ciel.begin(), ciel.end());
    /*for (auto val : jatk) {
        cout << val << " ";
    }
    cout << "\n";
    for (auto val : ciel) {
        cout << val << " ";
    }
    cout << "\n";*/
    /*ll ans = 0;
    ll l = jatk.size() - 1, r = m - 1;
    while (jatk.size() > 0 && ciel.size() > 0 && ciel[r] >= jatk[l]) {
        ans += ciel[r] - jatk[l];
        cout << ciel[r] << "-" << jatk[l] << ": " << ciel[r] - jatk[l] << "\n";
        atkpower -= ciel[r];
        ciel.pop_back();
        jatk.pop_back();
        --l;
        --r;
    }
    r = jdef.size() - 1;
    while (jdef.size() > 0 && ciel.size() > 0 && upper_bound(ciel.begin(), ciel.end(), jdef[r]) != ciel.end()) {
        atkpower -= *(upper_bound(ciel.begin(), ciel.end(), jdef[r]));
        ciel.erase(upper_bound(ciel.begin(), ciel.end(), jdef[r]));
        jdef.pop_back();
        --r;
    }
    if (jatk.size() == 0 && jdef.size() == 0) {
        ans += atkpower;
    }*/
    cout << max(case1(jatk, jdef, ciel), case2(jatk, ciel));
}