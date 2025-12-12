#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeRolls(vector<vector<pair<bool, bool>>> &grid) {
	int rolls = 0;
	for (int y = 0; y < grid.size(); y++) {
		for (int x = 0; x < grid[y].size(); x++) {
			if (grid[y][x].first) {
				char neighbours = 0;
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						if (dy == 0 && dx == 0) continue;
						int ny = y + dy;
						int nx = x + dx;
						if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[ny].size() && grid[ny][nx].first) {
							neighbours++;
						}
					}
				}
				if (neighbours < 4) {
					rolls++;
					grid[y][x].second = true;
				}
			}
		}
	}

	for (auto &row : grid) {
		for (auto &cell : row) {
			if (cell.second) cell = {false, false};
		}
	}

	return rolls;
}

int main() {
	vector<vector<pair<bool, bool>>> grid;
	string line;
	int rollsOne = 0;
	int rollsTwo = 0;
	
	while(getline(cin, line)) {
		vector<pair<bool, bool>> row;
		for(char c : line) {
			row.push_back({c == '@', false});
		}
		grid.push_back(row);
	}

	int newRolls;
	bool first = true;
	do {
		newRolls = removeRolls(grid);
		rollsTwo += newRolls;
		if (first) rollsOne += newRolls;
		first = false;
	} while (newRolls > 0);

	cout << rollsOne << endl;
	cout << rollsTwo << endl;

	return 0;
}