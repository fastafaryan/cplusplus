#include <iostream>
#include <string>
#include "car.h" // added car class file

using namespace std;

int main() {
	
	Car opel; // Create car object named opel.

	cout << "Car's id is " << opel.getId() << endl;

	opel.setOwner("Mustafa"); // Set owner name 
	cout << "Owner name is set to " <<  opel.getOwner() << endl; // Print owner name

	opel.setYear(2015); // Set car's model year to 2015
	cout << "Car's model year is set to " <<  opel.getYear() << endl; // Get car's model year

	// Setting and printing speed properties
	opel.changeSpeed(60); // Set car's speed 
	cout << "Car's speed is changed to " << opel.getSpeed() << endl; // print car's speed
	opel.accelerate();  // Accelerate car's speed 
	cout << "Car's speed is accelerated to " << opel.getSpeed() << endl; // print car's speed
	opel.stop(); // set speed to 0
	cout << "Car is stopped. It speed is " << opel.getSpeed() << endl; // print car's speed

	// Setting and printing direction properties
	opel.setDirection(60);
	cout << "Car's current direction is set to " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turnLeft(900);
	cout << "Car is turned to left. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turnRight(150);
	cout << "Car is turned to right. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction


	// Print highest vehicle identification number
	cout << "VIN is " << Car::getVIN() << endl;

	cout << "____________________________________________________________" << endl;

	// Created car object name bmw. It's owner is assigned to Ali by constructor.
	Car bmw("Ali");
	cout << "Car's id is " << bmw.getId() << endl;
	cout << "Owner name is " << bmw.getOwner() << endl;
	cout << "VIN is " << Car::getVIN() << endl; // Print highest vehicle identification number

	return 0;
}
