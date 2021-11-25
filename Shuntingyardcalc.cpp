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
    switch (str2int(s.c_str())) {
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
        default:
            cout << "???\n";
    }

    return 1;
}

double func(string s, double v, double v2 = 0)
{
    switch (str2int(s.c_str())) {
        case str2int("sin"):
            return sin(v); break;
        case str2int("cos"):
            return cos(v); break;
        case str2int("tan"):
            return tan(v); break;
        case str2int("sec"):
            return 1 / cos(v); break;
        case str2int("csc"):
            return 1 / sin(v); break;
        case str2int("cot"):
            return 1 / tan(v); break;
        case str2int("ln"):
            return log(v); break;
        case str2int("log10"):
            return log(v) / log(10); break;
        case str2int("log"):
            return log(v) / log(v2); break;
        case str2int("sqrt"):
            return sqrt(v); break;
        case str2int("cbrt"):
            return cbrt(v); break;
        case str2int("root"):
            return pow(v2, 1.0 / v); break;
        case str2int("abs"):
            return abs(v); break;
        case str2int("asin"):
            return asin(v); break;
        case str2int("acos"):
            return acos(v); break;
        case str2int("atan"):
            return atan(v); break;
        case str2int("asec"):
            return acos(1 / v); break;
        case str2int("acsc"):
            return asin(1 / v); break;
        case str2int("acot"):
            return atan(1 / v); break;

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
    vector<string> v {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot", "log", "root"};

    return find(v.begin(), v.end(), s) != v.end();
}

int paramamnt(string s)
{
    vector<string> v1 {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot"};
    vector<string> v2 {"log", "root"};

    if (find(v1.begin(), v1.end(), s) != v1.end()) {
        return 1;
    }

    return 2;
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
        else if (isoperator(q.front())) {
            double val1 = newstack.top();
            newstack.pop();
            double val2 = newstack.top();
            newstack.pop();
            newstack.push(operation(q.front(), val2, val1));
            q.pop();
        }
        else if (isfunction(q.front()) && paramamnt(q.front()) == 1) {
            double v = newstack.top();
            newstack.pop();
            newstack.push(func(q.front(), v));
            q.pop();
        }
         else if (isfunction(q.front()) && paramamnt(q.front()) == 2) {
            double v = newstack.top();
            newstack.pop();
            double v2 = newstack.top();
            newstack.pop();
            newstack.push(func(q.front(), v, v2));
            q.pop();
        }
    }

    return newstack.top();
}

vector<string> lex(string input)
{
    string buffer = "";
    vector<string> output;
    for (int i = 0; i < input.length(); ++i) {
        if (isoperator(input.substr(i, 1)) || input.substr(i, 1) == "(" || input.substr(i, 1) == ")") {
            output.push_back(buffer);
            output.push_back(input.substr(i, 1));
            buffer = "";
        }
        else if (input.substr(i, 1) == ",") {
            output.push_back(buffer);
            buffer = "";
        }
        else {
            buffer += input.substr(i, 1);
        }
    }
    output.push_back(buffer);
    output.erase(remove(output.begin(), output.end(), ""), output.end());
    
    return output;
}

queue<string> parse(string input)
{
    map<string, int> m {{"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}, {"^", 2}, {"(", 4}, {")", 4}}; //operator precedence
    map<string, char> assoc {{"+", 'l'},  {"-", 'l'}, {"*", 'l'}, {"/", 'l'}, {"^", 'r'}, {"(", 'l'}, {")", 'l'}}; //operator associativity

    stack<string> operate;
    queue<string> que;

    vector<string> tokens = lex(input);
    for (int i = 0; i < tokens.size(); ++i) {
        cout << "\"" << tokens[i] << "\" ";
    }
    for (int i = 0; i < tokens.size(); ++i) {
        string s = tokens[i];
        if (isNumber(s)) {
            que.push(s);
        }
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
            if (isfunction(operate.top())) {
                que.push(operate.top());
                operate.pop();
            }
        }
        /*queue<string> q2 = que;
        int q2size = q2.size();
        for (int i = 0; i < q2size; ++i) {
            cout << q2.front() << " ";
            q2.pop();
        }*/
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
    cout << "Enter (trig functions are in radians): \n";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    double val = evaluate(parse(input));
    cout << "answer: \n";
    if (isnan(val)) {
        cout << "undefined";
    }
    else {
        cout << val;
    }
}