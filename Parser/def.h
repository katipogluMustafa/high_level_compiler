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

#include"parser/parser.h"
#include"parser/arr.h"
#include"parser/generic.h"
#include"parser/genericLinkedList.h"
#include"parser/param.h"
#include"parser/varList.h"

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

