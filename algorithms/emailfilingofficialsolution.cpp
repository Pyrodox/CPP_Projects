#include <bits/stdc++.h>
 
using namespace std;
 
void rsolve() {
  int nfolder, nemail, windowsz;
  cin >> nfolder >> nemail >> windowsz;
  vector<int> emailtofolder(nemail);
  vector<vector<int>> foldertoemail(nfolder);
  vector<vector<int>> filetiming(nfolder);
  vector<bool> filed(nemail);
  vector<bool> skipped(nemail);
  vector<bool> inwindow(nemail);
  for(int i = 0; i < nemail; i++) {
    cin >> emailtofolder[i];
    filetiming[max(0, --emailtofolder[i] - windowsz + 1)].push_back(i);
    foldertoemail[emailtofolder[i]].push_back(i);
  }
  int currentemail = 0;
  int lhsemail = 0;
  int numinwindow = 0;
  int rhsemail = nemail-1;
  auto fileemail = [&](int id) -> void {
    if(inwindow[id]) {
      inwindow[id] = false;
      numinwindow--;
    }
    assert(!filed[id]);
    filed[id] = true;
  };
  int bottom = 0;
  for(int i = 0; i < nfolder; i++) {
    // file anything that can be newly filed
    if(i > bottom && i + windowsz <= nfolder) bottom++;
    for(int out: filetiming[i]) if(inwindow[out]) fileemail(out);
    while(foldertoemail[i].size() && currentemail <= foldertoemail[i].back()) {
      // the window is full so in order to consider this email, we must scroll past the current one
      if(numinwindow == windowsz) {
        while(!inwindow[lhsemail]) lhsemail++;
        skipped[lhsemail] = true;
        inwindow[lhsemail] = false;
        numinwindow--;
      }
      if(emailtofolder[currentemail] >= i && emailtofolder[currentemail] <= i + windowsz - 1) {
        // can file
        filed[currentemail++] = true;
        continue;
      }
      inwindow[currentemail++] = true; numinwindow++;
    }
    // scroll through emails that would be implicitly loaded
    while(currentemail < nemail && numinwindow < windowsz) {
      if(emailtofolder[currentemail] >= i && emailtofolder[currentemail] <= i + windowsz - 1) {
        // can file
        filed[currentemail++] = true;
        continue;
      }
      inwindow[currentemail++] = true; numinwindow++;
    }
    // scroll up emails since we've hit the end
    if(currentemail == nemail) {
      while(numinwindow < windowsz) {
        if(rhsemail < 0) break;
        if(!skipped[rhsemail]) {
          rhsemail--;
          continue;
        }
        if(emailtofolder[rhsemail] < bottom) {
          cout << "NO\n";
          return;
        }
        if(emailtofolder[rhsemail] <= bottom + windowsz - 1) {
          filed[rhsemail--] = true;
          continue;
        }
        inwindow[rhsemail--] = true; numinwindow++;
      }
    }
  }
  for(auto out: filed) {
    if(!out) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
 
void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}