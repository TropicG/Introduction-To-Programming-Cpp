#include <iostream>
using namespace std;

int main() {

	int weightlifters = 0;

	cout << "Enter the number of weightlifters: ";
	if (!(cin >> weightlifters) || weightlifters < 0 || weightlifters >50) {
		cout << "Invalid argument";
		return -1;
	}

	int bestPower = 0, bestWeight = 0;
	int helperPower = 0, helperWeight = 0;

	for (int i = 0; i < weightlifters; ++i) {

		cin >> helperPower >> helperWeight;
		if (helperPower > bestPower) {
			bestPower = helperPower;
			bestWeight = helperWeight;
		}
		if (helperPower == bestPower && helperWeight < bestWeight) {
			bestPower = helperPower;
			bestWeight = helperWeight;
		}
	}

	cout << "The best weightlifter is the champion with " << bestPower << " power and " << bestWeight << " weight";
	return 0;
}
