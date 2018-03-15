#include <iostream>
#include <string>

using namespace std;

const bool TURN_LEFT = true; 
const bool TURN_RIGHT = true;

class Car {

	public:
		// CONSTRUCTORS
		Car(); // Constructor without any argument
		Car(string ownerName); // Constructor with only owner name argument

		// INLINE METHODS
		inline int getSpeed() { return currentSpeed; } // Get car's current speed
		inline void changeSpeed(int newSpeed) { currentSpeed = newSpeed; } // change speed to giving number 
		inline void accelerate() { currentSpeed += 10; } // Accelerate car's speed by 10
		inline void stop() { currentSpeed = 0; } // Set car speed to 0
		inline void brake() { currentSpeed = 0; } // Same with stop function
		inline int getCurrentDirection() { return currentDirection; } // Get car's current direction
		inline string getOwner() { return string(ownerName); } // Get owner name. Inline function. Returns string.
		inline void setOwner(string name) { ownerName = name; } // Set owner name
		inline int getYear() { return year; } // Get car's model year
		inline void setYear(int givenYear) { year = givenYear; } // set car's model year to given year
		inline int getId() { return id; } // Get car's unique id
		
		// METHODS
		void setDirection(int newDirection); // Set car's current direction 
		void turnLeft(int numberOfDegrees);// Turning car to left as much as given degrees
		void turnRight(int numberOfDegrees);// Turning car to right as much as given degrees
		static int getVIN(); // Get highest vehicle identification number

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

// Set car's direction
void Car::setDirection(int newDirection) {
	if(newDirection < 0 || newDirection >= 360) {
		cout << "Invalid direction!" << endl; // Print out if new direction is invalid
	} else {
		currentDirection = newDirection;
	}
}

// Turn car's direction to right as given degrees 
void Car::turnRight(int numberOfDegrees) {
	currentDirection += numberOfDegrees; // sum current direction with given degrees
	if(currentDirection >= 360) { // if summation is greater than 360
		currentDirection = currentDirection%360;  // set current location to remainder of division current direction with 360
	}
}

// Turn car's direction to left as given degrees 
void Car::turnLeft(int numberOfDegrees) {
	currentDirection -= numberOfDegrees; // subtract current direction with given degrees
	if(currentDirection <= 0) {
		currentDirection = currentDirection%360; // set current location to remainder of division current direction with 360
		currentDirection += 360; // to get rid of from negative result sum current direction with 360
	}
}
