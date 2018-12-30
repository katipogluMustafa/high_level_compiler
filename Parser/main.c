#include"def.h"



int main(){
	stackFactory(200);
	FILE* in = fopen("Files/in.txt","r");
	FILE* out = fopen("Files/out.txt","w+");
	char buffer[N];
	int i = 0;
	char tmp;
	int curr_position;

	fgets(buffer,N,in);
	printf("%s", getFuncName(buffer) );	

	return 0;
}
