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
#include <string>
#include <cctype>
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
    string input;
    int choice = 0;

    cout << "Enter 1 or 2: ";
    getline(cin, input);

    while (input != "1" && input != "2")
    {
        cout << "ERROR: Please enter only 1 or 2: ";
        getline(cin, input);
    }

    // Convert from string to int after validation
    choice = stoi(input);
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
    string input;

    while (true)
    {
        cout << "\nWould you like to display another pattern? (Y/N): ";
        getline(cin, input);

        if (input.length() == 1)
        {
            char c = toupper(input[0]);

            if (c == 'Y' || c == 'N')
                return c;
        }

        cout << "ERROR: Please enter only Y or N.\n";
    }
}
