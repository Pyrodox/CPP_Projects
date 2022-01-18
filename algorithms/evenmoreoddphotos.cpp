#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, o = 0, e = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x % 2 == 0) {
            ++e;
        }
        else {
            ++o;
        }
    }
    while (o > e) {
        o -= 2;
        ++e;
    }
    if (e > o + 1) {
        e = o + 1;
    }
    cout << e + o;
}