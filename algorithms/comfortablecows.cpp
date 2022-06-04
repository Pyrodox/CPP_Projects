#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

bool present[3000][3000]; // which locations contain cows
 
int main() {
	int N; cin >> N;
	queue<pair<int,int>> cows_to_place;
	int total_cows = 0;
	for (int initial_cows = 1; initial_cows <= N; ++initial_cows) {
		pair<int,int> p; cin >> p.f >> p.s;
		p.f += 1000, p.s += 1000;
		cows_to_place.push(p);
		auto re_evaluate = [&](int x, int y) { 
			// if cow adjacent to exactly three others
			// add fourth location to queue
			if (!present[x][y]) return;
			int num_adj = 0;
			for (int d = 0; d < 4; ++d) 
				num_adj += present[x+dx[d]][y+dy[d]];
			if (num_adj == 3)
				for (int d = 0; d < 4; ++d) {
					pair<int,int> nex{x+dx[d],y+dy[d]};
					if (!present[nex.f][nex.s])
						cows_to_place.push(nex);
				}
		};
		while (!cows_to_place.empty()) {
			pair<int,int> loc = cows_to_place.front(); 
			cows_to_place.pop();
			if (present[loc.f][loc.s]) continue;
			++ total_cows; present[loc.f][loc.s] = 1;
			re_evaluate(loc.f,loc.s);
			for (int d = 0; d < 4; ++d) 
				re_evaluate(loc.f+dx[d],loc.s+dy[d]);
		}
		cout << total_cows-initial_cows << "\n";
	}
}