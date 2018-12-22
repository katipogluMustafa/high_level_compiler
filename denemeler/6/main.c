#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int bool;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#define N 100


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
		removeString(buffer, "_ldp");
		removeQuotes(buffer);

		if( ptr = strstr(buffer, "$") ){
			removeChar(buffer, ptr - buffer);
		}

	}

	printf("%s",buffer);
	

	return 0;
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

void removeChar(char* src, int index){

	strcpy(src+index, src+index+1);

}
/*
bool clearArrayIndex(char* src){
	void removeString(char*, char*);

}
*/

void rmSquareBracketPair(char* src){
	char* start = src;
	

}

bool fillSqaureBracketsArray(char* src){

	char* squares = malloc( 2 * sizeof(char) );
	int capacity = 2;

	fillOpenSquareBrackets(src,squares, capacity);
	
	
	fillClosingSquareBrackets(src, squares, capacity);
}

bool fillOpenSquareBrackets(char* src, char* squares, int capacity){

	bool doubleTheArraySize(void*, size_t, size_t);
	char* temp = src;
	int i = 0;
	
	while( *temp ){

		if( *temp == '[' ){

			if( i == capacity){
				doubleTheArraySize(squares, sizeof(char), capacity + 2 );
			}
			
			squares[i] = temp;
			i += 2;

		}

		temp++;
	}

	// if not NULL
	if( *temp ){
		return FALSE;
	}

	// if *temp == NULL
	return TRUE;
}

char* fillClosingSquareBrackets(char* src, char* squares, int capacity){

	bool doubleTheArraySize(void*, size_t, size_t);
	char* temp = src;
	int i = 0;
	
	while( *temp ){

		if( *temp == '[' ){

			
			squares[i] = temp;
			i += 2;

		}

		temp++;
	}

	// if not NULL
	if( *temp ){
		return FALSE;
	}

	// if *temp == NULL
	return TRUE;
}



bool doubleTheArraySize(void* src, size_t size, size_t n ){

	src = realloc(src, n * size);
	
	if( !src ){
		return FALSE;
	}	

	return TRUE;
}


