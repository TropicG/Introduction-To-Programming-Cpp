#include <iostream>
using namespace std;

int main() {


	int num = 0;

	cout << "Enter your number: ";
	if (!(cin >> num)) {
		cout << "Invalid argument";
		return -1;
	}

	int sum = 0, helper = 0;

	cout << "Enter other numbers: ";
	do{

		cin >> helper;
		if (sum + helper >= num) {
			break;
		}
		sum += helper;

	} while (sum < num);

	cout << "The sum of the inputed number smaller from the first inputted numbers is: " << sum;
	return 0;
}
