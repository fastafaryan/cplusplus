/* main.cpp 
   Fatih Yılmaz
   This program calculates BM and gives feedback to user.
*/

#include <iostream>

using namespace std;

int main () {

    // Declearing weight and height variables
    float weight;
    float height;

    // Getting user's weight
    cout << "Pls type ur weight in kilograms: ";
    cin >> weight;
    
    // Getting user's heigt
    cout << "Pls now type ur height in meters and use dot instead of comma: ";
    cin >> height;

    // Assgining BM with formula
    float bm = weight / (height*height);

    // Formatting float or double numbers 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Writing results to screen with respect to user's BM
    if (bm < 18.5) {
        cout << "Your BM is: " << bm << endl;
        cout << "You are too skinny!" << endl;
    } else if (bm > 18.5 && bm < 24.9) {
        cout << "Your BM is: " << bm << endl;
        cout << "You are OK!" << endl;
    }  else if (bm > 25 && bm < 29.9) {
        cout << "Your BM is: " << bm << endl;
        cout << "You are overweight!" << endl;
    } else if (bm > 30) {
        cout << "Your BM is: " << bm << endl;
        cout << "Gosh man! How many burgers do u eat a day? Stop it! (This means u are obese)" << endl;
    }


    return 0;

}