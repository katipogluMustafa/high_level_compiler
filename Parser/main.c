#include"def.h"



int main(){
	if( !stackFactory(200) ){
		error("Unsuccessful Starting of Stack");
	}
	FILE* in = fopen("Files/in.txt","r");
	FILE* out = fopen("Files/out.txt","w+");
	char buffer[N];
	int i = 0;
	char tmp;
	int curr_position;

//	fgets(buffer,N,in);
//	printf("%s", getFuncName(buffer) );	

	size_t x = ftell(in);
	size_t pos = getEndOffset(in, x);
	fseek(in, pos, SEEK_SET);

	fgets(buffer, N-1, in);
	printf("pos: %lu, string:  %s", pos, buffer);

	char* type = getFuncRetType(in, x, pos);

	printf("type: %s", type);
	
	
	return 0;
}
