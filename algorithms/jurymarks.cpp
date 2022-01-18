/*If I get TLE , it is good.If I get AC,it's NICE !*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=1e7+10;
const ll mod=1e9+7;
using namespace std;
typedef long long ll;
vector <int> temp;
map <int,int > mp;
int sum[3000];
int main(void)
{
    int n,k;
    cin >> n>> k;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        sum[i]=t+sum[i-1];
    }
    //for(int i=1;i<=n;i++)
    //    printf("%d\n",sum[i]);
    sort(sum+1,sum+1+n);
    int len=unique(sum+1,sum+1+n)-(sum+1);
    //for(int i=1;i<=len;i++)
    //    printf("%d\n",sum[i]);
    mp.clear();
    //int mmax=-INF;
    //int mmin=INF;
    for(int i=1;i<=k;i++)
    {
        int t;
        scanf("%d",&t);
        for(int j=1;j<=len;j++)
        {
           temp.push_back(t-sum[j]);
        }
    }
    sort(temp.begin(),temp.end()); // With sort AC and without TLE, the test data is T earlier than the following TLE code, so I suspect that the efficiency of map insertion may be related to the monotony of the original vector. The more monotonous, the faster.
    int cnt=0;
    //int index=mmax;
    for(int i=0;i<temp.size();i++)
    {
        mp[temp[i]]++;
    }
    for(int i=0;i<temp.size();i++)
    {
       if( mp[temp[i]] ==k )
            mp[temp[i]]=0,cnt++;
    }
    printf("%d\n",cnt);
}