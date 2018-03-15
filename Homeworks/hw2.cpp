/* hw2.cpp
Fatih Yılmaz
This program takes values for 5 by 5 array from user then sorts specific row or column as user's desire.
*/

#include <iostream>

using namespace std;

const int ROW_SIZE = 5;
const int COL_SIZE = 5;

void fillUp(int a[][COL_SIZE], int row_size); // Takes values from user and assigns them to array
char colOrRow(); // Asks user to sort row or col. Return user's input.
int askIndex(char selection); // Asks for which index to sort. Return user's input.
void printArray(int array[][COL_SIZE], int row_size, int col_size); // Print 2 dimensional array to screen
void sortRow(int array[][COL_SIZE], int index); // Sorts specific row in array
void sortCol(int array[][COL_SIZE], int index); // Sorts specific col in array

int main() {
	
	int array[ROW_SIZE][COL_SIZE]; // Create multi dimensional array

	fillUp(array, ROW_SIZE); // Invoke fillUp function to take values from user and assign them to array
	
	cout << "Your array is:" << endl;
	printArray(array, ROW_SIZE, COL_SIZE); // Print array to screen

	char selection = colOrRow(); // Variable to hold whether sort rows of columns.
	
	int index = askIndex(selection); // Variable to hold index

	if(selection == 'r') {
		sortRow(array, index); // Sort row of the array with defined index
	} else if(selection == 'c') {
		sortCol(array, index); // Sort column of the array with defined index
	}

	cout << "Your sorted array is:" << endl;
	printArray(array, ROW_SIZE, COL_SIZE);  // Print sorted array

	return 0;
}

// Takes values from user and assigns them to array
void fillUp(int a[][COL_SIZE], int row_size) {
	// Create a loop that will run as many as row_size  
	for(int i = 0; i < row_size; i++) {
		// Ask user to fill COL_SIZE amount of numbers for current line 
		cout << "Please enter " << COL_SIZE << " numbers for " << (i+1) << ". line of array."  << endl; 
		for(int j = 0; j < COL_SIZE; j++) {
			cin >> a[i][j]; // Take numbers from the user and assign it to current position in array 
		}
	}
}

// Asks user sort row of col
char colOrRow() {
	char selection;
	// Infinite loop to execute till user enter c or r input
	while(1) {
		cout << "If you want to sort a row please enter r or if you want to sort a column please enter c: ";
		cin >> selection; // Ask for input and assign it to selection
		if(selection == 'r' || selection == 'c') {
			break; // if input is r or c break the loop
		} else {
			cout << "Invalid input please type c or r" << endl; // if input is not r or c cout warning and ask to enter input again 
		}
	}
	return selection;
}


// Asks for which index to sort
int askIndex(char selection) {
	int index; // Holds which column or row to sort
	if(selection == 'r') {
		// Sort Rows
		while(1) {
			cout << "Which row do you want to sort ? ";
			cin >> index;
			// Check if input is valid
			if(index > 0 && index <= ROW_SIZE ) {
				break; // if valid break the loop
			} else {
				cout << "Invalid index! Please type again." << endl; // if not ask again
			}
		}
	} else if(selection == 'c') {
		// Sort Cols
		while(1) {
			cout << "Which column do you want to sort ? ";
			cin >> index;
			// Check if input is valid
			if(index > 0 && index <= COL_SIZE ) {
				break; // if valid break the loop
			} else {
				cout << "Invalid index! Please type again." << endl; // if not ask again
			}
		}
	}
	return index;
}

// Print 2 dimesional array to screen
void printArray(int array[][COL_SIZE], int row_size, int col_size) {
	for(int i = 0; i < row_size; i++) {
		for(int j = 0; j < col_size; j++) {
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
}

// Sorts specific row in array
void sortRow(int array[][COL_SIZE], int index) {
	int temp; // Holds value temporarily while swapping
	index = index-1; // subtract -1 because arrays starts from 0 index
	// Bubble sorting loop
	for (int i = 0; i < COL_SIZE; i++ ) {
		for (int j = 0; j < COL_SIZE-1; j++ ) {
			if (array[index][j] > array[index][j+1]) {
				// Swap values
				temp = array[index][j];
				array[index][j] = array[index][j+1];
				array[index][j+1] = temp;
			}
		}
	}

}

// Sorts specific col in array
void sortCol(int array[][COL_SIZE], int index) {
	int temp; // Holds value temporarily while swapping
	index = index-1; // subtract -1 because arrays starts from 0 index
	// Bubble sorting loop
	for (int i = 0; i < ROW_SIZE; i++ ) {
		for (int j = 0; j < ROW_SIZE-1; j++ ) {
			if (array[j][index] > array[j+1][index]) {
				// Swap values
				temp = array[j][index];
				array[j][index] = array[j+1][index];
				array[j+1][index] = temp;
			}
		}
	}

}