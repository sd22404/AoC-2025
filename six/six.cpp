#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct problem {
	char op;
	vector<vector<char>> matrix;
};

int main() {
	string line;
	string word;
	vector<vector<int>> nums;
	vector<vector<char>> rows;
	vector<int> row;
	vector<char> ops;
	bool final = false;


	while(getline(cin, line)) {
		rows.push_back(vector<char>(line.begin(), line.end()));

		if (line.at(0) == '+' || line.at(0) == '*') final = true;
		else row.clear();
		istringstream iss(line);
		while (iss >> word) {
			if (!final) row.push_back(stoi(word));
			else ops.push_back(word.at(0));
		}

		if (!final) nums.push_back(row);
	}

	long grandTotal = 0;
	for (int i = 0; i < nums.at(0).size(); i++) {
		long result = ops.at(i) == '+' ? 0 : 1;
		for (auto row : nums) {
			ops.at(i) == '+' ? result += row.at(i) : result *= row.at(i);
		}
		grandTotal += result;
	}

	cout << grandTotal << endl;
	
	vector<problem> problems;
	ops = rows.back();

	int offset = 0, back = 0;
	for (auto it = ops.rbegin(); it != ops.rend(); ++it) {
		offset++;
		if (*it == '*' || *it == '+') {
			auto m = vector<vector<char>>();
			for (int r = 0; r < rows.size() - 1; r++) {
				m.push_back(
					vector<char>(
						rows.at(r).end() - offset - back,
						rows.at(r).end() - back)
					);
			}
			problems.push_back({*it, m});
			back += offset;
			offset = 0;
		}
	}

	grandTotal = 0;
	for (auto p : problems) {
		long result = p.op == '+' ? 0 : 1;
		for (int col = p.matrix.at(0).size() - 1; col >= 0; col--) {
			int digit = 0;
			int num = 0;
			for (int row = 0; row < p.matrix.size(); row++) {
				if (p.matrix.at(row).at(col) == ' ') continue;
				num *= 10;
				num += (p.matrix.at(row).at(col) - '0');
				digit++;
			}
			if (num == 0) continue;
			if (p.op == '+') result += num;
			else result *= num;
		}
		grandTotal += result;
	}

	cout << grandTotal << endl;

	return 0;
}
