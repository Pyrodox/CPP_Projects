#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::vector; using std::sort; using std::remove_if;

vector<vector<double>> merge(vector<vector<double>>& v)
{
    if (v.size() == 1) {
        return v;
    }
    sort(v.begin(), v.end(), [=](vector<double>& a, vector<double>& b)
    {
        return a.size() < b.size();
    });
    vector<double> temp, a = v[0], b = v[1];
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            temp.push_back(a[i++]);
        }
        else {
            temp.push_back(b[j++]);
        }
    }
    for (; i < a.size(); ++i) {
        temp.push_back(a[i++]);
    }
    for (; j < b.size(); ++j) {
        temp.push_back(b[j++]);
    }
    v.erase(v.begin());
    v[0] = temp;

    return merge(v);
}

vector<double> merge_driver(vector<vector<double>>& v)
{
    return merge(v)[0];
}

int main()
{
    //assuming doubles inside vectors are already sorted
    vector<vector<double>> v {{1, 2, 3, 8, 10}, {0, 4, 6, 7, 11}, {5, 9, 12}};
    vector<double> v2 = merge_driver(v);
    for (auto val : v2) {
        cout << val << " ";
    }
}