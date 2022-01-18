#include <bits/stdc++.h>
using namespace std;

/*long long int countamt(vector<long long int> v1, vector<long long int> v2, long long int mx, long long int iteramt)
{
    if (mx == 1) {
        return 1;
    } 
    long long int times = 0;
    for (long long int i = 0; i < v2.size(); ++i) {
        if (v2[i] >= mx) {
            ++times;
        }
    }

    return (times - iteramt) * countamt(v1, v2, v1[v1.size() - 2 - iteramt], iteramt + 1);
}*/

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> v1(n), v2(n);
    for (long long int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    for (long long int i = 0; i < n; ++i) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long int mx = v1[v1.size() - 1];
    long long int total = 1;
    for (long long int i = 0; i < n; ++i) {
        long long int times = 0;
        for (long long int j = 0; j < v2.size(); ++j) {
            if (v2[j] >= mx) {
                ++times;
            }
        }
        mx = v1[v1.size() - 2 - i];
        if (times - i != 0) {
            total *= times - i;
        }
        else {
            break;
        }
    }
    cout << total;
}