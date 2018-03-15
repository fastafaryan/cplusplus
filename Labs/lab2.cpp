// Fatih Yılmaz

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int rand_num = rand() % 20 + 1;
    
    int usersNumber;
    cout << "Guess a number" << endl;
    while(1) {
        cin >> usersNumber;
        if (usersNumber == rand_num) { 
            cout << "Winner winner chicken dinner!" << endl;
            break;
        } else if (usersNumber > rand_num) {
            cout << "Too high, try again." << endl;
            cout << "Guess a number again!" << endl;
        } else if (usersNumber < rand_num) {
            cout << "Too low, try again." << endl;
            cout << "Guess a number again!" << endl;
        }
    }
    
    return 0;
}