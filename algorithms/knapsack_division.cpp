#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using std::cout; using std::map; using std::vector; using std::sort; using std::pair;

void knapsack_optimize(int weight, vector<pair<double, double>> m)
{
    map<int, double> vd;
    int j = 0;
    for (auto i = m.begin(); i != m.end(); ++i) {
        vd.insert({j, (double) i->first / i->second});
        ++j;
    }
    vector<pair<int, double>> pairs; //pair of item number and profit to weight ratio, vector sorted by profit per item (descending) 
    for (auto itr = vd.begin(); itr != vd.end(); ++itr) {
        pairs.push_back(*itr);
    }
    sort(pairs.begin(), pairs.end(), [=](pair<int, double>& a, pair<int, double>& b)
    {
        return a.second > b.second;
    });
    vector<int> objectnums;
    vector<pair<double, double>> v;
    j = 0;
    int counter = weight;
    while (counter > 0 && j < pairs.size()) {
        objectnums.push_back(pairs[j].first);
        if (counter - m[pairs[j].first].second >= 0) {
            counter -= m[pairs[j].first].second;
            v.push_back(m[pairs[j].first]);
        }
        else {
            v.push_back({counter * pairs[j].second, counter});
            break;
        }
        ++j;
    }
    cout << "Objects: ";
    cout << objectnums[0] + 1;
    for (int i = 1; i < objectnums.size(); ++i) {
        cout << ", " << objectnums[i] + 1;
    } //sorted by descended profit to weight ratio
    cout << "\n";
    double totalp = 0, totalw = 0;
    for (auto val : v) {
        totalp += val.first;
        totalw += val.second;
    }
    cout << "total profit: " << totalp << "\n";
    cout << "total weight: " << totalw << "\n";
}

int main()
{
    vector<pair<double, double>> items {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}}; //profit, weight
    //assume the first parameter (knapsack max weight) is less than the total weight, otherwise the program is unnecessary
    knapsack_optimize(15, items);
}