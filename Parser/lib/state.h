
typedef enum { 
			   UNDEFINED_OPERATOR, 
			   
			   PLUS,
			   MINUS,
			   MUL,
			   DIV,
			   MOD,

			   RELATIONAL_EQUAL,
			   RELATIONAL_NOT_EQUAL,

			   LOGICAL_NOT,
			   LOGICAL_AND,
			   LOGICAL_OR,
			   
			   BITWISE_NOT,
			   BITWISE_AND,
			   BITWISE_OR,
			   BITWISE_XOR,

			   ASSIGNMENT,
			   ASSIGNMENT_WITH_SUM,
			   ASSIGNMENT_WITH_DIFF,
			   ASSIGNMENT_WITH_MUL,
			   ASSIGNMENT_WITH_DIV,
			   ASSIGNMENT_WITH_MOD,
			   ASSIGNMENT_WITH_MUL,
			   ASSIGNMENT_WITH_LEFT_SHIFT,
			   ASSIGNMENT_WITH_RIGHT_SHIFT,
			   ASSIGNMENT_WITH_BITWISE_AND,
			   ASSIGNMENT_WITH_BITWISE_OR,
			   ASSIGNMENT_WITH_BITWISE_XOR,
			   					   
			   ADDRESS_OF,

			   PLUSPLUS,
			   MINUSMINUS,


			    } OPERATOR_TYPE;
			    
typedef enum { UNDEFINED, VARIABLE, ARRAY, OPERAT } DATA_TYPE;

typedef struct{
	struct{
		var* opVar;
		ARR* opArr;
		OPERATOR_TYPE operat;
	}data;
	DATA_TYPE type;
}OP;

struct statement{
	OP* info;
	struct statement* left;
	struct statement* right;
};

typedef struct statement STATE;


STATE* stateFactory(){
	OP* opFactory();

	STATE* state = (STATE*)malloc( sizeof(STATE) );
	
	state->right  = (STATE*)malloc( sizeof(STATE) );
	state->left   = (STATE*)malloc( sizeof(STATE) );
	

	state->right = NULL;
	state->left  = NULL;
	state->info  = opFactory();

	return state;
}

OP* opFactory(){
	OP* info 	= (OP*)malloc( sizeof(OP) );
	
	info->data.opVar    = (var*)malloc( sizeof(var) );
	info->data.opArr 	= (ARR*)malloc( sizeof(ARR) );
	info->data.operat   = UNDEFINED_OPERATOR;
	info->type 		    = UNDEFINED;

	return info;
}

void setOpAsVar(OP* op, var* variable){
	op->data.opVar = variable;	
	op->type = VARIABLE;
}


void setOpAsARR(OP* op, ARR* array){
	op->data.opArr = array;	
	op->type = ARRAY;
}

void setDataAsOperator(OP* op, OPERATOR_TYPE type){
	op->data.operat = type;	
	op->type = OPERAT;
}

bool fillState(STATE* state,char* buffer){
	
	// If the statement has == or != inside
		
	// If the stement has = inside

	// if the statement doesn't have assignment Operator



	if( ( ptr = strstr(buffer, ++) ) != NULL ){

	} 


}






