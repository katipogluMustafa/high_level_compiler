#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int bool;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#define N 100

struct{

	// Data
	int* data;

	// Info
	size_t max;
	size_t sp;

	// Methods
	void (*push)();
	int (*pop)();

}stack;

void push(int item){

	if(stack.sp == 0){
		fprintf(stderr,"ERROR: Stack Overflow!, Can not insert new item.\n");
		exit(0);
	}
	stack.sp--;
	stack.data[stack.sp] = item;

}

int pop(){
	
	if(stack.sp == stack.max){
		fprintf(stderr,"ERROR: Void Stack, Can not retrieve item.\n");
		exit(0);
	}
	int ret = stack.data[stack.sp];
	stack.sp++;

	return ret;
}

bool stackFactory(size_t max){

	void push(int);
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
	for(i = stack.max; i > stack.sp; i--){
		max--;
		newData[max] = stack.data[i];
	}

	stack.data = newData;
	stack.sp = newStackPointer;

	return TRUE;
}



int main(){
	/*
	void push(STACK* stack, int item);
	int pop(STACK* stack);

	STACK* stack;
	stackFactory( stack, N, push, pop);
*/
	stackFactory(100);
	stack.push(155);
	stack.push(156);
	stack.push(157);
	stack.push(158);

	updateStack(200);
	printf("%d\n",stack.pop());

	printf("%d\n",stack.pop());

	printf("%d\n",stack.pop());

	printf("%d\n",stack.pop());


	

	return 0;
}



