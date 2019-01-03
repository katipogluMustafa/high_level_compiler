#define N 500 			// stands for number of lines
#define M 1000			// stands for max num of chars in a line

typedef int bool;
typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

typedef struct{
	char** data;
	int linePointer;

}CODE;

CODE* codeFactory(){
	int i;

	char** content = (char**)malloc( N * sizeof(char*) );
	for(i = 0; i < N; i++){
		content[i] = (char*)malloc( M * sizeof(char) );
	}

	CODE* code = (CODE*)malloc( sizeof(CODE) );
	code->data = content;
	code->linePointer = 0;

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
	int i,j;

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