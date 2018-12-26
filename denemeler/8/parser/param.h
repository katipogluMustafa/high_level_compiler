typedef struct{
	char* type;
	char* name;
}param;

bool paramEqualTo(param x, param y){

	if( !strcmp(param.name, param.name) 
					&& 
		!strcmp(param.type, param.type)  
	  ) {

		return true;
		}

	return false;
}

void paramPrintf(param* x){
	printf("name: %s\ttype: %s\n", x->name, x->type);
}


struct genericNode* paramListFactory(param* val){
	return genericListFactory(val);
}

void paramPush(struct genericNode* head, param* val) {
	genericPush(head, val);
}

void paramList(struct genericNode* head){
	void paramPrintf(param*);
	genericList(head, paramPrintf);
}

struct genericNode* paramPushFront(struct genericNode* head, param* val){
	return paramPushFront(head, val);
}

bool paramDeleteNode(struct genericNode* head, param* val ){
	bool paramEqualTo(param, param);
	return genericDeleteNode(head, val, paramEqualTo);
}

struct genericNode* paramSearchNode(struct genericNode* head, param* val ){
	bool paramEqualTo(param, param);
	return genericSearchNode( head, val, paramEqualTo);
}
