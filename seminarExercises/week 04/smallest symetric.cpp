#include <iostream>
using namespace std;

int main() {


	int a = 0, b = 0, c = 0;
	cout << "Enter the three digits: ";
	if (!(cin >> a) || a < 0) {
		cout << "Invalid argument";
		return -1;
	}

	if (!(cin >> b) || b < 0) {
		cout << "Invalid argument";
		return -2;
	}

	if (!(cin >> c) || c < 0) {
		cout << "Invalid argument";
		return -3;
	}

	if (a == b && b == c) {
		cout << "The smallest symetric number with these digits is: " << (((a * 10) + b) * 10) + c;
	}
	else if (a == b && b != c) {
		cout << "The smallest symetric number with these digits is: " << (((((((a * 10) + b) * 10) + c) * 10) + b) * 10 + b);
	}
	else if (a == c && c != b) {
		cout << "The smallest symetric number with these digits is: " << (((a * 10) + b) * 10) + c;
	}
	else if (b == c && c != a) {
		cout << "The smallest symetric number with these digits is: " << (((((a * 10) + b) * 10) + c) * 10) + a;
	}
	else {
		cout << "The smallest symetric number with these digits is: " << (((((((a * 10) + b) * 10) + c) * 10) + b) * 10) + a;
	}

	return 0;
}
