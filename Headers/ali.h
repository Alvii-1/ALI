#include "../Headers/hardware.h"
#include "../Headers/instructions.h"

using namespace std;

#ifndef ALI_H
#define ALI_H

class ALI 
{
    public:
        Hardware hardware;              // Hardware object for ALI
        unsigned int instruction_count; // Number of instructions executed
        vector<string> program_source;  // Program source code

        // Mapping string inputs to Command subclasses via map
        map<string, Command*> instructions_map;
        DecInstruction DEC;
        LdaInstruction LDA;
        LdiInstruction LDI;
        StrInstruction STR;
        XchInstruction XCH;
        JmpInstruction JMP;
        JzsInstruction JZS;
        AddInstruction ADD;
        SubInstruction SUB;
        HltInstruction HLT;

        ALI(); // Constructor
        ~ALI(); // Destructor

        void load_file(string file);                // Load file
        void display_source();                      // Display source code
        void step_run(bool full_run_flag = false);  // Run single cmd
        void full_run();                            // Run entire file
}; // End ALI Class Declarations

#endif 