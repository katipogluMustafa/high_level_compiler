#ifndef N

#define N 500 			// stands for number of lines

#endif

#ifndef M

#define M 1000			// stands for max num of chars in a line

#endif

#ifndef K

#define K 10 			// max number of procedures in the code

#endif


#ifndef BOOL

#define BOOL bool

typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#endif


/*
 * Take a Function Code
 * Analyzes it
 * converts to c code
 */

void high_level_to_c_converter(CODE* func){
	void begin_end_converter(CODE*);

	begin_end_converter(func);

}

void begin_end_converter(CODE* func){
	void replaceString(char*, int, char*,  int);
	
	int lp = func->linePointer;
	int i;
	char* p;

	for(i = 0; i < lp;i++){

		if( p = strstr(func->data[i], "BEGIN") ){
			replaceString(p,5,"}",1);
		}

	}

}

void replaceString(char* p, int n1, char* str,  int n2){
	int i;
	for(i = 0; i < n2; i++){
		p[i] = str[i];
	}
	strcpy(p + n2, p + n1);
}
