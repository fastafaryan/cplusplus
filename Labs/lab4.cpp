//============================================================================
// Name        : lab5.cpp
// Author      : Fatih Yýlmaz
// Description : Find max number from 2 different array
//============================================================================

#include <iostream>
using namespace std;

//function declarations
void getNumbers(int arr[], int length); //get the array numbers from the user with cin
void printArray(int arr[], int length); //cout each array value
int findMax(int array1[], int array2[], int length1, int length2); //find max of two arrays


int main() {
	int length1=0, length2=0;
	cout << "Please enter the length of the first array: ";
	cin >> length1;
	cout << "Please enter the length of the second array: ";
	cin >> length2;

	//declare arrays
	int arr1[length1];
	int arr2[length2];

	getNumbers(arr1,length1);
	cout << "Arr1 is:" << endl;
	printArray(arr1,length1);

	getNumbers(arr2,length2);
	cout << "Arr2 is:" << endl;
	printArray(arr2,length2);

	int result = findMax(arr1, arr2, length1, length2);
	cout << "Max number is: " << result << endl;
	return 0;
}

//get the array numbers from the user with cin
void getNumbers(int arr[], int length) {
	cout << "Please enter " << length << " integers" << endl;
	for(int i=0; i<length; i++) {
		cout << "Please enter number " << i+1 << ": ";
		cin >> arr[i];
	}
}

//cout each array value
void printArray(int arr[], int length) {
	for(int i=0; i<length; i++) {
		cout << arr[i] << endl;
	}
}

//find max of two arrays
int findMax(int array1[], int array2[], int length1, int length2) {
	int max = 0;
	for(int i=0; i<length1; i++) {
		if(array1[i] > max) {
			max = array1[i];
		}
	}
	for(int i=0; i<length2; i++) {
		if(array2[i] > max) {
			max = array2[i];
		}
	}
	return max;
}
