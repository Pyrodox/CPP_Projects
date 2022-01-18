#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    fin >> n;
    vector<vector<int>> v(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        fin >> v[i][0] >> v[i][1];
    }
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x1 = v[i][0], y1 = v[i][1];
                int x2 = v[j][0], y2 = v[j][1];
                int x3 = v[k][0], y3 = v[k][1];
                long long int area, b = 0, h = 0;
                if (x1 == x2) {
                    h = abs(y2 - y1);
                }
                else if (x1 == x3) {
                    h = abs(y3 - y1); 
                }
                else if (x2 == x3) {
                    h = abs(y3 - y2);
                }
                if (y1 == y2) {
                    b = abs(x2 - x1);
                }
                else if (y1 == y3) {
                    b = abs(x3 - x1); 
                }
                else if (y2 == y3) {
                    b = abs(x3 - x2);
                }
                ans = max(ans, b * h);
            }
        }
    }
    fout << ans;
}