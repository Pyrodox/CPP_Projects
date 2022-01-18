#include <bits/stdc++.h>
using namespace std;

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int main()
{
    int k, n, tmp;
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    fin >> k >> n;
    vector<vector<int>> vv(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> tmp;
            vv[i].push_back(tmp);
        }
    }
    unordered_map<vector<int>, vector<bool>, VectorHasher> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int ind, index2;
            for (int l = 0; l < n; ++l) {
                if (vv[j][l] == i) {
                    ind = l;
                }
            }
            for (int l = i + 1; l <= n; ++l) {
                for (int l2 = 0; l2 < n; ++l2) {
                    if (vv[j][l2] == l) {
                        index2 = l2;
                    }
                }
                if (ind < index2) {
                    m[{i, l}].push_back(true);
                }
                else if (ind > index2) {
                    m[{i, l}].push_back(false);
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (m[{i, j}] == vector<bool>(k, true) || m[{i, j}] == vector<bool>(k, false)) {
                ++cnt;
            }
        }
    }
    fout << cnt;
}