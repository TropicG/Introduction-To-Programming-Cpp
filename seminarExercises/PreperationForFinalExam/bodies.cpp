#include <iostream>
#include <cmath>
using namespace std;

struct Body {

	//coordinates of the body in the 3d space
	int x = 0, y = 0, z = 0;

	//mass and the speed of the body
	int mass = 0, speed = 0;

	//description of the body
	char description[20];

	//getting the potential energy of the body
	double getPotential() const {

		double h = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		return this->mass * 9.8 * h;
	}


	//getting the kinetic energy of the body
	double getKinetic() const {

		return (this->mass * (this->speed * this->speed)) / 2;
	}

	//getting the combiened power of kinetic energy and potential of the body
	double getPower() const {

		return this->getPotential() + this->getKinetic();
	}
};

//printing all the bodies
void printBodies(Body bodies[], unsigned n) {

	for (int i = 0; i < n; ++i) {

		cout << "The coordinates of the body are: (" << bodies[i].x << ", " << bodies[i].y << ", " << bodies[i].z << ")" << endl;
		cout << "The mass of the body is " << bodies[i].mass << " and the speed is " << bodies[i].speed << endl;
		cout << "The description of the body is: " << bodies[i].description << endl;
		cout << endl;
	}
}

Body findBody(Body bodies[], unsigned int n, char type) {

	//return the body with the highest potential energy
	if (type == 'p') {

		//gets the first body in the array to have the highest potential energy
		Body maxPotential = bodies[0];
		for (int i = 0; i < n; ++i) {

			//if other body has bigger potential energy, it itself becomes the body with maxPotential
			if (bodies[i].getPotential() > maxPotential.getPotential()) {
				maxPotential = bodies[i];
			}
		}

		//returns the body with maxPotential
		return maxPotential;
	}

	//return the body with the highest kinetic energy
	if (type == 'k') {

		//gets the fisrt body in the array to have the highest kinetic energy
		Body maxKinetic = bodies[0];
		for (int i = 0; i < n; ++i) {

			//if other body has bigger kinetic energy, it itself becomes the body with maxKinetic
			if (bodies[i].getKinetic() > maxKinetic.getKinetic()) {
				maxKinetic = bodies[i];
			}
		}

		//return the body with the highest kinetic energy
		return maxKinetic;
	}

	//gets the avarage of all the power in the array
	double avaragePower = 0;
	for (int i = 0; i < n; ++i) {
		avaragePower += bodies[i].getPower();
	}
	avaragePower /= n;

	//compares the absolute values of the bodies and stores the closest one
	Body close = bodies[0];
	for (int i = 0; i < n; ++i) {
		if (abs(avaragePower - close.getPower()) > abs(avaragePower - bodies[i].getPower())) {
			close = bodies[i];
		}
	}

	return close;
}

int main() {

	Body bodies[5];

	//inputting the bodies
	cout << "Enter the planets: ";
	for (int i = 0; i < 5; ++i) {

		Body body;

		cin >> body.x;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(64, '/n');
			cout << "Invalid argument. try again: ";
			cin >> body.x;
		}

		cin >> body.y;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(64, '/n');
			cout << "Invalid argument. try again: ";
			cin >> body.y;
		}

		cin >> body.z;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(64, '/n');
			cout << "Invalid argument. try again: ";
			cin >> body.z;
		}

		cin >> body.mass;
		while (cin.fail() || body.mass < 0) {
			cin.clear();
			cin.ignore(64, '/n');
			cout << "Invalid argument. try again: ";
			cin >> body.mass;
		}

		cin >> body.speed;
		while (cin.fail() || body.speed < 0) {
			cin.clear();
			cin.ignore(64, '/n');
			cout << "Invalid argument. try again: ";
			cin >> body.speed;
		}

		cin >> body.description;

		bodies[i] = body;
	}

	cout << endl;
	printBodies(bodies, 3);

	cout << "The body with the highest potential energy is: " << findBody(bodies, 5, 'p').getPotential() << endl;
	cout << "The body with the highest kinetic energy is: " << findBody(bodies, 5, 'k').getKinetic() << endl;
	cout << "The closest body's power to the avarage power is: " << findBody(bodies, 5, 'a').getPower();
	return 0;
}
