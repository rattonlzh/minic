# mini-c-compiler

## 介绍
构建一个mini-c编译器，实现项目设计指导书中的词法分析、语法分析、语义分析、中间代码生成等功能

## 目录构成
```
mini-c-compiler
├─ README.md
├─ app
│  ├─ CMakeLists.txt
│  ├─ README.md
│  ├─ bin
│  ├─ build
│  ├─ include
│  └─ src
└─ docs
   ├─ 产品文档
   │  └─ 系统使用说明书.md
   ├─ 实验报告
   │  ├─ README.md
   │  ├─ 一、实验内容.md
   │  ├─ 三、实验文档.md
   │  ├─ 二、实验目的.md
   │  ├─ 五、参考文献.md
   │  ├─ 六、项目以及各成员自评.md
   │  ├─ 四、实验总结.md
   │  ├─ 编译原理项目设计指导书.pdf
   │  ├─ 项目设计报告书 书写格式（原版）.docx
   │  └─ 项目设计报告模板.docx
   ├─ 开发文档
   │  ├─ MINI-C的BNF.md
   │  ├─ MINI-C的词法.md
   │  ├─ 测试文档.md
   │  ├─ 编程规范.md
   │  └─ 项目要求.md
   └─ 进度报告.md

```

## 开发平台
Linux系统64位

## 编译工具
g++, make, cmake, qt工具链(qmake, uic，moc)

## 开发说明
采用git工作流（master+devop+feature+hotfix四分支）
注意查看`docs/开发文档/项目要求.md`的要求以及DDL
开发人员每日做的工作当天记录到`docs/进度报告.md`中
组长确定初始的项目分工，填写到`docs/开发文档/项目分工.md`中
