/* Standard Libraries */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

/* Parser */

#include"lib/parser.h"
#include"lib/arr.h"
#include"lib/generic.h"
#include"lib/genericLinkedList.h"
#include"lib/param.h"
#include"lib/varList.h"

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

