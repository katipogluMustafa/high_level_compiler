#include<stdio.h>

typedef int BOOL;
typedef int bool;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

typedef struct{

	union{	
		int i_value;
		char c_value;
		float f_value;
		long l_value;
		double d_value;
	}data;

	int id;
}var;

bool doSomething(void* x);

int main(){
	var myVar;

	myVar.data.d_value = 5.25;
	myVar.id = 20;
	
	doSomething(&myVar);

	// sending void to function which takes void*
	printf("%d", doSomething() );

	return 0;
}

bool doSomething(void* x){
	if( x == NULL){
		return false;
	}	

	var* temp = (var*)x;
	bool ret = false;
	if( temp->data.i_value ){
		printf("%d", temp->data.i_value );
		ret = true;
	}else if( temp->data.c_value ){
		printf("%c", temp->data.c_value);
		ret = true;
	}else if( temp->data.f_value ){
		printf("%f", temp->data.f_value);
		ret = true;
	}else if( temp->data.l_value ){
		printf("%lu", temp->data.l_value);
		ret = true;
	}else if( temp->data.d_value ){
		printf("%lf", temp->data.d_value);
		ret = true;
	}

	return ret;
}
