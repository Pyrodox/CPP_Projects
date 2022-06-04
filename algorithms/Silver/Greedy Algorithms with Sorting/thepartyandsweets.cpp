#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

	int n, m; cin >> n >> m;
	vector<int> b(n), g(m);
	ll res = 0;

	for(int i = 0; i < n; i++){
		cin >> b[i];
		res += b[i];
	}

	for(int i = 0; i < m; i++){
		cin >> g[i];
	}

	// Initial lower bound on answer
	res *= m;

	sort(b.begin(), b.end());
	sort(g.begin(), g.end());

	// If it's impossible to satisfy the constraints
	if (b[n - 1] > g[0]) {
		cout << -1;
		return 0;
	}

	for(int i = 1; i < m; i++){ 
		res += g[i] - b[n - 1];
	}
	
	if(g[0] != b[n - 1]){ 
		res += g[0] - b[n - 2]; 
	}

	cout << res << endl;
}