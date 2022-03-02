#include <iostream>
using namespace std;


int main() {


	int sum = 0, num = 0;

	cout << "Enter your numbers: ";
	do {

		cin >> num;
		sum += num;

	} while (num != 0);

	cout << "The sum of all the numbers before the zero is: " << sum;
	return 0;
}
