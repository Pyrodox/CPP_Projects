#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;

bool palindrome(string s)
{
    if (s.size() % 2 == 0) {
        string s2 = s.substr(s.size() / 2, s.size() / 2);
        reverse(s2.begin(), s2.end());

        return s.substr(0, s.size() / 2) == s2;
    }
    string s2 = s.substr(s.size() / 2 + 1, s.size() / 2);
    reverse(s2.begin(), s2.end());

    return s.substr(0, s.size() / 2) == s2; 
}

void check(vector<string> strsv, string s, ll k, ll ind, vector<string>& outpt)
{
    if (k >= 0) {
        for (ll k1 = k + 1; k1 < n; ++k1) {
            s += strsv[k1];
            if (palindrome(s)) {
                outpt[ind] = "YES";
                break;
            }
            else {
                check(strsv, s, k + 1, ind, outpt);    
            }
        }
    }
    
    return;
}

int main()
{
    cin >> t;
    vector<string> outpt(t);
    ll ind = 0;
    while (t--) {
        cin >> n;
        vector<string> strsv(n);
        for (ll i = 0; i < n; ++i) {
            cin >> strsv[i];
        }
        for (ll j = 0; j < n; ++j) {
            string s = strsv[j];
            check(strsv, s, 0, ind, outpt);
        }
        ++ind;
    }
    for (auto val : outpt) {
        if (val != "YES") {
            cout << "NO\n"; 
        }
        else {
            cout << val << "\n";
        }
    }
}