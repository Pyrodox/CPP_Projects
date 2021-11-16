#include <bits/stdc++.h>
using namespace std;

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

bool isNumber(const std::string& s){
   if(s.empty() || std::isspace(s[0]) || std::isalpha(s[0])) return false ;
   char * p ;
   strtod(s.c_str(), &p) ;
   return (*p == 0) ;
}

double operation(string s, double v1, double v2)
{
    switch(str2int(s.c_str())) {
        case str2int("+"):
            return v1 + v2; break;
        case str2int("-"):
            return v1 - v2; break;
        case str2int("*"):
            return v1 * v2; break;
        case str2int("/"):
            return v1 / v2; break;
        case str2int("^"):
            return pow(v1, v2); break;
        /*case '!':
            return tgamma(v1 + 1); break;*/
        default:
            cout << "???\n";
    }

    return 1;
}
bool isoperator(string s)
{
    vector<char> v {'+', '-', '*', '/', '^'}; //operators

    return find(v.begin(), v.end(), s) != v.end();
}

double evaluate(queue<string> q)
{
    stack<double> newstack;
    for (int i = 0; i < q.size(); ++i) {
        if (isNumber(q.front())) {
            newstack.push(stod(q.front()));
        }
        //continue later
        else if (isoperator(q.front())) {
            double val1 = newstack.top();
            newstack.pop();
            double val2 = newstack.top();
            newstack.pop();
            newstack.push(operation(q.front(), val1, val2));
        }
    }

    return newstack.top();
}

double parse(string input)
{
    map<string, int> m {{"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}, {"^", 2}, {"(", 4}, {")", 4}}; //operator precedence
    map<string, char> assoc {{"+", 'l'},  {"-", 'l'}, {"*", 'l'}, {"/", 'l'}, {"^", 'r'}, {"(", 'l'}, {")", 'l'}}; //operator associativity

    stack<string> operate;
    queue<string> que;

    for (int i = 0; i < input.length(); ++i) {
        string s = input.substr(i, i + 1);
        if (isNumber(s)) {
            que.push(s);
        }
        //add function option later, not ready yet
        else if (isoperator(s)) { //checking if c is an operator
            while (operate.size() != 0 && operate.top() != "(" && (m[operate.top()] > m[s] || ((m[s] == m[operate.top()] && assoc[s] == 'l')))) { 
                que.push(operate.top());
                operate.pop();
            }
            operate.push(s);
        }
        else if (s == "(") {
            operate.push(s);
        }
        else if (s == ")") {
            while (operate.top() != "(") {
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

    return evaluate(que);
}

int main()
{
    cout << "Enter: ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    
    cout << parse(input) << "\n";
}
