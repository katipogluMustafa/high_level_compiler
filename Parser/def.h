/* Standard Libraries */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<errno.h>

/* Data Structures */

#include"../lib/stack.h"

/* Parser */


#include"lib/genericLinkedList.h"
#include"lib/varList.h"
#include"lib/arr.h"
#include"lib/generic.h"
#include"lib/param.h"
#include"lib/strRemover.h"


/* Macros */

#define BEGIN "{"
#define END "}"
#define BEGIN_PARAMETER "("
#define END_PARAMETER ")"

#define BOOL bool
typedef int BOOL;
#define TRUE (1)
#define true (1)
#define FALSE (0)
#define false (0)

#define N 100

void error(char* msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno) );
	exit(1);
}
