#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string line;
	vector<pair<long, long>> ranges;
	bool ingredients = false;
	long fresh = 0;
	long freshIds = 0;

	while (getline(cin, line)) {
		if (line.size() < 1) {
			ingredients = true;
			sort(ranges.begin(), ranges.end());
			vector<pair<long, long>> merged;
			
			for (auto &range : ranges) {
				if (merged.empty() || merged.back().second < range.first - 1) {
					merged.push_back(range);
				} else {
					merged.back().second = max(merged.back().second, range.second);
				}
			}

			for (const auto &range : merged) {
				freshIds += (range.second - range.first + 1);
			}

			continue;
		}

		if (!ingredients) {
			int delim = line.find('-');
			long lower = stol(line.substr(0, delim));
			long upper = stol(line.substr(delim + 1));

			ranges.push_back({lower, upper});
		} else {
			long id = stol(line);
			for (const auto& range : ranges) {
				if (id >= range.first && id <= range.second) {
					fresh++;
					break;
				}
			}
		}
	}

	cout << fresh << endl;
	cout << freshIds << endl;
	
	return 0;
}