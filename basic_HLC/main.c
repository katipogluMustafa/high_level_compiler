#include"def.h"

char* getArgumans(char* buffer);
bool removeString(char* src, char* str);
char* clearString(char* in);
char* findType(char* srcStr);
void removeTheChar(char* src, char c);
char* getPrintIdentifier(char* in);

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

				fprintf(out, "%s, %s", clearString(buffer), getArgumans(buffer) );
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
	char* putStr(char*, int, int, char*);
	char* buffer = (char*)malloc( sizeof(char) * ( strlen(in) + 1 ) );
	strcpy(buffer, in);
	char* out;
	char* ptr;
	char* type;
	char* identifier;
	int start, end;
	if( ( ptr = strstr(buffer, "$") ) != NULL ){
		start = ptr - buffer;
		while( (*ptr != ',') && (*ptr != ' ') && (*ptr != '"') ){
			ptr++;
		}
		end = ptr - buffer;

		type = findType(buffer);
		identifier = getPrintIdentifier(type);
		//buffer = putStr(buffer, start, end, identifier);

	}

	free(type);
	return buffer;
}

char* putStr(char* buffer, int start, int end, char* in){
	char* newBuffer = malloc( ( strlen(buffer) + strlen(in) + 1 ) * sizeof(char) );
	int i = 0,k;

	while( i != start){
		newBuffer[i] = buffer[i];
		i++;
	}
	k = 0;
	while(in[k] != '\0'){
		newBuffer[i++] = in[k++];
	}
	k = end;
	while( buffer[k] != '\0' ){
		newBuffer[i++] = buffer[k++]; 
	}

	free(buffer);
	return newBuffer;
}

char* getPrintIdentifier(char* in){
	void error(char*);
	char* identifier;
	char* src = malloc( ( strlen(in) + 1) * sizeof(char) );
	strcpy(src, in);

	if( strlen(src) == 0){
		identifier = (char*)malloc( 5 * sizeof(char) );
		strcpy(identifier, "");
	}else if( removeString(src, "_cp") ){
		identifier = (char*)malloc( 6 * sizeof(char) );
		strcpy(identifier, "%s");

	}else if( removeString(src, "_ld") ){
		identifier = (char*)malloc( 12 * sizeof(char) );
		strcpy(identifier, "%lf");
	
	}else if( removeString(src, "_c") ){
		identifier = (char*)malloc( 5 * sizeof(char) );
		strcpy(identifier, "%c");
	
	}else if( removeString(src, "_f") ){
		identifier = (char*)malloc( 6 * sizeof(char) );
		strcpy(identifier, "%f");
	
	}else if( removeString(src, "_i") ){
		identifier = (char*)malloc( 4 * sizeof(char) );
		strcpy(identifier,"%d");
	
	}else if( removeString(src, "_l") ){
		identifier = (char*)malloc( 5 * sizeof(char) );
		strcpy(identifier,"%l");
	
	}else if( removeString(src, "_d") ){
		identifier = (char*)malloc( 7 * sizeof(char) );
		strcpy(identifier,"%lf");
	
	}else{
		printf("%s", src);
		error("unknown arguman type!");
	}
	free(src);
	return identifier;
}

char* getArgumans(char* in){
	char* buffer = malloc( sizeof(char) * ( strlen(in) + 1 ) );
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


char* findType(char* srcStr){
	void error(char*);
	char* type;
	char* src = malloc( ( strlen(srcStr) + 1) * sizeof(char) );
	strcpy(src, srcStr);

	if( strlen(src) == 0){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type, "void");
	}else if( removeString(src, "_file") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"FILE*");

	}else if( removeString(src, "_cp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"char*");

	}else if( removeString(src, "_fp") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"float*");

	}else if( removeString(src, "_ip") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"int*");

	}else if( removeString(src, "_ldp") ){
		type = (char*)malloc( 13 * sizeof(char) );
		strcpy(type,"long double*");
		
	}else if( removeString(src, "_lp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"long*");

	}else if( removeString(src, "_dp") ){
		type = (char*)malloc( 8 * sizeof(char) );
		strcpy(type,"double*");

	}else if( removeString(src, "_ld") ){
		type = (char*)malloc( 12 * sizeof(char) );
		strcpy(type,"long double");
	
	}else if( removeString(src, "_c") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"char");
	
	}else if( removeString(src, "_f") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"float");
	
	}else if( removeString(src, "_i") ){
		type = (char*)malloc( 4 * sizeof(char) );
		strcpy(type,"int");
	
	}else if( removeString(src, "_l") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"long");
	
	}else if( removeString(src, "_d") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"double");
	
	}else{
		printf("%s", src);
		error("unknown return type!");
	}
	free(src);
	return type;
}	
