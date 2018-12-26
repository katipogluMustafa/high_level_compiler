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

}