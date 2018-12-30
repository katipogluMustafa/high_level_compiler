int currId = 0;

int getId(){
	int id = currId;
	currId++;

	return id;
}

void error(char* msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno) );
	exit(1);
}

var* getVar(char* varstr){
	char* findType(char*);
	bool removeAfterwards(char*, char*);
	int getId();

	var* variable = malloc( sizeof(var*) );
	variable->type = findType(varstr);
	variable->id = getId();

	char* temp;
	strcpy(temp, varstr);
	removeAfterwards(temp, "_");

	variable->name = (char*)malloc( (strlen(temp) + 1) * sizeof(char) );

	strcpy(variable->name, temp); 

	free(temp);
	return variable;
}


param* getParam(char* paramStr){
	char* findType(char*);
	bool removeAfterwards(char*, char*);
	int getId();
	param* theParam = malloc( sizeof(param*) );
	theParam->type = findType(paramStr);
	theParam->id = getId();

	char* temp;
	strcpy(temp, paramStr);
	removeAfterwards(temp, "_");

	theParam->name = (char*)malloc( (strlen(temp) + 1) * sizeof(char) );

	strcpy(theParam->name, temp); 

	free(temp);
	return theParam;
}



char* findType(char* srcStr){
	void error(char*);
	char* type;
	char* src = malloc( ( strlen(srcStr) + 1) * sizeof(char) );
	strcpy(src, srcStr);

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
	free(src);
	return type;
}	

char** getParamNameList(char* buffer){
	char** params = (char**)malloc( sizeof(char*) );
	int i;
	char temp[N];

	i = 0;
	while( *buffer != '\0'){
		
		if( *buffer == ','){
			buffer++;
		}

		strcpy(temp, buffer);
		removeAfterwards(temp, ",");

		params[i] = (char*)malloc( strlen(temp) + 1 * sizeof(char) );
		strcpy(params[i], temp);
		buffer += strlen(temp);
		i++;
	}

	params[i] = (char*)malloc( 5 * sizeof(char) );
	strcpy(params[i], "NULL");

	return params;
}