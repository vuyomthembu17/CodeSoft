#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "\n\t\t-------------------Welcome to Vuyo's Guessing Game-------------------- \n" << endl;
    cout << "\n\t\t-----You will have to guess the number between these numbers 1 and 100.-----";
    cout << "\n\t\t--------------------Lets the game begin good luck.--------------------" << endl;

    srand(time(0));
    int randNumber = (rand() % 100) + 1;

    cout << "\n\t\t-------You will have 5 chances to try guess the right number.-------\n";
    int chanceleft = 5;
    int playerInput;
    for (int i = 1; i <= 5; i++)
    {
        cout << "\n---Enter a Number: ";
        cin >> playerInput;

        if (playerInput == randNumber)
        {
            cout << "\nCongrats, You guessed the right Number\n";
            cout << "\nPleasure for playing with us.";
            break;
        }
        else
        {
            if (playerInput > randNumber)
            {
                cout << "\n^^Insert Smaller Number. Try Again^^^\n";
            }
            else
            {
                cout << "\n^^[ Insert a Greater Number. Try Again ]^^^\n";
            }
        }
        chanceleft--;
        cout << "\n( Chances left to guess the Random Number: " << chanceleft << " )\n";
        if (chanceleft == 0)
        {
            cout << "\n Sorry Chances Are Over\n" << endl;
            cout << "The Random Number Was: " << randNumber << endl;
            cout << "Pleasure for playing with us great day ahead.";
        }
    }
    cout << "\n";
    return 0;
}
