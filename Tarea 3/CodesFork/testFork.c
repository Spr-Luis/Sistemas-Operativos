#include <stdio.h>
#include <stdlib.h>
#define NFORKS 50000

void do_nothing()
{
   int i;
   i= 0;
}

int main(int argc, char *argv[]) 
{
   int pid, j, status;

   for (j=0; j<NFORKS; j++) 
   {
      if ((pid = fork()) < 0 ) 
      {
         printf ("fork fallo con el error de codigo = %d\n", pid);
         exit(0);
      }
      else if (pid ==0)
      {
         do_nothing();
         exit(0);
      }
      else 
      {
         waitpid(pid, status, 0);
      }
   }
}  
