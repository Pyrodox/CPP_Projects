#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, tmp;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    
}