%locations
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

void yyerror(const char *s);
extern int yylineno; // 来自 lexer.l
extern FILE *yyin;   // 输入文件
extern int yylex(void);
extern int hasLexicalError;

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

// 递归打印语法树
void printTree(Node *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; ++i) printf("  ");

    if (!node->child) {
        // 是词法单元（终结符）
        if (strcmp(node->name, "ID") == 0 || strcmp(node->name, "TYPE") == 0) {
            printf("%s: %s\n", node->name, node->strVal);
        } else if (strcmp(node->name, "INT") == 0) {
            printf("%s: %d\n", node->name, node->intVal);
        } else if (strcmp(node->name, "FLOAT") == 0) {
            printf("%s: %f\n", node->name, node->floatVal);
        } else {
            printf("%s\n", node->name);  // 其他终结符，如 SEMI, LP 等
        }
    } else {
        // 是语法单元（非终结符）
        printf("%s (%d)\n", node->name, node->lineno);
    }

    printTree(node->child, indent + 1);
    printTree(node->brother, indent);
}
%}

%union {
    struct Node *node;
}

%token <node> INT
%token <node> FLOAT
%token <node> ID
%token <node> RELOP TYPE ASSIGNOP PLUS MINUS STAR DIV
%token <node> IF ELSE WHILE RETURN STRUCT
%token <node> AND OR NOT SEMI COMMA LP RP LC LB RB RC DOT

%type <node> Program ExtDefList ExtDef Specifier ExtDecList
%type <node> StructSpecifier VarList ParamDec DefList CompSt
%type <node> StmtList Stmt Exp DecList Dec VarDec Def FunDec OptTag Args Tag

// 操作符的结合性
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right LOWER_THAN_NOT NOT
%right DOT LP LB RP RB

// 处理 if else 移进/规约冲突
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
Program: ExtDefList {
        $$ = createNode("Program", @1.first_line);
        $$->child = $1;
        int indent = 0;
        if (!hasLexicalError){ // 通过全局变量判断是否需要打印语法树（没出现错误的情况下）
            printTree($$, indent);
        }
        }
       ;

ExtDefList: ExtDef ExtDefList { $$ = createNode("ExtDefList", @1.first_line); $$->child = $1; $1->brother = $2; }
          | /* empty */ { $$ = NULL; }
          ;

ExtDef: Specifier ExtDecList SEMI {
            $$ = createNode("ExtDef", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
      |Specifier SEMI {
           $$ = createNode("ExtDef", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
      }
      |Specifier FunDec CompSt {
             $$ = createNode("ExtDef", @1.first_line);
             $$->child = $1;
             $1->brother = $2;
             $2->brother = $3;
             }
      | error SEMI { yyerrok; }
      ;

ExtDecList: VarDec{$$ = createNode("ExtDecList", @1.first_line); $$->child = $1;}
      |VarDec COMMA ExtDecList {
              $$ = createNode("ExtDecList",@1.first_line);
              $$->child = $1;
              $1 -> brother = $2;
              $2 -> brother = $3;
                                }
      |VarDec error ExtDecList {
              yyerrok;
      }
      ;

Specifier: TYPE {
        $$ = createNode("Specifier", @1.first_line);
        $$->child = $1;
    }
      | StructSpecifier {
        $$ = createNode("Specifier", @1.first_line);
        $$->child = $1;
    }
      ;

StructSpecifier:
       STRUCT OptTag LC DefList RC {
            $$ = createNode("StructSpecifier", @1.first_line);
            $$->child = $1;

            if ($2) {
                $1->brother = $2;
                $2->brother = $3;
            } else {
                $1->brother = $3;
            }

            $3->brother = $4;
            $4->brother = $5;
       }
       |STRUCT Tag {
            $$ = createNode("StructSpecifier", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
       }
   ;

Tag:
      ID {
          $$ = createNode("Tag", @1.first_line);
          $$->child = $1;
      }
      ;

OptTag:
      ID {
          $$ = createNode("OptTag", @1.first_line);
          $$->child = $1;
      }
      |/* empty */ {
          $$ = NULL;
      }
      ;

DefList:
       Def {
           $$ = createNode("DefList", @1.first_line);
           $$->child = $1;
       }
       | Def DefList {
            $$ = createNode("DefList", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
       }
       ;

/*
$$ = $1;  // 保留最初创建的父节点
            Node *cur = $1->child;
            while (cur->brother) cur = cur->brother;
            cur->brother = $2;
*/

FunDec:
      ID LP VarList RP {
              $$ = createNode("FunDec", @1.first_line);
              $$ -> child = $1;
              // 需要注意避免VarList为空情况下的空指针
              if ($3) {
                  $1->brother = $2;
                  $2->brother = $3;
                  $3->brother = $4;
              } else {
                  $1->brother = $2;
                  $2->brother = $4;
              }
          }
      | ID LP error RP {
          yyerrok;
          $$ = NULL;
      }
      ;

VarList:
      ParamDec COMMA VarList {
          $$ = createNode("VarList", @1.first_line);
          $$->child = $1;
          $1->brother = $2;
          $2->brother = $3;
      }
      | ParamDec {
          $$ = createNode("VarList", @1.first_line);
          $$->child = $1;
      }
      | /* empty */ {
          $$ = NULL;
      }
      ;

ParamDec:
      Specifier VarDec {
          $$ = createNode("ParamDec", @1.first_line);
          $$->child = $1;
          $1->brother = $2;
      }
      ;

Def:
       Specifier DecList SEMI {
           $$ = createNode("Def", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
           $2->brother = $3;
       }
       | Specifier error SEMI {
           yyerrok;
           $$ = NULL;
       }
       ;

DecList:
      Dec COMMA DecList {
          $$ = createNode("DecList", @1.first_line);
          $$->child = $1;
          $1->brother = $2;
          $2->brother = $3;
      }
      | Dec {
          $$ = createNode("DecList", @1.first_line);
          $$->child = $1;
      }
      ;

Dec:
      VarDec {
          $$ = createNode("Dec", @1.first_line);
          $$->child = $1;
      }
      | VarDec ASSIGNOP Exp {
          $$ = createNode("Dec", @1.first_line);
          $$->child = $1;
          $1->brother = $2;
          $1->brother->brother = $3;
      }
      ;

VarDec:
     ID {
         $$ = createNode("VarDec", @1.first_line);
         $$->child = $1;
     }
     | VarDec LB INT RB {
         $$ = createNode("VarDec", @1.first_line);
         $$->child = $1;

         $1->brother = $2;
         $2->brother = $3;
         $3->brother = $4;
     }
     | VarDec LB error RB {
         yyerrok;
         $$ = createNode("VarDec", @1.first_line);
         $$->child = $1;
         $1->brother = $2;
         $2->brother = $4;
     }
     ;

// 由于之前设置了DefList非空，所以这里设置了两条产生式
CompSt:
       LC DefList StmtList RC {
           $$ = createNode("CompSt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;

           if ($3) {
               $2->brother = $3;
               $3->brother = $4;
           }else{
               $2->brother = $4;
           }
       }
       |LC StmtList RC{
           $$ = createNode("CompSt", @1.first_line);
           $$->child = $1;

           if ($2) {
               $1->brother = $2;
               $2->brother = $3;
           }else{
               $1->brother = $3;
           }
       }
   ;

StmtList:
       Stmt StmtList {
           $$ = createNode("StmtList", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
       }
       |/* empty */ {
           $$ = NULL;
       }
   ;

Stmt:
       Exp SEMI {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
       }
       | CompSt {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
       }
       | RETURN Exp SEMI {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
           $2->brother = $3;
       }
       | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
           $2->brother = $3;
           $3->brother = $4;
           $4->brother = $5;
       }
       | IF LP Exp RP Stmt ELSE Stmt {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
           $2->brother = $3;
           $3->brother = $4;
           $4->brother = $5;
           $5->brother = $6;
           $6->brother = $7;
       }
       | WHILE LP Exp RP Stmt {
           $$ = createNode("Stmt", @1.first_line);
           $$->child = $1;
           $1->brother = $2;
           $2->brother = $3;
           $3->brother = $4;
           $4->brother = $5;
       }
       | error SEMI {
           yyerrok;
           $$ = NULL;
       }
       ;

Exp:
        Exp ASSIGNOP Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp AND Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp OR Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp RELOP Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp PLUS Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp MINUS Exp %prec LOWER_THAN_NOT {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp STAR Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp DIV Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | LP Exp RP {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | MINUS Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
        }
        | NOT Exp {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
        }
        | ID LP Args RP {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
            $3->brother = $4;
        }
        | ID LP RP {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | Exp LB Exp RB {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
            $3->brother = $4;
        }
        | Exp DOT ID {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
            $1->brother = $2;
            $2->brother = $3;
        }
        | ID {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
        }
        | INT {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
        }
        | FLOAT {
            $$ = createNode("Exp", @1.first_line);
            $$->child = $1;
        }
        ;

Args:
     Exp COMMA Args {
         $$ = createNode("Args", @1.first_line);
         $$->child = $1;
         $1->brother = $2;
         $2->brother = $3;
     }
     | Exp {
         $$ = createNode("Args", @1.first_line);
         $$->child = $1;
     }

%%