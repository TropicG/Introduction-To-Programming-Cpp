#include <iostream>
using namespace std;

bool inside(int** A, const int& size, const int& target) {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (target == A[i][j]) {
				return true;
			}
		}
	}

	return false;
}

bool Up(int** A,const int& size, const int& sx, const int& sy, const int& target) {

	if (sx < 0) {
		return false;
	}

	if (A[sx][sy] > target || A[sx][sy] >= 10) {
		return false;
	}

	return true;
}

bool Down(int** A, const int& size, const int& sx, const int& sy, const int& target) {

	if (sx >= size) {
		return false;
	}

	if (A[sx][sy] > target || A[sx][sy] >= 10) {
		return false;
	}

	return true;
}

bool Left(int** A,const int& size, const int& sx, const int& sy, const int& target) {

	if (sy < 0) {
		return false;
	}
	if (A[sx][sy] > target || A[sx][sy] >= 10) {
		return false;
	}

	return true;
}

bool Right(int** A,const int& size, const int& sx, const int& sy, const int& target) {

	if (sy >= size) {
		return false;
	}
	if (A[sx][sy] > target || A[sx][sy] >= 10) {
		return false;
	}

	return true;
}

bool reachable(int** A, int size, int sx, int sy, int target) {

	if (sx >= size || sx < 0 || sy >= size || sy < 0) {
		return false;
	}

	if (A[sx][sy] >= 10){
		return false;
	}

	if (A[sx][sy] == target) {
		return true;
	}

	if (!Up(A, size, sx - 1, sy, target) && !Down(A, size, sx + 1, sy, target) && !Left(A, size, sx, sy - 1, target) && !Right(A, size, sx, sy + 1, target)) {
		return false;
	}

	A[sx][sy] = 10;

	bool up = reachable(A, size, sx - 1, sy, target);
	if (up) return true;

	bool left = reachable(A, size, sx, sy - 1, target);
	if (left) return true;

	bool down = reachable(A, size, sx + 1, sy, target);
	if (down) return true;

	bool right = reachable(A, size, sx, sy + 1, target);
	if (right) return true;

	return false;
}
int main() {

	//getting the size of the square matix
	int size = 0;
	cout << "Enter how many rows and collums you want to have: ";
	cin >> size;
	while (cin.fail() || size < 2 || size > 100) {
		cin.clear();
		cin.ignore(64,'\n');
		cout << "Invalid argument, try again: ";
		cin >> size;
	}

	//the matrix
	int** A = new int* [size];
	if (!A) {
		cout << "Bad memory allocation";
		for (int i = 0; i < size; ++i) {
			delete[] A[i];
		}
		delete[] A;
		return -1;
	}
	for (int i = 0; i < size; ++i) {
		A[i] = new int[size];
		if (!A[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < size; ++i) {
				delete[] A[i];
			}
			delete[] A;
			return -2;
		}
	}

	cout << "Input your matrix: ";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cin >> A[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore(64, '\n');
				cout << "Invalid argument, try again: ";
				cin >> A[i][j];
			}
		}
	}

	int sx = 0, sy = 0;
	cout << "Enter the coordianes for the start of the route: ";
	cin >> sx;
	while (cin.fail() || sx < 0 || sx >= size) {
		cin.clear();
		cin.ignore(64, '\n');
		cout << "Invalid argument, try again: ";
		cin >> sx;
	}
	cin >> sy;
	while (cin.fail() || sy < 0 || sy >= size) {
		cin.clear();
		cin.ignore(64, '\n');
		cout << "Invalid argument, try again; ";
		cin >> sy;
	}

	int target = 0;
	cout << "Enter the desired end of the route: ";
	cin >> target;
	while (!inside(A, size, target) || target > 10) {
		cin.clear();
		cin.ignore(64, '\n');
		cout << "Invalid argument, try again; ";
		cin >> target;
	}

	if (reachable(A, size, sx, sy, target)) {
		cout << "It is reachable";
	}
	else {
		cout << "It is not";
	}

	for (int i = 0; i < size; ++i) {
		delete[] A[i];
	}
	delete[] A;
	return 0;
}
