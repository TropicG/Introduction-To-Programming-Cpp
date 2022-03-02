#include <iostream>
using namespace std;

int main() {

	int num = 0;

	cout << "Enter a num: ";
	if (!(cin >> num)) {
		cout << "Invalid argument";
		return -1;
	}

	int reverse = 0;
	while (num != 0) {

		reverse *= 10;
		reverse += num % 10;
		num /= 10;

	}

	cout << "The reversed digit number is: " << reverse;
	return 0;
}
