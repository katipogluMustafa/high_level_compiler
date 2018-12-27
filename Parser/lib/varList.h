#include "../def.h"
#include "genericLinkedList.h"

typedef struct variable{
	char* name; 
	char* type;  // type
	int id; 		// id in variables table;
}var;

bool varEqualTo(var x, var y){

	if( !strcmp(x.name, y.name)  ){
		return true;
	}

	return false;
}

void varPrintf(var* x){
	printf("name: %s\ttype: %s\tid:   %d\n", x->name, x->type, x->id);
}

NODE* varListFactory(var* val){
	return genericListFactory(val);
}

void varPush(NODE* head, var* val) {
	genericPush(head, (void*)val);
}

void varList(NODE* head){
	void varPrintf(var*);
	genericList(head, varPrintf);
}

NODE* varPushFront(NODE* head, var* val){
	return genericPushFront(head,(void*)val);
}

bool varDeleteNode(NODE* head, var* val ){
	bool varEqualTo(var, var);
	return genericDeleteNode(head, (void*)val, varEqualTo);
}

NODE* varSearchNode(NODE* head, var* val ){
	bool varEqualTo(var, var);
	return genericSearchNode( head, (void*)val, varEqualTo);
}
