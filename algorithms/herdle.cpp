#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<char> answer(9);
    vector<char> guess(9);
    unordered_map<char, ll> answerm, guessm; 
    for (int i = 0; i < 9; ++i) {
        char tmp;
        cin >> tmp;
        answer[i] = tmp;
        answerm[tmp]++;
    }
    for (int i = 0; i < 9; ++i) {
        char tmp;
        cin >> tmp;
        guess[i] = tmp;
        guessm[tmp]++;
    }
    ll greencnt = 0, yellowcnt = 0;
    for (int i = 0; i < 9; ++i) {
        if (answer[i] == guess[i]) {
            ++greencnt;
            answerm[answer[i]]--;
            guessm[answer[i]]--;
        }
    }
    vector<char> alp = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < alp.size(); ++i) {
        if (answerm[alp[i]] != 0 && guessm[alp[i]] != 0) {
            yellowcnt += min(answerm[alp[i]], guessm[alp[i]]);
        }
    }
    cout << greencnt << "\n" << yellowcnt;
}