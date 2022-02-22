#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll v[3];
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    fin >> v[0] >> v[1] >> v[2];
    if (min(abs(v[0] - v[1]) - 1, abs(v[1] - v[2]) - 1) == 1) {
        fout << 1 << "\n";
    }
    else if (abs(v[0] - v[1]) - 1 == 0 && abs(v[1] - v[2]) - 1 == 0) {
        fout << 0 << "\n";
    }
    else {
        fout << 2 << "\n";
    }
    fout << max(abs(v[0] - v[1]) - 1, abs(v[1] - v[2]) - 1);
}