# Assembly Language Interpreter
Small-scale Assembly Language Interpreter to learn about low-level execution.

I created this to explore low-level execution. In tradition CS cirriculums, you might only have 1 machine organization class. But I wanted to go a bit further to explore what the relationship between something like program input and system memory looks like.


This program makes use of simple assembly language (SAL) as input. I plan to expand this significantly in the future to account for the variety of instructions in assembly. As it stands, the program simulates data registers, zero bit flags, accumulators, program counters and data and program memory. Inputs can be ran via uploading a file (should consider some GUI here...) and running in either single or multi step execution. Infinite loops are indeed possible with the limited instruction set here, so the program will ask you if you'd like to continue execution every 1000 runs of a command. You can either run the program and input file all at once and see the final output, or run in a step-wise fashion where the "hardware" states are displayed at each step of execution.

The primary objective of this program is to use the SAL input to perform arithmetic operations.

The possible commands are separated into subclasses of the superclass Command, which holds things like the opcode and calls virtual functions depending on the input from the input file.

The hardware exists in its own class and uses a union object MemObj to hold program memory, and uses a symbol table to map possible commands to their hardware level instructions.

The main ALI loop holds the command string -> object mapping, the instructions count (for infinite loops), and two methods which allow for step execution or full execution as described previously. Calling the full execution method via the input just continuously calls step run but with a true flag to tell it not to print hardware states until after its done executing.

The program makes use of the MacOS leaks software, unfortunately no valgrind to check here. Leaks is pretty similar though, and this program currently does not resulted in any memory-related problems (anymore...).

There is a makefile present to make running it easier.

```
make build  - compile program
make run    - run program after compiling
make leaks  - check for leaks (contrary to what the wording seems like, lol)
make clean  - delete current executable
```

I usually just run:

```
make build run leaks
```

Further, when in the program, there are three possible user inputs when the file is uploaded, which must be done first. The program will respond to confirm its method of execution.

```
s  -  Run a single line of code from the file and print hardware status.
a  -  Run all lines of code in the file and print final hardware status.
q  -  Terminate the program.
```

Test files are also attached as examples of possible file inputs.

Thats all there is to it for now. Definitely taught me a lot more about assembly execution, but also some fun C++ quirks when it comes to OOP. There is lots of possible instruction combinations, haven't tested them all yet but should be fun!

Side note: might be the prettiest C++ I've written. No idea why I decided to make it look so pretty.
