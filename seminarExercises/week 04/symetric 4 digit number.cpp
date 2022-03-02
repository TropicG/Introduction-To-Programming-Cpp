#include <iostream>
using namespace std;


int main() {


	int num = 0;
	cout << "Enter a number: ";

	if (!(cin >> num) || num < 1000 || num >> 9999) {
		cout << "Invalid argument";
		return -1;
	}

	int first = num / 1000, second = (num / 100) % 10, third = (num / 10) % 10, fourth = num % 10;

	if (first == fourth && second == third) {
		cout << "The number is symetric";
	}
	else {
		cout << "The number is not symetric";
	}

	return 0;
}
