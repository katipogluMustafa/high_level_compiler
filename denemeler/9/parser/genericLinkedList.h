#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "def.h"

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
	void genericPush(struct genericNode* head, void* val);
	void genericList(struct genericNode* head, void(*genericPrintf)() );
	struct genericNode* genericPushFront(struct genericNode* head, void* val);
	bool genericDeleteNode(struct genericNode* head, void* val, bool(*genericEqualTo)() );
	struct genericNode* genericSearchNode(struct genericNode* head, void* val, bool(*genericEqualTo)() );
	struct genericNode* genericListFactory(void* val);
*/
struct genericNode{
	void* val;
	struct genericNode* next;
};

typedef struct genericNode NODE;

struct genericNode* genericListFactory(void* val){
	struct genericNode* listHead = (struct genericNode*)malloc( sizeof(struct genericNode) );
	
	listHead->val = (void*)val;
	listHead->next = NULL;

	return listHead;
}

void genericPush(struct genericNode* head, void* val) {
    struct genericNode* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc( sizeof(struct genericNode) ); 
    current->next->val = val;					
    current->next->next = NULL;					
}

void genericList(struct genericNode* head, void(*genericPrintf)() ){

	struct genericNode* current = head;

    printf("liste elemanlari:\n");

	while (current->next != NULL) {
    	genericPrintf(current->val);
    	printf("\n");
        current = current->next;
    }

    genericPrintf(current->val);
    printf("\n");
}

struct genericNode* genericPushFront(struct genericNode* head, void* val) {
    struct genericNode* newN;

	newN = malloc( sizeof(struct genericNode) );

	newN->next = head;
	newN->val = val;
    
    return newN;
}

bool genericDeleteNode(struct genericNode* head, void* val, bool(*genericEqualTo)() )
{	
	bool genericDeleteFront(struct genericNode*, void*, bool(*)() );

	if( head->val == val){
		return genericDeleteFront(head, val, genericEqualTo);
	}

	struct genericNode* current = head, *before = NULL;
    
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

bool genericDeleteFront(struct genericNode* head, void* val, bool(*genericEqualTo)() ){
	struct genericNode* dummy;

	if( genericEqualTo(val, head->val) ){

		dummy = head->next;

		free(head);

		head = dummy;

		return true;
	}

	return false;
}

struct genericNode* genericSearchNode(struct genericNode* head, void* val, bool(*genericEqualTo)() ){
	struct genericNode* current = head;

	while( !genericEqualTo(current->val, val) && (current->next != NULL) ){

		current = current->next;

	}

	if ( current->next == NULL ){
		return NULL;
	}

	return current;
}

