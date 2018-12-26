// #include "def.h"
#include "genericLinkedList.h"
#include "varList.h"

struct Functions{
	char* retType;
	char* funcName;
	struct genericNode* localVarList; 		// varList
	struct genericNode* paramList; 			// paramList

//	LinkedList content;
};

struct callFunc{
	// argumanList is a varList
	struct genericNode* argumanList;
};

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
 
struct statement* getLeftStatement(struct statement* st){
	return st->left;
}

struct statement* getRightStatement(struct statement* st){
	return st->right;
}

