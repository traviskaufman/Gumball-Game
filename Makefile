deps=GumballMachine.h GB_Global.h

default: ${deps}
	g++ GumballGame.cpp GumballMachine.cpp -o GumballGame

dev: ${deps}
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ GumballGame.cpp GumballMachine.cpp -o GumballGame

ml: ${deps}
	export GLIBCXX_FORCE_NEW=true
	g++ Gumballgame.cpp GumballMachine.cpp -o GumballGame_ML
	valgrind --leak-check=full --show-reachable=yes -v ./GumballGame_ML
	export GLIBCXX_FORCE_NEW=false