/******************************************************************************
* FILE: hello-pthreads.c
* DESCRIPTION:
*   Programa simple que muestra el uso básico de pthreads. Crea hilos que 
*   imprimen un mensaje,se bloquean unos segundos y el main espera 
*   a que terminen
*   
* AUTHOR: Martín Baez
******************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5
#include <unistd.h>


void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   sleep(3);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	
   void *status;	

  // Creamos un arreglo de threads   
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Se crean los threads
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }
	 
	// Esperamos a terminen todos los threads para terminar el main 
    for(t=0;t<NUM_THREADS;t++){
     rc = pthread_join(threads[t], &status);
     printf("DEBUG; Termino el thread con estado %d\n", ((long *) status));

     if (rc){
       printf("ERROR; luego del join %d\n", t);
       exit(-1);
       }
     }

  printf("DEBUG; Termino el main \n");

   pthread_exit(NULL);
}
