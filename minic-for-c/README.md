<!--

## 目录结构及重要文件说明
```
.
├── bin
│   └── minic
├── tools
├── minic-gui
├── 项目设计报告书.doc
├── dist
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
    ├── gcd.mc
    ├── sort.mc
    ├── scan.mc
    ├── scan_error.mc
    ├── parse.mc
    ├── parse_error.mc
    └── typecheck.mc
```
- bin是命令行可执行程序的目录，
- src是命令行程序源码目录
- test是测试用例文件
- tools是flex.exe和bison.exe程序
- dist是gui程序的安装包
- minic-gui文件夹是gui程序的源码

## 编译软硬件要求

编译命令行需要有gcc和make工具

编译gui需要在装有qt5.12和在vs中装了qt tool插件

## 使用说明
bin目录下的minic.exe是命令行程序，运行格式为`minic.exe [option] filename`
option是编译标志，列举如下
```
-s 或 --scan: 词法分析阶段，打印扫描到的词法符号
-p 或 --p: 语法分析阶段，打印语法树
-a 或 --analyze： 语义分析阶段， 打印符号表和类型检查信息
-g 或 --DebugCode： 产生中间代码
-c 或 --code：产生中间代码时打印调试信息
```
由于打印语法树用到了特殊字符，因此需要命令行的字符集编码为utf8， cmd切换字符集为utf-8的命令：`chcp 65001`
tm虚拟机运行格式：`tm.exe filename`

输入g执行程序

打包的gui程序已经把minic.exe和tm.exe放在了和minic-gui.exe的同级目录下
