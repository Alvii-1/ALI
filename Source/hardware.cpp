#include "../Headers/hardware.h"
#include "../Headers/command.h"

MemObj::MemObj(Command* command, int num)
{
    value = num;
    cmd = command;
} // End MemObj Union Constructor

Hardware::Hardware() 
{
    register_a = 0;
    register_b = 0;
    prog_counter = 0;
    zero_bit = 0;
    memory.resize(256);
    
} // End Hardware Constructor

Hardware::~Hardware() 
{
    // Vector is deleted automatically
} // End Destructor

void Hardware::display()
{
    // Printing primitive hardware data members
    cout << endl 
         << ">> Printing Hardware Info..." << endl
         << "Accumulator:     " << register_a << endl
         << "Data Register:   " << register_b << endl
         << "Program Counter: " << prog_counter << endl
         << "Zero Bit:        " << zero_bit << endl;

    // Printing symbol table
    cout << endl << ">> Printing Symbol Table..." << endl;
    for (auto item = symbol_table.begin(); item != symbol_table.end(); item++)
    {
        cout << "Key: " << item->first << ", Value: " << item->second << endl;
    }

    // Printing program memory [0-127]
    cout << endl << ">> Printing Program Memory..." << endl;
    for (int i = 0; i < prog_counter; i++)
    {
        if (memory[i].cmd != nullptr)
        {
            cout << "Address " << i << ": " << memory[i].cmd->opcode << endl;
        }
    }
    
    // Printing data memory [128-255]
    cout << endl << ">> Printing Data Memory..." << endl;
    for (int j = 128; j < 128 + symbol_table.size(); j++)
    {
        cout << "Address " << j << ": " << memory[j].value << endl;
    }
} // End display Method

void Hardware::symbol_table_add(const string& var)
{
    symbol_table[var] = symbol_table_next_free;
    symbol_table_next_free++;
} // End symbol_table_push_back Method

void Hardware::update_zero_bit()
{
    // Check accumulator to flip zero result bit
    register_a == 0 ? zero_bit = 1 : zero_bit = 0;
} // End update_zero_bit Method