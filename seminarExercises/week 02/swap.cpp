#include <iostream>
using namespace std;


int main() {


	int n = 0, m = 0;
	cout << "Enter the first number: ";
	cin >> n;

	cout << "Enter the second number: ";
	cin >> m;

	int temp = 0;

	temp = n;
	n = m;
	m = temp;

	cout << "Your first number is: " << m << endl;
	cout << "Your second number is: " << n;

	return 0;
}
