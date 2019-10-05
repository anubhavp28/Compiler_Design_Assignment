objfiles = main.o parser.o lex.o stack.o
a.out: $(objfiles)
	cc $(objfiles)
main.o: main.c
	cc -c -Wall main.c
parser.o: parser.c
	cc -c -Wall parser.c
lex.o: lex.c
	cc -Wall -c lex.c
stack.o: stack.c
	cc -Wall -c stack.c
clean :
	rm a.out $(objfiles)
