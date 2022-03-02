#include <iostream>
using namespace std;

void transformMatrix(int** matrix, const int& rows) {

	for (int i = 0; i < rows; ++i) {
		for (int j = i+1; j < rows; ++j) {

			int temp = matrix[j][i];
			matrix[j][i] = matrix[i][j];
			matrix[i][j] = temp;
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

	transformMatrix(matrix, rows);

	cout << "Printing the matrix: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {

			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
