CCFLAGS=-std=c++11 -Wall -g -static
SRC_SCAN=$(addprefix src/, lex.cc scan.cc)
SRC_GENTREE=$(addprefix src/, lex.cc parse.cc TreeUtil.cc genTree.cc)
DEBUG=0
.PHONEY:test clean install testScanner testGenTree all doc debug
ifeq ($(OS),Windows_NT)

bin/scan.exe:src/lex.cc src/parse.cc  $(SRC_SCAN)
	g++ $(CCFLAGS) $(SRC_SCAN) -o bin/scan.exe
bin/genTree.exe:src/lex.cc src/parse.cc  $(SRC_GENTREE)
	g++ $(CCFLAGS) $(SRC_GENTREE) -o bin/genTree.exe
src/lex.cc: src/lexer.l
ifeq ($(DEBUG), 1)
	flexc++ src/lexer.l -d --target-directory=src
else
	flexc++ src/lexer.l --target-directory=src
endif
src/parse.cc:src/grammar.y
	bisonc++ src/grammar.y --target-directory=src
testScan:  bin/scan.exe
	bin/scan.exe test/in/testScan1.mc > test/out/scan1.txt && diff test/out/scan1.txt test/check/scan1.txt
	bin/scan.exe test/in/testScan2.mc > test/out/scan2.txt && diff test/out/scan2.txt test/check/scan2.txt
	bin/scan.exe test/in/testScan3.mc > test/out/scan3.txt && diff test/out/scan3.txt test/check/scan3.txt
	bin/scan.exe test/in/testScan4.mc > test/out/scan4.txt 2>&1 && diff test/out/scan4.txt test/check/scan4.txt

testGenTree: bin/genTree.exe
	bin/genTree.exe  test/in/testGenTree1.mc > test/out/genTree1.txt && diff test/out/genTree1.txt test/check/genTree1.txt
	bin/genTree.exe  test/in/testGenTree2.mc > test/out/genTree2.txt && diff test/out/genTree2.txt test/check/genTree2.txt
	bin/genTree.exe  test/in/testGenTree3.mc > test/out/genTree3.txt && diff test/out/genTree3.txt test/check/genTree3.txt
	bin/genTree.exe  test/in/testGenTree4.mc > test/out/genTree4.txt && diff test/out/genTree4.txt test/check/genTree4.txt
	bin/genTree.exe  test/in/testGenTree5.mc > test/out/genTree5.txt && diff test/out/genTree5.txt test/check/genTree5.txt

test: testScan testGenTree
	@echo 测试通过
debug:bin/scan.exe
	bin/scan.exe test/in/testScan1.mc
else
# Linux平台
bin/scan:src/lex.cc src/parse.cc $(SRC_SCAN)
	g++ $(CCFLAGS) $(SRC_SCAN) -o bin/scan
bin/genTree:src/lex.cc src/parse.cc  $(SRC_GENTREE)
	g++ $(CCFLAGS) $(SRC_GENTREE) -o bin/genTree
src/lex.cc: src/lexer.l
ifeq ($(DEBUG), 1)
		flexc++ src/lexer.l -d --target-directory=src
else
		flexc++ src/lexer.l --target-directory=src
endif
src/parse.cc:src/grammar.y
	bisonc++ src/grammar.y --target-directory=src
testScan:  bin/scan
	bin/scan test/in/testScan1.mc > test/out/scan1.txt && diff test/out/scan1.txt test/check/scan1.txt
	bin/scan test/in/testScan2.mc > test/out/scan2.txt && diff test/out/scan2.txt test/check/scan2.txt
	bin/scan test/in/testScan3.mc > test/out/scan3.txt && diff test/out/scan3.txt test/check/scan3.txt
	bin/scan test/in/testScan4.mc > test/out/scan4.txt 2>&1 && diff test/out/scan4.txt test/check/scan4.txt

testGenTree: bin/genTree
	bin/genTree  test/in/testGenTree1.mc > test/out/genTree1.txt && diff test/out/genTree1.txt test/check/genTree1.txt
	bin/genTree  test/in/testGenTree2.mc > test/out/genTree2.txt && diff test/out/genTree2.txt test/check/genTree2.txt
	bin/genTree  test/in/testGenTree3.mc > test/out/genTree3.txt && diff test/out/genTree3.txt test/check/genTree3.txt
	bin/genTree  test/in/testGenTree4.mc > test/out/genTree4.txt && diff test/out/genTree4.txt test/check/genTree4.txt
	bin/genTree  test/in/testGenTree5.mc > test/out/genTree5.txt && diff test/out/genTree5.txt test/check/genTree5.txt

test: testScan testGenTree
	@echo 测试通过
#clean: 
#	rm -f src/lex.cc  src/Scanner.h src/Scannerbase.h src/Parser.h src/Parserbase.h src/parse.cc  bin/scan bin/genTree
doc:
	doxygen ../docs/Doxyfile
	mv api文档 ../docs
debug:bin/scan
	bin/scan test/in/testScan1.mc
	bin/scan test/in/testScan2.mc
	bin/scan test/in/testScan3.mc
	bin/scan test/in/testScan4.mc
	bin/scan test/in/testGenTree1.mc
	
endif