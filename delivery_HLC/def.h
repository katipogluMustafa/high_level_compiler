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

#include"strRemover.h"


/*
 * Take a Function Code
 * Analyzes it
 * converts to c code
 */

void high_level_to_c_converter(CODE* func){
	void func_begin_end_converter(CODE*);
	void func_call_converter(CODE*);
	
	func_begin_end_converter(func);
	func_call_converter(func);
}

void func_call_converter(CODE* func){

	int lp = func->linePointer;
	int i,size = 0;
	char* p,*k;

	for(i = 0; i < lp;i++){

		if( ( p = strstr(func->data[i], "PRINT_LINE") ) != NULL ){
			strReplace(func->data[i],"PRINT_LINE","printf(");
			removeChars(func->data[i],'\n');
			strcat(func->data[i], ");\n");
		}else if( ( p = strstr(func->data[i], "GET_VAL") ) != NULL ){
			strReplace(func->data[i],"GET_VAL","scanf(");
			removeChars(func->data[i],'\n');
			strcat(func->data[i], ");\n");
		}

	}

} 


void func_begin_end_converter(CODE* func){
	void replaceString(char*, int, char*,  int);
	
	int lp = func->linePointer;
	int i;
	char* p;


	for(i = 0; i < lp;i++){

		if( p = strstr(func->data[i], "BEGIN") ){
			replaceString(p,5,"{",1);
		}else if( p = strstr(func->data[i], "END") ){
			replaceString(p,5,"}\n",3);
		}else if( p = strstr(func->data[i], "PROCEDURE MAIN()") ){
			replaceString(p,16,"void main()\n",13);
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
