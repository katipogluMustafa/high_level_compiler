#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"def.h"

int main(){

	int i,j;

	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");

	CODE* inputCode = getCode(in);
	printCode(*inputCode);

	CODE* outputCode = codeFactory();  

	return 0;
}

