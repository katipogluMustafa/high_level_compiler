#include<stdio.h>
#include<string.h>

typedef struct{
 char* str;

}var;

int main(){
 char str[20] = "Mustafa";
 char str2[20] = "Mustafa";
 
 var var1;
 var1.str = str;
 var var2;
 var2.str = str2; 


 if( !strcmp(var1.str,var2.str) ){
    printf("%s and %s are equal to each other...\n", str,str2);
 }else{
    printf("not equal to"); 
 }


return 0;
}
