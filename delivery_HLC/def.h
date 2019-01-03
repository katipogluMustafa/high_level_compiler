#ifndef N

#define N 500 			// stands for number of lines

#endif

#ifndef M

#define M 1000			// stands for max num of chars in a line

#endif

#ifndef K

#define K 10 			// max number of procedures in the code

#endif


#ifndef BOOL

#define BOOL bool

typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#endif

typedef struct{
	int start;
	int end;
}FuncInfo;

FuncInfo* FuncInfoFactory(){

	FuncInfo* info = (FuncInfo*)malloc( sizeof(FuncInfo) );

	info->start = 0;
	info->end = 0;

	return info;
}

/*
 * parameters: High Level Code inside CODE*
 * return: An Array Of NULL terminated Function Codes as CODE**
 *
 */
CODE** getFuncs(CODE* sourceCode){
	CODE* getFuncCode(CODE*, FuncInfo*);
	FuncInfo* getFunc(CODE*, int);

	CODE** funcs = (CODE**)malloc( sizeof(CODE*) * K );
	funcs[K-1] = NULL;

	int funcsPointer = 0;
	int lp = sourceCode->linePointer;
	
	int i = 0;
	while( i < lp){
		FuncInfo* funcData = getFunc(sourceCode, i);

		CODE* func = getFuncCode(sourceCode, funcData);
		funcs[funcsPointer] = func;
		funcsPointer++;

		i = funcData->end;
	}

	return funcs;
}

/*
 * Takes a source code and after finding a procedure
 * it returns it starting and ending point as FuncInfo
 */
FuncInfo* getFunc(CODE* src, int start){
	FuncInfo* FuncInfoFactory();
	size_t getStackSP();
	bool stackFactory(size_t);

	int i;
	int lp = src->linePointer;
	int flag = 0;
	char* p;
	size_t curr_sp;

	// start stack
	size_t sp;
	if( !stackFactory(200) ){
		printf("Unsuccessful Starting of Stack");
	}else{
		sp = getStackSP();
	}	

	FuncInfo* info = FuncInfoFactory();

	for(i = 0; i < lp; i++){

		if( flag == 0 && ( ( p = strstr(src->data[i], "PROCEDURE") ) != NULL ) ){
			flag = 1;
			info->start = i;
		}else if( ( p = strstr(src->data[i], "BEGIN") ) != NULL ){
			push(1);
		}else if( ( p = strstr(src->data[i], "END") ) != NULL ){
			pop();
		}else if( flag == 1 && ( ( curr_sp = getStackSP() ) == sp ) && (i > info->start) ){
			info->end = i-1;
			return info;
		}

	}

	// error
	if( info ->end == 0){
		return NULL;
	}

	return info;
}



/*
 * Takes a FuncInfo and cretes a code snipet
 * which includes the code of the source
 * between the line numbered as start and end
 */
CODE* getFuncCode(CODE* src, FuncInfo* info){
	void transferCodeSections(CODE*, CODE*, FuncInfo*);
	CODE* codeFactory();

	CODE* code = codeFactory();

	transferCodeSections(code, src, info);

	return code;
}

/*
 * Copies the source's data sections into destination's end.
 * parameters: takes 2 CODE*
 * return: no return
 */
void transferCodeSections(CODE* dest, CODE* src, FuncInfo* info){
	int destLP = dest->linePointer + 1;
	int srcLP = src->linePointer;
	int i;

	int start = info->start;
	int end = info->end;

	for(i = start; i < end; i++){
		strcpy(dest->data[destLP], src->data[i]);
		destLP++;
	}

	dest->linePointer = destLP -1 ;
}