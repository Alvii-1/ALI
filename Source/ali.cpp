#include "../Headers/ali.h"
#include "../Headers/hardware.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

ALI::ALI() 
{
    // ALI Constructor creates the hardware object, holds the instruction count,
    // and the map used to relate string inputs from the file to instructions

    hardware = Hardware();
    instruction_count = 0;

    instructions_map = {
        {"DEC", &DEC},
        {"LDA", &LDA},
        {"LDI", &LDI},
        {"STR", &STR},
        {"XCH", &XCH},
        {"JMP", &JMP},
        {"JZS", &JZS},
        {"ADD", &ADD},
        {"SUB", &SUB},
        {"HLT", &HLT},
    };
} // Constructor

ALI::~ALI() 
{

} // Destructor

void ALI::load_file(string filename)
{
    // load_file() method takes a filename as input and loads it into a
    // vector to hold the program's source code currently executing

    cout << ">> Loading " << filename << "..." << endl;
    ifstream file(filename);

    // Populating program source code vector
    string line, opcode;
    int instr_num = 0;

    while (getline(file, line)) 
    {
        string opcode = line.substr(0, 3);        // Isolating operation code
        hardware.memory[instr_num].cmd = instructions_map[opcode]; // load command into program memory
        hardware.memory[instr_num].cmd->opcode = opcode;           // set opcode
        program_source.push_back(line);
        instr_num++;
    }

    file.close();
}

void ALI::display_source()
{   
    // display_source() method simply prints the vector holding source code
    // Used at the same time as HLT command execution

    cout << endl << ">> Printing Source Code..." << endl;
    for (int i = 0; i < program_source.size();i++) 
    {
         cout << program_source[i] << endl;
    }
}

void ALI::step_run(bool full_run_flag)
{
    // step_run() method takes 1 optional parameter flag which controls whether or
    // not the final hardware status is displayed after each step. It handles all
    // instruction executions and terminates the program on HLT or input ending
    // also populates data and program memory

    string source_line = program_source[hardware.prog_counter];     // Assigning source code line
    string opcode = source_line.substr(0, 3);                       // Isolating operation code
    string instr;                                                   // Instantiating Instruction (may not be used)

    if (hardware.prog_counter > program_source.size() || opcode == "") { instructions_map["HLT"]->execute(hardware); } // Exit if no HLT at end

    if (source_line.size() > 3) { instr = source_line.substr(4); }  // If more than 3 char cmd is present, isolate
    else { instr = ""; }                                            // otherwise set empty instr

    // Below, first if branch handles executing normal commands. Second else branch handles HLT
    if (hardware.memory[hardware.prog_counter].cmd != nullptr && opcode != "HTL")
    {
        hardware.memory[hardware.prog_counter].cmd->execute(hardware, instr);
        if (opcode != "JMP" || opcode != "JZS") {hardware.prog_counter++; }  // Increment to track execution numbers
        instruction_count++;
    }
    else { instructions_map[opcode]->execute(hardware); } // Terminate on HLT

    if (!full_run_flag) { hardware.display(); } // Display each iteration of the hardware memory in single execution

    if (instruction_count % 1000 == 0)
    {
        string input;
        cout << endl << "Exceeded 1000 Instructions, continue? (y/n): ";
        cin >> input;
        
        if (input == "n" || input == "N") { instructions_map["HLT"]->execute(hardware); } // Terminate HLT
        cout << endl << ">> Continuing Program Execution..." << endl;
    }
}

void ALI::full_run()
{
    // full_run() method calls single_run() with flag set to true, so we don't
    // print hardware after each step, and it runs all lines of code from input

    while (true)
    {
        step_run(true); 
    }
    instructions_map["HLT"]->execute(hardware);
}