#include <iostream>
using namespace std;

int main() {

	int upSpeed = 0, downSpeed = 0;

	cout << "Enter the down speed of the elevetor: ";
	if (!(cin >> downSpeed) || downSpeed < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the up speed of the elevetor: ";
	if (!(cin >> upSpeed) || upSpeed < 0) {
		cout << "Invalid argument";
		return -2;
	}

	int floors = 0;
	cout << "Enter the number of floors: ";
	if (!(cin >> floors) || floors < 0) {
		cout << "Invalid argument";
		return -3;
	}

	int prev = 0, current = 0, time = 0;

	cout << "Enter the first floor: ";
	cin >> prev;

	cout << "Enter the route of the elevetor: ";
	for (int i = 1; i < floors; i++) {

		cin >> current;
		if (current > prev) {
			time += (upSpeed * (current - prev));
		}
		if (current < prev) {
			time += (downSpeed * (current - prev));
		}
		prev = current;
	}

	cout << "The time of the all route for the elevetor is: " << time << " seconds";
	return 0;
}
