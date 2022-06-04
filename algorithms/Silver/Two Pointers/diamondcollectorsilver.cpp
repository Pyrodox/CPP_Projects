#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k; cin >> n >> k;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];

	sort(A, A+n);

	// how many diamonds we can take
	// assuming i is the leftmost diamond
	int canTakeLeft[n];
	int l = 0, r = 0;
	for (; l < n; l++) {
		while (r < n && A[r] - A[l] <= k) r++;
		canTakeLeft[l] = r - l;
	}
    /*for (auto val : canTakeLeft) {
        cout << val << " ";
    }
    cout << "\n";*/
	// maxValAfterI[i] = max value of canTakeLeft[x] for some x >= i.
	int maxValAfterI[n+1];
	maxValAfterI[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		maxValAfterI[i] = max(maxValAfterI[i+1], canTakeLeft[i]);
	}
    /*for (auto val : maxValAfterI) {
        cout << val << " ";
    }
    cout << "\n";*/
	int ans = 0;
	for (int l = 0; l < n; l++) {
		ans = max(ans, canTakeLeft[l] + maxValAfterI[l + canTakeLeft[l]]);
        //cout << canTakeLeft[l] + maxValAfterI[l + canTakeLeft[l]] << "\n";
	}
	cout << ans << endl;

	return 0;
}