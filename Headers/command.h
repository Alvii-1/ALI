#include "../Headers/hardware.h"
#include <string>

using namespace std;

#ifndef COMMAND_H
#define COMMAND_H

class Command 
{
    public: 
        string opcode;                    // Operation code of current Instruction
        Command(const string& opcode);    // Constructor

        // Execute Method, Virtual, Redefined in Subclasses
        virtual void execute(Hardware& hardware, const string& value = "") = 0;   
}; // End Command Class Declarations

#endif 