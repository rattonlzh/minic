ifeq ($(shell uname), Linux)#linux平台 
	BIN_SCAN = bin/scan
	BIN_GENTREE = bin/genTree
else#window平台
	BIN_SCAN = bin/scan.exe
	BIN_GENTREE = bin/genTree.exe
endif
CCFLAGS=-std=c++11 -Wall -g -static
SRC_SCAN=lex.cc scan.cc 
SRC_GENTREE=lex.cc parse.cc TreeUtil.cc genTree.cc

.PHONEY:test clean install testScanner testGenTree all doc 
install: src/lex.cc src/parse.cc
	g++ $(CCFLAGS) $(addprefix src/, $(SRC_SCAN)) -o $(BIN_SCAN)
	g++ $(CCFLAGS) $(addprefix src/, $(SRC_GENTREE)) -o $(BIN_GENTREE)
	@echo 可执行文件已经在bin目录生成
src/lex.cc: src/lexer.l
	flexc++ src/lexer.l --target-directory=src
src/parse.cc:src/grammar.y
	bisonc++ src/grammar.y --target-directory=src
testScan:  $(BIN_SCAN)
	$(BIN_SCAN) test/in/testScan1.mc > test/out/scan1.txt && diff test/out/scan1.txt test/check/scan1.txt
	$(BIN_SCAN) test/in/testScan2.mc > test/out/scan2.txt && diff test/out/scan2.txt test/check/scan2.txt
	$(BIN_SCAN) test/in/testScan3.mc > test/out/scan3.txt && diff test/out/scan3.txt test/check/scan3.txt
	$(BIN_SCAN) test/in/testScan4.mc > test/out/scan4.txt 2>&1 && diff test/out/scan4.txt test/check/scan4.txt

testGenTree: $(BIN_GENTREE)
	$(BIN_GENTREE)  test/in/testGenTree1.mc > test/out/genTree1.txt && diff test/out/genTree1.txt test/check/genTree1.txt
	$(BIN_GENTREE)  test/in/testGenTree2.mc > test/out/genTree2.txt && diff test/out/genTree2.txt test/check/genTree2.txt
	$(BIN_GENTREE)  test/in/testGenTree3.mc > test/out/genTree3.txt && diff test/out/genTree3.txt test/check/genTree3.txt
	$(BIN_GENTREE)  test/in/testGenTree4.mc > test/out/genTree4.txt && diff test/out/genTree4.txt test/check/genTree4.txt
	$(BIN_GENTREE)  test/in/testGenTree5.mc > test/out/genTree5.txt && diff test/out/genTree5.txt test/check/genTree5.txt

test: testScan testGenTree
	@echo 测试通过
#clean: 
#	rm -f src/lex.cc  src/Scanner.h src/Scannerbase.h src/Parser.h src/Parserbase.h src/parse.cc  bin/scan bin/genTree
#doc:
#	doxygen ../docs/Doxyfile
#	mv api文档 ../docs