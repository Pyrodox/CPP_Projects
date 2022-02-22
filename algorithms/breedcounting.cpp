#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    fin >> n >> q;
    ll cowbreeds[n], q1[q], q2[q];
    for (int i = 0; i < n; ++i) {
        fin >> cowbreeds[i];
    }
    for (int i = 0; i < q; ++i) {
        fin >> q1[i] >> q2[i];
    }
    vector<vector<ll>> prefix(n + 1);
    prefix[0] = {0, 0, 0};
    for (int i = 1; i < n + 1; ++i) {
        prefix[i] = prefix[i - 1];
        if (cowbreeds[i - 1] == 1) {
            prefix[i][0]++;
        }
        else if (cowbreeds[i - 1] == 2) {
            prefix[i][1]++;
        }
        else {
            prefix[i][2]++;
        }
    }
    for (int i = 0; i < q; ++i) {
        fout << prefix[q2[i]][0] - prefix[q1[i] - 1][0] << " " << prefix[q2[i]][1] - prefix[q1[i] - 1][1] << " " << prefix[q2[i]][2] - prefix[q1[i] - 1][2] << "\n";
    }
}