#include <iostream>
#include <string>

using namespace std;

int main() {
	string bank;
	int joltsTwo = 0;
	long joltsTwelve = 0;

	while(getline(cin, bank)) {
		char tens = -1;
		char ones = -1;
		for (int i = 0; i < bank.size(); i++) {
			char joltage = bank.at(i) - '0';
			if (joltage > tens && i != bank.size() - 1) {
				tens = joltage;
				ones = -1;
			} else if (joltage > ones) {
				ones = joltage;
			}
		}

		cout << "Tens: " << tens << ", Ones: " << ones  << ", Bank: " << bank << endl;

		joltsTwo += tens * 10 + ones;
	}

	cout << joltsTwo << endl;
	cout << joltsTwelve << endl;

	return 0;
}
