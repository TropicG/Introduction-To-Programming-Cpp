#include <iostream>
using namespace std;

int getbits(int num) {

	int count = 0;
	while (num != 0) {

		if (num & 1 == 1) {
			count++;
		}
		num >>= 1;
	}
	return count;
}

int main() {


	int l = 0, r = 0;

	cout << "Enter the range of numbers: ";
	if (!(cin >> l) || l < 0) {
		cout << "Invalid argument";
		return -1;
	}
	if (!(cin >> r) || r < 0 || r < l) {
		cout << "Invalid argument";
		return -2;
	}

	int countBits = 0;
	for (int i = l; i <= r; ++i) {
		countBits += getbits(i);
	}
	cout << "The number of 1 bits in the numbers in this range is: " << countBits;

	return 0;
}
