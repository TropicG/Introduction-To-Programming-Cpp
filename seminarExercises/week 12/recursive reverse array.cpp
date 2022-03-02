#include <iostream>
using namespace std;

void reverse(int* numbers, int size) {

	if (size < 0) {
		return;
	}

	cout << numbers[size] << " ";
	return reverse(numbers, size - 1);
}

int main() {

	int size = 0;

	cout << "Enter the size of the array: ";
	cin >> size;
	while (cin.fail() || size < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter an valid argument: ";
		cin >> size;
	}

	int* numbers = new int[size];
	if (!numbers) {
		cout << "Bad memory allocation";
		delete[] numbers;
		return -1;
	}

	cout << "Enter the values: ";
	for (int i = 0; i < size; ++i) {
		cin >> numbers[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, try again: ";
			cin >> numbers[i];
		}
	}

	cout << "All the numbers reversed: ";  reverse(numbers, size-1);
	delete[] numbers;
	return 0;
}
