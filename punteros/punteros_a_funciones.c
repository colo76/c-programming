#include<stdio.h>


/*
Ejemplos de: 
  Como trabajar con punteros a funciones.
  Como pasar funciones como parámetros en C.

Como definir puntero a funciones:
 tipo (*nombre_funcion)([<tipo_parametro>])



*/

int suma(int a, int b) {
  return a+b;
}

int resta(int a, int b) {
 return a-b;
}


/*
Recibe: 
  Un puntero a una función que recibe enteros como parámetros.
  Dos parámetrosde tipo entero
Aplica la función recibida como parámetro a los otros dos parámetros que se asumen como sus argumentos
*/
void aplicar( int (*f1)(int,int) ,int a, int b){
    int res = f1(a,b);
   printf("\n El resultado de aplicar(resta(5,1)) es: %d \n",res);

}


main(){

/* Definimos un puntero a una función que toma dos parametros de tipo int */
 int (*funcion)(int,int) = suma;

 /*Aplicamos la función */
 int r1 = funcion(5,3);

 printf("\n El resultado de funcion(5,3) es %d \n",r1);

 /*Invocamos a aplicar con la función resta  */ 
 aplicar(resta,5,1);
 

}
