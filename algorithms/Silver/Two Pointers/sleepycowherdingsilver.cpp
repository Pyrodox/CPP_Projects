#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    fin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
    }
    sort(v.begin(), v.end());
    ll maxdif = 0, minmoves = INT_MAX;
    for (ll i = 0; i < n - 1; ++i) {
        maxdif = max(maxdif, v[i + 1] - v[i]);
    }
    int tot = 0;
	for (int i = 1; i < n; ++i) {
		tot += v[i] - v[i - 1] - 1;
	}
	if (v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2) {
		minmoves = 2;
	} else if (v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2) {
		minmoves = 2;
	} else {
		// Min is the patch that is >= N and has the least number of empty positions
		int j = 0;
		for (int i = 0; i < n; ++i) {
			while (j + 1 < n && v[j + 1] - v[i] < n) {
				j++;
			}
			minmoves = min(minmoves, n - (j - i + 1));
		}
	}
    fout << minmoves << "\n" << max(tot - (v[1] - v[0] - 1), tot - (v[n - 1] - v[n - 2] - 1));;
}