#include <iostream>
#include <cstring>
using namespace std;

const int delivered = INT_MAX;

bool Up(int** matrix, int currentRow, int currentCollum) {

	if (matrix[currentRow - 1][currentCollum] == delivered || currentRow - 1 < 0) {
		return false;
	}

	return true;
}

bool Down(int** matrix, const int& size, int currentRow, int currentCollum) {

	if (matrix[currentRow + 1][currentCollum] == delivered || currentRow + 1 >= size) {
		return false;
	}

	return true;
}

bool Left(int** matrix, int currentRow, int currentCollum) {

	if (matrix[currentRow][currentCollum - 1] == delivered || currentCollum - 1 < 0) {
		return false;
	}

	return true;
}

bool Right(int** matrix, const int& size, int currentRow, int currentCollum) {

	if (matrix[currentRow][currentCollum + 1] == delivered || currentCollum + 1 >= size) {
		return false;
	}

	return true;
}

bool foundRoute(int** village, const int& size,const int& maxCapacity, int currentCapacity, int currentRow, int currentColumn,
				const int& homeRow, const int& homeColumn, const int& grannyRow, const int& grannyCollumn, bool happyGranny) {

	if (currentRow == homeRow && currentColumn == homeColumn && happyGranny) {
		return true;
	}

	if(village[currentRow][currentColumn]<=0){
		if (currentCapacity - village[currentRow][currentColumn] < 0) {
			return false;
		}
	}

	if(currentCapacity + village[currentRow][currentColumn] > maxCapacity) {
		return false;
	}

	bool up = Up(village, currentRow, currentColumn);
	bool down = Down(village, size, currentRow, currentColumn);
	bool left = Left(village, currentRow, currentColumn);
	bool right = Right(village, size, currentRow, currentColumn);

	if (!up && !down && !left && !right) {
		return false;
	}

	if (currentRow == grannyRow && currentColumn == grannyCollumn) {
		happyGranny = true;
	}

	village[currentRow][currentColumn] = delivered;

	if (up) {
		return foundRoute(village, size, maxCapacity, currentCapacity + village[currentRow][currentColumn],
			currentRow - 1, currentColumn, homeRow, homeColumn, grannyRow, grannyCollumn, happyGranny);
	}
	else if (down) {
		return foundRoute(village, size, maxCapacity, currentCapacity + village[currentRow][currentColumn],
			currentRow +1, currentColumn, homeRow, homeColumn, grannyRow, grannyCollumn, happyGranny);
	}
	else if (left) {
		return foundRoute(village, size, maxCapacity, currentCapacity + village[currentRow][currentColumn],
			currentRow, currentColumn-1, homeRow, homeColumn, grannyRow, grannyCollumn, happyGranny);
	}
	else {
		return foundRoute(village, size, maxCapacity, currentCapacity + village[currentRow][currentColumn],
			currentRow, currentColumn+1, homeRow, homeColumn, grannyRow, grannyCollumn, happyGranny);
	}
}

int main() {

	unsigned size = 0;
	cout << "Enter the size of the village: ";
	cin >> size;
	while (cin.fail() || size < 0 || size > 128) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> size;
	}

	unsigned maxCapacity = 0;
	cout << "The the max capacity of the truck: ";
	cin >> maxCapacity;
	while (cin.fail() || size < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for the max capacity of the truck, try again: ";
		cin >> maxCapacity;
	}

	unsigned currentCapacity = 0;
	cout << "Enter the current capacity of the truck: ";
	cin >> currentCapacity;
	while (cin.fail() || currentCapacity<0 || currentCapacity>maxCapacity) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for the current capacity of the truck, try again: ";
		cin >> currentCapacity;
	}

	int** village = new int* [size];
	if (!village) {
		cout << "Bad memory allocation";
		for (int i = 0; i < size; ++i) {
			delete[] village[i];
		}
		delete[] village;
		return -1;
	}
	for (int i = 0; i < size; ++i) {
		village[i] = new int[size];
		if (!village[i]) {
			cout << "Bad memory allocation";
			for (int i = 0; i < size; ++i) {
				delete[] village[i];
			}
			delete[] village;
			return -2;
		}
	}

	cout << "Input the village: ";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {

			cin >> village[i][j];
			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid argument in inputting the village, try again: ";
				cin >> village[i][j];
			}
		}
	}

	int homeRow = 0, homeCol = 0;
	cout << "Enter the starting coordinates: ";
	cin >> homeRow;
	while (cin.fail() || homeRow < 0 || homeRow >= size) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for starting row Coordiantes, try again: ";
		cin >> homeRow;
	}
	cin >> homeCol;
	while (cin.fail() || homeCol < 0 || homeCol >= size) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for the starting collum coordinates, try again: ";
		cin >> homeCol;
	}

	int grannyRow = 0, grannyCol = 0;
	cout << "Enter the granny coordinates: ";
	cin >> grannyRow;
	while (cin.fail() || grannyRow < 0 || grannyRow >= size) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for the granny row, try again: ";
		cin >> grannyRow;
	}
	cin >> grannyCol;
	while (cin.fail() || grannyCol < 0 || grannyCol >= size) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument for the granny col, try again: ";
		cin >> grannyCol;
	}


	if (foundRoute(village, size, maxCapacity, currentCapacity, homeRow, homeCol, homeRow, homeCol, grannyRow, grannyCol, false)) {
		cout << "Found route!";
	}
	else {
		cout << "Not possible route!";
	}

	for (int i = 0; i < size; ++i) {
		delete[] village[i];
	}
	delete[] village;
	return 0;
}
