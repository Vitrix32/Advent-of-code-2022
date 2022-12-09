#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int sum = 0;
	fstream file;
	string line;
	file.open("Text.txt");
	while (!file.eof()) {
		getline(file, line);
		if (line == "A X") {
			sum += 3;
		}
		else if (line == "A Y") {
			sum += 4;
		}
		else if (line == "A Z") {
			sum += 8;
		}
		else if (line == "B X") {
			sum += 1;
		}
		else if (line == "B Y") {
			sum += 5;
		}
		else if (line == "B Z") {
			sum += 9;
		}
		else if (line == "C X") {
			sum += 2;
		}
		else if (line == "C Y") {
			sum += 6;
		}
		else if (line == "C Z") {
			sum += 7;
		}
	}
	cout << sum << endl;
	file.close();
	return 0;
}
