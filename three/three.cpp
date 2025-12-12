#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long getJolts(const int &joltsLen, const string &bank) {
	vector<char> digits(joltsLen, -1);
	long jolts = 0;

	for (int i = 0; i < bank.size(); i++) {
		char joltage = bank.at(i) - '0';
		for (int j = 0; j < joltsLen; j++) {
			if (joltage > digits[j] && i < bank.size() - (joltsLen - j - 1)) {
				digits[j] = joltage;
				for (int k = j + 1; k < joltsLen; k++) {
					digits[k] = -1;
				}
				break;
			}
		}
	}

	char power = joltsLen - 1;
	for (auto &digit : digits) {
		jolts += digit * pow(10, power);
		power--;
	}

	return jolts;
}

int main() {
	string bank;
	int joltsTwo = 0;
	long joltsTwelve = 0;

	while(getline(cin, bank)) {
		joltsTwo += getJolts(2, bank);
		joltsTwelve += getJolts(12, bank);
	}

	cout << joltsTwo << endl;
	cout << joltsTwelve << endl;

	return 0;
}
