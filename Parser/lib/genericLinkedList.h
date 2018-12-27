#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef BOOL

#define BOOL bool

typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#endif

/* Prototypes */
/*
	void genericPush(NODE* head, void* val);
	void genericList(NODE* head, void(*genericPrintf)() );
	NODE* genericPushFront(NODE* head, void* val);
	bool genericDeleteNode(NODE* head, void* val, bool(*genericEqualTo)() );
	NODE* genericSearchNode(NODE* head, void* val, bool(*genericEqualTo)() );
	NODE* genericListFactory(void* val);
*/

struct genericNode{
	void* val;
	struct genericNode* next;
};

typedef struct genericNode NODE;


NODE* genericListFactory(void* val){
	NODE* listHead = (NODE*)malloc( sizeof(NODE) );
	
	listHead->val = (void*)val;
	listHead->next = NULL;

	return listHead;
}

void genericPush(NODE* head, void* val) {
    NODE* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc( sizeof(NODE) ); 
    current->next->val = val;					
    current->next->next = NULL;					
}

void genericList(NODE* head, void(*genericPrintf)() ){

	NODE* current = head;

    printf("liste elemanlari:\n");

	while (current->next != NULL) {
    	genericPrintf(current->val);
    	printf("\n");
        current = current->next;
    }

    genericPrintf(current->val);
    printf("\n");
}

NODE* genericPushFront(NODE* head, void* val) {
    NODE* newN;

	newN = malloc( sizeof(NODE) );

	newN->next = head;
	newN->val = val;
    
    return newN;
}

bool genericDeleteNode(NODE* head, void* val, bool(*genericEqualTo)() )
{	
	bool genericDeleteFront(NODE*, void*, bool(*)() );

	if( head->val == val){
		return genericDeleteFront(head, val, genericEqualTo);
	}

	NODE* current = head, *before = NULL;
    
	while( !genericEqualTo( current->val, val) && (current->next != NULL) ){
		before=current;
		current = current->next;
	}
    
    if (current->next == NULL){
    	printf("silinmek istenen eleman listede yok\n");
    	return false;   	
    }else
    {
    	before->next = current->next;
    	free (current);
    	return true;
	}
        
}

bool genericDeleteFront(NODE* head, void* val, bool(*genericEqualTo)() ){
	NODE* dummy;

	if( genericEqualTo(val, head->val) ){

		dummy = head->next;

		free(head);

		head = dummy;

		return true;
	}

	return false;
}

NODE* genericSearchNode(NODE* head, void* val, bool(*genericEqualTo)() ){
	NODE* current = head;

	while( !genericEqualTo(current->val, val) && (current->next != NULL) ){

		current = current->next;

	}

	if ( current->next == NULL ){
		return NULL;
	}

	return current;
}

