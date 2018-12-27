#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL

#define BOOL bool

typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#endif

struct node{
    int val;
    struct node *next;
};	

typedef struct{ 
	struct node* l_node;
} LinkedList;

void push(struct node *head, int val);
void list(struct node *head);
struct node* pushFront(struct node *head, int val); 
bool deleteNode(struct node *head, int val);
struct node* searchNode(struct node* head, int Val);

void push(struct node *head, int val) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));  	
    current->next->val = val;					
    current->next->next = NULL;					
}


void list(struct node *head)
{
	struct node* current = head;
    printf("liste elemanlari:\n");
	while (current->next != NULL) {
    	printf("-%d-",current->val);
        current = current->next;
    }
    printf("-%d-\n",current->val);
}


struct node* pushFront(struct node *head, int val) {
    struct node* newN;
	newN=malloc(sizeof(struct node)); 
	newN->next =head;
	newN->val =val;
    return newN;
}


bool deleteNode(struct node *head, int val)
{	
	bool deleteFront(struct node*, int);

	if(head->val == val){
		return deleteFront(head,val);
	}

	struct node* current = head, *before=NULL;
    
    while ((current->val != val)&&(current->next != NULL))
	{
	    before=current;
		current = current->next;
	}
    
    if (current->next == NULL){
    	printf("silinmek istenen eleman listede yok\n");
    	return false;
    }else{
    	before->next=current->next;
    	free (current);
    	return true;
	}
        
}

bool deleteFront(struct node* head, int val){
	struct node* dummy;

	if ( val == head->val){

		dummy = head->next;

		free(head);

		head = dummy;

	}

	return true;
}

struct node* searchNode(struct node* head, int Val){
	struct node* current = head;

	while ( (current->val != val) && (current->next != NULL) )
	{
		current = current->next;
	}

	if (current->next == NULL){
		return NULL;
	}

	return current;
}



/*

typedef struct{ 
	struct node* l_node;
	bool(*deleteNode)();
	void(*listNode)();
	void(*pushNode)();
	struct node * (*pushFront)();
	struct node * (*searchNode)();
} LinkedList;


LinkedList linkedListFactory(int val, struct node* next,
							 void(*pushNode)(),
							 struct node *(*pushFront)(), 
							 bool(*deleteNode)(),
							 void(*listNode)(),
							 struct node *(*searchNode)() ){
	LinkedList* list = (LinkedList*)malloc( sizeof(LinkedList) );

	struct node* head = (struct node*)malloc( sizeof(struct node) );

	if(head == NULL){
		return NULL;
	}

	list->l_node = head;
	list->l_node->val = val;
	list->l_node->next = next; 

	list->pushNode = pushNode;
	list->deleteNode = deleteNode;
	list->listNode = listNode;
	list->searchNode = searchNode;
	list->pushFront = pushFront;

	return list;
}
*/