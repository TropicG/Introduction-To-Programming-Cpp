#include <iostream>
using namespace std;

int main() {

	//number of digits
	int count = 0;
	cout << "Enter the number of digits for the barcodes: ";
	if (!(cin >> count)) {
		cout << "Invalid argument!";
		return 0;
	}

	//if the number of digit is not divisible by 8 it throws error
	while (count % 8 != 0) {
		cout << "Invalid number of digits for the barcodes, the number of digits should be divided by 8" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Try again: ";
		cin >> count;
	}

	//storing the different kind of marmalades
	int blueberry = 0;
	int peaches = 0;
	int rosehip = 0;

	//storing the two types of digits, left one is for those digits we dont need
	//the right one is for those we need
	int digit = 0, important = 0;

	//loops until we have no barcodes to check
	while (count != 0) {

		//storing the 4giti part of the barcode we need
		int num = 0;

		//stores the first useless digit from the barcode
		for (int i = 0; i < 3; ++i) {
			cin >> digit;
		}

		//inputes the 3 important digit from the barcode
		for (int i = 0; i < 3; ++i) {

			cin >> important;

			//if the digit is 0 we * num by 10
			if (important == 0) {
				num *= 10;
			}

			//else we add to num the current digit and we add 10 to num
			else {
				num += important;
				num *= 10;
			}

		}

		//inputing the last important digit
		cin >> important;

		//if its zero we multiply by 10
		if (important == 0) {
			num *= 10;
		}

		//else we add the last digit to num
		else {
			num += important;
		}

		//inputing the last digit of the barcode
		cin >> digit;

		//if the 4digit num is %7, %13 or %17 we add to the corresponding marmalade
		if (num % 7 == 0) {
			blueberry++;
		}

		if (num % 13 == 0) {
			peaches++;
		}

		if (num % 17 == 0) {
			rosehip++;
		}

		//we subtract 8 from the count so signalise that we checked one barcode
		count -= 8;

	}


	//inputting the results
	cout << "Marmalade of blueberries: " << blueberry << endl;
	cout << "Marmalade of peaches: " << peaches << endl;
	cout << "Marmalade of rosehip: " << rosehip;

	return 0;




	return 0;
}
