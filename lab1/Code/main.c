#include <stdio.h>
#include <stdlib.h>
#include "syntax.tab.h"

// 外部变量声明
extern FILE *yyin;        // 输入文件流指针
extern int yylineno;      // 当前行号
extern int hasLexicalError; // 错误标记，0表示没有错误，非0表示有错误
extern struct Node *head; // 语法树的头节点指针

// 函数声明
extern int yyparse(void);                              // 语法分析函数
extern void yyrestart(FILE *input_file);               // 重置词法分析器的输入文件

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
        yyrestart(yyin);
    }

    yyparse();
    return 0;
}