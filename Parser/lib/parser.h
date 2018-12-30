
// returns an array of functions
FUNCTION* functionAnalizer(FILE* fp){
	bool getFuncSpecs(FUNCTION*, char[], char*);
	size_t linePosition;
	int curr_position = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char buffer[N];
	char* ptr;

	FUNCTION* funcs = (FUNCTION*)malloc( sizeof(FUNCTION) );
	int funcsCapacity = 1;
	int funcsIndex = 0;
	
	while(!feof(fp)){
		linePosition = ftell();
		fgets(buffer, N, fp);
		assert( buffer );
		if( (ptr = strstr(buffer, "PROCEDURE")) != NULL ){

			if(funcsCapacity == funcsIndex){
				funcs = (FUNCTION*)realloc(funcs, funcsCapacity + 1);
				assert( funcs );
				funcsCapacity++;
			}

			assert( getFuncSpecs(fp, &funcs[funcsIndex], buffer, linePosition) );
	
			funcsIndex += 1;
		}		


	}

	fseek(fp, curr_position, SEEK_SET);
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



size_t getEndOffset(FILE* fp, size_t startOffset){
	size_t getLineOfTheEndOFunc(FILE*, size_t);
	size_t curr = ftell(fp);
	fseek(fp, startOffset, SEEK_SET);

	while( fgetc(fp) != '\n' );

	size_t endOffset = getLineOfTheEndOFunc(fp, ftell(fp));

	fseek(fp, curr, SEEK_SET);

	return endOffset;
}

size_t getLineOfTheEndOFunc(FILE* fp, size_t start){
	size_t curr_position = ftell(fp);
	size_t sp, curr_sp, tempPosition, positionOfEnd;

	fseek(fp,start, SEEK_SET );
	char* tempBuffer = malloc( N * sizeof(char) );
	

	if( !isStackInitialized() ){
		error("Uninitialized Stack!!");
	}else{
		sp = getStackSP();
	}	


	while( !feof(fp) ){
		char* p;
		// tempPosition = position of the line in file
		tempPosition = ftell(fp);
		
		fgets(tempBuffer, N-1, fp);

		if( ( p = strstr(tempBuffer, "BEGIN") ) != NULL ){
			push(1);
		}else if( ( p = strstr(tempBuffer, "END") ) != NULL ){
			pop();
		}

		// if true, tempBuffer has END of function
		if(  ( ( curr_sp = getStackSP() ) == sp ) && (tempPosition > start) ){
			positionOfEnd = tempPosition; 
			break;
		}

	}

	fseek(fp, curr_position, SEEK_SET);
	return positionOfEnd;
}

char* getFuncRetType(FILE* fp, size_t start, size_t end){
	size_t curr = ftell(fp);
	fseek(fp,start,SEEK_SET);
	char* type;
	char* line = getReturnLine(fp, start, end);


	removeString(line, "RETURN");
	removeChars(line, ' ');
	type = findType(line);

	free(line);
	fseek(fp, curr, SEEK_SET);
	return type;
}

char* getReturnLine(FILE* fp, size_t start, size_t end){
	size_t curr = ftell(fp);
	fseek(fp,start,SEEK_SET);
	char* line = (char*)malloc( N * sizeof(char) );
	line[0] = '\0';
	char* ptr;

	while( !feof(fp) && ( ftell(fp) < end ) ){

		fgets(line, N-1, fp);

		if( ( ptr = strstr(line, "RETURN") ) != NULL ){
			break;
		}
	
	}

	fseek(fp, curr, SEEK_SET);
	return line;
}

char* findType(char* src){
	char* type;

	if( strlen(src) == 0){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type, "void");
	}else if( removeString(src, "_file") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"FILE*");

	}else if( removeString(src, "_cp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"char*");

	}else if( removeString(src, "_fp") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"float*");

	}else if( removeString(src, "_ip") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"int*");

	}else if( removeString(src, "_ldp") ){
		type = (char*)malloc( 13 * sizeof(char) );
		strcpy(type,"long double*");
		
	}else if( removeString(src, "_lp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"long*");

	}else if( removeString(src, "_dp") ){
		type = (char*)malloc( 8 * sizeof(char) );
		strcpy(type,"double*");

	}else if( removeString(src, "_ld") ){
		type = (char*)malloc( 12 * sizeof(char) );
		strcpy(type,"long double");
	
	}else if( removeString(src, "_c") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"char");
	
	}else if( removeString(src, "_f") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"float");
	
	}else if( removeString(src, "_i") ){
		type = (char*)malloc( 4 * sizeof(char) );
		strcpy(type,"int");
	
	}else if( removeString(src, "_l") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"long");
	
	}else if( removeString(src, "_d") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"double");
	
	}else{
		error("unknown return type!");
	}

	return type;
}	


bool getFuncSpecs(FILE* fp, FUNCTION* func, char[] buffer, size_t startOffset){
	
	/* Get Function Specs*/
	char* funcName = getFuncName(buffer); 						// done
	size_t endOffset = getEndOffset(fp, startOffset); 			// done
	char* retType = getFuncRetType(fp, startOffset, endOffset); // done
	NODE* localVarList = getLocalVarList();
	NODE* paramList = getParamList();
	int id = getId();

	/* Error Controls */

	assert( retType != NULL );
	assert( funcName != NULL );
	assert( localVarList != NULL );
	assert( paramList != NULL );

	/* Fill the Function */

	func->startOffset = startOffset;
	func->endOffset = endOffset;
	func->retType = retType;
	func->funcName = funcName;
	func->localVarList = localVarList;
	func->paramList = paramList;
	func->id = id;

	return true;
}
