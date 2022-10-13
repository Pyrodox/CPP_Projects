#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<char> stringtobuild, firstletterappearance(1001);
    vector<ll> charsfound(1);
    ll current = 1;
    cout << "? 1 " << current << "\n";
    fflush(stdout);
    char c;
    cin >> c;
    firstletterappearance[1] = c;
    charsfound.push_back(1);
    stringtobuild.push_back(c);
    ++current;
    while (stringtobuild.size() != n) {
        cout << "? 2 1 " << current << "\n";
        fflush(stdout);
        ll amt;
        cin >> amt;
        if (amt == charsfound.size()) {
            cout << "? 1 " << current << "\n";
            fflush(stdout);
            char c;
            cin >> c;
            firstletterappearance[current] = c;
            charsfound.push_back(current);
            stringtobuild.push_back(c);
        }
        else {
            ll l = 1, r = charsfound.size();
            while (l < r) {
                ll mid = l + (r - l) / 2;
                cout << "? 2 " << charsfound[mid] << " " << current << "\n";
                fflush(stdout);
                ll amt;
                cin >> amt;
                if (amt <= charsfound.size() - mid) {
                    l = mid + 1;
                }   
                else {
                    r = mid;
                }
            }
            stringtobuild.push_back(firstletterappearance[charsfound[max((ll)1, l - 1)]]);
            firstletterappearance[current] = stringtobuild[current - 1];
            charsfound.erase(charsfound.begin() + l - 1);
            charsfound.push_back(current); 
        }
        ++current;
    }
    cout << "! ";
    for (ll i = 0; i < n; ++i) {
        cout << stringtobuild[i];
    }
}