#include <iostream>
using namespace std;

//finding the size of given string
int sizeString(const char* string) {
	int size = 0;
	while (string[size] != '\0') {// adding to i until we meeat \0
		size++;
	}
	return size;
}

//when met 'e' in a string it's changed to '!'
//when met 'y' in a string it's changed to '*'
void changeString(char* string, const int& size) {
	for (int i = 0; i < size; i++) {
		if (string[i] == 'e') {
			string[i] = '!';
		}
		else if (string[i] == 'y') {
			string[i] = '*';
		}
	}
}

//convertes the numbers found in the string to an integer
int stringToInteger(const char string[]) {
	int number = 0;
	for (int i = 0; i < 4; i++) {
		number = number * 10 + (string[i] - '0');
	}
	return number;
}




int* countletters(int numbers1[], int numbers2[], const int& size) {

	//storing the sum of the elements from two different arrays on the same position
	int* sum = new int[size];
	//memory allocation validation
	if (sum == nullptr) {
		cout << "Unssussesfull allocation";
		delete[] sum;
		return nullptr;
	}

	//times when a number is coresponding to an ascsii symbol for 'a'-'z' or 'A'-'Z'
	int lowerLetter = 0, upperLetter = 0;

	//inputting sum
	for (int i = 0; i < size; i++) {
		sum[i] = numbers1[i] + numbers2[i];
	}

	//checking each elemet of sum does it corresponds to ascci numbers for letters
	for (int i = 0; i < size; i++) {
		if (sum[i] >= (int)'A' && sum[i] <= (int)'Z') {
			upperLetter++;
		}
		if (sum[i] >= (int)'a' && sum[i] <= (int)'z') {
			lowerLetter++;
		}
	}

	//storing here the information how mnay numbers corresponded to lower and upper case characters
	int* information = new int[2];
	//memory allocation validation
	if (information == nullptr) {
		cout << "Unssussesfull allocation";
		delete[] sum;
		delete[] information;
		return nullptr;
	}

	information[0] = upperLetter;
	information[1] = lowerLetter;

	delete[] sum;
	return information;

}

//return true of the given yaer is leap
bool checkDate(char string[]) {

	int year = stringToInteger(string);
	if ((year % 4 == 0) && (year % 100 != 0))
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}



char* revandreplace(char* string){

	//geting the size of the string
	int sizeStr = sizeString(string);
	changeString(string, sizeStr);

	char* revertedString = new char[sizeStr + 1];
	//memory allocation validation
	if (revertedString == nullptr) {
		cout << "Unssussesfull allocation";
		delete[] revertedString;
		return nullptr;
	}

	//position of the element in the end
	int positionReverted = sizeStr-1;

	//reverting a string
	for (int i = 0; i < sizeStr; i++) {
		//the last element of string becomes the first in revertedStinrg and so on
		revertedString[i] = string[positionReverted];
		positionReverted--;
	}

	//storing the terminated null at the end
	revertedString[sizeStr] = '\0';
	return revertedString;
}

int main() {
}