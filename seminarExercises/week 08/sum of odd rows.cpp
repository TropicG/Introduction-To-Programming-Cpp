#include <iostream>
using namespace std;

double sumRow(int** matrix,const int& rows ,const int& j) {

	double sum = 0;
	for (int i = 0; i < rows; ++i) {
		sum += matrix[i][j];
	}

	return sum;
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
			while (cin.fail() || matrix[i][j] < 10 || matrix[i][j]>99) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument, try again: ";
				cin >> matrix[i][j];
			}
		}
	}

	double globalSum = 0;
	for (int j = 0; j < rows; ++j) {
		if (j & 2 != 0) {

			double sum = sumRow(matrix, rows, j);
			cout << "The sum of the " << j << " row is: " << sum;
			globalSum += sum;
			cout << endl;
		}
	}

	cout << "The glovalsum of the rows is: " << globalSum;

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
