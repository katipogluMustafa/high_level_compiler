struct Function{
	char* retType;
	char* funcName;
	NODE* localVarList; 		// varList
	NODE* paramList; 			// paramList
	int id;
};

typedef struct Function FUNCTION;

struct callFunc{
	// argumanList is a varList
	NODE* argumanList;
	int id;
};

struct Conditional{
	NODE* localVarList; 
	struct Condition* conditions;
	int id;
};

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
	NODE* localVarList;
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

