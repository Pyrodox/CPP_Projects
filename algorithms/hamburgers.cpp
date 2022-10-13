#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    ll bur = 0, sau = 0, chee = 0, currentbur, currentsau, currentchee, bcost, scost, ccost, money;
    bool a = false, b = false, c = false;
    cin >> s >> currentbur >> currentsau >> currentchee >> bcost >> scost >> ccost >> money;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            ++bur;
            a = true;
        }
        else if (s[i] == 'S') {
            ++sau;
            b = true;
        }
        else {
            ++chee;
            c = true;
        }
    }
    ll currentburmake, currentsaumake, currentcheemake, total = 0;
    if (a) {
        currentburmake = currentbur / bur;
        total += bur * bcost;
    }
    else {
        currentburmake = 99999999999999999;
    }
    if (b) {
        currentsaumake = currentsau / sau;
        total += sau * scost;
    }
    else {
        currentsaumake = 99999999999999999;
    }
    if (c) {
        currentcheemake = currentchee / chee;
        total += chee * ccost;
    }
    else {
        currentcheemake = 9999999999999999;
    }
    ll ans = min(currentburmake, min(currentsaumake, currentcheemake));
    currentbur -= ans * bur;
    currentsau -= ans * sau;
    currentchee -= ans * chee;
    ll reqb, reqs, reqc;
    if (a) {
        reqb = ceil((double)currentbur / bur);
    }
    else {
        reqb = 0;
    }
    if (b) {
        reqs = ceil((double)currentsau / sau);
    }
    else {
        reqs = 0;
    }
    if (c) {
        reqc = ceil((double)currentchee / chee);
    }
    else {
        reqc = 0;
    }
    ll nextreq = max(reqb, max(reqs, reqc));
    if (max((ll)0, (nextreq * bur - currentbur)) * bcost + scost * max((ll)0, (nextreq * sau - currentsau)) + ccost * max((ll)0, (nextreq * chee - currentchee)) <= money) {
        ans += nextreq;
        money -= max((ll)0, bcost * (nextreq * bur - currentbur));
        money -= max((ll)0, scost * (nextreq * sau - currentsau));
        money -= max((ll)0, ccost * (nextreq * chee - currentchee));
        ans += money / total;
    }
    else {
        ll l = 0, r = nextreq;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (max((ll)0, (mid * bur - currentbur)) * bcost + scost * max((ll)0, (mid * sau - currentsau)) + ccost * max((ll)0, (mid * chee - currentchee)) <= money) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        ans += max((ll)0, l - 1);
    }
    cout << ans;
}