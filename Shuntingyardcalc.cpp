#include <bits/stdc++.h>
using namespace std;

double operation(char c, double v1, double v2)
{
    switch(c) {
        case '+':
            return v1 + v2; break;
        case '-':
            return v1 - v2; break;
        case '*':
            return v1 * v2; break;
        case '/':
            return v1 / v2; break;
        case '^':
            return pow(v1, v2); break;
        /*case '!':
            return tgamma(v1 + 1); break;*/
        default:
            cout << "???\n";
    }

    return -1.0;
}

int main()
{
    vector<char> v {'+', '-', '*', '/', '^', '!'}; //operators
    map<char, int> m {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'^', 2}, {'(', 4}, {')', 4}}; //operator precedence
    map<char, char> assoc {{'+', 'l'},  {'-', 'l'}, {'*', 'l'}, {'/', 'l'}, {'^', 'r'}, {'(', 'l'}, {')', 'l'}}; //operator associativity

    stack<char> operate;
    queue<char> que;
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); ++i) {
        char const &c = input.at(i);
        if (isdigit(c)) {
            que.push(c);
        }
        //add function option later, not ready yet
        else if (find(v.begin(), v.end(), c) != v.end()) { //checking if c is an operator
            while (operate.top() != '(' && 
            (m[operate.top()] > m[c] || (m[c] == m[operate.top()] && assoc[c] == 'l'))) { //should be checking if c is left associative
                que.push(operate.top());
                operate.pop();
            }
            operate.push(c);
        }
        else if (c == '(') {
            operate.push(c);
        }
        else if (c == ')') {
            while (operate.top() != '(') {
                que.push(operate.top());
                operate.pop();
            }
            operate.pop();
            //add if statement for function
        }
    }
    for (int i = 0; i < operate.size(); ++i) {
        que.push(operate.top());
        operate.pop();
    }
    stack<double> newstack;
    for (int i = 0; i < que.size(); ++i) {
        if (isdigit(que.front())) {
            newstack.push((double) que.front());
        }
        //continue later
        else if (find(v.begin(), v.end(), que.front()) != v.end()) {
            double val1 = newstack.top();
            newstack.pop();
            double val2 = newstack.top();
            newstack.pop();
            newstack.push(operation(que.front(), val1, val2));
        }
    }
    
    cout << newstack.top() << "\n";
}