#include"genericLinkedList.h"

typedef struct variable{
	char* name; 
	char* type;  // type
	int id; 		// id in variables table;
}var;


void varPrintf(var*);
NODE* varListFactory(var*);
void varPush(var*, var*);
void varList(var*);
NODE* varPushFront(var*, var*);
bool varDeleteNode(var*, var*);
NODE* varSearchNode(var*, var*);

bool isVarAddedBefore(var* head, var* item){
	
	var* found = (var*)varSearchNode(head, item);

	if( found == NULL){
		return false;
	}

	return true;
}

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
	return genericListFactory((void*)val);
}

void varPush(var* head, var* val) {
	genericPush((void*)head, (void*)val);
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
