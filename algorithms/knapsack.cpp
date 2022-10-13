#include<bits/stdc++.h>
using namespace std;
#define int long long
 
pair<int, int>a[200005];
 
 
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        int n, w;cin>>n>>w;
        for(int i=1;i<=n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a+1, a+n+1);
        int ff=0, ind=-1;
        for(int i=n;i>=1;i--){
            if(a[i].first<=w and a[i].first>=(w+1)/2){
                ff=1;
                ind=a[i].second;
            }
        }
        if(ff){
            cout<<1<<endl;
            cout<<ind<<endl;
            continue;
        }
        int ss=0;
        vector<int>pp;
        for(int i=n;i>=1;i--){
            if(a[i].first<(w+1)/2){
                ss+=a[i].first;
                pp.push_back(a[i].second);
            }
            if(ss>=(w+1)/2){
                ff=1;
                break;
            }
        }
        if(ff){
            cout<<pp.size()<<endl;
            sort(pp.begin(), pp.end());
            for(auto i:pp){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}