#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> years = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

string get_animal(int year)
{
    int a = 0, y = 0;
    while (y < year) { 
        ++y;
        ++a;
        if (a == 12) { 
            a = 0;
        } 
    }
    while (y > year) {
        --y;
        --a; 
        if (a == -1) {
            a = 11;
        } 
    }

    return years[a];
}

int main()
{
    int n;
    unordered_map<string, int> lst {{"Bessie", 0}};
    cin >> n;
    string name, b, iny, order, animal, year, from, name2;
    for (int i = 0; i < n; ++i) {
        cin >> name >> b >> iny >> order >> animal >> year >> from >> name2;
        lst[name] = lst[name2];
        do {
            if (order == "previous") {
                lst[name]--;
            }
            else {
                lst[name]++;
            }
        } while (get_animal(lst[name]) != animal);
    }
    cout << abs(lst["Elsie"]);
}