#include <iostream>
using namespace std;

int main() {

	int size = 0;

	cout << "Enter the size of the array: ";
	cin >> size;
	while (cin.fail() || size < 0 || size > 100) {
		cin.clear();
		cin.ignore();
		cout << "Invalid argument, please try again: ";
		cin >> size;
	}

	int arr[100];
	cout << "Enter the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, please try again: ";
			cin >> arr[i];
		}
	}

	int best = 0, bestMet = 0;
	int current = 0;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {

			if (arr[i] == arr[j]) {
				current++;
			}
		}

		if (current > bestMet) {
			bestMet = current;
			best = arr[i];
		}

		current = 0;

	}

	cout << "The number met most in the array is " << best << " and its met " << bestMet << " times";
	return 0;
}
