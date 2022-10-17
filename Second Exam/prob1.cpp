#include <iostream>
using namespace std;

bool dublicateDigits(const int& number, int copy) {

	if (number < 10) {
		return false;
	}

	if (copy == 0) {
		return false;
	}

	int lastDigit = copy % 10, helper = number, count = 0;

	while (helper != 0) {

		if (helper % 10 == lastDigit) {
			count++;
		}

		helper /= 10;

	}

	if (count >= 2) {
		return true;
	}

	return dublicateDigits(number, copy / 10);

}


int* collect(int** matrix, const int& n) {


	int count = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (dublicateDigits(matrix[i][j], matrix[i][j])) {
				count++;
			}


		}
	}

	int* collectArr = new int[count];
	if (!collectArr) {
		return nullptr;
	}

	int collectIndex = 0;


	for (int i = n; i <= 1; --i) {

		for (int j = 0; j <= n - i; ++j) {

			if (dublicateDigits(matrix[i + j][j], matrix[i + j][j])) {
				collectArr[collectIndex] = matrix[i][j];
				collectIndex++;
			}
		}

	}

	for (int i = 0; i < n; ++i) {
		if (dublicateDigits(matrix[i][i], matrix[i][i])) {
			collectArr[collectIndex] = matrix[i][i];
			collectIndex++;
		}
	}

	for (int j = 1; j < n-1; ++j) {
		
		int helper = j;
		for (int i = 0; i < n; ++i) {

			if (helper == n) {
				break;
			}

			if (dublicateDigits(matrix[i][helper], matrix[i][helper])) {
				collectArr[collectIndex] = matrix[i][helper];
				collectIndex++;
			}

			helper++;

		}


	}

	if (dublicateDigits(matrix[0][n - 1], matrix[0][n - 1])) {
		collectArr[collectIndex] = matrix[0][n-1];
		collectIndex++;
	}


	return collectArr;
}


int main() {



	int n = 0;
	cout << "Enter the number of rows and collums for your matrix: ";
	if (!(cin >> n) || n < 1 || n >30) {
		cout << "Invalid argument";
		return -1;
	}

	int** matrix = new int* [n];
	if (!matrix) {

		cout << "Bad memory allocation";
		for (int i = 0; i < n; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return -2;
	}
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];

		if (!matrix[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < n; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return -3;
		}
	}

	int test = 0;
	cin >> test;
	if (dublicateDigits(test, test)) {
		cout << "true";
		return 2;
	}


	cout << "Input your matrix: ";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			cin >> matrix[i][j];
			while (cin.fail()) {

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, please try again: ";
				cin >> matrix[i][j];

			}

		}
	}

	int* collectArr = collect(matrix, n);
	if (collectArr == nullptr) {
		cout << "Bad memory allocation";
		for (int i = 0; i < n; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		delete[] collectArr;
		return -5;
	}


	cout << "Printing all the numbers: ";
	for (int i = 0; i < n; ++i) {
		if (collectArr[i] == 0) {
			break;
		}
		cout << collectArr[i] << " ";
	}


	for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] collectArr;
	return 0;
}