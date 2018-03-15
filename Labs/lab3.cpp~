//============================================================================
// Name        : lab.cpp
// Author      : Fatih Yýlmaz
// Description : Area calculator for circle, rectangle, triangle.
//============================================================================

#include <iostream>
#include <math.h>
#define PI 3.14

using namespace std;

void area(int r); //circle
void area(int a, int b); //rectangle
void area(float a, int b, int c); //triangle
void changeRadius(int& radius); // change radius

int main() {
	while(1) {
		int choice;
		int radius;

		cout << "_________________________________________________" << endl;
		cout << "1.Area of Circle\n2.Area of Rectangle\n3.Area of Triangle\n4.Change radius\n5.Exit\n";
		cout << "Enter your Choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "What is the radius of the circle? ";
			cin >> radius;
			area(radius);
		} else if (choice == 2) {
			int edge1, edge2;
			cout << "Enter length of the first edge: ";
			cin >> edge1;
			cout << "Enter length of the second edge: ";
			cin >> edge2;
			area(edge1, edge2);
		} else if (choice == 3) {
			float edge1;
			int edge2, edge3;
			cout << "Enter length of the first edge: ";
			cin >> edge1;
			cout << "Enter length of the second edge: ";
			cin >> edge2;
			cout << "Enter length of the third edge: ";
			cin >> edge3;
			area(edge1, edge2, edge3);
		} else if (choice == 4) {
			radius = 10;
			cout << "Default radius value is " << radius << endl;
			changeRadius(radius);
		} else if (choice == 5) {
			cout << "Bye!" << endl;
			break;
		}
	}

	return 0;
}

//circle
void area(int r) {
	cout << "Area of the circle is " << (r*r) *  PI << endl;
}

//rectangle
void area(int a, int b) {
	cout << "Area of the rectangle is " << a*b << endl;
}

//triangle
void area(float a, int b, int c) {
	double s = (a+b+c)/2;
	double areaOfTriangle = sqrt( s*(s-a)*(s-b)*(s-c) );
	cout << "Area of the triangle is " << areaOfTriangle << endl;
}

// change radius
void changeRadius(int& radius) {
	cout << "Enter the value that you want to change: " << endl;
	cin >> radius;
	cout << "Radius value has changed to " << radius<< endl;
}
