#include <iostream>
using namespace std;


int main() {

	int num = 0;
	cout << "Enter 5 digit number: ";
	cin >> num;

	if (num < 10000 || num > 99999) {
		cout << "Invalid argument";
		return -1;
	}

	while (num != 0) {

		cout << num % 10 << " ";
		num /= 10;

	}

}
