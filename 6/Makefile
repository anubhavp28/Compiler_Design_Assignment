a.out: 218.tab.c++ lex.yy.c
	g++ 218.tab.c++ lex.yy.c
218.tab.c++ : 218.y++
	bison -d -v 218.y++
lex.yy.c : 218.l
	flex 218.l
clean:
	rm a.out 218.output 218.tab.c++ 218.tab.h++ lex.yy.c

