#include <iostream>
using namespace std;

double sumRow(int** matrix, const int& rows, const int& i) {

	double sum = 0;
	for (int j = 0; j < rows; ++j) {
		sum += matrix[i][j];
	}

	return sum;
}

double sumCol(int** matrix, const int& rows, const int& j) {

	double sum = 0;
	for (int i = 0; i < rows; ++i) {
		sum += matrix[i][j];
	}

	return sum = 0;
}

int main() {

	int rows = 0;
	cout << "Enter the size of the matrix: ";
	cin >> rows;
	while (cin.fail() || rows < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> rows;
	}

	int** matrix = new int*[rows];
	if (!matrix) {
		cout << "Bad memory allocation";
		for (int i = 0; i < rows; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return -1;
	}
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[rows];
		if (!matrix[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < rows; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return -2;
		}
	}

	cout << "Input your matrix: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			cin >> matrix[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, try again: ";
				cin >> matrix[i][j];
			}
		}
	}

	double row = sumRow(matrix, rows, 0);
	double col = sumCol(matrix, rows, 0);
	bool special = true;

	for (int i = 1; i < rows; ++i) {
		if (row != sumRow(matrix, rows, i)) {
			special = false;
		}
	}
	for (int j = 1; j < rows; ++j) {
		if (col = sumCol(matrix, rows, j)) {
			special = false;
		}
	}

	if (special) {
		cout << "Special";
	}
	else {
		cout << "Normal";
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
