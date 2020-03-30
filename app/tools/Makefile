objects = y.tab.o lex.yy.o
.PHONY: test
test: $(objects) testScanner.o
	gcc $(objects) testScanner.o -o testScanner
testScanner.o : testScanner.c
	gcc -c testScanner.c
y.tab.o : y.tab.c
	gcc -c y.tab.c
lex.yy.o : lex.yy.c
	gcc -c lex.yy.c
y.tab.h y.tab.c : minic.y
	yacc -d minic.y
lex.yy.c : minic.l
	lex minic.l

