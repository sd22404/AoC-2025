#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> split(const string &line, const string &delim) {
	auto haystack = line;
	vector<string> tokens;
	size_t pos;
	while ((pos = haystack.find(delim)) != string::npos) {
		tokens.push_back(haystack.substr(0, pos));
		haystack.erase(0, pos + delim.length());
	}
	tokens.push_back(haystack);
	return tokens;
}


int main() {
	string ranges;
	getline(cin, ranges);

	auto pairs = split(ranges, ",");
	long sumOne = 0;
	long sumTwo = 0;
	bool foundTwo = false;

	for (auto pair : pairs) {
		auto range = split(pair, "-");
		long start = stol(range.at(0));
		long end = stol(range.at(1));
		for (long i = start; i <= end; i++) {
			string id = to_string(i);
			int len = id.size();
			if (len < 2) continue;

			foundTwo = false;

			for (int testLen = 1; testLen <= len / 2; testLen++) {
				string test = id.substr(0, testLen);
				int count = 1;
				for (int j = testLen; j < len; j += testLen) {
					if (id.substr(j, testLen) == test) count++;
				}
				if (count == ceil(len / float(testLen))) {
					if (!foundTwo) { sumTwo += i; foundTwo = true; }
					if (testLen == ceil(len / 2.0)) { sumOne += i; break; }
				}
			}
		}
	}

	cout << sumOne << endl;
	cout << sumTwo << endl;
	return 0;
}