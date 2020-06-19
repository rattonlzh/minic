.PHONY:clean test all testGcd testSort run
CC = gcc

CFLAGS = -Wall -g

OBJS = y.tab.o lex.yy.o main.o util.o symtab.o analyze.o code.o cgen.o


ifeq ($(OS),Windows_NT)
TARGET = ..\bin\minic.exe
DEL = del
TM = ..\bin\tm.exe
else
TARGET = ../bin/minic
DEL = rm
TM = ../bin/tm
endif

all: $(TARGET)
	@echo 目标文件已生成在bin目录下

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	$(DEL) $(OBJS)

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

lex.yy.o: util.h globals.h lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.o: y.tab.h y.tab.c util.h globals.h
	$(CC) $(CFLAGS) -c y.tab.c

lex.yy.c: scanner.l
	flex -o lex.yy.c scanner.l

y.tab.h y.tab.c: parser.y
	bison -d parser.y --yacc
clean:
	$(DEL) $(OBJS) tm.o 

testGcd:$(TARGET)
	$(TARGET) ../test/gcd.mc -s -p -a -c
testSort:$(TARGET)
	$(TARGET) ../test/sort.mc -s -p -a -c
test:$(TARGET)
	$(TARGET) ../test/sort.mc -s -p -a -c

$(TM):tm.o
	$(CC) $(CFLAGS) tm.o -o $(TM)
	$(DEL) tm.o
tm.o :tm.c
	$(CC) $(CFLAGS) -c tm.c

run:$(TM)
	$(TM) ../test/test.tm