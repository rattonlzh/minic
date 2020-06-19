/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/minic2/minic/src/main.c
 * @Description: 主函数入口文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-19 19:01:27
 * @LastEditors: Liang Zehao
 */

#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "y.tab.h"
#include "analyze.h"
#include "cgen.h"

// 全局变量定义，外部声明在globals.h中
int lineno = 1;
FILE *source;
FILE *listing;
FILE *code;

// 打印词法符号
int TraceScan = FALSE;
// 生成语法树
int TraceParse = FALSE;
// 类型检查和生成符号表
int TraceAnalyze = FALSE;
// 跟踪中间代码生成工程
int TraceCode = FALSE;
// 产生中间代码
int GenCode = FALSE;
// 如果出现错误则置为ＴＲＵＥ
int Error = FALSE;
// 输入参数的最大长度
#define MAX_LEN 120
//保存输入文件名
char infile[MAX_LEN];
// 保存中间代码的文件名
char codefile[MAX_LEN];
// 文件名的长度
int lenF = 0;
// 是否指定输入文件
int in = FALSE;

void main(int argc, char *argv[])
{
    // 参数不足
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <infile>\n", argv[0]);
        exit(1);
    }
    // 整个程序的语法树根节点
    TreeNode *syntaxTree;
    // 输出流设为标准输出流
    listing = stdout;
    int hasOption = FALSE;
    // 扫描所有输入参数
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            // 解析选项
            if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--scan") == 0)
            {
                // 允许打印词法符号
                TraceScan = TRUE;
                hasOption = TRUE;
            }
            else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--parse") == 0)
            {
                // 允许打印语法树
                TraceParse = TRUE;
                hasOption = TRUE;
            }
            else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--analyze") == 0)
            {
                TraceAnalyze = TRUE;
                hasOption = TRUE;
            }
            else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--code") == 0)
            {
                GenCode = TRUE;
                TraceCode = TRUE;
                hasOption = TRUE;
            }else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--genCode") == 0)
            {
                GenCode = TRUE;
                hasOption = TRUE;
            }
            else
            {
                fprintf(stderr, "Unknown option!\n");
                exit(1);
            }
        }
        else // 指定输入文件
        {
            strncpy(infile, argv[i], MAX_LEN);
            lenF = len(infile, MAX_LEN);
            // 检查后缀是否是.mc
            if (lenF >= 4 && '.' == infile[lenF - 3] && 'm' == infile[lenF - 2] && 'c' == infile[lenF - 1])
            {
                strncpy(codefile, infile, lenF - 2);
                strcat(codefile, "tm");
            }
            else
            {
                fprintf(stderr, "Infile is invalid. It must be with .mc suffix and length should not be lower than 4.\n");
                exit(1);
            }

            in = TRUE;
        }
    } // 扫描完所有参数
    // 如果不加option默认开启所有option
    if (!hasOption)
    {
        TraceScan = TRUE;
        TraceParse = TRUE;
        TraceAnalyze = TRUE;
        TraceCode = TRUE;
        GenCode = TRUE;
    }
    if (!in)
    {
        fprintf(stderr, "A inputfile is needed.\n");
    }
    source = fopen(infile, "r");
    // 找不到文件则结束
    if (source == NULL)
    {
        fprintf(stderr, "File %s not found\n", infile);
        exit(1);
    }
    printf("\n==== Compilation for %s ====\n", infile);
    if (TraceScan)
    {
        init(); // 设置lex分析器的输入流和输出流
        printf("Scanning the tokens...\n");
        while (getToken() != ENDFILE)
            ; // 打印词法符号
        fclose(source);
        // 重新打开文件流,让后面的语法分析正常工作
        source = fopen(infile, "r");
        // 找不到文件则结束
        if (source == NULL)
        {
            fprintf(stderr, "File %s not found\n", infile);
            exit(1);
        }
    }

    // 得到语法树
    syntaxTree = parse(source);
    if (!Error)
    {
        if (TraceParse)
        {
            printf("Generating the syntax tree...\n");
            printTree(syntaxTree);
        }
        if (TraceAnalyze)
        {
            printf("Building symbol table...\n");
            buildSymtab(syntaxTree);
            printf("Checking types...\n");
            typeCheck(syntaxTree);
            printf("Type Checking Finished\n");
        }
        if (GenCode)
        {
            code = fopen(codefile, "w");
            if (code == NULL)
            {
                printf("Unable to create %s\n", codefile);
                exit(1);
            }
            codeGen(syntaxTree, codefile);
            printf("intermediate code file %s generated.", codefile);
            fclose(code);
            
        }
    }
    else
    {
        // 出错
        fprintf(listing, "Your horse is gone.");
    }

    fclose(source);
}