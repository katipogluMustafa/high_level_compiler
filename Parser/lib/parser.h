#include"../def.h"

// returns an array of functions
FUNCTION* functionAnalizer(FILE* fp){
	bool getFuncSpecs(FUNCTION*, char[], char*);

	int curr_position = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char buffer[N];
	char* ptr;

	FUNCTION* funcs = (FUNCTION*)malloc( sizeof(FUNCTION) );
	int funcsCapacity = 1;
	int funcsIndex = 0;
	
	while(!feof(fp)){

		fgets(buffer, N, fp);
		assert( buffer );
		if( (ptr = strstr(buffer, "PROCEDURE")) != NULL ){

			if(funcsCapacity == funcsIndex){
				funcs = (FUNCTION*)realloc(funcs, funcsCapacity + 1);
				assert( funcs );
				funcsCapacity++;
			}

			assert( getFuncSpecs(&funcs[funcsIndex], buffer, ptr ) );
	
			funcsIndex += 1;
		}		


	}

	fseek(fp, curr_position, SEEK_SET);
}

bool getFuncSpecs(FUNCTION* func, char[] buffer, char* ptrToPROC){
	
	/* Get Function Specs*/

	char* retType = getFuncRetType();
	char* funcName = getFuncName(buffer);
	NODE* localVarList = getLocalVarList();
	NODE* paramList = getParamList();
	int id = getId();

	/* Error Controls */

	assert( retType != NULL );
	assert( funcName != NULL );
	assert( localVarList != NULL );
	assert( paramList != NULL );

	/* Fill the Function */

	func->retType = retType;
	func->funcName = funcName;
	func->localVarList = localVarList;
	func->paramList = paramList;
	func->id = id;

	return true;
}

char* getFuncName(char* buffer){

	char* tempBuffer = malloc( strlen(buffer) * sizeof(char) );
	strcpy(tempBuffer, buffer);

	removeAfterwards(tempBuffer, "(");
	removeString(tempBuffer, "PROCEDURE");
	removeChars(tempBuffer, ' ');

	char* funcName = malloc( ( strlen(buffer) + 1)  * sizeof(char) );
	strcpy(funcName, tempBuffer);

	free(tempBuffer);

	return funcName;
}

char* getFuncRetType(char* buffer, char* ptrToPROC){
	char* getPointerToEndOfFunction(buffer);
}

char* getPointerToEndOfFunction(FILE* fp, int start){
	int curr_position = ftell(fp);
	fseek(fp,start, SEEK_SET );

	char* tempBuffer = malloc( N * sizeof(char) );
	size_t sp, curr_sp, tempPosition;

	if( !isStackInitialized() ){
		error("Uninitialized Stack!!");
	}else{
		sp = getStackSP();
	}	


	while( !feof(fp) ){
		tempPosition = ftell(fp);
		fgets(tempBuffer, N-1, fp);
		char* p;

		if( ( p = strstr(tempBuffer, "BEGIN") ) != NULL ){
			push(1);
		}else if( ( p = strstr(tempBuffer, "END") ) != NULL ){
			pop();
		}

		// if true, tempBuffer has END of function
		if(  ( curr_sp = getStackSP() ) == sp ){
			
		}

	}


	fseek(fp, curr_position, SEEK_SET);
	return ptr;
}