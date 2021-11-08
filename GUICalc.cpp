#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v {'+', '-', '*', '/', '^', '!'};
    //make a map of char and int for operator precedence
    string input;
    stack<char> operate;
    queue<int> que;
    cin >> input;
    for (int i = 0; i < input.length(); ++i) {
        char const &c = input.at(i);
        if (isdigit(c)) {
            que.push(int(c));
        }
        //add function option later, not ready yet
        else if (find(v.begin(), v.end(), c) != v.end()) {
            while (operate.top() != '(' && (operate.top() > c || c == operate.top())) {

            }
        }
    }
}