#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, m;
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> x >> y >> m;
    int mx = 0;
    for (int i = 0; i * x <= m; ++i) {
        for (int j = 0; j * y  + i * x <= m; ++j) {
            if (i * x + j * y > mx) {
                mx = i * x + j * y;
            }
        }
    }

    fout << mx;
}