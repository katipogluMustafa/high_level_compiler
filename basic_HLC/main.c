#include"def.h"

char* getArgumans(char* buffer);
bool removeString(char* src, char* str);
char* clearString(char* in);

int main(){
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w+");
	char buffer[N];
	int x;
	char* temp;
	char* varies;

	fprintf(out, "#include\"stdio.h\"\n\n\n");

	fgets(buffer, N-1, in);
	fgets(buffer, N-1, in);
	fprintf(out, "void main(){\n");

	while( !feof(in) ){
		
		fgets(buffer, N-1, in);
		x = strlen(buffer);
		buffer[x] = '\0';

		if(  ( varies = strstr(buffer, "END") )  != NULL ){
			fprintf(out,"}\n");
		}else if( ( varies = strstr(buffer, "PRINT_LINE") )  != NULL ){
			fprintf(out, "\tprintf(");
			removeBefore(buffer, " ");
			removeChars(buffer, '\n');

			if( ( varies = strstr(buffer, "$") )  != NULL ){

				fprintf(out, "%s %s", clearString(buffer) ,getArgumans(buffer) );
			}else{			
				fprintf(out, "%s", buffer );				
			}
			
			fprintf(out, ")\n");
		}


	}

	fclose(out);
	fclose(in);

	return 0;
}

char* clearString(char* in){
	char* buffer = malloc( sizeof(char) * ( strlen(buffer) + 1 ) );
	strcpy(buffer, in);
	


}

char* getArgumans(char* in){
	char* buffer = malloc( sizeof(char) * ( strlen(buffer) + 1 ) );
	strcpy(buffer, in);
	char* output;
	int sizeOfOutput = 0;
	char* temp2;
	char* temp = malloc( sizeof(char) * ( strlen(buffer) + 1 ) );
	

	if ( ( temp2 = strstr(buffer, "$") ) != NULL ){
		strcpy(temp, buffer);	
		removeBefore(temp, "$");
		removeAfterwards(temp, "_");
		output = malloc( sizeof(char) * ( strlen(temp) + 1) );
		strcpy(output, temp);
		sizeOfOutput += strlen(temp);
		removeString(buffer, "$");
	}

	while( ( temp2 = strstr(buffer, "$") ) != NULL ){
		strcpy(temp, buffer);
		removeBefore(temp, "$");
		removeAfterwards(temp, "_");
		output = realloc( output , sizeof(char) * ( sizeOfOutput + strlen(temp) + 1) );
		sizeOfOutput += strlen(temp);
		strcat(output, ",");
		strcat(output, temp);
		removeString(buffer, "$");
	}

	free(temp);
	return output;
}
