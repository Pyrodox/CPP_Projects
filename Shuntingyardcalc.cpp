#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
#include <complex>
using std::cout; using std::string; using std::getline; using std::complex; using std::abs;
using std::vector; using std::stack; using std::queue; using std::transform;
using std::invalid_argument; using std::map; using std::function; using namespace std::literals;
using std::isinf; using std::isnan; using std::cin; using std::exception;

typedef complex<double> cmpd;

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

cmpd operation(string s, cmpd v1, cmpd v2 = 0, bool deg = false) //operations
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
        case str2int("^"):
            return pow(v1, v2);
        default:
            return tgamma(v1.real() + 1); //factorial, technically it is a function but it is conveninent to treat it as an operator here
    }
}

cmpd func(string s, cmpd v, cmpd v2 = 0, bool deg = false) //functions, radians
{
    double toRad = acos(-1) / 180.0;
    double toDeg = 180.0 / acos(-1);
    if (deg) {
        switch (str2int(s.c_str())) {
            case str2int("sin"):
                return sin(v * toRad);
            case str2int("cos"):
                return cos(v * toRad);
            case str2int("tan"):
                return tan(v * toRad);
            case str2int("sec"):
                return 1.0 / cos(v * toRad);
            case str2int("csc"):
                return 1.0 / sin(v * toRad);
            case str2int("cot"):
                return 1.0 / tan(v * toRad);
            case str2int("asin"):
                return asin(v) * toDeg;
            case str2int("acos"):
                return acos(v) * toDeg;
            case str2int("atan"):
                return atan(v) * toDeg;
            case str2int("asec"):
                return acos(1.0 / v) * toDeg;
            case str2int("acsc"):
                return asin(1.0 / v) * toDeg;
            default: //acot
                return atan(1.0 / v) * toDeg;
        }
    }
    switch (str2int(s.c_str())) {
        case str2int("sin"):
            return sin(v);
        case str2int("cos"):
            return cos(v);
        case str2int("tan"):
            return tan(v);
        case str2int("sec"):
            return 1 / cos(v.real());
        case str2int("csc"):
            return 1 / sin(v.real());
        case str2int("cot"):
            return 1 / tan(v.real());
        case str2int("ln"):
            if (v.real() == 0) {
                return INFINITY; //returning INFINITY for domain errors
            }
            return log(v);
        case str2int("log10"):
            if (v.real() == 0) {
                return INFINITY;
            }
            return log10(v);
        case str2int("log"):
            if (v.real() == 0 || v.real() == 1 || v2.real() == 0) {
                return INFINITY;
            }
            return log(v2) / log(v);
        case str2int("exp"):
            return exp(v);
        case str2int("sqrt"):
            return sqrt(v);
        case str2int("cbrt"):
            return pow(v, 1.0 / 3);
        case str2int("root"):
            if (v == 0.0) {
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
            return acos(1.0 / v);
        case str2int("acsc"):
            return asin(1.0 / v);
        default: //acot
            return atan(1.0 / v);
    }
}

bool isOperator(string s) //checks if string is operator
{
    vector<string> v {"+", "-", "*", "/", "^", "#", "!"};

    return find(v.begin(), v.end(), s) != v.end();
}

bool isFunction(string s) //checks if string is function
{
    vector<string> v {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "exp", "sqrt", "!", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot", "log", "root"};

    return find(v.begin(), v.end(), s) != v.end();
}

int paramamnt(string s) //checks parameter amount of a function
{
    vector<string> v1 {"sin", "cos", "tan", "sec", "csc", "cot", "ln", "log10", "exp", "sqrt", "cbrt", "abs", "asin", "acos", "atan", "asec", "acsc", "acot"};
    vector<string> v2 {"log", "root"};

    return find(v1.begin(), v1.end(), s) != v1.end() ? 1 : 2;
}

void newval(int n, stack<cmpd> &s, queue<string> &q, function<cmpd(string o, cmpd a, cmpd b, bool deg)> func, bool isdeg) //evaluates using either the operate or the func function
{
    if (s.size() < n) {
        throw invalid_argument("Error: invalid expression");
    }

    cmpd a = s.top();
    s.pop();
    if (n == 1) {
        s.push(func(q.front(), a, 0, isdeg));
    }
    else {
        cmpd b = s.top();
        s.pop();
        s.push(func(q.front(), b, a, isdeg));
    }
    q.pop();
}

cmpd evaluate(queue<string> q, bool isdeg) //evaluates reverse polish notation given by parse function
{
    stack<cmpd> valstack;
    const int qsize = q.size();

    for (int i = 0; i < qsize; ++i) {
        if (isNumber(q.front())) {
            if (q.front() == "3.142") {
                valstack.push(acos(-1));
            }
            else if (q.front() == "2.718") {
                valstack.push(exp(1));
            }
            else {
                valstack.push(stod(q.front()));
            }
            q.pop();
        }
        else if (isOperator(q.front())) {
            q.front() == "!" ? newval(1, valstack, q, operation, isdeg) : newval(2, valstack, q, operation, isdeg);
        }
        else if (isFunction(q.front())) {
            paramamnt(q.front()) == 1 ? newval(1, valstack, q, func, isdeg) : newval(2, valstack, q, func, isdeg);
        }
    }

    return valstack.top();
}

queue<string> parse(vector<string> tokens) //converts vector of tokens to reverse polish notation
{
    map<string, int> m {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3}, {"!", 4}, {"#", 5}}; //operator precedence
    map<string, char> assoc {{"+", 'l'}, {"-", 'l'}, {"*", 'l'}, {"/", 'l'}, {"^", 'r'}, {"!", 'r'}, {"(", 'l'}, {")", 'l'}}; //operator and parenthesis associativity

    stack<string> operate;
    queue<string> que;

    for (int i = 0; i < tokens.size(); ++i) { //checking the vector of tokens
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
    for (int i = 0; i < q2size; ++i) { //checking queue here
        cout << q2.front() << " ";
        q2.pop();
    }

    return que;
}

vector<string> lex(string input) //tokenizes input
{
    for (int i = 0; i < input.length() - 1; ++i) { //checks if a number is next to a function in order to multiply them
        if (isdigit(input[i]) && isalpha(input[i + 1])) {
            input = input.substr(0, i + 1) + "*" + input.substr(i + 1);
        }
    }

    string buffer = "";
    vector<string> output {"0", "+"};
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '-') {
            output.push_back(buffer);
            if (output.size() != 0 && (output[output.size() - 1] == ")" || isNumber(output[output.size() - 1]))) { //subtraction
                output.push_back(input.substr(i, 1));
            }
            else { //negative val
                string a = "";
                if (output.size() >= 2) {
                    string a = output[output.size() - 2];
                }
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
            output.push_back(",");
            buffer = "";
        }
        else if (input[i] == 'e' && (input[i + 1] != 'x' && input[i + 1] != 'c' || i == input.length() - 1)) { //e
            output.push_back("2.718");
        }
        else if (input[i] == 'p' && input[i + 1] == 'i') { //pi
            input = input.substr(0, i) + input.substr(i + 1);
            output.push_back("3.142");
        }
        else if (input[i] == 'i' && (i == 0 || input[i - 1] != 's')) {
            output.push_back("sqrt");
            output.push_back("(");
            output.push_back("-1");
            output.push_back(")");
        }
        else { //number or function
            buffer += input.substr(i, 1);
        }
    }
    
    output.push_back(buffer);
    output.erase(remove(output.begin(), output.end(), ""), output.end());
    if (count(output.begin(), output.end(), "(") != count(output.begin(), output.end(), ")")) {
        throw invalid_argument("Error: mismatched parentheses");
    }

    for (int i = 1; i < output.size(); ++i) {
        if (output[i] == "(" && (isNumber(output[i - 1]) || output[i - 1] == ")" || output[i - 1] == "!")) {
            output.insert(output.begin() + i, "*");
        }
        else if (output[i] == ")" && isNumber(output[i + 1])) {
            output.insert(output.begin() + i + 1, "*");
            ++i;
        }
        else if (isNumber(output[i]) && (isNumber(output[i - 1]))) {
            output.insert(output.begin() + i, "*");
            ++i;
        }
    }

    output.erase(remove(output.begin(), output.end(), ","), output.end());

    return output;
}

int main()
{
    cout << "This calculator has experimental support with complex numbers.\n";
    cout << "3.142 and 2.718 are assumed as pi and e respectively (type 3.1420 for example if you want 3.142 instead of pi).\n";
    cout << "If the absolute value of a number is <= 0.0001, it will be rounded to 0.\n";

    cout << "\nRadians or Degrees? Enter rad or deg. (default is radians): ";
    string measure;
    cin >> measure;
    transform(measure.begin(), measure.end(), measure.begin(), ::tolower);
    if (measure != "rad" && measure != "deg") {
        cout << "defaulting to rad...\n";
        measure = "rad";
    }
    bool isdeg = measure != "rad";

    cin.ignore();

    cout << "\nEnter (use parenthesis for functions like ln()): \n";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end()); //removes spaces from input

    cmpd val;
    try {
        val = evaluate(parse(lex(input)), isdeg);
    } catch (const exception& e) {
        cout << e.what();
        return 1;
    }

    cout.precision(16);
    cout << "\nanswer: \n";
    if (isnan(val.real()) || isinf(val.real())) {
        cout << "undefined";
    }
    else {
       if (abs(val.real()) <= 0.0001) { //used a tolerance value here because for some reason sqrt(-1)^2 evaluated into -1 + a very small constant times i so...
            if (abs(val.imag()) <= 0.0001) { //lots of if statements for formatting purposes
                cout << 0;
            }
            else {
                if (val.imag() == 1) {
                    cout << "i";
                }
                else if (val.imag() == -1) {
                    cout << "-i";
                }
                else {
                    cout << val.imag() << "i";
                }
            }
        }
        else if (abs(val.imag()) <= 0.0001) {
            cout << val.real();
        }
        else {
            cout << val.real() << " + " << val.imag() << "i";
        }
    }
}