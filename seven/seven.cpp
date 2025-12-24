#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int splits = -1;

    while (getline(cin, line)) {
        for (auto & c : line) {
            if (c == '^') splits++;
        }
    }

    cout << splits << endl;

    return 0;
}