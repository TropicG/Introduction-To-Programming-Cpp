#include <iostream>
using namespace std;

int main() {


	int kurpichki = 0;
	cout << "Enter how many kurpichki do you want to buy: ";
	if (!(cin >> kurpichki) || kurpichki < 0 || kurpichki > 1000000) {
		cout << "Invalid argument";
		return -1;
	}

	const int paket = 1, stack = 8, box = 40 * stack;

	int paketCount=0, stackCount=0, boxCount = 0;

	while (kurpichki >= box) {

		boxCount++;
		kurpichki -= box;

	}

	while (kurpichki >= stack) {

		stackCount++;
		kurpichki -= stack;
	}

	while (kurpichki >= paket) {

		paketCount++;
		kurpichki -= paket;

	}

	cout << "The best purchase for you is: " << boxCount << " boxes, " << stackCount << " stacks and " << paketCount << " pakets";

	return 0;
}
