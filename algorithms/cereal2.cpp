#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct edge {
    ll cow, to; // which cow's choice 
    bool is_first;
 
    edge() {};
    edge(ll cow, ll to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};

ll n, m;
vector<edge> adj[100001];
bool visited_cycle[100001]; // array for cycle finding
bool visited[100001]; // visited array for finding which order of cows we should use
bool gets_cereal[100001]; 
queue<ll> order;
ll ignore_edge = -1, first_cereal = -1, hungry_cows = 0; // the cereal we start the search from, if the CC is not a tree then this must be on a cycle
 
void find_cycle(ll cur, ll prev = -1)
{
    visited_cycle[cur] = true;
    for (edge next : adj[cur]) {
        if (visited_cycle[next.to]) {
            if (first_cereal == -1 && next.to != prev) {
                if (next.is_first) {
                    first_cereal = next.to; 
                }
                else {
                    first_cereal = cur;
                }
                ignore_edge = next.cow; 
                order.push(next.cow);
                gets_cereal[next.cow] = true;
            }
        }
        else {
            find_cycle(next.to, cur);
        }
    }
}

void dfs(ll cur)
{
    visited[cur] = true;
    for (edge next : adj[cur]) {
        if (!visited[next.to] && next.cow != ignore_edge) { 
            gets_cereal[next.cow] = true;
            order.push(next.cow);
            dfs(next.to);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(edge(i, b, false));
        adj[b].push_back(edge(i, a, true));
    }
    /*for (ll i = 1; i <= m; ++i) {
        cout << "cereal: " << i << "\n";
        for (ll j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j].cow << " " << adj[i][j].to << "\n"; 
        }
    }*/
    for (ll i = 1; i <= m; ++i) {
        first_cereal = -1;
        ignore_edge = -1;
        if (!visited[i]) {
            find_cycle(i);
           
            if (first_cereal > 0) {
                //cout << first_cereal << "\n";
                dfs(first_cereal);
            } else {
                //cout << "i: " << i << "\n";
                dfs(i);
            }
        }
    }
    for (ll i = 1; i <= n; ++i) {
        if (!gets_cereal[i]) {
            ++hungry_cows;
            order.push(i);
        } 
    }
    cout << hungry_cows << "\n";
    while (!order.empty()) {
        cout << order.front() << "\n"; 
        order.pop();
    }
}