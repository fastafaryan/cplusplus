/* tester.cpp
   Fatih Yılmaz
   This program includes car.h library and makes tests on car class. 
*/
#include <iostream>
#include <string>
#include "car.h" // added car class file

using namespace std;

int main() {
	cout << "*********************************************************************" << endl;
	Car opel; // Create car object named opel.
	cout << "Car's id is " << opel.getId() << endl; // Print car's id
	opel.setOwner("Mustafa"); // Set owner name 
	cout << "Owner name is set to " <<  opel.getOwner() << endl; // Print owner name
	opel.setYear(2015); // Set car's model year to 2015
	cout << "Car's model year is set to " <<  opel.getYear() << endl; // Get car's model year
	opel.changeSpeed(60); // Set car's speed 
	cout << "Car's speed is changed to " << opel.getSpeed() << endl; // print car's speed
	opel.accelerate();  // Accelerate car's speed 
	cout << "Car's speed is accelerated to " << opel.getSpeed() << endl; // print car's speed
	opel.decelerate();  // Decelerate car's speed 
	cout << "Car's speed is decelerated to " << opel.getSpeed() << endl; // print car's speed
	opel.stop(); // set speed to 0
	cout << "Car is stopped. It speed is " << opel.getSpeed() << endl; // print car's speed
	opel.setDirection(60);
	cout << "Car's current direction is set to " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turn(950);
	cout << "Car is turned. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turn(-475);
	cout << "Car is turned. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turnExplicit('r');
	cout << "Car is turned to right. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction
	opel.turnExplicit('l');
	cout << "Car is turned to left. It new direction is " << opel.getCurrentDirection() << endl; // print car's direction
	cout << "VIN is " << Car::getVIN() << endl; // Print highest vehicle identification number
	cout << "*********************************************************************" << endl;
	
	// Created car object name bmw. It's owner is assigned to Ali by constructor.
	Car bmw("Ali");
	cout << "Car's id is " << bmw.getId() << endl;
	cout << "Owner name is " << bmw.getOwner() << endl;
	cout << "VIN is now " << Car::getVIN() << endl; // Print highest vehicle identification number
	// We can add and print other properties too, like above.
	cout << "*********************************************************************" << endl;

	// Create and object with constructor that accepts 4 arguments
	Car mercedes("Hans", 2016, 90, 30);
	cout << "Car's id is " << mercedes.getId() << endl;
	cout << "Car's owner name is " << mercedes.getOwner() << endl;
	cout << "Car's model year is " << mercedes.getYear() << endl;
	cout << "Car's speed is " << mercedes.getSpeed() << endl;
	cout << "Car's direction is " << mercedes.getCurrentDirection() << endl;
	cout << "VIN is now " << Car::getVIN() << endl; // Print highest vehicle identification number


	return 0;
}
