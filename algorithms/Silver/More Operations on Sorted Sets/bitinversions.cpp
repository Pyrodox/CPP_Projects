#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll m;
set<ll> dif;
multiset<ll> ret;

void change(ll x)
{
	if (!x || x == s.size()) {
		return;
	}
	auto it = dif.find(x);
	if (it != dif.end()) {
		ll a = *prev(it), b = *next(it);
		ret.erase(ret.find(x - a));
		ret.erase(ret.find(b - x));
		ret.insert(b - a);
		dif.erase(*it);
	}
	else {
		it = dif.insert(x).first;
		ll a = *prev(it), b = *next(it);
		ret.erase(ret.find(b - a));
		ret.insert(x - a);
		ret.insert(b - x);
	}
	/*for (auto val : dif) {
		cout << val << " ";
	}
	cout << "\n";
	for (auto val : ret) {
		cout << val << " ";
	}
	cout << "\n\n";*/
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s >> m;
	dif.insert(0), dif.insert(s.size());
	for (ll i = 0; i < s.size() - 1; ++i) {
		if (s[i] != s[i + 1]) {
			dif.insert(i + 1);
		}
	}
	for (auto it = dif.begin(); next(it) != dif.end(); ++it) {
		ret.insert(*(next(it)) - *it);
	}
	/*for (auto val : dif) {
		cout << val << " ";
	}
	cout << "\n";
	for (auto val : ret) {
		cout << val << " ";
	}
	cout << "\n\n";*/
	for (ll i = 0; i < m; ++i) {
		ll x;
		cin >> x;
		change(x);
		change(x - 1);
		cout << *ret.rbegin() << " ";
	}
}