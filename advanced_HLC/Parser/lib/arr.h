typedef struct{
	char* name;
	char* type;
	int capacity;
	int id;
	var* indexPointer;
	void* arr;
}ARR;

ARR* ArrayFactory(char* name, char* type, int capacity){
	void* genericArrayFactory(ARR* arr);

	ARR* arr = (ARR*)malloc( sizeof(ARR) );
	arr->name = name;
	arr->type = type;
	arr->capacity = capacity;
	arr->arr = (void*)genericArrayFactory(arr);

	arr->indexPointer = NULL;

	return arr;
}

bool setArrIndex(ARR* array, var* var ){
	array->indexPointer = var;
}

void* genericArrayFactory(ARR* arr){

	if( !strcmp(arr->type, "_file") ){
		FILE* array = (FILE*)malloc( arr->capacity * sizeof(FILE) );
		return array;
	}else if( !strcmp(arr->type, "char*") ){
		char** array = (char**)malloc( arr->capacity * sizeof(char*) );
		return array;
	} else if( !strcmp(arr->type, "float*") ){
		float** array = (float**)malloc( arr->capacity * sizeof(float*) );
		return array;
	} else if( !strcmp(arr->type, "int*") ){
		int** array = (int**)malloc( arr->capacity * sizeof(int*) );
		return array;
	} else if( !strcmp(arr->type, "long double*") ){
		long double** array = (long double**)malloc( arr->capacity * sizeof(long double*) );
		return array;
	} else if( !strcmp(arr->type, "long*") ){
		long** array = (long**)malloc( arr->capacity * sizeof(long*) );
		return array;
	} else if( !strcmp(arr->type, "double*") ){
		double** array = (double**)malloc( arr->capacity * sizeof(double*) );
		return array;
	} else if( !strcmp(arr->type, "long double") ){
		long double* array = (long double*)malloc( arr->capacity * sizeof(long double) );
		return array;
	} else if( !strcmp(arr->type, "char") ){
		char* array = (char*)malloc( arr->capacity * sizeof(char) );
		return array;
	} else if( !strcmp(arr->type, "float") ){
		float* array = (float*)malloc( arr->capacity * sizeof(float) );
		return array;
	} else if( !strcmp(arr->type, "int") ){
		int* array = (int*)malloc( arr->capacity * sizeof(int) );
		return array;
	} else if( !strcmp(arr->type, "long") ){
		long* array = (long*)malloc( arr->capacity * sizeof(long) );
		return array;
	} else if( !strcmp(arr->type, "double") ){
		double* array = (double*)malloc( arr->capacity * sizeof(double) );
		return array;
	} 

}
