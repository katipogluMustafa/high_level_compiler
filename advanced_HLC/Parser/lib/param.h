typedef struct{
	char* type;
	char* name;
	int id;
}param;

bool paramEqualTo(param x, param y){

	if( !strcmp(x.name, y.name) 
					&& 
		!strcmp(x.type, y.type)  
	  ) {

		return true;
		}

	return false;
}

void paramPrintf(param* x){
	printf("name: %s\ttype: %s\n", x->name, x->type);
}


NODE* paramListFactory(param* val){
	return genericListFactory(val);
}

void paramPush(NODE* head, param* val) {
	genericPush(head, val);
}

void paramList(NODE* head){
	void paramPrintf(param*);
	genericList(head, paramPrintf);
}

NODE* paramPushFront(NODE* head, param* val){
	return paramPushFront(head, val);
}

bool paramDeleteNode(NODE* head, param* val ){
	bool paramEqualTo(param, param);
	return genericDeleteNode(head, val, paramEqualTo);
}

NODE* paramSearchNode(NODE* head, param* val ){
	bool paramEqualTo(param, param);
	return genericSearchNode( head, val, paramEqualTo);
}
