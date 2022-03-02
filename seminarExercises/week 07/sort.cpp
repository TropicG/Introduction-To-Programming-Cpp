#include <iostream>
using namespace std;

void sort(int* arr, const int& size) {

	int temp = 0;

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {

			if (arr[i] > arr[j]) {

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print(int* arr, const int& size) {

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
}

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

	sort(arr, size);
	print(arr, size);

	return 0;
}
