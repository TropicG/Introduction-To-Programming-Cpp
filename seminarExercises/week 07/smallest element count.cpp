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

	float arr[100];
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

	float small = 0;
	for (int i = 0; i < size; ++i) {
		if (small > arr[i]) {
			small = arr[i];
		}
	}

	int count = 0;
	for (int i = 0; i < size; ++i) {
		if (small = arr[i]) {
			count++;
		}
	}

	cout << "The smallest element in the array is met " << count << " times";
	return 0;
}
