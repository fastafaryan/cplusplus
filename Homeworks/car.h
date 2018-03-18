/* car.h
   Fatih Yılmaz
   This file contains car class and can be used as library. 
*/
#include <iostream>
#include <string>

using namespace std;

const int TURN_RIGHT = 180;
const int TURN_LEFT = -180; 

class Car {

	public:
		// CONSTRUCTORS
		Car(); // Constructor without any argument
		Car(string ownerName); // Constructor with only owner name argument
		Car(string ownerName, int year, int speed, int direction); // Constructor with a few arguments

		// INLINE METHODS
		inline int getSpeed() { return currentSpeed; } // Get car's current speed
		inline void accelerate() { currentSpeed += 10; } // Accelerate car's speed by 10
		inline void stop() { currentSpeed = 0; } // Set car speed to 0
		inline int getCurrentDirection() { return currentDirection; } // Get car's current direction
		inline string getOwner() { return string(ownerName); } // Get owner name. Inline function. Returns string.
		inline void setOwner(string name) { ownerName = name; } // Set owner name
		inline int getYear() { return year; } // Get car's model year
		inline void setYear(int givenYear) { year = givenYear; } // set car's model year to given year
		inline int getId() { return id; } // Get car's unique id
		
		// METHODS
		void changeSpeed(int newSpeed); // change speed to giving number 
		int decelerate(); // Decelerate car's speed by 10
		int setDirection(int newDirection); // Set car's current direction 
		int turn(int numberOfDegrees);// Turning car to left as much as given degrees
		int turnExplicit(char c);// Turning car to right as much as given degrees
		static int getVIN(); // Get highest vehicle identification number
		int makeDirectionValid(); // Check if edited directions between 0 and 360. If not set them between this range.

	private:
		// VARIABLES 
		int currentSpeed; // Car's current speed
		int currentDirection; // car's current direction in degrees
		string ownerName; // Car's owner name
		int year; // Car's model year
		int id; // Car's unique id
		static int VIN; // Highest vehicle identification number
};

// Set VIN to a default value. Because it is static variable.
int Car::VIN = 0; 

// Get Highest vehicle identification number
int Car::getVIN() {
	return VIN;
}

// Constructor without any argument
Car::Car() {
	id = ++VIN; // first increase VIN by one then assign it to created object's id
}

// Constructor with only owner name argument. Owner name is set to given parameter.
Car::Car(string ownerName) : ownerName(ownerName) {
	id = ++VIN;  // first increase VIN by one then assign it to created object's id
}

// Constructor with ownerName, year, speed and direction
Car::Car(string ownerName, int year, int speed, int direction) : ownerName(ownerName), year(year), currentSpeed(speed), currentDirection(direction) {
	id = ++VIN;  // first increase VIN by one then assign it to created object's id
}

// Change car speed to given parameter
void Car::changeSpeed(int newSpeed) {
	if(newSpeed<=0) {
		currentSpeed = 0;
	}
	currentSpeed = newSpeed;
}

// Decelerate car's speed by 10. Return currentSpeed
int Car::decelerate() {
	currentSpeed -= 10;
	if(currentSpeed <= 0) {
		cout << "Car has stopped." << endl;
		currentSpeed = 0;
	}
	return currentSpeed;
}

// Set car's direction
int Car::setDirection(int newDirection) {
	if(newDirection < 0 || newDirection >= 360) {
		cout << "Invalid direction!" << endl; // Print out if new direction is invalid
	} else {
		currentDirection = newDirection;
	}
	return currentDirection;
}

// Turn car's direction as given degrees. Return last version of the direction.
int Car::turn(int numberOfDegrees) {
	currentDirection += numberOfDegrees; // sum current direction with given degrees
	Car::makeDirectionValid();
	return currentDirection;
}

// Turn car's direction with constant TURN_LEFT and TURN_RIGHT variables
int Car::turnExplicit(char c) {
	switch(c) {
		case 'r':
		case 'R':
			currentDirection += TURN_RIGHT;
			break;
		case 'l':
		case 'L':
			currentDirection += TURN_LEFT;
			break;
		default:
			cout << "Invalid argument for turnExplicit" << endl;
	}
	Car::makeDirectionValid();
	return currentDirection;
}

// Check if edited directions between 0 and 360. If not set them between this range with respect to current direction.
int Car::makeDirectionValid() {
	if(currentDirection >= 360) { // if currentDirection is greater than 360
		currentDirection = currentDirection%360;  // set currentDirection to remainder of division of currentDirection with 360
	} else if(currentDirection <= 0) {
		currentDirection = currentDirection%360;  // set currentDirection to remainder of division of currentDirection with 360
		currentDirection += 360; // to get rid of from negative result sum currentDirection with 360
	}
}
