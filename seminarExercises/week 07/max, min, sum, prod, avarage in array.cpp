#include <iostream>
using namespace std;

int main() {

	int size = 0;

	cout << "Enter the size of the array: ";
	cin >> size;
	while (cin.fail() || size < 0 || size>100) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, plase try again: ";
		cin >> size;
	}

	int arr[100];
	cout << "Enter the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
		while (cin.fail() || arr[i]<0) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid argument, plase try again: ";
			cin >> size;
		}
	}

	int smallest = arr[0];
	for (int i = 0; i < size; ++i) {
		if (smallest > arr[i]) {
			smallest = arr[i];
		}
	}
	cout << "The smallest number in the array is: " << smallest << endl;

	int biggest = arr[0];
	for (int i = 0; i < size; ++i) {
		if (biggest < arr[i]) {
			biggest = arr[i];
		}
	}
	cout << "The biggest number in the array is: " << biggest << endl;

	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	cout << "The sum of the array is: " << sum << endl;

	int prod = 1;
	for (int i = 0; i < size; ++i) {
		prod *= arr[i];
	}
	cout << "The prod of the array is: " << prod << endl;

	cout << "The avarage of the array is: " << sum / size;
	return 0;
}
