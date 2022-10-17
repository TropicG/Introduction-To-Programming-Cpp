#include <iostream>
using namespace std;

void transformMatrix(int** A, int** B, const int& rows, const int& cols) {

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			if (A[i][j] < B[i][j]) {
				A[i][j] = B[i][j];
			}
			if (A[i][j] > B[i][j]) {
				A[i][j] -= (2 * A[i][j]);
			}
		}

	}
}

int main() {

	int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0;

	cout << "Enter the rows for the first matrix: ";
	cin >> rows1;
	if (!(cin >> rows1) || rows1 < 0) {
		cout << "Invalid argument for rows for the first matrix";
		return -1;
	}

	cout << "Enter the collums for the first matrix: ";
	cin >> cols1;
	if (!(cin >> cols1) || cols1 < 0) {
		cout << "Invalid argument for collums for the first matrix";
		return -2;
	}

	cout << "Enter the rows for the second matrix: ";
	cin >> rows2;
	if (!(cin >> rows2) || rows2 < 0) {
		cout << "Invalid argument for rows for the second matrix";
		return -3;
	}

	cout << "Enter the collums for the second matrix: ";
	cin >> cols2;
	if (!(cin >> cols2) || cols2 < 0) {
		cout << "Invalid argument for collums for the second matrix";
		return -4;
	}


	if (rows2 < rows1) {
		rows1 = rows2;
	}
	if (cols2 < cols1) {
		cols1 = cols2;
	}

	int** A = new int* [rows1];
	if (!A) {

		cout << "Bad memory allocation for the first matrix!";

		for (int i = 0; i < rows1; ++i) {
			delete[] A[i];
		}
		delete[] A;

		return -1;

	}

	for (int i = 0; i < rows1; ++i) {

		A[i] = new int[cols1];

		if (!A[i]) {
			cout << "Bad memory allocation for the first matrix!";

			for (int i = 0; i < rows1; ++i) {
				delete[] A[i];
			}
			delete[] A;

			return -2;

		}
	}


	int** B = new int* [rows2];
	if (!B) {
		cout << "Bad memory allocation for the second matrix!";

		for (int i = 0; i < rows2; ++i) {
			delete[] B[i];
		}
		delete[] B;


		return -3;
	}

	for (int i = 0; i < rows2; ++i) {
		B[i] = new int[cols2];

		if (!B[i]) {
			cout << "Bad memory allocation for the second matrix";

			for (int i = 0; i < rows2; ++i) {
				delete[] B[i];
			}
			delete[] B;

			return -4;
		}
	}


	cout << "Input the first matrix: ";
	for (int i = 0; i < rows1; ++i) {
		for (int j = 0; j < cols1; ++j) {

			cin >> A[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Invalid argument for the element at position " << i << " " << j << " in the first matrix, try again: ";
				cin >> A[i][j];
			}

		}
	}

	cout << "Input the second matrix: ";
	for (int i = 0; i < rows2; ++i) {
		for (int j = 0; j < cols2; ++j) {

			cin >> B[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Invalid argument for the element at position " << i << " " << j << " in the second matrix, try again: ";
				cin >> B[i][j];
			}

		}
	}

	transformMatrix(A, B, rows1, cols1);
	cout << "The first matrix after the tranformation is: " << endl;
	for (int i = 0; i < rows1; ++i) {
		for (int j = 0; j < cols1; ++j) {

			cout << A[i][j] << " ";

		}

		cout << endl;
	}


	for (int i = 0; i < rows1; ++i) {
		delete[] A[i];
	}
	delete[] A;
	for (int i = 0; i < rows2; ++i) {
		delete[] B[i];
	}
	delete[] B;

	return 0;
}
