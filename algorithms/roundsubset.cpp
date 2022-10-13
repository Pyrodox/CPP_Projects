#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
//dp[i][j][k] =  maximum powers of 2 given that you use the first i and choose j and have k powers of 5
int pre[205][6005];
int curr[205][6005];
int tw[205];
int f[205];
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, B;
	cin >> N >> B;	
	vector<ll> A(N+1);
	memset(pre, -1, sizeof(pre));
	memset(curr, -1, sizeof(curr));
	for(int i = 1; i <= N;i ++){
		cin >> A[i];
	}
	for(int i = 1; i <= N;i ++){
		int two =0;
		int fv = 0;
		while(A[i] % 2 == 0){
			two++;
			A[i]/=2;
		}
		while(A[i] % 5 == 0){
			fv++;
			A[i]/=5;
		}
		tw[i]=two;
		f[i]=fv;
	}
	pre[0][0]=0;
	int ans = 0;
	for(int i =1;i <= N;i ++){
		assert(f[i] < 30);
		for(int j = 0;j <= B; j++){
			for(int k = 0; k<=6000;k ++){
				//use the i'th
				//if(j > i)continue;
				if(f[i] <= k && j != 0){
					if(pre[j-1][k-f[i]] != -1){
						curr[j][k] = max(curr[j][k], pre[j-1][k-f[i]] + tw[i]);
					}
				}
				//don't use the i'th
				if(pre[j][k] != -1){
					curr[j][k] = max(curr[j][k], pre[j][k]);
				}
			}
		}
		for(int j = 0;j <= B;j ++){
			for(int k  =0; k<= 6000;k++){
				pre[j][k] = curr[j][k];
				curr[j][k] = -1;
			}
		}
	}
	for(int i = 0; i<=6000;i++){
		ans = max(ans,min(i,pre[B][i]));
	}
	cout << ans << '\n';

}