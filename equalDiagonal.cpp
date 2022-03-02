#include <iostream>
using namespace std;

bool equalDiagonal(int** matrix, const int& rows) {

	for (int i = 0; i < rows - 1; i++) {
		if (matrix[i][i] != matrix[i + 1][i + 1]) {
			return false;
		}
	}
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

	if (equalDiagonal(matrix, rows)) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
