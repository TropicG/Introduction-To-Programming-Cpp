#include <iostream>
using namespace std;

void reverse(int* arr, const int& size) {

	int helper[100];
	int helperIndex = 0;

	for (int i = size - 1; i >= 0; --i) {
		helper[helperIndex] = arr[i];
		helperIndex++;
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = helper[i];
	}
}

void reverseSwap(int* arr, const int& size) {

	int temp;

	for (int i = 0; i < size / 2; ++i) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
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

	reverse(arr, size);
	print(arr, size);

	return 0;
}
