#include <iostream>
#include <cstdlib>
#include <ctime>
#define rock 0
#define scissor 1
#define paper 2

using namespace std;

int comp_mode();

int main()
{
    srand(time(NULL)); // Initialize random seed
    int select_1, select_2, i, num, vs_mode;

    cout << "Welcome to our small game: Rock, Scissors, Paper\n";
    cout << "-------------------------------------------------\n";
    cout << "Enter the number of rounds: ";
    cin >> num;
    cout << "For rock, press 1\n";
    cout << "For scissors, press 2\n";
    cout << "For paper, press 3\n";

    there:
    cout << "1) VS Player \t 2) VS Computer\n";
    cin >> vs_mode;

    switch (vs_mode)
    {
        case 2: // VS Computer Mode
        {
            for (i = 0; i < num; i++)
            {
                cout << "Player, select: ";
                cin >> select_1;

                // Adjust user input to be compatible with internal logic (1 -> rock, 2 -> scissor, 3 -> paper)
                select_1--;

                int comp_choice = comp_mode();
                cout << "Computer selected: " << comp_choice + 1 << endl; // Output the computer's selection (adding 1 to match the player's input scale)

                // Compare the player's choice with the computer's choice
                if ((select_1 == rock && comp_choice == scissor) ||
                    (select_1 == scissor && comp_choice == paper) ||
                    (select_1 == paper && comp_choice == rock))
                {
                    cout << "Player wins!\n";
                }
                else if ((select_1 == scissor && comp_choice == rock) ||
                         (select_1 == paper && comp_choice == scissor) ||
                         (select_1 == rock && comp_choice == paper))
                {
                    cout << "Computer wins!\n";
                }
                else if (select_1 == comp_choice)
                {
                    cout << "It's a draw!\n";
                }
                else
                {
                    cout << "Invalid input, please try again...\n";
                    return 0;
                }

                cout << "-----------------------------------\n";
            }
            break;
        }

        case 1: // VS Player Mode
        {
            for (i = 0; i < num; i++)
            {
                cout << "Player 1, select: ";
                cin >> select_1;
                cout << "Player 2, select: ";
                cin >> select_2;

                // Adjust user input to be compatible with internal logic
                select_1--;
                select_2--;

                if ((select_1 == rock && select_2 == scissor) ||
                    (select_1 == scissor && select_2 == paper) ||
                    (select_1 == paper && select_2 == rock))
                {
                    cout << "Player 1 wins!\n";
                }
                else if ((select_1 == scissor && select_2 == rock) ||
                         (select_1 == paper && select_2 == scissor) ||
                         (select_1 == rock && select_2 == paper))
                {
                    cout << "Player 2 wins!\n";
                }
                else if (select_1 == select_2)
                {
                    cout << "It's a draw!\n";
                }
                else
                {
                    cout << "Invalid input, please try again...\n";
                    return 0;
                }

                cout << "-----------------------------------\n";
            }
            break;
        }

        default:
        {
            cout << "Please enter a valid number!\n";
            goto there;
        }
    }

    cout << "Hope you enjoyed the game!\n";
    cout << "---------------------------\n";

    return 0;
}

int comp_mode()
{
    return rand() % 3; // Generates a random number between 0 (rock), 1 (scissors), and 2 (paper)
}
