#include <iostream>
using namespace std;

int main() {


	int days = 0;
	cout << "Enter how many days the vacation will be: ";
	if (!(cin >> days) || days < 2 || days >22) {
		cout << "Invalid argument the days must be between[2,22]";
		return -1;
	}

	if (22 + days > 31) {
		days -= 31 - 22;
		cout << "The students must be in school on the: " << days;
		return 0;
	}

	cout << "The students must be in school on the: " << 21 + days;
	return 1;
}
