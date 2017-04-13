/*

tipo *nombre;

Declara una variable llamada nombre que es un  puntero a una zona de memoria que tiene un valor del tipo indicado

*/

main() {


 int *p_int; /* p_int es un puntero a un entero */

 int val = 10;  

  p_int = &val;   /* p_int tomar la posición de memoria de val */

  printf(" \n El valor de *p_int es: %d \n",*p_int); 


} 
