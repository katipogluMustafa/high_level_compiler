#include"genericLinkedList.h"

typedef struct variable{
	char* name; 
	char* type;
}var;

var* getVar(char*, char*);
void varPrintf(var*);
NODE* varListFactory(var*);
void varPush(var*, var*);
void varList(var*);
NODE* varPushFront(var*, var*);
bool varDeleteNode(var*, var*);
NODE* varSearchNode(var*, var*);

char* getName( var* variable ){
	return variable->name;
}

char* getType( var* variable ){
	return variable->type;
}

bool isVarAddedBefore(var* head, var* item){
	
	var* found = (var*)varSearchNode(head, item);

	if( found == NULL){
		return false;
	}

	return true;
}

var* getVar(char* name, char* type){
	var* variable = (var*)malloc( sizeof(var) );
	
	variable->name = malloc( ( strlen(name) + 1) * sizeof(char) );
	strcpy(variable->name, name);
	
	variable->type = malloc( ( strlen(type) + 1) * sizeof(char) );
	strcpy(variable->type, type);
	
	return variable;
}

bool varEqualTo(var x, var y){

	if( !strcmp(x.name, y.name)  ){
		return true;
	}

	return false;
}

void varPrintf(var* x){
	printf("name: %s\ttype: %s\n", getName(x), getType(x) );
}

NODE* varListFactory(var* val){
	return genericListFactory((void*)val);
}

void varPush(var* head, var* val) {
	if( head == NULL ){
		head = (var*)varListFactory(val);
	}else if( !isVarAddedBefore(head,val) ){
		genericPush((void*)head, (void*)val);
	}
}

void varList(var* head){
	void varPrintf(var*);
	genericList((void*)head, varPrintf);
}

NODE* varPushFront(var* head, var* val){
	return genericPushFront((void*)head,(void*)val);
}

bool varDeleteNode(var* head, var* val ){
	bool varEqualTo(var, var);
	return genericDeleteNode((void*)head, (void*)val, varEqualTo);
}

NODE* varSearchNode(var* head, var* val ){
	bool varEqualTo(var, var);
	return genericSearchNode( (void*)head, (void*)val, varEqualTo);
}
