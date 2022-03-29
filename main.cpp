#include "klotski.h"

using namespace KlotskiGame;

int main()
{
    srand(time(NULL));

    Klotski mainGame;
    int mainMenuInput;
    string userMove;

    cout << "WELCOME TO THE KLOTSKI GAME!" << endl;

    while (mainGame.isFinished())
    {
        cout << "\n\n1: You play the next move\n";
        cout << "2: Computer plays one move for you.\n";
        cout << "Enter your input please 1 or 2: ";
        if (cin >> mainMenuInput)
        {
            if (mainMenuInput == 1)
            {
                mainGame.print();
                cout << "Move examples: 6D, 8R, 9L etc";
                cout << "\nEnter your move please: ";
                cin >> userMove;

                mainGame.playUser(userMove);
            }
            else if (mainMenuInput == 2)
            {
                mainGame.playAuto();
            }
            else
            {
                cout << "\nEnter an integer 1 or 2 please!" << endl;
                continue;
            }

            mainGame.print();
            cout << "Current score " << mainGame.boardScore() << endl;
        }
        else
        {

            // clear the buffer
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "\nEnter an integer 1 or 2 please!" << endl;
        }
    }

    cout << "\nGame has finished!" << endl;
    cout << "Thank you for playing the game!" << endl;
}