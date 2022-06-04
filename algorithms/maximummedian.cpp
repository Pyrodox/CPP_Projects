#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool condition(vector<ll>& v, ll n, ll m, ll k)
{
	ll total = 0;
	for (ll i = (n - 1) / 2; i < n; ++i) {
		if (m - v[i] >= 0) {
			total += m - v[i];
		}
	}

	return total <= k;
}

ll findmedian(vector<ll>& v, ll k)
{
	ll l = 1, r = v[v.size() - 1] + k, mx = 0;
	while (l < r) {
		ll m = l + (r - l + 1) / 2;
		if (condition(v, v.size(), m, k) && m >= mx) {
			l = m;
			mx = m;
			//cout << m << "\n";
		}
		else {
			r = m - 1;
		}
	}

	return l;
}

int main()
{
	ll n, k;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	vector<ll> v(n);
	for (ll& a : v) {
		cin >> a;
	}	
	sort(v.begin(), v.end());
	cout << findmedian(v, k);
}