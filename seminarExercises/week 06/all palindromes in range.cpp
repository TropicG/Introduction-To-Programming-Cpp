#include <iostream>
using namespace std;

bool palindrome(const int& num) {

	if (num < 10) {
		return true;
	}
	else if (num > 10 && num < 99) {

		if (num % 10 == num / 10) {
			return true;
		}
		else {
			return false;
		}
	}
	else {

		if (num % 10 == num / 100) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {

	int k = 0, l = 0;
	cout << "Enter the range of the numbers: ";
	if (!(cin >> k) || !(cin >> l) || k < 0 || l < 0 || k>1000 || l >> 1000 || k > l) {
		cout << "Invalid argument";
		return -1;
	}

	for (int i = k; i < l; ++i) {

		if (palindrome(i)) {
			cout << i << " ";
		}
	}

	return 0;
}
