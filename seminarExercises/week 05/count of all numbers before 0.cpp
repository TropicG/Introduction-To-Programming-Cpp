#include <iostream>
using namespace std;


int main() {


	int count = 0, num = 0;

	cout << "Enter your numbers: ";
	do {

		cin >> num;
		count++;

	} while (num != 0);

	cout << "The sum of all the numbers before the zero is: " << count-1;
	return 0;
}
