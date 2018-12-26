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

struct genericNode* varListFactory(var* val){
	return genericListFactory(val);
}

void varPush(struct genericNode* head, var* val) {
	genericPush(head, (void*)val);
}

void varList(struct genericNode* head){
	void varPrintf(var*);
	genericList(head, varPrintf);
}

struct genericNode* varPushFront(struct genericNode* head, var* val){
	return genericPushFront(head,(void*)val);
}

bool varDeleteNode(struct genericNode* head, var* val ){
	bool varEqualTo(var, var);
	return genericDeleteNode(head, (void*)val, varEqualTo);
}

struct genericNode* varSearchNode(struct genericNode* head, var* val ){
	bool varEqualTo(var, var);
	return genericSearchNode( head, (void*)val, varEqualTo);
}
