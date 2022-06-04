#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll l = n - 1, r = 2 * n;
        while (l < r && n > 1) {
            ll mid = l + (r - l + 1) / 2, threshold = ceil(mid / 2.0), edgemake = mid - threshold, vertexuse = n - threshold;
            bool check = true;
            if (vertexuse < 0 || (vertexuse * (vertexuse - 1)) / 2 < edgemake || edgemake > threshold) {
                check = false;
            }
            if (check) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
}