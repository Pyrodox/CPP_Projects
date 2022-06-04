#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 251;

ll n, b, mincnt = 250;
vector<ll> path(mx);

void floodfill(ll tile, queue<pair<ll, ll>> que, ll cnt)
{
    if (tile >= n || que.empty() || que.front().first < tile || cnt >= mincnt) {
        //cout << cnt << " reached n\n";
        mincnt = min(mincnt, cnt);

        return;
    }
    ll recurs = 0, minval = 2500;
    for (ll i = 1; i <= que.front().second && tile + i <= n; ++i) {
        if (path[tile + i] <= que.front().first) {
            //cout << tile + i << " " << que.front().first << " " << que.front().second << " " << cnt << "\n";
            minval = min(minval, path[tile + i]);
            floodfill(tile + i, que, cnt);
            ++recurs;
        }
    }
    if (recurs == 0) {
        ++cnt;
        ll a = que.front().second;
        que.pop();
        for (ll i = 0; i < que.size(); ++i) {
            if (que.front().first >= minval || que.front().second >= a) {
                floodfill(tile, que, cnt);
            }
            que.pop();
            ++cnt;
        }
        //cout << que.front().first << " " << que.front().second << " " << cnt << "\n";
    }
}

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    fin >> n >> b;
    for (ll i = 1; i <= n; ++i) {
        fin >> path[i];
    }
    queue<pair<ll, ll>> boots;
    for (ll i = 0; i < b; ++i) {
        ll a, b;
        fin >> a >> b;
        boots.push({a, b});
    }
    //cout << "\n";
    floodfill(1, boots, 0);
    fout << mincnt;
}