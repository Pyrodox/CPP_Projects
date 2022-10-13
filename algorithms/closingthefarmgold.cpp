#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int mxn=2e5+1;
int n,m,order[mxn];
vector<int> adj[mxn];
bool vis[mxn];
vector<string> ans;

struct DSU{
    vector<int> e;
    DSU(int N){e=vector<int>(N+1,-1);}
    int find(int a){return e[a]<0?a:e[a]=find(e[a]);}
    int size(int a){return -e[find(a)];}
    void unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return;
        if(e[a]>e[b]) swap(e[a],e[b]);
        e[a]+=e[b];e[b]=a;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin >> order[i];
    reverse(order+1,order+n+1);
    for(int i=1;i<=n;i++){
        vis[order[i]]=1;
        for(int j:adj[order[i]])
            if(vis[j])
                dsu.unite(order[i],j);
        if(dsu.size(order[i])==i) 
            ans.push_back("YES\n");
        else ans.push_back("NO\n");
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout << i;

}