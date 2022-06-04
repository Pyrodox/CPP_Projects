#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
 
	int N,B; cin >> N >> B;
	vector<int> f(N); for (int& t: f) cin >> t;

	vector<int> tiles_by_depth;
	for (int i = 1; i < N-1; ++i)
		tiles_by_depth.push_back(i);
	sort(begin(tiles_by_depth),end(tiles_by_depth),
		[&](int x, int y) { return f[x] > f[y]; });

	set<int> indices;
	for (int i = 0; i < N; ++i)
		indices.insert(i);

	vector<array<int,3>> q;
	for (int i = 0; i < B; ++i) {
		int s,d; cin >> s >> d;
		q.push_back({s,d,i});
	}
	sort(q.rbegin(), q.rend());

	int tile_index = 0, needed_step = 1;
	vector<bool> ans(B);
	for (auto a: q) {
		while (tile_index < tiles_by_depth.size()
				 && f[tiles_by_depth[tile_index]] > a[0]) {
			int x = tiles_by_depth[tile_index];
			auto it = indices.find(x);
			needed_step = max(needed_step,*next(it)-*prev(it));
			indices.erase(it);
			++tile_index;
		}
		ans[a[2]] = a[1] >= needed_step;
	}

	for (bool b: ans)
		cout << b << "\n";
}