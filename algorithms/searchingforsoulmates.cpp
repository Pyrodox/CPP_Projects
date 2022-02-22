#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v;
    for (int i = 0; i < n; ++i) {
        vector<ll> v2(2);
        cin >> v2[0] >> v2[1];
        v.push_back(v2);
    }
    for (int i = 0; i < n; ++i) {
        ll cnt = 0;
        while (v[i][0] != v[i][1]) {
            if (v[i][0] > v[i][1]) {
                if (v[i][0] % 2 == 0) {
                    v[i][0] /= 2;
                    ++cnt;
                }
                else {
                    v[i][0]++;
                    v[i][0] /= 2;
                    cnt += 2;
                }
            }
            else {
                ll numfind = v[i][1] / 2;
                if (v[i][0] * 2 > v[i][1]) {    
                    if (v[i][1] - v[i][0] < ) {
                        
                    }
                }
                else {
                    if (v[i][1] % 2 == 0) {
                        if (v[i][1] / 2 - v[i][0] < v[i][1] - v[i][0] * 2) {
                            ll a = v[i][1] / 2 - v[i][0];
                            v[i][0] += a;
                            v[i][0] *= 2;
                            cnt += a + 1;
                        }
                        else {
                            ll a = v[i][1] - v[i][0] * 2;
                            v[i][0] *= 2;
                            v[i][0] += a;
                            cnt += a + 1;
                        }
                    }
                    else {
                        if ((v[i][1] - 1) / 2 - v[i][0] < v[i][1] - v[i][0] * 2) {
                            ll b = (v[i][1] - 1) / 2 - v[i][0];
                            v[i][0] += b;
                            v[i][0] *= 2;
                            ++v[i][0];
                            cnt += b + 2;
                        }
                        else {
                            ll b = v[i][1] - v[i][0] * 2;
                            v[i][0] *= 2;
                            v[i][0] += b;
                            cnt += b + 1;
                        }
                    }
                }
            }
            cout << v[i][0] << "\n";
        }
        cout << cnt << "\n";
    }
}