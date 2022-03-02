#include <iostream>
using namespace std;

int main() {

	int numbers = 0;
	cout << "Enter the count of numbers you are going to enter: ";

	int previous = 0, current = 0;
	int sum = 0, route = 0;
	int currentRoute = 1, currentSum = 1;

	for (int i = 0; i < 13; ++i) {

		cin >> current;

		if (current == previous) {
			currentSum += current;
			currentRoute++;
			previous = current;
		}
		else {
			if (currentRoute > route) {
				route = currentRoute;
				sum = currentSum;
				previous = current;
			}
			else{
				previous = current;
			}

			currentRoute = 1; currentSum = 1;
		}
	}

	cout << "The longest route with its sum is: " << sum;

	return 0;
}
