#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef BOOL

#define BOOL bool

typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#endif

#ifndef N

#define N 100

#endif

struct{

	// Data
	int* data;

	// Info
	size_t max;
	size_t sp;

	// Methods
	bool (*push)();
	int (*pop)();

}stack;

size_t getStackSP(){
	return stack.sp;
}

size_t getStackMax(){
	return stack.max;
}

bool isStackInitialized(){

	if( stack.data == NULL){
		return true;
	}

	return false;
}

bool push(int item){
	int ret;
	if(stack.sp == 0){
		fprintf(stderr,"ERROR: Stack Overflow!, Can not insert new item.\n");
		ret = FALSE;
	}else{
		
		stack.sp--;
		stack.data[stack.sp] = item;
		ret = TRUE;
	}

	return ret;
}

int pop(){
	int ret;
	
	if(stack.sp == stack.max){
		fprintf(stderr,"ERROR: Void Stack, Can not retrieve item.\n");
		ret = -1;
	}else{
		ret = stack.data[stack.sp];
		stack.sp++;
	}

	return ret;
}

bool stackFactory(size_t max){

	bool push(int);
	int pop();

	stack.max = max;
	stack.sp = max;

	stack.push = push;
	stack.pop = pop;

	stack.data = (int*)calloc(stack.max, sizeof(int) );

	if( stack.data == NULL ){
		return FALSE;
	}

	return TRUE;
}

bool updateStack(size_t max){

	int* newData = (int*)calloc( max, sizeof(int) );
	int newStackPointer = max;

	if( newData == NULL ){
		return FALSE;
	}

	int i;
	for(i = stack.max-1; i != stack.sp - 1;i--){
		newData[--newStackPointer] = stack.data[i];
	}


	free(stack.data);

	stack.data = newData;
	stack.sp = newStackPointer;
	stack.max = max;


	return TRUE;
}

bool clearStack(){
	int ret = TRUE;
	int i;
	int n = stack.max - stack.sp;

	for(i = 0; i < n; i++){
		ret *= stack.pop();
	}

	if( ret < 0 ){
		ret = FALSE;
	}else{
		ret = TRUE;
	}

	return ret;
}

bool setStack(int numberOfElements, int setToThis){
	int ret = 1;
	int i;
	for(i = 0; i < numberOfElements; i++){
		ret *= stack.push(setToThis);
	}

	if( ret > 0 ){
		ret = TRUE;
	}

	return ret;
}

bool refactorTheStack(size_t max){
	int ret = TRUE;

	ret *= updateStack(max);
	ret *= clearStack();

	return ret;
}
