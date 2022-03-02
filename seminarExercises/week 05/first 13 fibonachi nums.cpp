#include <iostream>
using namespace std;

int fibonachi(int num) {

	if (num == 0) {
		return 0;
	}

	if (num == 1) {
		return 1;
	}

	return fibonachi(num - 1) + fibonachi(num - 2);

}

int main() {


	for (int i = 0; i < 13; ++i) {

		cout << fibonachi(i) << " ";

	}


	return 0;
}
