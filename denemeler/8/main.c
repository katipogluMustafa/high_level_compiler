#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100
#define BEGIN "{"
#define END "}"
#define BEGIN_PARAMETER "("
#define END_PARAMETER ")"

int main(){
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