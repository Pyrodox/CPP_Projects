#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using std::cout; using std::cin; using std::map; using std::string; using std::vector; using std::find;

int main()
{
    map<vector<int>, string> res1 {{{1, 2}, "P2 wins, paper beats rock"}, {{2, 3}, "P2 wins, scissors beats paper"}, 
    {{3, 1}, "P2 wins, rock beats scissors"}, {{2, 1}, "P1 wins, paper beats rock"}, 
    {{3, 2}, "P1 wins, scissors beats paper"}, {{1, 3}, "P1 wins, rock beats scissors"}};
    map<int, string> res2 {{1, "rock against rock is tie"}, {2, "paper against paper is tie"}, {3, "scissors against scissors is tie"}};

    int p1, p2;
    bool on = false;
    do {
        on = false;
        cin >> p1 >> p2;
        vector<int> e {p1, p2};

        if (p1 == p2) {
            cout << res2[p1] << "\n";
        }
        else {
            if(res1.find(e) != res1.end()) {
                cout << res1[e] << "\n";
            }
            else {
                cout << "try again\n";
                on = true;
            }
        }
    }
    while (on);

    return 0;
}