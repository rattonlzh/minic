<!--
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 -->




## 目录结构及重要文件说明
.
├── bin
│   └── minic
├── README.md
├── src
│   ├── analyze.c
│   ├── analyze.h
│   ├── cgen.c
│   ├── cgen.h
│   ├── code.c
│   ├── code.h
│   ├── globals.h
│   ├── lex.yy.c
│   ├── main.c
│   ├── Makefile
│   ├── parser.y
│   ├── scanner.l
│   ├── symtab.c
│   ├── symtab.h
│   ├── tm.c
│   ├── util.c
│   ├── util.h
│   ├── y.tab.c
│   └── y.tab.h
└── test
    ├── expected
    ├── gcd.mc
    ├── gcd.tm
    ├── parse1.mc
    ├── parse1.tm
    ├── parse2.mc
    ├── parse3.mc
    ├── parse4.mc
    ├── parse5.mc
    ├── scan1.mc
    ├── scan2.mc
    ├── scan3.mc
    ├── scan4.mc
    └── sort.mc
- bin是命令行可执行程序的目录，
- src是命令行程序源码目录
- test是测试用例文件，test/expected的文件是同名测试用例的预期输出
- tools是flex.exe和bison.exe程序

## 编译软硬件要求

## 运行命令

