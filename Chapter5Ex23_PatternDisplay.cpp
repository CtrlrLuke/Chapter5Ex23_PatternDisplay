/*
File Name: Chapter5Ex23_PatternDisplay.cpp
Developer: Luke Pritchard
Date: 04/13/2025
Requirements:
- Use a loop to display Pattern A (increasing +)
- Use another loop to display Pattern B (decreasing +)
- Input must be validated
- Use modular design with at least 3 functions
- Program must be repeatable
*/

#include <iostream>
using namespace std;

// Function Prototypes
void ShowMenu();
int GetChoice();
void PatternA();
void PatternB();
char GetRepeatChoice();

/*
   main
   Repeats the menu until the user chooses not to.
*/
int main()
{
    char again;

    do
    {
        ShowMenu();
        int choice = GetChoice();

        if (choice == 1)
            PatternA();
        else
            PatternB();

        again = GetRepeatChoice();

    } while (again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}

/*
   ShowMenu
   Displays pattern options.
*/
void ShowMenu()
{
    cout << "\nChoose a pattern to display:\n";
    cout << "1. Pattern A (increasing)\n";
    cout << "2. Pattern B (decreasing)\n";
}

/*
   GetChoice
   Gets a valid choice of 1 or 2 from the user.
*/
int GetChoice()
{
    int choice;

    cout << "Enter 1 or 2: ";
    while (!(cin >> choice) || (choice != 1 && choice != 2))
    {
        cout << "ERROR: Please enter a valid number (1 or 2): ";
        cin.clear();  // Clear the error flag
        cin.ignore(1000, '\n');  // Discard invalid input
    }

    return choice;
}


/*
   PatternA
   Displays an increasing + pattern (1 to 10).
*/
void PatternA()
{
    cout << "\nPattern A:\n";
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "+";
        cout << endl;
    }
}

/*
   PatternB
   Displays a decreasing + pattern (10 to 1).
*/
void PatternB()
{
    cout << "\nPattern B:\n";
    for (int i = 10; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << "+";
        cout << endl;
    }
}

/*
   GetRepeatChoice
   Asks user to display another pattern. Validates input.
*/
char GetRepeatChoice()
{
    char choice;
    cout << "\nWould you like to display another pattern? (Y/N): ";
    cin >> choice;

    while (toupper(choice) != 'Y' && toupper(choice) != 'N')
    {
        cout << "ERROR: Enter Y or N: ";
        cin >> choice;
    }

    return toupper(choice);
}
