#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, m;
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin >> n >> d >> m;
    vector<int> jobs(m);
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> val;
    for (int i = 1; i <= m; ++i) {
        int a;
        cin >> a;
        jobs[i - 1] = a;
        mp[a].push_back(i);
    }
    sort(jobs.begin(), jobs.end());
    vector<vector<int>> ans;
    int l = 1, r = m;
    while (l < r) {
        int mid = l + (r - l) / 2, start = 0;
        //cout << "testing mid: " << mid << "\n";
        bool check = true;
        vector<vector<int>> jobstmp(n);
        for (int i = 0; i < n && check; ++i) {
            //cout << i << "\n";
            for (int j = 0; j < mid && start <= m - 1; ++j) {
                //cout << "bat\n";
                if (jobs[start] <= i + 1 && i + 1 - jobs[start] <= d) {
                    jobstmp[i].push_back(jobs[start]);
                    ++start;
                    //cout << "at\n";
                }
                else if (i + 1 - jobs[start] > d) {
                    check = false;
                    break;
                }
                else {
                    break;
                }
            }
        }
        /*for (auto val : jobstmp) {
            for (int i : val) {
                cout << i << " ";
            }
            cout << "\n";
        }*/
        //cout << "start: " << start << " check: " << "\n";
        if (check && start == m) {
            //cout << "r from " << r << " to r -> " << mid << "\n";
            r = mid;
            ans = jobstmp;
        }
        else {
            //cout << "l from " << l << " to l -> " << mid << " + 1\n";
            l = mid + 1;
        }
    }
    cout << l << "\n";
    for (auto i : ans) {
        for (int j : i) {
            cout << mp[j][val[j]] << " ";
            ++val[j];
        }
        cout << "0\n";
    }
}