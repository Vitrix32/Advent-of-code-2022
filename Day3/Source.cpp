#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	bool done1 = false;
	bool done2 = false;
	char a;
	char b;
	int d = 0;
	int sum = 0;
	string line1;
	string line2;
	string line3;
	string common = "";
	fstream file;

	file.open("Text.txt");
	while (!file.eof()) {
		getline(file,line1);
		getline(file, line2);
		getline(file, line3);
		for (int i = 0; i < line1.length(); i++) {
			a = line1[i];
			for (int j = 0; j < line2.length(); j++) {
				if (a == line2[j]) {
					common += a;
				}
			}
		}
		for (int i = 0; i < common.length() && !done2; i++) {
			a = common[i];
			for (int j = 0; j < line3.length() && !done2; j++) {
				if (a == line3[j]) {
					if (isupper(line3[j])) {
						cout << a << endl;
						sum += int(a) - 38;
						done2 = true;
					}
					else {
						cout << a << endl;
						sum += int(a) - 96;
						done2 = true;
					}
				}
			}
		}
		d++;
		cout << d << endl;
		common = "";
		done1 = false;
		done2 = false;	
	}
	cout << sum;
	file.close();
	return 0;
}
