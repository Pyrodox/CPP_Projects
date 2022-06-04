#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, lvlx = 0, lvly = 0, lvlmx = 0, lvlmy = 0;
string x, y, motherx, mothery;
vector<vector<ll>> adj(1001), adjrev(1001);
unordered_map<string, ll> mp;
bool flagx = false, flagy = false;

vector<ll> findroots()
{
    vector<ll> v;
    for (ll i = 1; i <= n; ++i) {
        if (adjrev[i].size() == 0) {
            v.push_back(i);
        }
    }

    return v;
}

void dfs(ll node, ll e, ll level)
{
    if (mp[x] == node) {
        lvlx = level;
        flagx = true;
    }
    else if (mp[y] == node) {
        lvly = level;
        flagy = true;
    }
    else if (mp[motherx] == node) {
        lvlmx = level;
    }
    else if (mp[mothery] == node) {
        lvlmy = level;
    }
    for (ll a : adj[node]) {
        if (a != e) {
            dfs(a, node, level + 1);
        }
    }
}

string ancestorsearch(string older, string younger)
{
    dfs(mp[older], 0, min(lvlx, lvly));
    string tmp = "";
    for (ll i = 0; i < abs(lvly - lvlx) - 2; ++i) {
        tmp += "great-";
    }
    if (flagx && flagy) {
        if (abs(lvly - lvlx) == 1) {
            return older + " is the mother of " + younger;
        }
        else {
            return older + " is the " + tmp + "grand-mother of " + younger;
        }
    }
    else {
        bool a = false;
        if (lvlmx < lvlmy) {
            for (ll i = 0; i < adj[mp[motherx]].size(); ++i) {
                if (adj[mp[motherx]][i] == mp[mothery]) {
                    a = true;
                }
            }
        }
        else if (lvlmx > lvlmy) {
            for (ll i = 0; i < adj[mp[mothery]].size(); ++i) {
                if (adj[mp[mothery]][i] == mp[motherx]) {
                    a = true;
                }
            }
        }
        if (abs(lvly - lvlx) == 1 && a) {
            return older + " is the aunt of " + younger;
        }
        if (abs(lvly - lvlx) == 1) {
            return "COUSINS";
        }
    }
    tmp += "great-";

    return older + " is the " + tmp + "aunt of " + younger; 
}

int main()
{
    ifstream fin("family.in");
    ofstream fout("family.out");
    fin >> n >> x >> y;
    ll cnt = 1;
    for (ll i = 0; i < n; ++i) {      
        string a, b;
        fin >> a >> b;
        if (b == x) {
            motherx = a;
        }
        else if (b == y) {
            mothery = a;
        }
        if (mp[a] == 0) {
            mp[a] = cnt;
            ++cnt;
        }
        if (mp[b] == 0) {
            mp[b] = cnt;
            ++cnt;
        }
        adj[mp[a]].push_back(mp[b]);
        adjrev[mp[b]].push_back(mp[a]);
    }
    vector<ll> roots = findroots();
    for (ll i = 0; i < roots.size(); ++i) {
        dfs(roots[i], 0, 1);
        if (flagx && flagy) {
            flagx = false; flagy = false;
            break;
        }
        flagx = false; flagy = false;
        lvlx = 0; lvly = 0;
        if (i == roots.size() - 1) {
            fout << "NOT RELATED";
            return 0;
        }
    }
    if (motherx == mothery) {
        fout << "SIBLINGS";
    }
    else if (lvlx == lvly) {
        fout << "COUSINS";
    }
    else {
        if (lvlx < lvly) {
            fout << ancestorsearch(x, y);
        }
        else {
            fout << ancestorsearch(y, x);
        }
    }
}