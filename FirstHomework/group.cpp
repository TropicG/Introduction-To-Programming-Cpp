#include <iostream>
using namespace std;

//we start from the second index until we reached 35th and we store the value from the previous function index
int recursion(int k, int previous) {


	//end of recursion if the index of the function reached 35
	if (k == 35) {

		//if the previous number is divided by 2 we return the function with
		//previous/2
		if (previous % 2 == 0 ) {
			return previous / 2;
		}

		//else
		else {
			return 3 * previous + 1;
		}
	}

	//if the previous value is divided by 2 we return the function with increased index and previous /2
	if (previous % 2 == 0) {
		return recursion(k + 1, previous / 2);
	}

	//else we return the function with increase index and 3*previous + 1
	else {
		return recursion(k + 1, 3 * previous + 1);
	}


}

int main() {


	int x = 0;

	cout << "Enter your number: ";
	if(!(cin>>x)){
		cout << "Invalid argument!";
		return -1;
	}

	//we start from the second index since the f1(x) = x
	cout << "The value of f35(x) is: " << recursion(2, x);


	return 0;
}
