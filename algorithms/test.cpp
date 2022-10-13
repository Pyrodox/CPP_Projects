#include <bits/stdc++.h>
using namespace std;

int rnd(int l, int r) {
    return l + rand() % (r - l + 1);
}

bool equal(string file1, string file2) {
    auto read_file = [&](string f) {
        vector<string> words;
        ifstream in(f);
        string token;
        while (in >> token) words.push_back(token);
        return words;
    };
    return read_file(file1) == read_file(file2);
}


int main() {
    srand(time(0));

    for (int t = 0; ; t++) {
        cout << "testing: " << t << endl;

        ofstream out("in.txt");

        {
            
    }

        out.close();

        system("a.cpp < gen.cpp > out1.txt");
        system("brute.cpp < gen.cpp > out2.txt");

        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
}