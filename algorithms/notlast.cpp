#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    fin >> n;
    string name;
    unordered_map<string, int> u {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    for (int i = 0; i < n; ++i) {
        fin >> name;
        fin >> m;
        u[name] += m;
    }
    vector<int> v;
    for (auto val : u) {
        v.push_back(val.second);
    }
    sort(v.begin(), v.end());
    v.erase(remove(v.begin(), v.end(), v[0]), v.end());
    int cnt = 0;
    string finname;
    for (auto val : u) {
        if (val.second == v[0]) {
            ++cnt;
            finname = val.first;
        }
    }
    if (cnt > 1 || v.size() == 0) {
        fout << "Tie\n";
    }
    else {
        fout << finname << "\n";
    }
}