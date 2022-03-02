#include <iostream>
using namespace std;

int main() {


	double a=0, b = 0;

	cout << "Enter the a coenficient: ";
	cin >> a;


	cout << "Enter the b coeficient: ";
	cin >> b;

	if (a == 0 && b == 0) {
		cout << "The x can be in the range (-infinity, +infinity)";
		return 1;
	}

	if (a != 0 && b == 0) {
		cout << "The x is 0";
		return 1;
	}

	if (a == 0 && b != 0) {
		cout << "Invalid argument";
		return -1;
	}


	cout << "The result is: " << b / a;

	return 0;

}
