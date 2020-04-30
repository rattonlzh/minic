# mini-c-compiler项目说明
本项目实现一个mini-c编译器的构建，实现项目设计指导书中的词法分析、语法分析、语义分析、中间代码生成等功能。实验分成两个图形界面和命令行程序两个部分。前期以命令行程序的形式实现项目要求，后期实现图形界面程序，通过GUI调用命令行程序输出结果。为了方便安装和使用flexc++和bisonc++工具，项目开发在Linux环境上进行。图形界面开发采用QT库实现，后期使用Qt Installer Framework等工具对程序进行打包生成安装包

## 目录树
```
.
├── app
│   ├── bin
│   │   ├── scan.exe
│   │   ├── genTree.exe
│   │   ├── genTree
│   │   └── scan
│   ├── makefile
│   ├── src
│   │   ├── genTree.cc
│   │   ├── grammar.y
│   │   ├── lex.cc
│   │   ├── lexer.l
│   │   ├── parse.cc
│   │   ├── Parserbase.h
│   │   ├── Parser.h
│   │   ├── Parser.ih
│   │   ├── scan.cc
│   │   ├── Scannerbase.h
│   │   ├── Scanner.h
│   │   ├── Scanner.ih
│   │   ├── TreeNode.h
│   │   ├── TreeUtil.cc
│   │   └── TreeUtil.h
│   └── test
│       ├── check
│       │   ├── check1.txt
│       │   ├── check2.txt
│       │   ├── check3.txt
│       │   └── check4.txt
│       ├── in
│       │   ├── test1.mc
│       │   ├── test2.mc
│       │   ├── test3.mc
│       │   ├── test4.mc
│       │   ├── testParser1.mc
│       │   ├── testParser2.mc
│       │   ├── testParser3.mc
│       │   └── testParser4.mc
│       └── out
│           ├── res1.txt
│           ├── res2.txt
│           ├── res3.txt
│           └── res4.txt
├── docs
│   ├── Doxyfile
│   ├── 分析文档
│   │   ├── 概要设计.md
│   │   ├── 详细设计
│   │   │   ├── minc-editor界面图.png
│   │   │   ├── minic程序体系结构图.png
│   │   │   ├── minic语法树类图.png
│   │   │   ├── 加减乘除的语法树.png
│   │   │   └── 长子-兄弟链表法示意图.png
│   │   ├── 详细设计.md
│   │   └── 需求描述.md
│   ├── 实验报告
│   │   ├── 中期检查报告.md
│   │   ├── 一、实验内容.md
│   │   ├── 三、实验文档.md
│   │   ├── 二、实验目的.md
│   │   ├── 四、实验总结.md
│   │   ├── 五、参考文献.md
│   │   ├── 六、项目以及各成员自评.md
│   │   ├── 编译原理项目设计指导书.pdf
│   │   ├── 项目设计报告书 书写格式（原版）.docx
│   │   └── 项目设计报告模板.docx
│   ├── 开发文档
│   │   ├── 构建说明.md
│   │   ├── 测试文档.md
│   │   └── 编程规范.md
│   └── 管理文档
│       ├── 进度报告.md
│       ├── 项目分工.md
│       └── 项目要求.md
└── README.md
```
## 目录说明
- app/src是源码目录
- lexer.l文件定义minic的词法，通过flexc++编译可以生成Scannerbase.h, Scanner.h,Scanner.ih,lex.cc四个文件，其中Scanner.ih如果已存在，则重新编译lexer.l不会重新生成该文件
- grammar.y定义minic的语法，通过bisonc++编译可以生成Parser.h, Parser.ih, Parserbase.h, parse.cc四个文件，其中Parser.ih如果已存在，重新编译grammar.y不会重新生成该文件
- scan.cc包含一个主函数，可以生成词法扫描的可执行程序
- genTree.cc包含一个主函数，可以生成产生语法树的可执行程序
- makefile文件定义了构建可执行程序、执行测试、产生api文档的命令序列，供make工具使用
- app/test是测试文件目录，其中in目录包含测试的输入文件，out目录存放执行测试时产生的输出文件，check目录存放测试的预期结果
- docs目录存放项目的相关文档，其中Doxyfile文件定义了api文档生成的相关配置选项，供doxygen工具使用

### 编译环境
OS：ubuntu18.04 LTS
处理器架构：x86_64
需要工具及版本：
g++ >= 7.5
make >= 4.1
flexc++ >= 2.06.02
bisonc++ >= 6.01.00
doxygen >= 1.8.13
diff >= 3.6
如果缺少以上工具，可以使用Linux软件包管理器安装
ubuntu的安装命令：`sudo apt install g++ make flexc++ bisonc++`

### 构建说明
1. 确保系统有g++，make，flexc++，bisonc++程序且已添加到环境变量中

2. 假设当前目录为项目根目录，切换到app目录：`cd app`

3. 输入构建命令：`make install`

4. 在bin文件夹会生成scan和genTree两个可执行程序，分别用于词法扫描和语法树生成

   
### 运行说明

#### 词法扫描器的运行

1. 假设当前目录为项目根目录，切换到bin目录：`cd app/bin`

2. 编写minic源文件，并保存为test.mc

3. 运行命令：`./scan test.mc`

#### 语法树生成器的运行

1. 假设当前目录为项目根目录，切换到bin目录：`cd app/bin`

2. 编写minic源文件，并保存为test.mc

3. 运行命令：`./genTree test.mc`


## 开发说明
采用git工作流（master+devop+feature+hotfix四分支）
注意查看`docs/开发文档/项目要求.md`的要求以及DDL
开发人员每日做的工作当天记录到`docs/进度报告.md`中
组长确定初始的项目分工，填写到`docs/开发文档/项目分工.md`中

