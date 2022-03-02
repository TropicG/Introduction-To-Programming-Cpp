#include <iostream>
using namespace std;

int main() {


	int a = 0, b = 0, c = 0, d = 0;

	cout << "Enter your cooeficients: ";
	if (!(cin >> a)) {
		cout << "Invalid argument for a cooeficient";
		return -1;
	}
	if (!(cin >> b)) {
		cout << "Invalid argument for b cooeficient";
		return -2;
	}
	if (!(cin >> c)) {
		cout << "Invalid argument for c coeficient";
		return -3;
	}
	if (!(cin >> d)) {
		cout << "Invalida rgument for d coeficient";
		return -4;
	}

	for (int i = 0; i < 24; ++i) {
		for (int j = 0; j < 24; ++j) {
			for (int n = 0; n < 24; ++n) {
				if (a * i + b * j + c * n == d) {
					cout << i << " " << j << " " << n << endl;
				}
			}
		}
	}

	return 0;
}
