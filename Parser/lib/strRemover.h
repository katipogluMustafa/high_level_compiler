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

void removeChar(char* src, int index){

	strcpy(src+index, src+index+1);

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

bool removeString(char* src, char* str){
	char* ptr;
	if( ( ptr = strstr(src,str) ) != NULL ){
		strcpy(ptr, ptr + strlen(str) );
		// successfull
		return TRUE;
	}

	// unsuccessful attempt to delete
	return FALSE;
}

/* 
 * Description: Removes the string starting from str in src.
 * Parameters: Takes sources string and string in which we'll start removing
 * Return: if successful true, else false
 */
bool removeAfterwards(char* src, char* str){
	char* ptr;

	if ( ( ptr = strstr(src,str) ) != NULL ){
		*ptr = '\0';
		return true;
	}

	return false;
}

bool removeBefore(char* src, char* str){
	char* ptr;

	if ( ( ptr = strstr(src,str) ) != NULL ){
		strcpy(src, ptr + strlen(str) );

		return true;
	}

	return false;
}