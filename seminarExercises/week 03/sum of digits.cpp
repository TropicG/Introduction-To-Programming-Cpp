#include <iostream>
using namespace std;


int main() {


	int num = 0;
	cout << "Enter 3 digit number: ";
	cin >> num;

	if (num < 100 || num > 999) {
		cout << "The num is not digit";
	}

	int sum = 0;
	while (num != 0) {

		sum += num % 10;
		num /= 10;

	}

	cout << "The sum of the digits is: " << sum;
	return 0;
}
