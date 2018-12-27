#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int bool;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#define N 100


bool clearArrayIndex(char* src){
	void removeString(char*, char*);

}

int main(){
	int isQuote(char);
	char* findType(char* src);
	void removeChar(char*, int);
	bool removeString(char* src, char* str);
	void removeChars(char* src, char c);
	void removeQuotes(char* src);
	
	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char tmp;
	char buffer[N];
	int i = 0;

	fgets(buffer,100,in);

	printf("%s\n",buffer);

	char* ptr;
	if( ( ptr = strstr(buffer, "GET_VAL" ) ) != NULL  ){
		removeString(buffer, "GET_VAL");
		removeChars(buffer, ' ');
		bool isArray = clearArrayIndex(buffer);
		printf("\n%s\n", findType(buffer));
		removeQuotes(buffer);

		if( ptr = strstr(buffer, "$") ){
			removeChar(buffer, ptr - buffer);
		}

	}

	printf("%s",buffer);
	

	return 0;
}

char* findType(char* src){
	bool pullAndClear(char* src, char* type);
	char* type;

	if( pullAndClear(src, "_file") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"FILE*");

	}else if( pullAndClear(src, "_cp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"char*");

	}else if( pullAndClear(src, "_fp") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"float*");

	}else if( pullAndClear(src, "_ip") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"int*");

	}else if( pullAndClear(src, "_ldp") ){
		type = (char*)malloc( 13 * sizeof(char) );
		strcpy(type,"long double*");
		
	}else if( pullAndClear(src, "_lp") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"long*");

	}else if( pullAndClear(src, "_dp") ){
		type = (char*)malloc( 8 * sizeof(char) );
		strcpy(type,"double*");

	}else if( pullAndClear(src, "_ld") ){
		type = (char*)malloc( 12 * sizeof(char) );
		strcpy(type,"long double");
	
	}else if( pullAndClear(src, "_c") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"char");
	
	}else if( pullAndClear(src, "_f") ){
		type = (char*)malloc( 6 * sizeof(char) );
		strcpy(type,"float");
	
	}else if( pullAndClear(src, "_i") ){
		type = (char*)malloc( 4 * sizeof(char) );
		strcpy(type,"int");
	
	}else if( pullAndClear(src, "_l") ){
		type = (char*)malloc( 5 * sizeof(char) );
		strcpy(type,"long");
	
	}else if( pullAndClear(src, "_d") ){
		type = (char*)malloc( 7 * sizeof(char) );
		strcpy(type,"double");
	
	}

	return type;
}	
/* TRUE if successful otherwise 0 */
bool pullAndClear(char* src, char* type){
	bool removeString(char* src, char* str);
	return !removeString(src,type);
}

/* returns FALSE if successfully removes a string, otherwise TRUE*/
bool removeString(char* src, char* str){
	char* ptr;
	if( ( ptr = strstr(src,str) ) != NULL ){
		strcpy(ptr, ptr + strlen(str) );
		// successfull
		return FALSE;
	}

	// unsuccessful attempt to delete
	return TRUE;
}

int isQuote(char x){
	int ret = 0;

	if( x == '"' ){
		ret = 1;
	}

	return ret;
}

void removeQuotes(char* src){
	char* first = src;
	char* last  = src + strlen(src) - 1;  

	while( isQuote(*first++) );
	while( isQuote(*last--) );

	if(last != first){

		strcpy(first, first + 1 );
		strcpy(last - 1, last);

	}else{
		printf("Odd number of quotes!");
	}

}

void removeChars(char* src, char c){
	void removeChar(char*, int);

	char* temp = src;

	while( *temp ){

		if(*temp == c){
			removeChar(src, temp-src);
		}

		temp++;
	}

}

// remove the first occurence of the char
bool removeCharFO(char* src, char c){
	void removeChar(char*, int);

	char* temp = src;

	while( *temp ){

		if(*temp == c){
			removeChar(src, temp-src);
			return TRUE;
		}

		temp++;
	}

	return FALSE;
}


// remove the last occurence of the char
bool removeCharLO(char* src, char c){
	void removeChar(char*, int);

	char* temp = src + strlen(src) - 1;

	while( *temp ){

		if(*temp == c){
			removeChar(src, temp-src);
			return TRUE;
		}

		temp--;
	}

	return FALSE;
}

void rmSquareBracketPair(char* src){
	char* start = src;
	

}


void removeChar(char* src, int index){

	strcpy(src+index, src+index+1);

}

