CC = gcc

CFLAGS = -Wall -g

OBJS = y.tab.o lex.yy.o main.o util.o symtab.o analyze.o code.o cgen.o

minic: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o minic

main.o: main.c globals.h util.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h
	$(CC) $(CFLAGS) -c util.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

analyze.o: analyze.c globals.h symtab.h analyze.h
	$(CC) $(CFLAGS) -c analyze.c

code.o: code.c code.h globals.h
	$(CC) $(CFLAGS) -c code.c

cgen.o: cgen.c globals.h symtab.h code.h cgen.h
	$(CC) $(CFLAGS) -c cgen.c

lex.yy.o: scanner.l util.h globals.h
	flex -o lex.yy.c scanner.l
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.o: parser.y util.h globals.h
	bison -d parser.y --yacc
	$(CC) $(CFLAGS) -c y.tab.c

clean:
	-del minic.exe
	-del y.tab.c
	-del y.tab.h
	-del lex.yy.c
	-del $(OBJS)

test:
	-minic test.cm

all: minic
