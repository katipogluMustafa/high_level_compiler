#include"def.h"

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

	char* line = getReturnLine(in, x, pos);

	printf("line: %s", line);
	
	
	return 0;
}
