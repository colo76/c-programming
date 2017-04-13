#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 512

void main(int argc, char **argv){
   int fd_in, fd_out, n_read;
   char buffer[BUFSIZE];
   
   /* Se abre el archivo de entrada */
   fd_in = open(argv[1], O_RDONLY);

   if (fd_in < 0){
      perror("open source file");
      exit(1); 
   }

   /* Se crea el archivo de salida */
   fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0751);
  
   if (fd_out < 0){
      close(fd_in);  
      perror("Open detination file"); 
      exit(1);
   }

    /* loop para transferir datos entre archivos */
   while ((n_read = read(fd_in,buffer,BUFSIZE))>0) {
        /* Transferir datos de un buffer al archivo de salida */  
        if (write(fd_out, buffer, n_read) < n_read) {
           perror("write");
           close(fd_in); close(fd_out);
           exit(1);
        } 
   }
  
   if (n_read < 0){
      perror("read"); 
      close(fd_in); close(fd_out);
      exit(1);
   }

   close(fd_in); close(fd_out);
   exit(0);
}
