build:
	rm -f ./a.out
	g++ -std=c++11 -g Source/main.cpp Source/instructions.cpp Source/ali.cpp Source/hardware.cpp Source/command.cpp -O

run:
	./a.out

leak:
	rm -f ./a.out
	g++ -std=c++11 -g Source/main.cpp Source/instructions.cpp Source/ali.cpp Source/hardware.cpp Source/command.cpp -O
	leaks --atExit -- ./a.out

clean:
	rm -f ./a.out