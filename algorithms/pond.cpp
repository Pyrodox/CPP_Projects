#include <bits/stdc++.h>
using namespace std;
 
#define N 805
#define MAX_A 1000000000
#define rep(i, n) for(int i = 0; i < n; ++i)
 
int main(void) {
	int n, k, lim;
	int a[N][N];
	int s[N][N];
	rep(i, N) {
		s[i][0] = 0;
		s[0][i] = 0;
	}
	int ng = -1;
	int ok = MAX_A;
	int mid;
	bool ext;
	cin >> n >> k;
	lim = ((k*k) / 2) + 1;
	rep(i, n) {
		rep(j, n)cin >> a[i][j];
	}
	while ((ng + 1) < ok) {
		mid = (ng + ok) / 2;
		rep(i, n) {
			rep(j, n) {
				s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j];
				if (a[i][j] > mid)s[i + 1][j + 1]++;
			}
		}
		ext = false;
		rep(i, n - k + 1) {
			rep(j, n - k + 1) {
				if ((s[i + k][j + k] + s[i][j] - s[i][j + k] - s[i + k][j]) < lim)ext = true;
			}
		}
		if (ext)ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}