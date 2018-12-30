#include"def.h"

char** getParamNameList(char* buffer){
	char** params = (char**)malloc( sizeof(char*) );
	int i;
	char temp[N];

	i = 0;
	while( *buffer != '\0'){
		
		if( *buffer == ','){
			buffer++;
		}

		strcpy(temp, buffer);
		removeAfterwards(temp, ",");

		params[i] = (char*)malloc( strlen(temp) + 1 * sizeof(char) );
		strcpy(params[i], temp);
		buffer += strlen(temp);
		i++;
	}

	params[i] = (char*)malloc( 5 * sizeof(char) );
	strcpy(params[i], "NULL");

	return params;
}

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

	removeBefore(buffer, "(");
	removeAfterwards(buffer, ")");
	removeChars(buffer, ' ');
	
	printf("%s", buffer);

	char** list = getParamNameList(buffer);

	printf("\n");
	for(i = 0; strcmp(list[i], "NULL") != 0;i++ ){
		printf("\n%s\n", list[i]);
	}

	return 0;
}
