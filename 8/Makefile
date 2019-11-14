a.out: lex.yy.c
	gcc lex.yy.c
lex.yy.c: main.l
	flex main.l
clean:
	rm lex.yy.c a.out
