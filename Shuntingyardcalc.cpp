#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v {'+', '-', '*', '/', '^', '!'}; //operators
    map<char, int> m {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'^', 2}, {'!', 3}, {'(', 4}, {')', 4}}; //operator precedence
    map<char, char> assoc {{'+', 'l'},  {'-', 'l'}, {'*', 'l'}, {'/', 'l'}, {'^', 'r'}, {'!', 'l'}, {'(', 'l'}, {')', 'l'}}; //operator associativity
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
        else if (find(v.begin(), v.end(), c) != v.end()) { //checking if c is an operator
            while (operate.top() != '(' && 
            (m[operate.top()] > m[c] || (m[c] == m[operate.top()] && assoc[c] == 'l'))) { //should be checking if c is left associative

            }
        }
    }
}