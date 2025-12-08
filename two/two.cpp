#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &line, const char delim) {
	auto haystack = line;
	vector<string> tokens;
	size_t pos;
	while ((pos = haystack.find(delim)) != string::npos) {
		tokens.push_back(haystack.substr(0, pos));
		haystack.erase(0, pos + 1);
	}
	tokens.push_back(haystack);
	return tokens;
}


int main() {
	string ranges;
	getline(cin, ranges);

	auto pairs = split(ranges, ',');
	long sum = 0;

	for (auto pair : pairs) {
		auto range = split(pair, '-');
		long start = stol(range.at(0));
		long end = stol(range.at(1));
		for (long i = start; i <= end; i++) {
			string id = to_string(i);
			int len = id.size();
			if (len < 2 || len % 2 != 0) continue;
			string half = id.substr(0, len / 2);
			string secondHalf = id.substr(len / 2, len / 2);
			if (half == secondHalf) {
				sum += i;
			}
		}
	}

	cout << sum << endl;
	return 0;
}