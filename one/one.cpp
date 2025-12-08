#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
	ifstream file("inputs.txt");
	string line;

	int pos = 50;
	int pwd = 0;

	while (getline(file, line)) {
		bool left = line.at(0) == 'L';
		int dist = stoi(line.substr(1));
		int newPos = left ? pos - dist : pos + dist;

		// if (left) {
		// 	int spins = -newPos / 100;
		// 	pwd += newPos <= 0 ? spins + 1 : 0;
		// } else {
		// 	int spins = newPos / 100;
		// 	pwd += newPos >= 100 ? spins : 0;
		// }

		pos = ((newPos % 100) + 100) % 100;
		pwd += pos == 0;
	}

	cout << pwd << endl;
	return 0;
}