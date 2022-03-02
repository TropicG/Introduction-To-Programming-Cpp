#include <iostream>
using namespace std;


int main() {


	int a = 0, b = 0;

	cout << "Enter your interval: ";
	if (!(cin >> a)) {
		cout << "Invalid argument";
		return -1;
	}
	if (!(cin >> b) || b <= a) {
		cout << "Invalid argument";
		return -2;
	}

	cout << "All the number divided by 3 in the rainge [" << a << "," << b << "] are: ";
	for (int i = a; i <= b; ++i) {
		if (i % 3 == 0) {
			cout << i << " ";
		}
	}

	return 0;
}
