#include <string>
#include <iostream>

using namespace std;

int main() {
	string line;

	int pos = 50;
	int pwdOne = 0;
	int pwdTwo = 0;

	while (getline(cin, line)) {
		bool left = line.at(0) == 'L';
		int dist = stoi(line.substr(1));

		int newPos = left ? pos - dist : pos + dist;
		int wraps = left ? -newPos / 100 : newPos / 100;
		wraps += left && (pos > 0) && (newPos <= 0);

		pwdTwo += wraps;
		pos = ((newPos % 100) + 100) % 100;
		
		if (pos == 0) pwdOne++;
	}

	cout << pwdOne << endl;
	cout << pwdTwo << endl;
	return 0;
}