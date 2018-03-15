//============================================================================
// Name        : lab6.cpp
// Author      : Fatih Yýlmaz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Address {
	public:
		Address(int houseNumber, string street, int apartmentNumber, string city, string state, string zipCode); // fully qualified constructor
		Address(int houseNumber, string street, string city, string state, string zipCode); // constructor without apartment number
		Address(); // constructor without parameters
		void print(); // print private variables to screen

	private:
		int houseNumber;
		string street;
		int apartmentNumber;
		string city;
		string state;
		string zipCode;
};


int main() {

	Address berk; // create object
	berk.print(); // print the object

	Address sencer(5, "Güneþ", 1, "samsun", "türkiye", "55000"); // create object
	sencer.print();// print the object

	Address ali(5, "Mýzrap", "istanbul", "türkiye", "34000"); // create object
	ali.print();// print the object

	Address enes(47, "saray", 9, "istanbul", "arnavutluk", "95654"); // create object
	enes.print();// print the object

	Address yusuf; // create object
	yusuf.print();// print the object
	return 0;
}

// fully qualified constructor
Address::Address(int houseNumber, string street, int apartmentNumber, string city, string state, string zipCode)
: houseNumber(houseNumber), street(street), apartmentNumber(apartmentNumber), city(city), state(state), zipCode(zipCode) {}

// constructor without apartment number
Address::Address(int houseNumber, string street, string city, string state, string zipCode)
: houseNumber(houseNumber), street(street), city(city), state(state), zipCode(zipCode) {}

// constructor without parameters
Address::Address()
: houseNumber(1), street("1"), apartmentNumber(1), city("1"), state("1"), zipCode("1") {}

// definition of print func
void Address::print() {
	cout << "ADDRESS INFORMATIONS" << endl;
	cout << "Street: " << street << endl;
	cout << "City: " << city << endl;
	cout << "State: " << state << endl;
	cout << "House number: " << houseNumber << endl;
	cout << "Apartment number: " << apartmentNumber << endl;
	cout << "Zip Code: " << zipCode << "\n\n";
}
