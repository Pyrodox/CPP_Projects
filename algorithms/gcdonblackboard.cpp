#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 1e5 + 5;

int arr[maxN];
int prefGcd[maxN]; //prefGcd[i] = GCD of a1,a2, ..., ai
int suffGcd[maxN]; //suffGcd[i] = GCD of ai, ai+1, ..., an
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for(int i = 1; i <= N; ++i)cin >> arr[i];

	prefGcd[0] = 0;
	suffGcd[N + 1] = 0;

	for(int i = 1; i <= N; ++i){
		prefGcd[i] = __gcd(prefGcd[i - 1], arr[i]);
	}

	for(int i = N; i >= 1; --i){
		suffGcd[i] = __gcd(suffGcd[i + 1], arr[i]);
	}
    for (ll i = 0; i <= N; ++i) {
        cout << prefGcd[i] << " ";
    }
    cout << "\n";
    for (ll i = 0; i <= N; ++i) {
        cout << suffGcd[i] << " ";
    }
	int res = 0;
	for(int i = 1; i <= N; ++i){
		res = max(res, __gcd(prefGcd[i - 1], suffGcd[i + 1]));
	}
	cout << res;
}