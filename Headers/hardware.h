#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifndef HARDWARE_H
#define HARDWARE_H

class Command; // Forward declaration to avoid circular redefinition, 
               // since MemObj doesnt actually change Command 

union MemObj
{
    // MemObj holds a command pointer and integer value and is the type for the memory vector below
    int value;      // Integer Value
    Command* cmd;   // Instruction

    MemObj(Command* command = nullptr, int num = -1); // Constructor
}; // End Union Datatype for Memory Items

class Hardware 
{
    // Holds all hardware instatiations (memory, bits, counters, zero bit)
    private:
        int symbol_table_next_free = 128;

    public:
        vector <MemObj> memory;           // Memory Vector
        map <string, int> symbol_table;   // Symbol Table
        unsigned short int prog_counter;  // Program Counter (def 0) (8bit)
        short int register_a;             // Accumulator (def 0) (16bit)
        short int register_b;             // Data Register (def 0) (16bit)
        bool zero_bit;                    // Zero Result Bit (def 0) (0-1)
     
        Hardware();                       // Constructor
        ~Hardware();                      // Destructor
        void symbol_table_add(const string& variable); // Method to add into symbol table
        void display();                   // Print Method
        void update_zero_bit();           // Update Zero Bit     
}; // End Hardware Class Declarations

#endif 