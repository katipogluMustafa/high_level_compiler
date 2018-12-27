/* Standard Libraries */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

/* Data Types */

#include"stack.h"
#include"linkedList.h"

/* Parser */

#include"parser/lib/parser.h"
#include"parser/lib/arr.h"
#include"parser/lib/generic.h"
#include"parser/lib/genericLinkedList.h"
#include"parser/lib/param.h"
#include"parser/lib/varList.h"

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

