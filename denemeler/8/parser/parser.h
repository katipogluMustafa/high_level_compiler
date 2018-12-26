#include "def.h"

union content{
	LinkedList ifThen;
	LinkedList whileDo;
	LinkedList forLoop;
	LinkedList callFunc;
	LinkedList assignment;
}

struct conditioned{
	LinkedList localVars;
//	LinkedList content;
	Condition conditions;
}

typedef struct callFunc PRINT_LINE;
typedef struct callFunc GET_VAL;

typedef struct conditioned ifThen;
typedef struct conditioned whileDo; 


/*
typedef struct{
	var startVar;
	var endVar;
}FORLOOP; // FL = ForLoop
*/