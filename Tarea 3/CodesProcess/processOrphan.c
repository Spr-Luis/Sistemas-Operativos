#include<stdio.h>
#include<unistd.h>

int main()
{
   pid_t p;

   p=fork();

   if(p==0) 
   {
      sleep(10);
   }
 
   printf("El PID del Proceso Hijo es %d el PID del Proceso Padre %d\n", getpid(), getppid());

   sleep(20); 
 
   printf("\nProceso %d esta hecho su PID Padre %d...\n", getpid(), getppid());

   return 0;
}
