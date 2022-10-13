#include <bits/stdc++.h>

using namespace std;

using P = pair<long long, long long>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<P, int>> all_subsets(const vector<P> &dirs) {
	vector<pair<P, int>> v{{}};
	for (const P &d : dirs) {
		v.resize(2 * v.size());
		for (int i = 0; i < v.size() / 2; i++) {
			v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
		}
	}
	sort(v.begin(), v.end());
	return v;
}

int main() {
	int N;
	cin >> N;
	P goal;
	cin >> goal.first >> goal.second;
	vector<P> dirs(N);
	for (auto &d : dirs) {
		cin >> d.first >> d.second;
	}
	vector<pair<P, int>> a =
		all_subsets(vector<P>(begin(dirs), begin(dirs) + N / 2));
	vector<pair<P, int>> b =
		all_subsets(vector<P>(begin(dirs) + N / 2, end(dirs)));
	reverse(b.begin(), b.end());
    /*for (auto val : a) {
        cout << val.first.first << " " << val.first.second << " " << val.second << "\n";
    }
    cout << "\n";
    for (auto val : b) {
        cout << val.first.first << " " << val.first.second << " " << val.second << "\n";
    }*/
	vector<long long> ans(N + 1);
	vector<int> with_num;
	P rest_prev{1e18, 1e18};
	int ib = 0;
	for (const auto &[offset, num] : a) {
		const P rest = goal - offset;
		if (rest != rest_prev) {
            //cout << rest.first << " " << rest.second << "\n";
			rest_prev = rest;
			with_num = vector<int>(N - N / 2 + 1);
			for (; ib < b.size() && b.at(ib).first > rest; ++ib);
			for (; ib < b.size() && b.at(ib).first == rest; ++ib) {
				++with_num.at(b.at(ib).second);
			}
		}
		for (int i = 0; i < with_num.size(); i++) {
			ans[i + num] += with_num[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}