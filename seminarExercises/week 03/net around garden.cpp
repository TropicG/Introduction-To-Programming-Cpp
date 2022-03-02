#include <iostream>
using namespace std;


int main() {


	double radius = 0;
	cout << "Enter the radius of the garden: ";
	cin >> radius;

	if (radius < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "There would need about " << 2 * 3.14*radius << " net";


	return 0;
}
