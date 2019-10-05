objfiles = main.o parser.o lex.o backend.o

a.out: $(objfiles)
	cc $(objfiles)

main.o: main.c
	cc -c -Wall main.c

parser.o: parser.c
	cc -c -Wall parser.c

lex.o: lex.c
	cc -Wall -c lex.c

backend.o: backend.c
	cc -Wall -c backend.c

clean : 
	rm a.out $(objfiles)
