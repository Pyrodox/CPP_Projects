//C++ Solution by Daniel Suh
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mpa make_pair
#define pb push_back
#define ins insert
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define nl "\n"

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

int MOD = 1;

bool cmp(int &a, int &b) {
	//Sorts by the max mod, so Bessie can get the max amount of leftovers
	return (a % MOD) > (b % MOD);
}

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int maxD = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		maxD = max(maxD, A[i]);
	}
	int mx = 0;
	for(int i = 1; i <= maxD; i++) {
		int amount = 0;
		//For loop calculates how many groups of "i" berries can be put into a basket
		for(int j = 0; j < N; j++) {
			amount += A[j] / i;
		}
		//If the amount is not enough for K / 2 baskets, it is not valid
		if(amount < K / 2) {
			continue;
		}
		if(amount >= K) {
			//If there is greater than or equal to "i" sections for both Bessie and Ellie, then Bessie can collect (K / 2) * i berries
			mx = max(mx, (K / 2) * i);
			continue;
		}
		MOD = i;
		sort(all(A), cmp);
		//Gives the maximum amount of leftovers to Bessie
		int cur = (amount - K / 2) * i;
		for(int j = 0; j < N && j + amount < K; j++) {
			cur += A[j] % i;
		}
		mx = max(mx, cur);
	}
	cout << mx << nl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	fileIO("berries");

	solve();
}