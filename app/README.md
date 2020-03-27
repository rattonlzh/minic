# 构建说明
## 在Linux上构建
在Linux平台上编译，需要已经安装`cmake`，`make`，`gcc`,`g++`
切换到build目录下，输入命令`cmake ..`,根据上层目录的`CMakeLists.txt`在build目录生成`Makefile`文件,
输入`make`命令根据`Makefile`文件进行编译、链接，生成可执行程序到bin目录下