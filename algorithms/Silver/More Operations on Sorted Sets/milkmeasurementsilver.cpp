#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("measurement.in" , "r", stdin );
  freopen("measurement.out", "w", stdout);
  int n, g;
  cin >> n >> g;
  vector<vector<int>> v(n);
  for (auto &i : v) {
    int day, id, milk;
    cin >> day >> id >> milk;
    i = vector<int>({day, id, milk});
  }
  sort(v.begin(), v.end());
  int ans = 0, maxMilk = 0, cnt = n;
  map<int,int> mem; multiset<int> milk;
  for (int i = 1; i <= n; i++) {
    mem[i] = 0;
    milk.insert(0);
  }
  for (auto &i : v) {
    int id = i[1], addMilk = i[2], oldMilk = mem[id];
    milk.erase(milk.find(oldMilk));
    mem[id] += addMilk;
    milk.insert(mem[id]);
    if (mem[id] > maxMilk) {
      if (cnt != 1 || oldMilk != maxMilk) ans++;
      maxMilk = mem[id];
      cnt = 1;
    }
    else if (mem[id] == maxMilk) {
      cnt++;
      ans++;
    }
    else if (oldMilk == maxMilk) {
      maxMilk = *milk.rbegin();
      int wascnt = cnt;
      cnt = milk.count(maxMilk);
      if (wascnt != 1 || cnt != 1 || mem[id] != maxMilk) ans++;
    }
  }
  cout << ans << '\n';
}