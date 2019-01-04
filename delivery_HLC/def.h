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

#include"stack.h"
#include"strRemover.h"
#include"varList.h"
#include"codeGenerator.h"
#include"funcs.h"

/*
 * Take a Function Code
 * Analyzes it
 * converts to c code
 */

void high_level_to_c_converter(CODE* func){
	void func_begin_end_converter(CODE*);
	void func_call_converter(CODE*);
	void control_statement_converter(CODE*);
	void for_condition_converter(CODE*);

	func_begin_end_converter(func);
	func_call_converter(func);
	control_statement_converter(func);
	for_condition_converter(func);

}
void for_condition_converter(CODE* func){
	bool removeString(char*, char*);
	void removeChars(char*, char);
	char* findType(char*);

	int lp = func->linePointer;
	int i;
	char *s, *e, *type, *name;
	char temp[N];

	for(i = 0; i < lp;i++){
		if( ( s = strstr(func->data[i], "for(") ) != NULL ){
			if( ( e = strstr(func->data[i], "<-") ) != NULL ){
				s += 4;
				strcpy(temp, s);
				removeString(temp,e);
				removeChars(temp,' ');
				type = findType(temp);
				removeAfterwards(temp, "_");
				name = malloc( ( strlen(temp) + 1 ) * sizeof(char) );
				strcpy(name,temp);
			}		
		}
	}
}

void control_statement_converter(CODE* func){
	int lp = func->linePointer;
	int i;
	char *	s, *e;

	for(i = 0; i < lp;i++){
		if( ( s = strstr(func->data[i], "FOR") ) != NULL ){
			s += 3;
			if( ( e = strstr(s, "LOOP") ) != NULL ){
				strReplace(func->data[i], "FOR", "for(");
				strReplace(func->data[i], "LOOP", ")");
			}else{
				printf("Error!, Missing LOOP Keyword in For Loop");
			}
		}else if( ( s = strstr(func->data[i], "IF") ) != NULL ){
			s += 2;
			if( ( e = strstr(s, "THEN") ) != NULL ){
				strReplace(func->data[i], "IF", "if(");
				strReplace(func->data[i], "THEN", ")");
			}else{
				printf("Error!, Missing then Keyword in if statement");
			}
		}
	}
}

void func_call_converter(CODE* func){

	int lp = func->linePointer;
	int i;
	char* p;

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
			removeChars(func->data[i-1],'\n');
			replaceString(p,5,"{\n",1);
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
		printf("%s", src);
		error("unknown return type!");
	}
	free(src);
	return type;
}	