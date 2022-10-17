#include <iostream>
using namespace std;

bool interesting(int num, int previous) {

	//end of recursion if the last two digits are with different parity we return true
	if (num < 10 && num % 2 != previous % 2) {
		return true;
	}

	//end of recursion if the last two digits are with equal parity we return false
	if (num < 10 && num % 2 == previous % 2) {
		return false;
	}

	//strotting the current digit and the next digit
	int current = num % 10, next = (num / 10) % 10;

	//if current has qeual parity with next or with previous we return false
	if (current % 2 == next % 2 || current % 2 == previous % 2) {
		return false;
	}

	//we return the function with the number divided by 10 and we take the last digit
	return interesting(num / 10, num % 10);
}

int main() {

	int a = 0, b = 0;
	cout << "Enter a: ";
	if (!(cin >> a) || a<0) {
		cout << "Invalid argument for a!";
		return -1;
	}

	cout << "Enter b: ";
	if (!(cin >> b) || b<0) {
		cout << "Invalid argument for b!";
		return -2;
	}

	if (a > b) {
		cout << "a cant be higher than b!";
		return -3;
	}

	//sum of interesting numbers
	int sum = 0;

	//we loop with i starting with a until we finish the range with b
	for (int i = a; i <= b; ++i) {

		//if the current number is below 10 we automaticlly add it to the sum
		if (i < 10) {
			sum += i;
		}

		//if the current number is interesting and is higher than 10 we add it to the sum
		if (interesting(i / 10, i % 10) && i >= 10) {
			sum += i;
		}
	}

	cout << "The sum of interesting numbers in this range is: " << sum;
	return 0;
}
