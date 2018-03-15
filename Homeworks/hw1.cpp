/* Fatih Yılmaz
This program calculates GPA if GPA is lower than 2 makes suggestion to user to higher their grade to optimum level
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  
	int currentClass; // Stores user's current class
	float previousGPA; // User's GPA from previous semesters
	int previousCredits; // User's credits from previous semesters
	int coursesTaken; // User's number of courses from this semester 
	int creditsTaken = 0; // User's number of credits from this semester 

	cout << "Welcome to the expected GPA Calculator" << endl;

	// Getting current class of the user
	// If user's class is not between at 1 and 4 ask it again till it's between the asked range
	cout << "________________________________________________________" << endl;
	while (1) {
		cout << "Please enter your class: ";
		cin >> currentClass;
		if (currentClass <= 4 && currentClass >= 1) {
			break; // If it is at valid range break the loop and proceed to next lines of code
		} else {
			cout << "Please type your class between 1 and 4!" << endl;
		}
	}

	// Check if user's current class is 1 or not
	// If it is 1 assign previous GPA and previously taken credits to 0
	if (currentClass == 1) {
		previousGPA = 0;
		previousCredits = 0;
		cout << "*Your current GPA and credits are assigned to 0!" << endl; 
	} else {
		// Getting current GPA of the user
		// If user's GPA is not between at 1 and 4 ask it again till it's between the valid range
		cout << "________________________________________________________" << endl;
		while (1) {
			cout << "Please enter your current GPA (except this semester): ";
			cin >> previousGPA;
			if (previousGPA >= 0 && previousGPA <= 4) {
				break; // If it is at valid range break the loop and proceed to next lines of code
			} else {
				cout << "Your GPA is not valid. Please type your current GPA between 1 and 4!" << endl;
			}
		}

		// Ask to user have many credits they have taken from previous semesters
		cout << "________________________________________________________" << endl;
		cout << "How many credits have you taken? (except this semester): ";
		cin >> previousCredits;
	}

	// Get have many courses user has taken for this semester
	cout << "________________________________________________________" << endl;
	cout << "How many courses have you taken this semester?: ";
	cin >> coursesTaken;

	string courseNames[coursesTaken]; // This semester's course names
	int courseCredits[coursesTaken]; // This semester's course credits
	double expectedGrades[coursesTaken]; // This semester's expected course grades

	// Create a loop and ask names and expected grades for every courses
	for (int i = 0; i < coursesTaken; i++ ) {

		// Getting course name
		cout << "________________________________________________________" << endl;
		cout << "Please enter the name of course " << i+1 << ": ";
		cin >> courseNames[i];

		// Getting credit of the course till it's between a valid range
		while (1) {
			cout << "Please enter credit of " << courseNames[i] << ": ";
			cin >> courseCredits[i];
			// Check if given credit is between a valid range
			if (courseCredits[i] >= 1 && courseCredits[i] <= 4) {
				creditsTaken += courseCredits[i]; // if it's between a valid range add course credit to total taken credits
				break; // then break the while loop
			} else {
				// if it's not valid print warning
				cout << "*Invalid credit! Please type credit of the course between 1 and 4." << endl;
			}
		}

		// Getting expected grade till it has a valid value
		while (1) { 
			cout << "Please enter the expected grade for " << courseNames[i] << ": ";
			cin >> expectedGrades[i];
			// Check if expected grade is given as required
			if (expectedGrades[i] == 0 || expectedGrades[i] == 2 || expectedGrades[i] == 2.5 || expectedGrades[i] == 3 || expectedGrades[i] == 3.5 || expectedGrades[i] == 4) {
				break; // if it's valid break the while loop
			} else {
				// if expected grade is given invalid print warning
				cout << "*Invalid grade value! Please type: \n"
					 << " 0   for FF\n"
				  	 << " 2   for CC\n"
				  	 << " 2.5 for CB\n"
				  	 << " 3   for BB\n"
				  	 << " 3.5 for BA\n"
				  	 << " 4   for AA\n";
			}
		}
	}
	// Check if credits are less than 18
	if (creditsTaken < 18) {
		// if it's less than print warning
		cout << "You have to take at least 18 credits for this semester! Please select courses again!" << endl;
	} else {

		// Calculating new GPA
		double procuction = previousGPA * previousCredits; // Stores production of GPAs and Credits from previous classes
		for (int i = 0; i < coursesTaken; i++ ) {
			procuction += courseCredits[i] * expectedGrades[i]; // Adds production of expected GPAs and credits of currently taking courses
		}
		int totalCredits = creditsTaken + previousCredits; // Stores total credits of student
		double expectedGPA = procuction / totalCredits; // expected GPA of user in the end of this semester

		// Set precision to 2 for double and floating point numbers
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		// Check expected GPA and print messages to the screen
		if(expectedGPA > 3.5) {
			cout << "Your expected GPA is " << expectedGPA  << endl;
			cout << "You are a high honor student"  << endl;
		} else if(expectedGPA > 3) {
			cout << "Your expected GPA is " << expectedGPA  << endl;
			cout << "You are a honor student"  << endl;
		} else if(expectedGPA < 2) {
			// if expected GPA of the user less than 2 suggest to user to take worst 3 courses again
			cout << "Your expected GPA is " << expectedGPA  << endl;
			cout << "You should take some courses again."  << endl;

			// Bubble sorting arrays to have 3 courses with worst grades
			string swapName; // temporarly holds course names for swapping
			double swapGrade; // temporarly holds course grades for swapping
			int swapCredit; // temporarly holds course credits for swapping
			// Bubble sorting loop
			for (int i = 0; i < coursesTaken; i++ ) {
				for (int j = 0; j < coursesTaken-1; j++ ) {
					if (expectedGrades[j] > expectedGrades[j+1]) {
						// Swap course names
						swapName = courseNames[j];
				        courseNames[j] = courseNames[j+1];
				        courseNames[j+1] = swapName;

				        // Swap expected course grades 
						swapGrade = expectedGrades[j];
				        expectedGrades[j] = expectedGrades[j+1];
				        expectedGrades[j+1] = swapGrade;

				        // Swap course credits 
						swapCredit = courseCredits[j];
				        courseCredits[j] = courseCredits[j+1];
				        courseCredits[j+1] = swapCredit;
					}
				}
			}

			// Print to screen worst 3 courses
			cout << "The 3 courses with lowest grades are " << courseNames[0] << " " << courseNames[1] << " " << courseNames[2] << "." << endl;

			// Two variables below will be used if user has very bad GPA and can't fix with just 3 grade upgrade
			bool reachedLimit = false; // This holds if upgrade of worst 3 courses reaches to max limit which is 4
			int reachedIndex = 3; // Holds index for other suggested upgraded courses

			// Check if expected GPA is lower than 2
			while (expectedGPA < 2) {

				// If when 3 worst courses should be AA grade and even thought they can't save user's GPA to reach 2
				// program will suggest user to upgrade some other courses' grades too
				if(reachedLimit) {
					if (expectedGrades[reachedIndex] == 0) {
						expectedGrades[reachedIndex] = 2; // if expected grade of the course is 0 increase it to 2
					} else if (expectedGrades[reachedIndex] == 4) {
						reachedIndex++; // increase index if one more course can't save GPA
					}
					 else {
						expectedGrades[reachedIndex] += 0.5; // if expected grade of the course is not 0 sum it with 0.5
					}
				} else {
					for (int k = 0; k < 3; k++) {
						if (expectedGrades[k] == 0) {
							expectedGrades[k] = 2; // if expected grade of the course is 0 increase it to 2
							reachedLimit = false;
						} else if (expectedGrades[k] == 4) {
							reachedLimit = true; // if all courses' suggested grades reached to 4 assign this variable to true
							continue;
						} else {
							expectedGrades[k] += 0.5; // if expected grade of the course is not 0 sum it with 0.5
							reachedLimit = false;
						}
					}
				}

				// Recalculate GPA
				procuction = previousGPA * previousCredits; // Stores production of GPAs and Credits from previous classes
				for (int i = 0; i < coursesTaken; i++ ) {
					procuction += courseCredits[i] * expectedGrades[i]; // Adds production of expected GPAs and credits of currently taking courses
				}
				totalCredits = creditsTaken + previousCredits; // Stores total credits of student
				expectedGPA = procuction / totalCredits; // expected GPA of user in the end of this semester
			}

			// Print suggested grades for worst 3 courses
			for (int k = 0; k < 3; k++) {
				cout << "Minimum grade for " << courseNames[k] << " should be " << expectedGrades[k] << endl;
			}

			// Show other suggested course grades if 3 suggestion can't make GPA bigger than 2
			if (reachedLimit) {
				for (int x = 3; x <= reachedIndex; x++) {
					cout << "Also minimum grade for " << courseNames[x] << " should be " << expectedGrades[x] << endl;
				}
			}

			// Print expected GPA when suggested course grades are implemented
			cout << "If you make these course grades as suggested your expected GPA will be " << expectedGPA << endl;
			
		} else { 
			// expected GPA is between 2 and 3 just print GPA value.
			cout << "Your expected GPA is " << expectedGPA  << endl;
		}

	}
  
	return 0;
  
}