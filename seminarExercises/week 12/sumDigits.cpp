#include <iostream>
using namespace std;

int sumDigits(int num) {

	if (num < 10) {
		return num;
	}

	return num % 10 + sumDigits(num / 10);
}

int main() {

	int num = 0;
	cout << "Enter the size of the array: ";
	cin >> num;
	while (cin.fail() || num < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter an valid argument: ";
		cin >> num;
	}

	cout << "The sum of the digits of this number is: " << sumDigits(num);
	return 0;
}
