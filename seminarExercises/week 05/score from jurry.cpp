#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double juries = 0;
	cout << "Enter the number if juries: ";
	if (!(cin >> juries) || juries < 3) {
		cout << "Invalid argument";
		return -1;
	}

	double sum = 0, helper = 0;
	for (int i = 0; i < juries; ++i) {
		cin >> helper;
		sum += helper;
	}

	cout << "The score of the juries is: " << ceil( (sum/juries)*100.00)/100.00;

	return 0;
}
