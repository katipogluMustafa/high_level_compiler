#define N 500 			// stands for number of lines
#define M 1000			// stands for max num of chars in a line

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