#include "../Headers/command.h"
#include <iostream>

using namespace std;

#ifndef INSTR_H
#define INSTR_H

// Below follows all of the instruction subclass declarations

class DecInstruction: public Command 
{
    public:
        DecInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End DEC Instruction Class Declaration

class LdaInstruction: public Command 
{
    public:
        LdaInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End LDA Instruction Class Declaration

class LdiInstruction: public Command 
{
    public:
        LdiInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End LDI Instruction Class Declaration

class StrInstruction: public Command
{
    public:
        StrInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End STR Instruction Class Declaration

class XchInstruction: public Command
{
    public:
        XchInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End XCH Instruction Class Declaration

class JmpInstruction: public Command
{
    public:
        JmpInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End JMP Instruction Class Declaration

class JzsInstruction: public Command
{
    public:
        JzsInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End JZS Instruction Class Declaration

class AddInstruction: public Command
{
    public:
        AddInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End ADD Instruction Class Declaration

class SubInstruction: public Command
{
    public:
        SubInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End SUB Instruction Class Declaration

class HltInstruction: public Command
{
    public:
        HltInstruction();                         
        void execute(Hardware& hardware, const string& value = "") override;
}; // End HLT Instruction Class Declaration

#endif 