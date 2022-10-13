#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    deque<ll> que;
    vector<ll> dist(k, -1);
    dist[1] = 1;
    que.push_front(1);
    while (que.size()) {
        ll x = que.front();
        que.pop_front();
        ll edge0 = x * 10 % k;
        if (dist[edge0] == -1 || dist[x] < dist[edge0]) {
            dist[edge0] = dist[x];
            que.push_front(edge0);
        }
        ll edge1 = (x + 1) % k;
        if (dist[edge1] == -1 || dist[x] + 1 < dist[edge1]) {
            dist[edge1] = dist[x] + 1;
            que.push_back(edge1);
        }
    }
    cout << dist[0];
}