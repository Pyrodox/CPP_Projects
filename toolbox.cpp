#include <bits/stdc++.h>
using namespace std;

constexpr unsigned int str2int(const char* str, int h = 0) //convert string to int
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

bool isNumber(const string& s) //check if string is a number
{
   if(s.empty() || ::isspace(s[0]) || isalpha(s[0])) {
       return false;
   }
   char *p;
   strtod(s.c_str(), &p);

   return (*p == 0);
}

bool containsDuplicate(vector<int>& v) //if a container contains duplicates, can change to remove duplicates if function changed into a set return
{
    unordered_set<int> s {v.begin(), v.end()};

    return s.size() != v.size();
}

int main()
{
    string s;
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); //remove spaces from a string
    char c = '5';
    int c2 = c - '0'; //char (digit) to int
    vector<int> v {1, 2, 3};
    sort(v.begin(), v.end(), [](int a, int b)
    {
        return a > b; //lambda, sort example
    });
    for (auto val : v) { //shortened loop for containers, full range and value only
        cout << val << " ";
    }
    cout << "\n";
    set<int> s2;
    s2.insert(v.begin(), v.end()); //set insertion
    unordered_map<int, int> u;
    u[0]++; //adds a pair with 0 as the key and 1 as the value
    int zeroval = 0;
    v.erase(remove_if(v.begin(), v.end(), [&zeroval] (int a) {return a == zeroval;}), v.end()); //erase-remove example for if a value is equal to 0
}