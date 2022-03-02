#include <iostream>
using namespace std;

int main() {


	int num = 0;
	cout << "Enter the num: ";

	if (!(cin >> num) || num < 0) {
		cout << "Invalid argument";
		return -1;
	}

	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}

	cout << "The number of digits of this number is: " << count;
	return 0;
}
