#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string str(string s) {
	char ops[4] = { '+', '-', '*', '/' };
	int t;
	for (int i = 0; i < 4; i++) {
		t = s.rfind(ops[i]);
		if (t > 0) {
			return str(s.substr(0, t)) + " " + str(s.substr((t + 1), s.length() - t - 1)) + " " + ops[i];
		}
	}
	return s;
}

float calc(string s) {
	float stack[20];
	int p = 0;
	float z = 0;
	string c;
	char e;
	bool q = true;
	istringstream stream(s);
	while (stream >> c) {
		e = c[0];
		switch (e) {
		case '+':
			if (p > 1) {
				p--;
				stack[p - 1] += stack[p];
			}
			break;
		case '-':
			if (p > 1) {
				p--;
				stack[p - 1] -= stack[p];
			}
			break;
		case '*':
			if (p > 1) {
				p--;
				stack[p - 1] *= stack[p];
			}
			break;
		case '/':
			if (p > 1) {
				p--;
				if (stack[p] != 0) {
					stack[p - 1] /= stack[p];
				}
				else {
					q = false;
				}
			}
			break;

		default:
			stack[p] = stof(c);
			p++;
		}
	}
	if (q == true) {
		return stack[0];
	}
	else {
		cout << "Devision by zero";
	}
}
	
int main() {
	string s;
	getline(cin, s);
	s = str(s);
	cout << calc(s);
	cin.get();
	return 0;
}
