#include "../Headers/command.h"
#include "../Headers/hardware.h"

Command::Command(const string& opcode) 
{
    this->opcode = opcode;
} // Constructor