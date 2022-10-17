#include <iostream>
using namespace std;


int length(int k) {

	int len = 0;
	while (k > 0) {
		len++;
		k /= 10;
	}


	return len;
}

bool inside(int num, int k) {

	int help = pow(10, length(k));

	if (num < 10 && num % 10 != k) {
		return false;
	}

	if (num % help == k) {
		return true;
	}

	return inside(num / 10, k);

}


int pow(int number, int power) {

	if (power == 1) {
		return number;
	}

	return pow(number * number, power - 1);

}

int main() {

	int n = 0, k = 0;

	if (!(cin >> n) || !(cin>>k)) {
		cout << "Invalid argument";
		return -1;
	}

	if (length(k) == length(n) || length(k) > length(n) || length(n)-length(k)==1) {
		return false;
	}



	if (length(k) == 1 && length(n) > 2) {

		int last = n % 10;
		int first = n % pow(10, length(n)-1);

		if (!inside(n, k)) {
			return false;
		}

		if (last != k && first != k) {
			return true;
		}
		else if (last == k && first == k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else if (last != k && first == k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else if (last == k && first != k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else {
			return false;
		}


	}
	else {

		int last = n & pow(10, length(k));
		int first = n / pow(10, length(k));

		if (!inside(n, k)) {
			return -10;
		}

		if (last != k && first != k) {
			return true;
		}
		else if (last == k && first == k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else if (last != k && first == k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else if (last == k && first != k && inside(((n / 10) % pow(10, length(n) - 1)), k)) {
			return true;
		}
		else {
			return false;
		}

	}

}
