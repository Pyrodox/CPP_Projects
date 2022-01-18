#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string a, b;
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    fin >> n >> a >> b;
    int ans = 0;
    bool mismatched = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (!mismatched) {
                mismatched = true;
                ++ans;
            }
        }
        else {
            mismatched = false;
        }
    }
    fout << ans;
}