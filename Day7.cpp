#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int sumtot = 0;
	int dupe = 0;
	bool done = false;
	string home;
	string buffer;
	fstream file;
	vector<string> directories;
	vector<vector<string>> filePath;
	vector<vector<string>> contains;
	file.open("Text.txt");

	while (!file.eof()) {
		file >> buffer;
		if (buffer == "cd") {
			file >> buffer;
			if (buffer != "..") {
				home = home + " " + buffer;
				directories.push_back(home);
				vector<string> directory;
				getline(file, buffer);
				getline(file, buffer);
 				while (!done && !file.eof()) {
					file >> buffer;
					if (buffer == "$") {
						done = true;
					}
					else if (buffer == "dir") {
						file >> buffer;
						directory.push_back(home + " " + buffer);
					}
					else if (isdigit(buffer[0])) {
						directory.push_back(buffer);
						sumtot += stoi(buffer);
					}
				}
				filePath.push_back(directory);
				done = false;
			}
			else {
				while (!isspace(home[home.length() - 1])) {
					home.pop_back();
				}
				home.pop_back();
			}
		}
	}
	file.close();
	double closest = 99999999;
	int spaceAvailable = 70000000 - sumtot;
	int spaceNeeded = 30000000 - spaceAvailable;
	int total = 0;
	int sum = 0;
	bool dir = false, doneAgain = false;
	while (!doneAgain) {
		doneAgain = true;
		for (int i = 0; i < directories.size(); i++) {
			if (directories[i] != "Done") {
				for (int j = 0; j < filePath[i].size(); j++) {
					if (!isdigit(filePath[i][j][0])) {
						dir = true;
						doneAgain = false;
					}
				}
				if (!dir) {
					for (int j = 0; j < filePath[i].size(); j++) {
						sum += stoi(filePath[i][j]);
					}
					
					if (sum >= spaceNeeded) {
						if (sum < closest) {
							closest = sum;
						}
					}

					for (int k = 0; k < filePath.size(); k++) {
						for (int l = 0; l < filePath[k].size(); l++) {
							if (directories[i] == filePath[k][l]) {
								filePath[k][l] = to_string(sum);
								directories[i] = "Done";
							}
						}
					}
					sum = 0;
				}
				dir = false;
			}
		}
	}
	cout << int(closest) << endl;
	return 0;
}