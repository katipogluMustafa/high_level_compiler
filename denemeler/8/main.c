#include"def.h"
#include"stack.h"

int main(){
	stackFactory(200);
	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char buffer[N];
	int i = 0;
	char tmp;
	int curr_position;


	fgets(buffer,N-1,in);

	if( strstr(buffer, "PROCEDURE") ){
		if( strstr(buffer, "MAIN") ){
			curr_position = fseek(in, 0, SEEK_CUR);
			while( !feof(in) ){
				fgets(buffer, N-1, in);
				// stack yapmadan hangi end in bizim end olduğunu bilemeyiz...
				// stack yapınca devam et
			}

		}
	}


	return 0;
}