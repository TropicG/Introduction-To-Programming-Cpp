#include <iostream>
using namespace std;


int main() {


	int hours = 0;
	cout << "Enter the hours: ";
	cin >> hours;

	if (hours < 0 || hours > 10000) {
		cout << "Bad argument";
		return -1;
	}

	int count = 0;
	while (hours > 12) {

		count++;
		hours -= 12;

	}

	cout << "After these hours there would be " << count << " clock cycles and the time will be: " << 12 + hours;
	return 0;
}
