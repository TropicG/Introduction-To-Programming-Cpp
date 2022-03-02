#include <iostream>
using namespace std;

int main() {


	int hour1 = 0, min1 = 0;
	int hour2 = 0, min2 = 0;
	char c;

	cout << "Enter the first hour and mins: ";
	cin >> hour1 >> c >>min1;

	if (hour1 < 0 || hour1 > 23 || min1 < 0 || min1 > 59) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "Enter the second hour and mins: ";
	cin >> hour2 >> c >> min2;

	if (hour2 < 0 || hour2 > 23 || min2 < 0 || min2 > 59) {
		cout << "Invalid argument";
		return -2;
	}

	if ((hour1 > hour2) || (hour1 == hour2 && min1 >= min2)) {
		cout << "Invalid argument";
		return -3;
	}


	if (min1 > min2) {
		cout << "The result is " <<  hour2 - hour1 << ":" << min1 - min2;
	}
	else if (min2 > min1) {
		cout << "The result is " << hour2 - hour1 << ":" << min2 - min1;
	}
	else {
		cout << "The result is " << hour2 - hour1 << ":" << min1 - min2;
	}
}
