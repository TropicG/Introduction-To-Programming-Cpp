#include <iostream>
#include <cstring>
using namespace std;

bool inside(int* used, const int& usedIndex, const int& index) {


	for (int i = 0; i < usedIndex; ++i) {
		if (used[i] == index) {
			return true;
		}
	}

	return false;
}

int getValue(const char symb, const char* letters, int* values, const int& n) {


	for (int i = 0; i < n; ++i) {

		if (symb == letters[i]) {
			return values[i];
		}

	}

	return 0;
}


bool validAlgebra(char* algebra) {


	int size = strlen(algebra);

	for (int i = 0; i < size; ++i) {

		if (!(algebra[i] >= 'a' && algebra[i] <= 'z') && algebra[i] != '+' && algebra[i] != '.') {
			return false;
		}

	}

	if (algebra[0] == '.' || algebra[0] == '+') {
		return false;
	}

	for (int i = 1; i < size - 1; ++i) {


		if (algebra[i] == '+' && (!(algebra[i - 1] >= 'a' && algebra[i - 1] <= 'z') || !(algebra[i + 1] >= 'a' && algebra[i + 1] <= 'z'))) {
			return false;
		}

		if (algebra[i] == '.' && (!(algebra[i - 1] >= 'a' && algebra[i - 1] <= 'z') || !(algebra[i + 1] >= 'a' && algebra[i + 1] <= 'z'))) {
			return false;
		}
	}

	if (algebra[size - 1] == '.' || algebra[size - 1] == '+') {
		return false;
	}

	return true;
}


int calculate(const char* algebra, const int& size, const int& n, const char* letters, int* values) {


	int* used = new int[size];
	if (!used) {
		cout << "Bad memory input";
		return -100000;
	}
	int usedIndex = 0;


	int prod = 0, sum = 0;
	for (int i = 1; i < size - 1; ++i) {

		if (algebra[i] == '.') {

			int currentProd = 1;

			if (!inside(used, usedIndex, i - 1)) {
				currentProd *= getValue(algebra[i - 1], letters, values, n);
				used[usedIndex] = i - 1;
				usedIndex++;
			}

			if (!inside(used, usedIndex, i + 1)) {
				currentProd *= getValue(algebra[i + 1], letters, values, n);
				used[usedIndex] = i + 1;
				usedIndex++;
			}

			prod += currentProd;

		}

	}

	for (int i = 1; i < size - 1; ++i) {

		if (algebra[i] == '+') {

			if (!inside(used, usedIndex, i - 1)) {
				sum += getValue(algebra[i - 1], letters, values, n);
				used[usedIndex] = i - 1;
				usedIndex++;
			}

			if (!inside(used, usedIndex, i + 1)) {
				sum += getValue(algebra[i + 1], letters, values, n);
				used[usedIndex] = i + 1;
				usedIndex++;
			}

		}

	}

	delete[] used;
	return sum + prod;
}


int main() {


	int n = 0;
	cout << "Enter how many letters are you going to input: ";
	if (!(cin >> n) || n < 0) {
		cout << "Invalid argument, try again: ";
	}

	char* letters = new char[n + 1];
	if (!letters) {
		cout << "Bad memory allocation";
		delete[] letters;
		return -1;
	}

	int* values = new int[n];
	if (!values) {
		cout << "Bad memory allocation";
		delete[] values;
		return -2;
	}

	cout << "Enter all your letters: ";
	for (int i = 0; i < n; ++i) {

		cin >> letters[i];
		while (!(letters[i] >= 'a' && letters[i] <= 'z')) {

			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, try again!: ";
			cin >> letters[i];

		}

	}

	cout << "Enter all the values for the letters: ";
	for (int i = 0; i < n; ++i) {

		cin >> values[i];
		while (cin.fail()) {

			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, try again: ";
			cin >> values[i];

		}

	}


	char algebra[128];
	cout << "Enter your equation: ";
	cin >> algebra;


	while (!validAlgebra(algebra)) {

		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid algebra equation try again: ";
		cin >> algebra;

	}

	int equation = calculate(algebra, strlen(algebra), n, letters, values);
	if (equation == -100000) {
		delete[] values;
		delete[] letters;
		return -4;
	}

	cout << "The result from the equation is: " << equation;


	delete[] values;
	delete[] letters;
	return 0;
}