#include<stdio.h>
/*
Ejemplo: Una  de una función que recibe parámetros de tipo void(cualquier tipo).
Luego internamente los trata como char[], solo a modo de ejemolo

*/

void myFunc(void *pArray){
 char* myArr =  (char *) pArray;
 
 //También podria ser así..
 //char[] myArr =  (char []) pArray;
 
 printf("El primer elemento es %c \n", myArr[0] );
 printf("El segundo elemento es %c \n", myArr[1] );
 printf("El tercer elemento es %c \n", myArr[2] );

}


int main(){
  
 char myArr[3] = {'A','B','C'};

 myFunc((void *) myArr);

 return 0;
}
