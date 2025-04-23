%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntax.tab.h"
#include "Node.h"

void yyerror(const char *s); // 语法错误处理

int yycolumn = 1;

int hasLexicalError = 0;

// 行数同步
#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

// 词法错误报告
void print_lexical_error(const char* msg) {
    printf("Error type A at Line %d: %s\n", yylineno, msg);
}

// 创建语法树节点
Node *createNode(char *name, int lineno) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    node->name = strdup(name);
    node->lineno = lineno;
    node->child = NULL;
    node->brother = NULL;
    return node;
}
// 处理语法报错
static int lastErrorLine = -1;
void yyerror(const char *s) {
    if (lastErrorLine != yylineno) {
        printf("Error type B at Line %d: %s\n", yylineno, s);
        lastErrorLine = yylineno;
    }
}
// 创建节点
Node *createNode_lex(char *name, int lineno, void *val) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->name = strdup(name);
    node->child = NULL;
    node->brother = NULL;

    if (strcmp(name, "ID") == 0 || strcmp(name, "TYPE") == 0) {
        node->strVal = strdup((char *)val);
    } else if (strcmp(name, "INT") == 0) {
        node->intVal = *((int *)val);
    } else if (strcmp(name, "FLOAT") == 0) {
        node->floatVal = *((float *)val);
    } else {
        node->lineno = lineno;  // 非终结符或无值的词法符号使用行号
    }

    return node;
}

%}

%option noyywrap yylineno

INT     0|[1-9][0-9]*
FLOAT   {INT}\.[0-9]+
ID      [_a-zA-Z][0-9_a-zA-Z]*
RELOP   >|<|>=|<=|==|!=
TYPE    int|float

%%
[ \t\r]+   { /* 忽略空白字符 */ }
\n         { yycolumn = 1;}
"//".*     { /* 忽略单行注释 */ }
"/*"([^*]|\*[^/])*"*/" { /* 忽略多行注释 */ }

{INT}   { int val = atoi(yytext); yylval.node = createNode_lex("INT", yylineno, &val); return INT; }
{FLOAT} { float fval = atof(yytext); yylval.node = createNode_lex("FLOAT", yylineno, &fval); return FLOAT; }
{RELOP} { yylval.node = createNode_lex("RELOP", yylineno, NULL); return RELOP; }
{TYPE}  {  yylval.node = createNode_lex("TYPE", yylineno, strdup(yytext)); return TYPE; }

"struct" {  yylval.node = createNode_lex("STRUCT", yylineno, NULL); return STRUCT; }
"return" {  yylval.node = createNode_lex("RETURN", yylineno, NULL); return RETURN; }
"if"     {  yylval.node = createNode_lex("IF", yylineno, NULL); return IF; }
"else"   {  yylval.node = createNode_lex("ELSE", yylineno, NULL); return ELSE; }
"while"  {  yylval.node = createNode_lex("WHILE", yylineno, NULL); return WHILE; }
"."      {  yylval.node = createNode_lex("DOT", yylineno, NULL); return DOT; }

"="     {  yylval.node = createNode_lex("ASSIGNOP", yylineno, NULL); return ASSIGNOP; }
"+"     {  yylval.node = createNode_lex("PLUS", yylineno, NULL); return PLUS; }
"-"     {  yylval.node = createNode_lex("MINUS", yylineno, NULL); return MINUS; }
"*"     {  yylval.node = createNode_lex("STAR", yylineno, NULL); return STAR; }
"/"     { yylval.node = createNode_lex("DIV", yylineno, NULL); return DIV; }
"&&"    {  yylval.node = createNode_lex("AND", yylineno, NULL); return AND; }
"||"    {  yylval.node = createNode_lex("OR", yylineno, NULL); return OR; }
"!"     {  yylval.node = createNode_lex("NOT", yylineno, NULL); return NOT; }

";"     {  yylval.node = createNode_lex("SEMI", yylineno, NULL); return SEMI; }
","     {  yylval.node = createNode_lex("COMMA", yylineno, NULL); return COMMA; }
"("     {  yylval.node = createNode_lex("LP", yylineno, NULL); return LP; }
")"     { yylval.node = createNode_lex("RP", yylineno, NULL); return RP; }
"{"     {  yylval.node = createNode_lex("LC", yylineno, NULL); return LC; }
"}"     {  yylval.node = createNode_lex("RC", yylineno, NULL); return RC; }
"["     {  yylval.node = createNode_lex("LB", yylineno, NULL); return LB; }
"]"     {  yylval.node = createNode_lex("RB", yylineno, NULL); return RB; }

{ID}    { yylval.node = createNode_lex("ID", yylineno, strdup(yytext)); return ID; }

.       { print_lexical_error("Invalid character"); hasLexicalError = 1; }

%%