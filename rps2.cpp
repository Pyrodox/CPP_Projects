#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using std::cout; using std::cin; using std::map; using std::string; using std::vector; using std::find; using std::rand;
    
map<vector<int>, string> res1 {{{1, 2}, "P2 wins; Paper beats Rock."}, {{2, 3}, "P2 wins; Scissors beats Paper."}, 
                            {{3, 1}, "P2 wins; Rock beats Scissors."}, {{2, 1}, "P1 wins; Paper beats Rock."}, 
                            {{3, 2}, "P1 wins; Scissors beats Paper."}, {{1, 3}, "P1 wins; Rock beats Scissors."}};

map<int, string> res2 {{1, "Rock against Rock is a tie."}, {2, "Paper against Paper is a tie."}, {3, "Scissors against Scissors is a tie."}};

int main()
{
    srand(time(NULL));

    int p1, p2;
    bool on = false;
    do {
        on = false;

        cin >> p1;
        p2 = (rand() % 3) + 1;
        vector<int> e {p1, p2};

        if (p1 == p2) {
            cout << res2[p1] << "\n";
        }
        else {
            if(1 <= p1 <= 3) {
                cout << res1[e] << "\n";
            }
            else {
                cout << "Try again.\n";
                on = true;
            }
        }
    }
    while (on);

    return 0;
}