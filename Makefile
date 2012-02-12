deps=GumballMachine.h GB_Global.h

default: ${deps}
	g++ GumballGame.cpp GumballMachine.cpp -o GumballGame

dev: ${deps}
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ GumballGame.cpp GumballMachine.cpp -o GumballGame