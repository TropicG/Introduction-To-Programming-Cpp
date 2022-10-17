#include <iostream>
using namespace std;

bool inside(int** positions, const int& size, const int& i, const int& j) {

	for (int n = 0; n < size; ++n) {


		if (positions[n][0] == i && positions[n][1] == j) {
			return true;
		}

	}

	return false;

}

int main() {

	//rows and collums of the playground
	int rows = 0, cols = 0;

	//inputting the rows
	cout << "Enter the number of rows of the playground for the robot: ";
	if (!(cin >> rows) || rows < 0) {
		cout << "Invalid argument for rows, try again!";
		return -1;
	}

	//inputting the colls
	cout << "Enter the number of collums of the playground for the robot: ";
	if (!(cin >> cols) || cols < 0) {
		cout << "Invalid argument for collums, try again!";
		return -2;
	}

	//the matrix that will be filled with 'R', 'U', 'L', 'D'
	char** playground = new char* [rows];

	//memory allocation check
	if (!playground) {

		cout << "Bad memory allocaiton";
		for (int i = 0; i < rows; ++i) {
			delete[] playground[i];
		}
		delete[] playground;

		return -3;
	}

	//memory allocation of the 2d matrix
	for (int i = 0; i < rows; ++i) {

		playground[i] = new char[cols];

		//memory allocation check for each row
		if (!playground[i]) {

			cout << "Bad memory allocaiton";
			for (int i = 0; i < rows; ++i) {
				delete[] playground[i];
			}
			delete[] playground;

			return -4;

		}

	}

	//inputting the playground
	cout << "Input your playground: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {


			cin >> playground[i][j];

			//if the user's input is different from 'R', 'U', 'D' or 'L' we ask the user to input again
			while (playground[i][j] != 'R' && playground[i][j] != 'U' && playground[i][j] != 'L' && playground[i][j] != 'D') {

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Your input must be one of the characters: U, R, D, L";
				cin >> playground[i][j];

			}

		}
	}

	//iBest and jBest are used to keep track of the location of the tile on which we have the longest route
	//best is used to keep track of the best route on coordinates iBest and jBest on the matrix
	int iBest = 0, jBest = 0, best = 0;

	//we check for best route each and every title of the playground
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			//iCurrent and jCurrent are used to keep track of the start of the route from this tile
			int iCurrent = i, jCurrent = j, current = 0, index = 0;

			//this array is used to keep track of all tiles that the robot has passed by from current position
			int** positions = new int* [rows * cols];

			if (!positions) {

				cout << "Bad memory allocaiton";
				for (int i = 0; i < rows * cols; ++i) {
					delete[] positions[i];
				}
				delete[] positions;

				return -3;
			}
			for (int i = 0; i < rows * cols; ++i) {
				positions[i] = new int[2];
				if (!positions[i]) {
					cout << "Bad memory allocaiton";
					for (int i = 0; i < rows * cols; ++i) {
						delete[] positions[i];
					}
					delete[] positions;

					return -3;
				}
			}


			//until the robot reached the end of the playground or reached a tile for the second time
			while (true) {


				//if the current tile is R we move the robot on R
				if (playground[iCurrent][jCurrent] == 'R') {

					jCurrent += 1;

					//checks if we have reached the end of if the coordinates are inside the positions array
					if (jCurrent > (cols - 1) || inside(positions, index, iCurrent, jCurrent)) {

						//if the current route is longer than the best
						if (current > best) {

							//the program remembers the positions of the start of this route as best
							iBest = i;
							jBest = j;

							//and takes the lenght of this route as best
							best = current;
						}

						break;
					}

					//increase the count of succsessful operations
					current++;

					//we add the coordinates to the once that were passed by the robot
					positions[index][0] = iCurrent;
					positions[index][1] = jCurrent;
					index++;


				}

				//if the current tile is L we move the robot on left
				if (playground[iCurrent][jCurrent] == 'L') {

					jCurrent -= 1;

					if (jCurrent < 0 || inside(positions, index, iCurrent, jCurrent)) {

						if (current > best) {

							iBest = i;
							jBest = j;
							best = current;
						}

						break;
					}


					current++;
					positions[index][0] = iCurrent;
					positions[index][1] = jCurrent;
					index++;

				}

				//if the current tile is U we move the robot on up
				if (playground[iCurrent][jCurrent] == 'U') {


					iCurrent -= 1;

					if (iCurrent < 0 || inside(positions, index, iCurrent, jCurrent)) {

						if (current > best) {

							iBest = i;
							jBest = j;
							best = current;
						}

						break;

					}

					current++;
					positions[index][0] = iCurrent;
					positions[index][1] = jCurrent;
					index++;

				}

				//if the current tile is D we move the robot down
				if (playground[iCurrent][jCurrent] == 'D') {


					iCurrent += 1;


					if (iCurrent > (rows - 1) || inside(positions, index, iCurrent, jCurrent)) {

						if (current > best) {

							iBest = i;
							jBest = j;
							best = current;
						}

						break;

					}

					current++;
					positions[index][0] = iCurrent;
					positions[index][1] = jCurrent;
					index++;

				}
			}

			for (int i = 0; i < rows * cols; ++i) {
				delete[] positions[i];
			}
			delete[] positions;

		}
	}


	cout << "The title with the best route is: " << iBest << " " << jBest;

	for (int i = 0; i < rows; ++i) {
		delete[] playground[i];
	}
	delete[] playground;
	return 0;
}
