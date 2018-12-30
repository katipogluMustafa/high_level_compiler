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

	fgets(buffer, N-1, in);
	printf("%s", buffer);

	NODE* params = getParamList(in, ftell(in));

	paramList(params);

	return 0;
}
