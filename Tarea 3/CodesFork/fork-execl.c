#include <stdio.h>
#include <stdlib.h>

// Para sistemas Linux
//#include </usr/include/x86_64-linux-gnu/sys/types.h>
// Para sistemas Unix
#include <sys/types.h>

#include <unistd.h>

// Para sistemas Linux
//#include <x86_64-linux-gnu/sys/wait.h>
// Para sistemas Unix
#include <sys/wait.h>

int main( int argc, char *argv[], char *env[] )
{
   pid_t child_pid;
   int status;

   printf("\nPADRE: Mi PID es %d\n\n", getpid());
   printf("PADRE: El PID de mi proceso PADRE es %d\n\n", getppid());

   if((child_pid = fork()) < 0 )
   {
      perror("fork failure");
      exit(1);
   }

   if(child_pid == 0)
   {  
      printf("\nHIJO: Soy un nuevo proceso!\n\n");
      printf("HIJO: Mi PID es: %d\n\n", getpid());
      printf("HIJO: El PID de mi proceso PADRE es: %d\n\n", getppid());
      printf("HIJO: Me dormire 3 segundos y entonces ejecutare el comando - date -\n\n");

      sleep(3); 
      printf("HIJO: Ahora, me desperte y estoy ejecutando el comando date\n\n");
      execl("/bin/date", "date", 0, 0);
      perror("fallo execl()!\n\n");

      printf("Esta impresion es despues de execl y no debe haberse ejecutado si execl tuvo exito! \n\n");

      exit(1);
   }
   else
   {
      printf("\nPADRE: He creado un proceso hijo.\n\n");
      printf("PADRE: Mi PID del HIJO es: %d\n\n", child_pid);
      system("ps -aef | grep a.out");
      printf("\n \n");
      wait(&status); 
      printf("\n PADRE: Mi hijo esta muerto. Me ire.\n \n ");
   }
   return 0;
}
