#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp1(const vector<ll>& a, const vector<ll>& b)
{
    return a[0] > b[0];
}

bool cmp2(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] < b[1];
}

bool cmp3(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] > b[1];
}

int main()
{
    ll n;
    ifstream cin("reduce.in");
    ofstream cout("reduce.out");
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    auto left = v, right = v, bot = v, top = v;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), cmp1);
    sort(bot.begin(), bot.end(), cmp2);
    sort(top.begin(), top.end(), cmp3);
    vector<ll> removed(n);
    ll ans = (right[0][0] - left[0][0]) * (top[0][1] - bot[0][1]);
    if (!ans) {
        cout << 0;
        return 0;
    }
    ll cnt = 0, leftit = 0, rightit = 0, botit = 0, topit = 0, leftit2 = 1, rightit2 = 1, botit2 = 1, topit2 = 1;
    while (cnt != 3) {
        vector<ll> tmpseen(n);
        while (removed[left[leftit][2]]) {
            ++leftit;
        }
        while (removed[right[rightit][2]]) {
            ++rightit;
        }
        while (removed[bot[botit][2]]) {
            ++botit;
        }
        while (removed[top[topit][2]]) {
            ++topit;
        }
        while (removed[left[leftit2][2]]) {
            ++leftit2;
        }
        while (removed[right[rightit2][2]]) {
            ++rightit2;
        }
        while (removed[bot[botit2][2]]) {
            ++botit2;
        }
        while (removed[top[topit2][2]]) {
            ++topit2;
        }
        tmpseen[left[leftit][2]]++;
        tmpseen[right[rightit][2]]++;
        tmpseen[top[topit][2]]++;
        tmpseen[bot[botit][2]]++;
        ll vertical = top[topit][1] - bot[botit][1], horizontal = right[rightit][0] - left[leftit][0];
        ll mxsubt = (left[leftit2][0] - left[leftit][0]) * vertical;
        ll currentremove = left[leftit][2];

        ll rightside = right[rightit][0] - right[rightit2][0];
        ll topside = top[topit][1] - top[topit2][1];
        ll botside = bot[botit2][1] - bot[botit][1];
        ll leftside = left[leftit2][0] - left[leftit][0];

        if (rightside * vertical > mxsubt) {
            mxsubt = rightside * vertical;
            currentremove = right[rightit][2];
        }
        if (topside * horizontal > mxsubt) {
            mxsubt = topside * horizontal;
            currentremove = top[topit][2];
        }
        if (botside * horizontal > mxsubt) {
            mxsubt = botside * horizontal;
            currentremove = bot[botit][2];
        }
        if (tmpseen[bot[botit][2]] == 2 && tmpseen[left[leftit][2]] == 2) {
            if (leftside * vertical + horizontal * botside - leftside * botside > mxsubt) {
                currentremove = bot[botit][2];
                mxsubt = leftside * vertical + horizontal * botside - leftside * botside;
            }
        }
        if (tmpseen[right[rightit][2]] == 2 && tmpseen[bot[botit][2]] == 2) {
            if (rightside * vertical + horizontal * botside - rightside * botside > mxsubt) {
                currentremove = bot[botit][2];
                mxsubt = rightside * vertical + horizontal * botside - rightside * botside;
            }
        }
        if (tmpseen[top[topit][2]] == 2 && tmpseen[left[leftit][2]] == 2) {
            if (leftside * vertical + horizontal * topside - leftside * topside > mxsubt) {
                currentremove = top[topit][2];
                mxsubt = leftside * vertical + horizontal * topside - leftside * topside;
            }
        }
        if (tmpseen[right[rightit][2]] == 2 && tmpseen[top[topit][2]] == 2) {
            if (rightside * vertical + horizontal * topside - rightside * topside > mxsubt) {
                currentremove = top[topit][2];
                mxsubt = rightside * vertical + horizontal * topside - rightside * topside;
            }
        }
        ++cnt;
        removed[currentremove] = 1;
        ans -= mxsubt;
    }
    cout << ans;
}