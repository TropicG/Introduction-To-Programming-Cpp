#include <iostream>
using namespace std;

int main() {


	int h = 0, m = 0, t = 0;

	cout << "Enter the hours of the flight: ";
	cin >> h;
	if (h < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the mins of the flight: ";
	cin >> m;
	if (m < 0 || m >59) {
		cout << "Invalid argument";
		return -2;
	}

	cout << "Enter the number of mins the flight will be late: ";
	cin >> t;
	if (t < 0) {
		cout << "Invalid argument";
		return -3;
	}


	int hours = 0;
	while (t > 60) {
		hours++;
		t -= 60;
	}

	cout << "The flight will arrive at: " << h + hours << ":" << m + t;
	return 0;
}
