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

int main()
{
    string s;
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); //remove spaces from a string
}