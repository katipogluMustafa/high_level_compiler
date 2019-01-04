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

void removeChars(char* src, char c){
	void removeChar(char*, int);

	char* temp = src;

	while( *temp ){

		if(*temp == c){
			strcpy(src + (temp -src), src+ ( temp-src )+1);
		}

		temp++;
	}

}


// length of change needs to greater than toThis!
bool strReplace(char* src, char* change, char* toThis){

	char* ptr;
	int i;
	if( ( ptr = strstr(src,change) ) != NULL ){

		for( i = 0; i < strlen(toThis); i++){
			ptr[i] = toThis[i];
		}
		for(; i < strlen(change); i++){
			ptr[i] = ' ';
		}
	}else{
		return false;
	}

	return true;
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