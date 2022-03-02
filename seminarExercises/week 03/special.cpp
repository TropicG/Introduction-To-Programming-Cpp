#include <iostream>
using namespace std;


int main() {


	int num = 0;

	cout << "Enter the num: ";
	cin >> num;
	if (num < 1000 || num > 9999) {
		cout << "Invalid argument";
		return -1;
	}

	int helper = num;

	bool special = true;
	while (helper!=0) {

		int last = helper % 10;

		if (last != 3 && last != 1 && last != 7) {
			special = false;
		}

		helper /= 10;

	}

	if (special) {
		return 1;
	}

	helper = num;
	special = true;

	while (helper != 0) {

		int last = helper % 10;

		if (last != 0 && last != 2 && last != 4) {
			special = false;
		}

		helper /= 10;
	}

	if (special) {
		return 1;
	}
	return 0;
}
