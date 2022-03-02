#include <iostream>
using namespace std;

int sumDigits(int num) {

	if (num < 10) {
		return num;
	}
	return num % 10 + sumDigits(num / 10);
}

bool concNum(const int& num) {

	int first = num / 1000;
	int second = num % 1000;

	if (num % (sumDigits(first) + sumDigits(second)) == 0) {
		return true;
	}

	return false;
}

int main() {


	int l = 0, r = 0;

	cout << "Enter two numbers: ";
	if (!(cin >> l) || l < 100000 || l > 999999) {
		cout << "Invalid argument";
		return -1;
	}
	if (!(cin >> r) || r < 10000 || r > 999999 || l > r) {
		cout << "Invalid argument";
		return -2;
	}

	int concCount = 0, concSum = 0;
	for (int i = l; i <= r; ++i) {

		if (concNum(i)) {
			concCount++;
			concSum += i;
		}
	}

	cout << "THe sum of all concNums is " << concSum << " and the count of all concNums is " << concCount;
	return 0;
}
