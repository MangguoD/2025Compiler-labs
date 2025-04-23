#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define HASH_SIZE 0x3fff

#define INT_TYPE 1
#define FLOAT_TYPE 2
#define DECLA 1
#define DEFIN 2

typedef struct Type_ *Type;
typedef struct FieldList_ *FieldList;

typedef struct Type_ {
	enum {BASIC, ARRAY, STRUCTURE, FUNCTION,STR_SPE} kind;//结构类型和结构定义不是一个东西
    union{
		//基本类型
		int basic;
		//数组类型信息包括元素类型与数组大小构成
		struct {
			Type elem;
            int size;
		}array;
		// 结构体类型信息是一个链表
		FieldList structure;
		//函数
		struct{
			FieldList params;//参数
			Type funcType;//返回值类型
			int paramNum;//参数数量
			int state;//状态 
			int lineno;//行数 
		}function;
	}u;
}Type_;
/*
对作用域的用处有两个地方，一个是看该变量名能不能被定义，也就是说该名字有没有在同层下重复定义过或者与结构体类型相同，
此时就需要当前的作用域信息，这里我用current_id标记当前作用域，sc_table则是一个作用域(散列)表，这样就能通过current_id找到当前作用域。
另一个是使用变量时看先前有没有被定义，这就需要从里层往外层找变量的定义，此时就需要知道当前作用域和其外层作用域的范围，故而该结构需要知道wno和w。其中计算其外层作用域范围的方法只需
要用其parent作用域的w加上自己即可。（也可只往parent遍历）同时我们还需要进行进入新的作用域和退出当前作用域的操作，而退出当前作用域也需要parent_id的存在
 */
//作用域
typedef struct scope{
	int id;
	int parent_id;//自己外面一层的作用域
	int wno;//自己和自己所有外层作用域的数量
	int w[50];//自己和自己所有外层作用域的id
}scope;


//FieldList = 变量
typedef struct FieldList_ {
	char *name;//域的名字
	Type type;//域的类型
	FieldList tail;//下一个域
	int scope_id;//作用域
}FieldList_;

void enter_scope();
void exit_scope();

//符号表
unsigned int hash_pjw(char *name);
void initHashtable();
int insert(FieldList f);
//search会找外层的 用于判断是否未定义以使用 所以肯定是从当前层找
FieldList search(char *name,int flag);
//ifexist会找同层的 用于判断是否重复定义
FieldList ifexist(char *name,int id);
int TypeEqual(Type type1,Type type2);
void printSymbol();

//树
void Program(Node *root);
void ExtDefList(Node *node);
void ExtDef(Node *node);
Type Specifier(Node *node);
void ExtDecList(Node *node,Type spec);
void FunDec(Node *node,Type spec,int state);
void CompSt(Node *node,Type ftype);
FieldList VarDec(Node *type,Type spec);
Type StructSpecifier(Node *node);
void OptTag(Node *node,Type spec);
void DefList(Node *node);
// Type VarList(Node *node);
// void ParamDec(Node *node);
// void StmtList(Node *node);
void Stmt(Node *node,Type ftype);
Type Exp(Node *root);
void Def(Node *node);
void DecList(Node *node,Type spec);
void Dec(Node *node,Type spec);
// void Args(Node *node);

void check_declar();
