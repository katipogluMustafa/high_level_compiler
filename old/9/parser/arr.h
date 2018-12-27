#include "../def.h"

typedef struct{
	char* name;
	char* type;
	int capacity;
	int id;
	void* arr;
}Arr;

Arr* ArrayFactory(char* name, char* type, int capacity){
	Arr* arr = (Arr)malloc( sizeof(Arr) );
	arr.name = name;
	arr.type = type;
	arr.capacity = capacity;
	arr.arr = genericArrayFactory(arr);

	return arr;
}

void* genericArrayFactory(Arr arr){

	if( !strcmp(arr.type, "_file") ){
		FILE* arr = (FILE*)malloc( arr.capacity * sizeof(FILE) );
		return arr;
	}else if( !strcmp(arr.type, "char*") ){
		char** arr = (char**)malloc( arr.capacity * sizeof(char*) );
		return arr;
	} else if( !strcmp(arr.type, "float*") ){
		float** arr = (float**)malloc( arr.capacity * sizeof(float*) );
		return arr;
	} else if( !strcmp(arr.type, "int*") ){
		int** arr = (int**)malloc( arr.capacity * sizeof(int*) );
		return arr;
	} else if( !strcmp(arr.type, "long double*") ){
		long double** arr = (long double**)malloc( arr.capacity * sizeof(long double*) );
		return arr;
	} else if( !strcmp(arr.type, "long*") ){
		long** arr = (long**)malloc( arr.capacity * sizeof(long*) );
		return arr;
	} else if( !strcmp(arr.type, "double*") ){
		double** arr = (double**)malloc( arr.capacity * sizeof(double*) );
		return arr;
	} else if( !strcmp(arr.type, "long double") ){
		long double* arr = (long double*)malloc( arr.capacity * sizeof(long double) );
		return arr;
	} else if( !strcmp(arr.type, "char") ){
		char* arr = (char*)malloc( arr.capacity * sizeof(char) );
		return arr;
	} else if( !strcmp(arr.type, "float") ){
		float* arr = (float*)malloc( arr.capacity * sizeof(float) );
		return arr;
	} else if( !strcmp(arr.type, "int") ){
		int* arr = (int*)malloc( arr.capacity * sizeof(int) );
		return arr;
	} else if( !strcmp(arr.type, "long") ){
		long* arr = (long*)malloc( arr.capacity * sizeof(long) );
		return arr;
	} else if( !strcmp(arr.type, "double") ){
		double* arr = (double*)malloc( arr.capacity * sizeof(double) );
		return arr;
	} 

}
