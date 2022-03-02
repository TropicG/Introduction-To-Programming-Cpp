#include <iostream>
using namespace std;

int main() {


	float a = 0, b = 0, c = 0;

	cout << "Enter the first side: ";
	if (!(cin >> a) || a < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the second side: ";
	if (!(cin >> b) || b < 0) {
		cout << "Invalid argument";
		return -2;
	}

	cout << "Enter the third side: ";
	if (!(cin >> c) || c < 0) {
		cout << "Invalid argument";
		return -3;
	}

	if ((a < c - b) || (b < c - a) || (c < b - a)) {
		cout << "The triangle is incorrect";
		return -4;
	}

	if (a == b && b == c) {
		cout << "The triangle is equilateral";
		return 1;
	}
	else if (a == b) {
		cout << "The triangle is isosceles";
		return 2;
	}
	else {
		cout << "The triangle is multifaceted";
		return 3;
	}
}
