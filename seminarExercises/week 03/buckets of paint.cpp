#include <iostream>
using namespace std;


int main() {


	int l = 0, w = 0, a = 0;

	cout << "Enter the length of the room: ";
	cin >> l;

	if (l < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the width of the room: ";
	cin >> w;

	if (w < 0) {
		cout << "Invalid argument";
		return -2;
	}

	cout << "Enter how many m^2 one bucket of paint paints: ";
	cin >> a;

	if (a < 0) {
		cout << "Invalid argument";
		return -3;
	}

	int area = l * w;
	int count = 1;

	while (area > a) {

		count++;
		area -= a;

	}
	cout << "The requirment of bucket is: " << count;
}
