#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll ans = 0, prefix = 0;
    map<ll, int> m;
    m[0] = 1;
    for (int val : v) {
        prefix += val;
        ans += m[prefix - k];
        m[prefix]++;
    }
    cout << ans;
}