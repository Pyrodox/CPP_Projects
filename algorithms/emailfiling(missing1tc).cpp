#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

int main()
{
    ll n, t, m, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        vector<ll> emailloc(n + 1), folderquota(m + 1);
        for (ll i = 0; i < n; ++i) {
            cin >> emailloc[i + 1];
            ++folderquota[emailloc[i + 1]];
        }
        ll emailbound = k, folderbound = k;
        vector<ll> foldersavail(m + 1);
        set<ll> emailsavail;
        for (ll i = 1; i <= k; ++i) {
            foldersavail[i] = 1;
            emailsavail.insert(i);
        }
        vector<ll> emailsinfolder(m + 1), foldergone(n + 1);
        ll filedemails = 0, topfolder = 1;
        bool flag = true;
        vector<ll> emailsscrolledpast;
        while (filedemails != n && flag) {
            bool nonefiled = true, recentlyfound = false;;
            for (auto it = emailsavail.begin(); it != emailsavail.end(); ++it) {
                if (recentlyfound) {
                    --it;
                    recentlyfound = false;
                }
                if (foldersavail[emailloc[*it]]) {
                    nonefiled = false;
                    recentlyfound = true;
                    ++filedemails;
                    ++emailsinfolder[emailloc[*it]];
                    if (++emailbound <= n) {
                        emailsavail.insert(emailbound);
                    }
                    emailsavail.erase(it++);
                    if (!emailsavail.size()) {
                        break;
                    }
                }
                else if (foldergone[emailloc[*it]]) {
                    flag = false;
                    break;
                }
            }
            while (emailsavail.size() < k && emailsscrolledpast.size()) {
                emailsavail.insert(emailsscrolledpast[emailsscrolledpast.size() - 1]);
                emailsscrolledpast.pop_back();
            }
            if (emailsinfolder[topfolder] == folderquota[topfolder] && folderbound < m) {
                foldergone[topfolder]++;
                foldersavail[topfolder++] = 0;
                foldersavail[++folderbound] = 1;
            }
            else if (emailbound < n) {
                if (foldergone[*emailsavail.begin()]) {
                    flag = false;
                    break;
                }
                emailsscrolledpast.push_back(*emailsavail.begin());
                emailsavail.erase(emailsavail.begin());
                emailsavail.insert(++emailbound);
            }
            else if (nonefiled && emailbound >= n && filedemails != n) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}