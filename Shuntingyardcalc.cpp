#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
using std::cout; using std::string; using std::getline;
using std::vector; using std::stack; using std::queue;
using std::invalid_argument; using std::map; using std::function;
using std::isinf; using std::isnan; using std::cin; using std::exception;

constexpr unsigned int str2int(const char* str, int h = 0) //string to int conversion for switch case purposes
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

bool isNumber(const string& s) //check if a string is a number
{
   if(s.empty() || ::isspace(s[0]) || isalpha(s[0])) {
       return false;
   }
   char *p;
   strtod(s.c_str(), &p);

   return (*p == 0);
}

double operation(string s, double v1, double v2) //operations
{
    switch (str2int(s.c_str())) {
        case str2int("+"):
            return v1 + v2;
        case str2int("-"):
            return v1 - v2;
        case str2int("*"):
            return v1 * v2;
        case str2int("#"): //for negative powers
            return v1 * v2;
        case str2int("/"):
            return v1 / v2;
        default:
            return pow(v1, v2);
    }
}

double func(string s, double v, double v2 = 0) //functions
{
    switch (str2int(s.c_str())) {
        case str2int("sin"):
            return sin(v);
        case str2int("cos"):
            return cos(v);
        case str2int("tan"):
            return tan(v);
        case str2int("sec"):
            return 1 / cos(v);
        case str2int("csc"):
            return 1 / sin(v);
        case str2int("cot"):
            return 1 / tan(v);
        case str2int("ln"):
            if (v <= 0) {
                return INFINITY;
            }
            return log(v);
        case str2int("log10"):
             if (v <= 0) {
                return INFINITY;
            }
            return log10(v);
        case str2int("log"):
             if (v <= 0) {
                return INFINITY;
            }
            return log(v2) / log(v);
        case str2int("sqrt"):
            return sqrt(v);
        case str2int("cbrt"):
            return cbrt(v);
        case str2int("root"):
            if (v == 0) {
                return INFINITY;
            }
            return pow(v2, 1.0 / v);
        case str2int("abs"):
            return abs(v);
        case str2int("asin"):
            return asin(v);
        case str2int("acos"):
            return acos(v);
        case str2int("atan"):
            return atan(v);
        case str2int("asec"):
            return acos(1 / v);
        case str2int("acsc"):
            return asin(1 / v);
        case str2int("acot"): //acot
            return atan(1 / v);
        default:
            return tgamma(v + 1);
    }
}

bool isOperator(string s) //checks if string is operator
{
    vector<string> v {"+", "-", "*", "/", "^", "#"};

    return find(v.begin(), v.end(), s) != v.end();
}

bool isFunction(string s) //checks if string is function
{
    vector<string> v {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot", "log", "root"};

    return find(v.begin(), v.end(), s) != v.end();
}

int paramamnt(string s) //checks parameter amount of a function
{
    vector<string> v1 {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot"};
    vector<string> v2 {"log", "root"};

    return find(v1.begin(), v1.end(), s) != v1.end() ? 1 : 2;
}

void newval(int n, stack<double> &s, queue<string> &q, function<double(string o, double a, double b)> func) //evaluates using either the operate or the func function
{
    if (s.size() < n) {
        throw invalid_argument("Error: invalid expression");
    }

    double a = s.top();
    s.pop();
    if (n == 1) {
        s.push(func(q.front(), a, 0));
    }
    else {
        double b = s.top();
        s.pop();
        s.push(func(q.front(), b, a));
    }
    q.pop();
}

double evaluate(queue<string> q) //evaluates reverse polish notation given by parse function
{
    stack<double> valstack;
    const int qsize = q.size();

    for (int i = 0; i < qsize; ++i) {
        if (isNumber(q.front())) {
            valstack.push(stod(q.front()));
            q.pop();
        }
        else if (isOperator(q.front())) {
            newval(2, valstack, q, operation);
        }
        else if (isFunction(q.front())) {
            paramamnt(q.front()) == 1 ? newval(1, valstack, q, func) : newval(2, valstack, q, func);
        }
    }

    return valstack.top();
}

vector<string> lex(string input) //tokenizes input
{
    for (int i = 0; i < input.length() - 1; ++i) { //checks if a number is next to a function in order to multiply them
        if (isdigit(input[i]) && isalpha(input[i + 1])) {
            input = input.substr(0, i + 1) + "*" + input.substr(i + 1);
        }
    }

    string buffer = "";
    vector<string> output;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '-') {
            output.push_back(buffer);
            if (output.size() != 0 && (output[output.size() - 1] == ")" || isNumber(output[output.size() - 1]))) { //subtraction
                output.push_back(input.substr(i, 1));
            }
            else { //negative val
                string a = output[output.size() - 2];
                output.push_back("-1");
                if (a == "^") {
                    output.push_back("#");
                }
                else {
                    output.push_back("*");
                }
            }
            buffer = "";
        }
        else if (isOperator(input.substr(i, 1)) || input[i] == '(' || input[i] == ')') { //operator or parenthesis
            output.push_back(buffer);
            output.push_back(input.substr(i, 1));
            buffer = "";
        }
        else if (input[i] == ',') { //comma
            output.push_back(buffer);
            buffer = "";
        }   
        else { //number
            buffer += input.substr(i, 1);
        }
    }
    
    output.push_back(buffer);
    output.erase(remove(output.begin(), output.end(), ""), output.end());
    if (count(output.begin(), output.end(), "(") != count(output.begin(), output.end(), ")")) {
        throw invalid_argument("Error: mismatched parentheses");
    }

    for (int i = 1; i < output.size(); ++i) {
        if (output[i] == "(" && (isNumber(output[i - 1]) || output[i - 1] == ")")) {
            output.insert(output.begin() + i, "*");
        }
    }

    return output;
}

queue<string> parse(string input) //converts vector of tokens to reverse polish notation
{
    map<string, int> m {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3}, {"#", 4}}; //operator precedence
    map<string, char> assoc {{"+", 'l'}, {"-", 'l'}, {"*", 'l'}, {"/", 'l'}, {"^", 'r'}, {"(", 'l'}, {")", 'l'}}; //operator and parenthesis associativity

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
        else if (isFunction(s) || s == "(") {
            operate.push(s);
        }
        else if (isOperator(s)) {
            while (operate.size() != 0 && operate.top() != "(" && (m[operate.top()] > m[s] || (m[s] == m[operate.top()] && assoc[s] == 'l'))) { 
                que.push(operate.top());
                operate.pop();
            }
            operate.push(s);
        }
        else if (s == ")") {
            if (operate.size() < 1) {
                throw invalid_argument("Error: right parenthesis at start of expression");
            }
            while (operate.top() != "(") {
                que.push(operate.top());
                operate.pop();
            }
            operate.pop();
            if (isFunction(operate.top())) {
                que.push(operate.top());
                operate.pop();
            }
        }
        else {
            throw invalid_argument("Error: invalid token");
        }
    }
    
    const int osize = operate.size();
    for (int i = 0; i < osize; ++i) {
        que.push(operate.top());
        operate.pop();
    }

    cout << "\n";
    queue<string> q2 = que;
    const int q2size = q2.size();
    for (int i = 0; i < q2size; ++i) {
        cout << q2.front() << " ";
        q2.pop();
    }

    return que;
}

int main()
{
    cout << "This calculator is currently only in the domain of real numbers.\n";
    cout << "Trig functions are in radians, and 3.142 will be changed to an approximation of pi and 2.718 will be changed to an approximation of e.\n";
    cout << "Enter (use parenthesis for functions like ln()): \n";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end()); //removes spaces from input

    cout << "\n" << __cplusplus << "\n";

    double val;
    try { //if bad input, tells user what's wrong, otherwise continues as normal
        val = evaluate(parse(input));
    } catch (const exception& e) {
        cout << e.what();
        return 1;
    }

    cout << "\nanswer: \n";
    if (isnan(val) || isinf(val)) { //if undefined
        cout << "undefined";
    }
    else {
        cout << val;
    }
}