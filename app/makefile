.PHONEY: all codes clean
all:src/lexer.cc src/parse.cc
	g++ src/*.cc -o bin/minic
src/lexer.cc src/parse.cc: src/lexer.l src/grammar.y
	bisonc++ src/grammar.y --target-directory=src/
	flexc++ src/lexer.l --target-directory=src/

clean: 
	rm -f src/Scanner.h src/Scannerbase.h src/Parser.h src/Parserbase.h src/parse.cc src/lexer.cc