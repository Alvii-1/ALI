#include "../Headers/instructions.h"

// Each instruction here first calls its constructor which then calls the Command constructor
// in order to set the instruction's opcode

// Then, the method definition for each virtual deferred execute() method follows

DecInstruction::DecInstruction() : Command("DEC") {}

void DecInstruction::execute(Hardware& hardware, const string& value) 
{
   // DEC loads an instruction into program memory
   hardware.symbol_table_add(value);
}

LdaInstruction::LdaInstruction() : Command("LDA") {}

void LdaInstruction::execute(Hardware& hardware, const string& value)
{
   // LDA sets the accumulator to be the value from the address of 
   // the given instruction from the symbol table
   int address = hardware.symbol_table[value];
   hardware.register_a = hardware.memory[address].value;
}

LdiInstruction::LdiInstruction() : Command("LDI") {}

void LdiInstruction::execute(Hardware& hardware, const string& value)
{
   // LDI loads an integer from input into the accumulator
   int num = stoi(value);
   if (num >= INT16_MIN && num <= INT16_MAX)
   {
      hardware.register_a = num;
   }
}

StrInstruction::StrInstruction() : Command("STR") {}

void StrInstruction::execute(Hardware& hardware, const string& value)
{
   // STR gets the integer location of the string intstruction from the symbol table
   // and assigns the accumulator to that location in data memory
   int address = hardware.symbol_table[value];
   hardware.memory[address].value = hardware.register_a;
}

XchInstruction::XchInstruction() : Command("XCH") {}

void XchInstruction::execute(Hardware& hardware, const string& value)
{
   // XCH exchanges the values of the accumulator and data register
   int temp = hardware.register_a;
   hardware.register_a = hardware.register_b;
   hardware.register_b = temp;
}

JmpInstruction::JmpInstruction() : Command("JMP") {}

void JmpInstruction::execute(Hardware& hardware, const string& value)
{
   // JMP jumps to the specified program instruction passed by parameter
   hardware.prog_counter = stoi(value) - 1;
}

JzsInstruction::JzsInstruction() : Command("JZS") {}

void JzsInstruction::execute(Hardware& hardware, const string& value)
{
   // JZS jumps to the passed step number only if the zero bit is set (1)
   if (hardware.zero_bit) 
   { 
      hardware.prog_counter = stoi(value);
   }
}

AddInstruction::AddInstruction() : Command("ADD") {}

void AddInstruction::execute(Hardware& hardware, const string& value)
{
   // ADD sums the registers and sets the accumulator as the result
   // Nothing happens if the number is outside the 16 bit range
   int sum = hardware.register_a + hardware.register_b;

   if (sum >= INT16_MIN && sum <= INT16_MAX)
   {
      hardware.register_a = sum;
      hardware.update_zero_bit();
   }
}

SubInstruction::SubInstruction() : Command("SUB") {}

void SubInstruction::execute(Hardware& hardware, const string& value)
{
   // SUB subtracts the register b from a and sets register a as the result
   // Nothing happens if the number is outside the 16 bit range

   int diff = hardware.register_a - hardware.register_b;

   if (diff >= INT16_MIN && diff <= INT16_MAX)
   {
      hardware.register_a = diff;
      hardware.update_zero_bit();
   }
}

HltInstruction::HltInstruction() : Command("HLT") {}

void HltInstruction::execute(Hardware& hardware, const string& value)
{  
   // HLT displays the final hardware state and ends the program
   hardware.prog_counter++;
   hardware.display();
   cout << endl << ">> Program Termination." << endl;
   exit(0);
}
