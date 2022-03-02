#include <iostream>
using namespace std;

int main() {


	float x = 0, y = 0;
	cout << "Enter the x coordinates of the point: ";
	if (!(cin >> x)) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the y coordinates of the point: ";
	if (!(cin >> y)) {
		cout << "Invalid argument";
		return -2;
	}

	if (x == 0 && y == 0) {
		cout << "The point is in the center";
		return 0;
	}
	else if (x >= 0 && y >= 0) {
		cout << "The point is in the I quadrant";
		return 1;
	}
	else if (x <= 0 && y >= 0) {
		cout << "The point is in the II quadrant";
		return 2;
	}
	else if (x <= 0 && y <= 0) {
		cout << "The point is in the III quadrant";
		return 3;
	}
	else {
		cout << "The point is in the IV quadrant";
		return 4;
	}
}
