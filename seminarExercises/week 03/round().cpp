#include <iostream>
#include <cmath>
using namespace std;


int main() {


	float a = 0, b = 0;

	cout << "Enter the first number: ";
	cin >> a;

	cout << "Enter the second number: ";
	cin >> b;

	if (b < 0) {
		cout << "Invalid argument";
	}

	cout << "The division with round up is: " << round(a / b);

	return 0;
}
