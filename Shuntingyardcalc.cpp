#include <bits/stdc++.h>
using namespace std;

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

bool isNumber(const string& s)
{
   if(s.empty() || ::isspace(s[0]) || isalpha(s[0])) {
       return false;
   }
   char *p;
   strtod(s.c_str(), &p);

   return (*p == 0);
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
        /*case str2int("!"):
            return tgamma(v1 + 1); break;*/
        default:
            cout << "???\n";
    }

    return 1;
}
bool isoperator(string s)
{
    vector<string> v {"+", "-", "*", "/", "^"};

    return find(v.begin(), v.end(), s) != v.end();
}

bool isfunction(string s)
{
    vector<string> v {"sin", "cos", "tan", "ln", "log", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan"};

    return find(v.begin(), v.end(), s) != v.end();
}

double evaluate(queue<string> q)
{
    stack<double> newstack;
    const int qsize = q.size();
    for (int i = 0; i < qsize; ++i) {
        if (isNumber(q.front())) {
            newstack.push(stod(q.front()));
            q.pop();
        }
        //continue later
        else if (isoperator(q.front())) {
            double val1 = newstack.top();
            newstack.pop();
            double val2 = newstack.top();
            newstack.pop();
            newstack.push(operation(q.front(), val2, val1));
            q.pop();
        }
    }

    return newstack.top();
}

queue<string> parse(string input)
{
    map<string, int> m {{"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}, {"^", 2}, {"(", 4}, {")", 4}}; //operator precedence
    map<string, char> assoc {{"+", 'l'},  {"-", 'l'}, {"*", 'l'}, {"/", 'l'}, {"^", 'r'}, {"(", 'l'}, {")", 'l'}}; //operator associativity


    stack<string> operate;
    queue<string> que;

    for (int i = 0; i < input.length(); ++i) {
        string s = input.substr(i, 1);
        if (isNumber(s)) {
            que.push(s);
        }
        //edit mechanism of this part later
        else if (isfunction(s)) {
            operate.push(s);
        }
        else if (isoperator(s)) {
            while (operate.size() != 0 && operate.top() != "(" && (m[operate.top()] > m[s] || (m[s] == m[operate.top()] && assoc[s] == 'l'))) { 
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
    
    const int osize = operate.size();
    for (int i = 0; i < osize; ++i) {
        que.push(operate.top());
        operate.pop();
    }

    return que;
}

int main()
{
    cout << "Enter: \n";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    cout << "answer: \n";
    cout << evaluate(parse(input));
}