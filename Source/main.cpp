#include "../Headers/instructions.h"
#include "../Headers/hardware.h"
#include "../Headers/command.h"
#include "../Headers/ali.h"
#include <iostream>

using namespace std;

void output_help()
{
    cout << endl << ">> Valid Commands:" << endl
         << "s  -  Run a single line of code from the file and print hardware status." << endl
         << "a  -  Run all lines of code in the file and print final hardware status." << endl
         << "q  -  Terminate the program." << endl 
         << endl;
} // End output_help() function

int main() 
{   
    // Getting file and initializing the ALI
    string filename;
    cout << endl << "Enter file name: ";
    cin >> filename;
    ALI interpreter = ALI();
    interpreter.load_file(filename);

    // Main Program Loop
    string input;
    while (true)
    {
        cout << endl << "Enter choice: (help for list of commands): ";
        cin >> input;
        cout << endl;

        if (input == "help")
        {
            output_help();
        } 
        else if (input == "s")
        {
            cout << ">> Running with single command execution..." << endl;
            interpreter.step_run();
        } 
        else if (input == "a")
        {
            cout << ">> Running with complete program execution..." << endl;
            interpreter.full_run();
            break;
        } 
        else if (input == "q")
        {
            break;
        }
    }

    cout << ">> Goodbye." << endl;
    return 0;
} // End main function