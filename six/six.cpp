#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string line;
	string word;
	vector<vector<int>> rows;
	vector<int> row;
	vector<char> ops;
	bool final = false;
	
	while(getline(cin, line)) {
		if (line.at(0) == '+' || line.at(0) == '*') final = true;
		else row.clear();
		istringstream iss(line);
		while (iss >> word) {
			if (!final) row.push_back(stoi(word));
			else ops.push_back(word.at(0));
		}

		if (!final) rows.push_back(row);
	}

	long grandTotal = 0;
	for (int i = 0; i < rows.at(0).size(); i++) {
		long result = ops.at(i) == '+' ? 0 : 1;
		for (auto row : rows) {
			ops.at(i) == '+' ? result += row.at(i) : result *= row.at(i);
		}
		grandTotal += result;
	}

	cout << grandTotal << endl;

	return 0;
}