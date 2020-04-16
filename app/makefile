.PHONEY: all 
.PHONY: clean 
.PHONY: test
all:src/lexer.cc src/parse.cc
	g++ src/*.cc -o bin/scanner
src/lexer.cc src/parse.cc: src/lexer.l src/grammar.y
	bisonc++ src/grammar.y --target-directory=src/
	flexc++ src/lexer.l --target-directory=src/
test:

	@bin/scanner test/in/test1.mc  test/out/res1.txt  && diff test/out/res1.txt test/check/check1.txt
	@bin/scanner test/in/test2.mc  test/out/res2.txt  && diff test/out/res2.txt test/check/check2.txt
	@bin/scanner test/in/test3.mc  test/out/res3.txt  && diff test/out/res3.txt test/check/check3.txt
	@bin/scanner test/in/test4.mc  test/out/res4.txt 2>test/out/res4.txt && diff test/out/res4.txt test/check/check4.txt
	
clean: 
	rm -f src/Scanner.h src/Scannerbase.h src/Parser.h src/Parserbase.h src/parse.cc src/lexer.cc