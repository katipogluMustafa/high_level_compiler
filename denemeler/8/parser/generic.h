#include "../def.h"
#include "genericLinkedList.h"
#include "varList.h"
#include "param.h"
#include "arr.h"

struct Function{
	char* retType;
	char* funcName;
	struct genericNode* localVarList; 		// varList
	struct genericNode* paramList; 			// paramList
	int id;
};

struct callFunc{
	// argumanList is a varList
	struct genericNode* argumanList;
	int id;
};

struct Conditional{
	struct genericNode* localVarList; 
	Condition* conditions;
	int id;
}

struct Condition{
	struct Condition* left;
	struct Condition* right;
	char* operator;
};

// Library Functions

typedef struct callFunc PRINT_LINE;
typedef struct callFunc GET_VAL;

// Grammars

typedef struct Conditional ifThen;
typedef struct Conditional whileDo; 
typedef struct{
	struct genericNode* localVarList;
	var startVar;
	var endVar;
	int id;
}FORLOOP; // FL = ForLoop





/*
struct statement{

	union{
			var varData;
			char* opData;
	}data;

	struct statement* left;
	struct statement* right;	
};

struct statement* statementListFactory(var varData, char* opData){
	struct statement* head = (struct statement*)malloc( sizeof(struct statement) );
	head.left = (struct statement*)malloc( sizeof(struct statement) );
	head.right = (struct statement*)malloc( sizeof(struct statement) );

	if( varData != NULL ){
		head.data.varData = varData;
	}else if( strlen(opData) != 0 ){
		head.data.opData = opData;
	}

	return head;
}
*/

