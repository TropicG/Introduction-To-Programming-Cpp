#include <iostream>
using namespace std;


int main() {


	float num1 = 0, num2 = 0;
	char c;

	cout << "Enter your equation: ";
	if (!(cin >> num1)) {
		cout << "Invalid argument";
		return -1;
	}

	cin >> c;
	if (c != '+' && c != '-' && c != '*' && c != '/') {
		cout << "Invalid argument";
		return -2;
	}

	if (!(cin >> num2)) {
		cout << "Invalid argument";
		return -3;
	}

	if (c == '+') {
		cout << "The result is: " << num1 + num2;
	}
	else if (c == '-') {
		cout << "The result is: " << num1 - num2;
	}
	else if (c == '*') {

		if (num1 == 0 || num2 == 0) {
			cout << "The result is 0";
		}

		cout << "The result is: " << num1 * num2;
	}
	else {

		if (num2 == 0) {
			cout << "Invalid argument";
			return -4;
		}

		cout << "The result is: " << num1 / num2;

	}

	return 0;
}
