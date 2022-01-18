#include <iostream>
using std::cout;

int numofways(int n)
{
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }
    int a = 1, b = 2, c = 4, total = 0;
    for (int i = 4; i <= n; ++i) {
        total = a + b + c;
        a = b;
        b = c;
        c = total;
    }

    return total;
}

int main()
{
    cout << numofways(10) << "\n";
}