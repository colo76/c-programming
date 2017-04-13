#include<stdio.h>

/*

Podemos tratar a los arreglos como tales, pero también los
podemos tratar como punteros

*/

main() {

int a[10];

int *p_int;

a[0] = 10;
a[1] = 20;

p_int = &a; /* pa apunta a la primera posición del arreglo */

printf("\n El valor de *p_int es: %d \n",*p_int);

p_int++; /* Sumamos unos al valor de p_int, ahora p_int apunta a la segunda posición del arreglo */

printf("\n Luedo de p_int++, el valor de *p_int es: %d \n",*p_int);

p_int++;  /* Ojo, ahora p_int apunta a una posición del arreglo NO inicializada(inicializada por defecto) */

printf("\n Luedo de p_int++(posición del arreglo no inicializada), el valor de *p_int es: %d \n",*p_int);


}
