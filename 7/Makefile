a.out: 218.tab.c++ lex.yy.c symTab.o
	g++ 218.tab.c++ lex.yy.c symTab.o
218.tab.c++ : 218.y++
	bison -d -v 218.y++
lex.yy.c : 218.l
	flex 218.l
symTab.o : symTab.c++ symTab.h
	g++ -Wall -c symTab.c++
clean:
	rm a.out 218.output 218.tab.c++ 218.tab.h++ symTab.o lex.yy.c

