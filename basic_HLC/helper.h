char* getFuncName(char* buffer){

	char* tempBuffer = malloc( strlen(buffer) * sizeof(char) );
	strcpy(tempBuffer, buffer);

	removeAfterwards(tempBuffer, "(");
	removeString(tempBuffer, "PROCEDURE");
	removeChars(tempBuffer, ' ');

	char* funcName = malloc( ( strlen(buffer) + 1)  * sizeof(char) );
	strcpy(funcName, tempBuffer);

	free(tempBuffer);

	return funcName;
}