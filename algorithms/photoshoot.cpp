#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    fin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        fin >> b[i];
    }
    vector<int> a(n);
    bool flag = true;
    iota(a.begin(), a.end(), 1);
    do {
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] + a[i + 1] != b[i]) {
                break;
            }
            if (i == a.size() - 2) {
                for (int j = 0; j < a.size() - 1; ++j) {
                    fout << a[j] << " ";
                }
                fout << a[a.size() - 1];
                flag = false;
            }
        }
    } while (next_permutation(a.begin(), a.end()) && flag);
}