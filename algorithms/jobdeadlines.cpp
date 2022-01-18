#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using std::cout; using std::vector; using std::sort; using std::pair; using std::max;

void sequence(vector<pair<double, int>> v)
{
    vector<pair<int, pair<double, int>>> v2;
    for (int i = 1; i <= v.size(); ++i) {
        v2.push_back({i, v[i - 1]});
    }
    sort(v2.begin(), v2.end(), [=](pair<int, pair<double, int>>& a, pair<int, pair<double, int>>& b)
    {
        return a.second.first > b.second.first;
    });
    int maxdeadline = 0;
    for (auto val : v2) {
        maxdeadline = max(maxdeadline, val.second.second);
    }
    vector<int> jobs(maxdeadline);
    int totalprofit = 0;
    for (auto val : v2) {
        for (int i = val.second.second; i > 0; --i) {
            if (jobs[i - 1] == 0) {
                totalprofit += val.second.first;
                jobs[i - 1] = val.first;
                break;
            }
        }
    }
    for (auto val : jobs) {
        cout << val << " ";
    }
    cout << "\n" << totalprofit;
}

int main()
{
    //assuming unsorted and max deadline not given; example is sorted
    vector<pair<double, int>> v{{35, 3}, {30, 4}, {25, 4}, {20, 2}, {15, 3}, {12, 1}, {5, 2}}; //profits, deadlines
    sequence(v);
}