
// returns an array of functions
FUNCTION* functionAnalizer(FILE* fp){
	bool getFuncSpecs(FILE* fp, FUNCTION* func, char* buffer, size_t startOffset);

	size_t linePosition;
	int curr_position = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char buffer[N];
	char* ptr;

	FUNCTION* funcs = (FUNCTION*)malloc( sizeof(FUNCTION) );
	int funcsCapacity = 1;
	int funcsIndex = 0;
	
	while(!feof(fp)){
		linePosition = ftell(fp);
		fgets(buffer, N-1, fp);
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
	void error(char*);
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
	char* getReturnLine(FILE*, size_t, size_t);

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


NODE* getParamList(FILE* fp, size_t start){
	NODE* getParamLinkedList(char*);
	bool removeAfterwards(char*, char*);
	bool removeBefore(char*, char*);
	void removeChars(char*, char);

	size_t curr = ftell(fp);
	fseek(fp, start, SEEK_SET);
	char* line = (char*)malloc( N * sizeof(char) );
	fgets(line,N-1, fp);

	removeBefore(line, "(");
	removeAfterwards(line, ")");
	removeChars(line, ' ');

	NODE* params = getParamLinkedList(line);

	free(line);
	fseek(fp, curr, SEEK_SET);
	return params;
}

NODE* getParamLinkedList(char* buffer){
	char** getParamNameList(char*); // splits params into a list
	param* getParam(char*);

	int i;
	NODE* headOfParams;

	char** list = getParamNameList(buffer);

	if( strcmp(list[0], "NULL") != 0 ){
		headOfParams = paramListFactory( getParam(list[0]) );
	}

	for(i = 1; strcmp(list[i], "NULL") != 0 ;i++ ){
		paramPush(headOfParams, getParam(list[i]));
	}

	return headOfParams;
}

NODE* getLocalVarList(FILE* fp, size_t start, size_t end){
	void error(char*);
	int i;
	char* p;
	var* listHead, tempList;
	size_t curr = ftell(fp);
	fseek(fp, start, SEEK_SET);
	size_t sp, curr_sp, tempPos;
	char* Buffer[N];

	if(!isStackInitialized){
		error("Uninitialized Stack!!");
	}

	sp = getStackSP() + 1; 		// add first BEGIN's place

	while( !feof(fp) ){
		tempPos = ftell(fp);
		if( tempPos > end ){
			break;
		}
		fgets(buffer, N-1, fp);

		if( ( p = strstr(tempBuffer, "BEGIN") ) != NULL )
			push(1);
		else if( ( p = strstr(tempBuffer, "END") ) != NULL )
			pop();
		
		if( ( curr_sp = getStackSP() ) == sp ){
			if( strstr(buffer, "_"),  ){
				tempList = extractVars(buffer);
				i = 0;
				while( tempList[i] != NULL){
					if( !isVarAddedBefore(head, tempList[i]) )
						varPush(head, tempList[i]);
				}
			}
		}

	}

	fseek(fp, curr, SEEK_SET);
	return listHead;
}


/* 
 * Takes a buffer and returns a list of variables which is found inside buffer
 */
NODE* extractVars(char* buffer){
	/* Complete This*/
}




bool getFuncSpecs(FILE* fp, FUNCTION* func, char* buffer, size_t startOffset){
	char* getFuncName(char*);
	size_t getEndOffset(FILE*, size_t);
	char* getFuncRetType(FILE*, size_t, size_t);
	NODE* getLocalVarList(FILE*, size_t, size_t);
	NODE* getParamList(FILE*, size_t);
	int getId();
	

	/* Get Function Specs*/
	char* funcName = getFuncName(buffer); 						// done
	size_t endOffset = getEndOffset(fp, startOffset); 			// done
	char* retType = getFuncRetType(fp, startOffset, endOffset); // done
	NODE* localVarList = getLocalVarList(fp, startOffset, endOffset); 					
	NODE* paramList = getParamList(fp, startOffset); 			// done, test it
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
