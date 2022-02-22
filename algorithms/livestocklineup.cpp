#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    fin >> n;
    string v[n][2];
    string name1, must, be, milked, beside, name2;
    for (int i = 0; i < n; ++i) {
        fin >> name1 >> must >> be >> milked >> beside >> name2;
        v[i][0] = name1;
        v[i][1] = name2;
    }
    vector<string> names = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    do {
        vector<ll> cntvec(n);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    if ((v[j][0] == names[i] && v[j][1] == names[i + 1]) || (v[j][1] == names[i] && v[j][0] == names[i + 1])) {
                        cntvec[j] = 1;
                    }
                }
                else if (i == 7) {
                    if ((v[j][0] == names[i] && v[j][1] == names[i - 1]) || (v[j][1] == names[i] && v[j][0] == names[i - 1])) {
                        cntvec[j] = 1;
                    }
                }
                else if ((v[j][0] == names[i] && (v[j][1] == names[i - 1] || v[j][1] == names[i + 1])) || (v[j][1] == names[i] && (v[j][0] == names[i - 1] || v[j][0] == names[i + 1]))) {
                    cntvec[j] = 1;
                }
            }
        }
        if (count(cntvec.begin(), cntvec.end(), 0) == 0) {
            for (auto val : names) {
                fout << val << "\n";
            }

            return 0;
        }
    } while (next_permutation(names.begin(), names.end()));
}