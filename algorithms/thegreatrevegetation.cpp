#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    fin >> n >> m;
    vector<ll> fields = {1};
    ll favoritepastures[m][2];
    for (int i = 0; i < m; ++i) {
        fin >> favoritepastures[i][0] >> favoritepastures[i][1];
    }
    for (int i = 2; i <= n; ++i) {
        vector<ll> grasstypes = {1, 2, 3, 4};
        for (int j = i - 1; j > 0; --j) {
            for (int k = 0; k < m; ++k) {
                if ((favoritepastures[k][0] == i && favoritepastures[k][1] == j) || (favoritepastures[k][0] == j && favoritepastures[k][1] == i)) {
                    grasstypes[fields[j - 1] - 1] = 0;
                }
            }
        }
        for (auto val : grasstypes) {
            if (val != 0) {
                fields.push_back(val);
                break;
            }
        }
    }
    for (auto val : fields) {
        fout << val;
    }
}