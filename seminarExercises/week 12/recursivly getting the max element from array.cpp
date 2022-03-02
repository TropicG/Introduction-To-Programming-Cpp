#include <iostream>
using namespace std;

int maxElement(int* numbers,int index, int max) {

	if (index < 0) {
		return max;
	}

	if (numbers[index] > max) {
		return maxElement(numbers, index - 1, numbers[index]);
	}

	return maxElement(numbers, index - 1, max);
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

	cout << "Input the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> numbers[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter an valid argument: ";
			cin >> numbers[i];
		}
	}

	cout << "The max element in the array is: " << maxElement(numbers, size - 1, 0);
	delete[] numbers;
	return 0;
}
