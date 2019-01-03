#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"codeGenerator.h"
#include"funcs.h"
#include"def.h"

	
int main(){

	int i,j;
	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");

	CODE* inputCode = getCode(in);
//	printCode(*inputCode);
/*
	CODE** myFuncs = malloc( sizeof(CODE*) * 3);
	myFuncs[0] = inputCode;
	myFuncs[1] = inputCode;
	myFuncs[2] = NULL;
	CODE* outputCode = combineFuncs(myFuncs);
	printCode(*outputCode);
*/		
	CODE** functions = getFuncs(inputCode);	
	i = 0;
	while(functions[i] != NULL){
		high_level_to_c_converter(functions[i++]);
	}

	CODE* outputCode = combineFuncs(functions);

	if ( exportCode(outputCode,out) ){
		printf("\nSuccessfully Output Code is generated!\n");
	}else{
		printf("\nError while exporting code!\n");
	}

	return 0;
}



