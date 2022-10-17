#include <iostream>
using namespace std;

bool inside(char ch, char* arr, int size) {

	bool in = false;

	for (int i = 0; i < size; ++i) {
		if (ch == arr[i]) {
			in = true;
		}
	}

	return in;
}

int main() {

	int size1 = 0, size2 = 0;
	if (!(cin >> size1) || !(cin >> size2)) {
		cout << "Invalid argument";
		return -1;
	}
	if (size1 < 0 || size2 < 0) {
		cout << "Sizes should be positive numbers";
		return -3;
	}
	if (size1 > 1024 || size2 > 1024) {
		cout << "Sizes should not be over 1024";
		return -4;
	}
	if (size2 > size1) {
		cout << "Size2 should not be higher than size1";
		return -2;
	}


	char firstArr[1024];
	char secondArr[1024];

	cout << "Enter the first array: ";
	for (int i = 0; i < size1; ++i) {
		cin >> firstArr[i];
	}

	cout << "Enter the second array: ";
	for (int i = 0; i < size2; ++i) {
		cin >> secondArr[i];
	}

	bool found = true;

	for (int i = 0; i < size1 - size2 + 1; ++i) {

		bool stringin = true;

		for (int j = 0; j < size2; ++j) {
			if (!inside(firstArr[j], secondArr, size2)) {
				stringin = false;
				break;
			}
		}

		if (stringin == true) {

			cout << "Rotation ";
			for (int k = 0; k < size2; ++k) {
				cout << secondArr[k];
			}
			cout << " found after deleteing " << i << " characters from the start";
			cout << " and " << size1 - size2 - i << " characters from the end";
			break;

		}

		if ((size1 - size2 + 1)-i==1) {
			found = false;
		}

	}


	if (found == false) {
		cout << "No rotation found!";
	}




	return 0;
}
