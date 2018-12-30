#include"def.h"


char* getFuncRetType(FILE* fp, size_t start, size_t end){
	char* getReturnLine(FILE*, size_t, size_t);
	char* findType(char* src);

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


int main(){
	if( !stackFactory(200) ){
		error("Unsuccessful Starting of Stack");
	}
	FILE* in = fopen("Files/in.txt","r");
	FILE* out = fopen("Files/out.txt","w+");
	char buffer[N];
	int i = 0;
	char tmp;
	int curr_position;

//	fgets(buffer,N,in);
//	printf("%s", getFuncName(buffer) );	

	size_t x = ftell(in);
	size_t pos = getEndOffset(in, x);
	fseek(in, pos, SEEK_SET);

	fgets(buffer, N-1, in);
	printf("pos: %lu, string:  %s", pos, buffer);

	char* type = getFuncRetType(in, x, pos);

	printf("type: %s", type);
	
	
	return 0;
}
