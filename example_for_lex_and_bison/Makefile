.PHONY:all

calc: calc++.o driver.hh driver.o parser.hh position.hh location.hh parser.o scan.o
	g++ calc++.o driver.o parser.o scan.o -o calc
calc++.o: calc++.cc parser.hh
	g++ -c calc++.cc
scan.o: scan.c
	g++ -c scan.c
driver.o: driver.cc
	g++ -c driver.cc
parser.o: parser.cc
	g++ -c parser.cc
parser.cc location.hh position.hh parser.hh: parser.yy
	bison parser.yy -d -o parser.cc
scan.c: scan.l
	 flex -o scan.c scan.l
