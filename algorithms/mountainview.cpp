#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct mountain {
    ll start, end;
};

bool cmp(const mountain& x, const mountain& y)
{
    if (x.start == y.start) {
        return x.end > y.end;
    }
    return x.start < y.start;
}

int main()
{
    ll n;
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    fin >> n;
    vector<mountain> v;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        fin >> a >> b;
        v.push_back({a - b, a + b});
    }
    sort(v.begin(), v.end(), cmp);
    ll newmx = v[0].end, ans = 0;
    for (ll i = 1; i < n; ++i) {
        if (v[i].end <= newmx) {
            ++ans;
        }
        else {
            newmx = v[i].end;
        }
    }
    fout << n - ans;
}