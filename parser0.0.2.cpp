#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string str;
	float a, c;
	char b;
	bool q = true;
	getline(cin, str);
	istringstream stream(str);
	stream >> c;
	while (stream >> b) {
		if (b == '*') {
			stream >> a;
			c = c * a;
		}
		else if (b == '/') {
			stream >> a;
			if (a != 0) {
				c = c / a;
			}
			else {
				cout << "Devision by zero";
				q = false;
			}
		}
	}
	while (stream >> b) {
		if (b == '+') {
			stream >> a;
			c = c + a;
		}
		else if (b == '-') {
			stream >> a;
			c = c - a;
		}
	}

	if (q == true)
		cout << c;
	cin.get();
	return 0;

}
