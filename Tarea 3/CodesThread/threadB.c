#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdint.h> /* 64 bits */
#define NUM_THREADS 4

void *do_something(void *arg)
{
   int tid;       	  	
   int i, num_loops;
   int y = 0, x = 0; 		

   tid = pthread_self();        

   srand(time(NULL)+tid);  	

   num_loops = (int)rand()%5 + 1;   

   for (i=1; i<=num_loops; i++)
   {
      printf("en %d, iteracion numero %d de %d, x = %d, y = %d.\n",tid,i,num_loops,x,y);
      y=x+1;
      sleep((int)rand()%3+1);
      x=y;
   }
   pthread_exit((void*) arg);

}

int main(int argc, char *argv[])
{
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc, t;
   void *status;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for(t=0;t<NUM_THREADS;t++) 
   {
      printf("Main: creando hilo %d\n", t);
      rc = pthread_create(&thread[t], &attr, do_something, (void *)(intptr_t)t);

      if (rc) 
      {
         printf("ERROR: el codigo devuelto por pthread_create() es %d\n", rc);
         exit(EXIT_FAILURE);
      }
   }
  
   pthread_attr_destroy(&attr);

   for(t=0;t<NUM_THREADS;t++) 
   {
      rc = pthread_join(thread[t], &status);

      if (rc) 
      {
         printf("ERROR: el codigo devuelto por pthread_join() es %d\n", rc);
         exit(EXIT_FAILURE);
      }

      printf("Main: join completado con hilo %d teniendo un estatus de %d\n", t, (int)status);
   }

   printf("Main completado. Saliendo.\n");
   pthread_exit(NULL);
} 
