#ifndef N

#define N 500 			// stands for number of lines

#endif

#ifndef M

#define M 1000			// stands for max num of chars in a line

#endif

#ifndef K

#define K 10 			// max number of procedures in the code

#endif

typedef struct{
	char** data;
	char** tokenizedData;
	int linePointer;
	int isTokenized;
}CODE;

CODE* codeFactory(){
	int i;

	char** content = (char**)malloc( N * sizeof(char*) );
	for(i = 0; i < N; i++){
		content[i] = (char*)malloc( M * sizeof(char) );
	}
	char** tokenizedContent = (char**)malloc( N * sizeof(char*) );
	for(i = 0; i < N; i++){
		tokenizedContent[i] = (char*)malloc( M * sizeof(char) );
	}

	CODE* code = (CODE*)malloc( sizeof(CODE) );
	code->data = content;
	code->tokenizedData = tokenizedContent;
	code->linePointer = 0;
	code->isTokenized = 0;

	return code;
}

CODE* getCode(FILE* in){
	int i;

	CODE* code = codeFactory();

	i = 0;
	while( !feof(in) ){
		fgets(code->data[i], M-1, in);
		i++;
	}

	code->linePointer = i - 1;

	return code;
}


void printCode(CODE code){
	int i = code.linePointer,j;
	for(j = 0; j < i; j++){
		printf("%s",code.data[j]);
	}
}

/*
 * takes a CODE* src
 * and after copying its data into tokenizedData
 * tokenizes the tokenizedData
 */

void tokenizeTheCode(CODE* src){
	void copyDataIntoTokenizedData(CODE*);

	copyDataIntoTokenizedData(src);

	src->isTokenized = 1;
}

void copyDataIntoTokenizedData(CODE* src){
	int lp = src->linePointer;
	int i;

	for(i = 0; i < lp; i++){
		strcpy(src->tokenizedData[i], src->data[i]);
	}
}

/*
 * parameters: array of CODE* which has function codes inside of each Code
 * return: a single CODE* which has all the function codes. 
 */
CODE* combineFuncs(CODE** funcs){
	void transferCode(CODE*, CODE*);

	CODE* output = codeFactory();
	int i;
	for(i = 0; funcs[i] != NULL; i++){
		transferCode(output, funcs[i]);
	}
	return output;
}

/*
 * Copies the source's data into destination's data.
 * parameters: takes 2 CODE*
 * return: no return
 */
void transferCode(CODE* dest, CODE* src){
	int destLP = dest->linePointer + 1;
	int srcLP = src->linePointer;
	int i;

	for(i = 0; i < srcLP; i++){
		strcpy(dest->data[destLP], src->data[i]);
		destLP++;
	}

	dest->linePointer = destLP -1 ;
}

/*
 * parameters: CODE* sourceCode, FILE* outFile
 * return: if successfully written true, else false
 */

bool exportCode(CODE* sourceCode, FILE* out){
	int i = sourceCode->linePointer,j;

	for(j = 0; j < i; j++){
		fputs(sourceCode->data[j],out);
	}

	return true;
}
