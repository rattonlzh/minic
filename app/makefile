.PHONEY:test clean install testScanner testGenTree all doc
all: clean install
install: bin/scan bin/genTree
	@echo 可执行文件已经在bin目录生成
bin/scan:src/lex.cc src/parse.cc
	g++ src/lex.cc src/parse.cc src/scan.cc src/TreeUtil.cc -o bin/scan
bin/genTree:src/lex.cc src/parse.cc
	g++ src/lex.cc src/parse.cc src/TreeUtil.cc src/genTree.cc -o bin/genTree
src/lex.cc: src/lexer.l
	flexc++ src/lexer.l --target-directory=src/
src/parse.cc:src/grammar.y
	bisonc++ src/grammar.y --target-directory=src/
testScan:  bin/scan
	bin/scan test/in/test1.mc > test/out/res1.txt && diff test/out/res1.txt test/check/check1.txt
	bin/scan test/in/test2.mc > test/out/res2.txt && diff test/out/res2.txt test/check/check2.txt
	bin/scan test/in/test3.mc > test/out/res3.txt && diff test/out/res3.txt test/check/check3.txt
	bin/scan test/in/test4.mc > test/out/res4.txt 2>&1 && diff test/out/res4.txt test/check/check4.txt

testGenTree: bin/genTree
	bin/genTree  test/in/testParser1.mc
	bin/genTree  test/in/testParser2.mc
	bin/genTree  test/in/testParser3.mc
	bin/genTree  test/in/testParser4.mc

test: testScan testGenTree
	@echo 测试完成
clean: 
	rm -f src/lex.cc  src/Scanner.h src/Scannerbase.h src/Parser.h src/Parserbase.h src/parse.cc  bin/scan bin/genTree
doc:
	doxygen ../docs/Doxyfile
	mv api文档 ../docs