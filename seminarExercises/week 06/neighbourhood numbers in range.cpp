#include <iostream>
using namespace std;

bool neighbour(int num, int prev) {

	if (num < 10 && prev != num) {
		return false;
	}

	if (num == prev) {
		return true;
	}

	return neighbour(num / 10, num % 10);
}

int main() {


	int k = 0, l = 0;
	cout << "Enter the range: ";
	if (!(cin >> k) || !(cin >> l) || k < 0 | l < 0 || k > 100000 || l > 10000 || k > l) {
		cout << "Invalid argument";
		return -1;
	}

	for (int i = k; i <= l; ++i) {

		if (neighbour(i / 10, i % 10)) {
			cout << i << " ";
		}
	}

	return 0;
}
