#include "generic.h"

int main(){
  var x = {.name = "Mustafa", .type = "string", .id = 1515 };
  var y = {.name = "ahmet", .type = "string", .id = 2652};
  var z = {.name = "pointer", .type = "int*", .id = 2312};
  var* k = malloc( sizeof(var) );
  k->name = "mert";
  k->type = "string";
  k->id = 1220;
 
  /* Using Arrays */ 
  var arr[3];
  arr[0] = x;
  arr[1] = y;
  arr[2] = z;
	
  int i;
  for(i = 0; i < 3; i++ ){
	varPrintf(&arr[i]);
  }
  /* Using varList */
  struct genericNode* myList = varListFactory(&x);
  varList(myList);
  
  varPush(myList, &y);
  varPush(myList, &z);
  varPush(myList, k);
  varList(myList);  

  printf("myNewList\n");
  struct genericNode* myNewList = varListFactory(&x);
  varList(myNewList);
  printf("\n");
  varPush(myNewList, &y);
  varPush(myNewList, &z);
  varList(myNewList);  


return 0;
}
