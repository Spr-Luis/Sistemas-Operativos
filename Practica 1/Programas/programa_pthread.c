//
//  programa_pthread.c
//  
//
//  Created by Luis Armando Chávez Soto on 18/04/15.
//
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h> /* 64 bits */

#define clear() printf("\033[H\033[J")


void *helloWorld(void *numHilo)
{
    int i,hilo;
    
    hilo =  (int) numHilo;
    
    for (i=0; i<5; i++){
        printf("Hola Mundo [%d]\n",hilo);
    }
    pthread_exit((void*) numHilo);
}

int main()
{
    // Limpiamos Pantalla
    clear();
    
    // Arreglo de hilos
    pthread_t thread[10];
    pthread_attr_t attr;
    
    // Contador y rc
    int rc, i;
    void *status;
    
    // Inicializador y tipo de Hilo
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    // Ciclo para crear hilo con surespectiva función y paso de argumento
    for(i=0;i<10;i++)
    {

        int *numHilo;
        numHilo = i+1;
        rc = pthread_create(&thread[i], &attr, helloWorld, (void *)numHilo);
        if (rc){
            printf("ERROR: pthread_create() -> %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    // Destruccón del hilo
    pthread_attr_destroy(&attr);
    
    // Estado final del hilo
    for(i=0;i<10;i++)
    {
        rc = pthread_join(thread[i], &status);
        
        if (rc){
            printf("ERROR: pthread_join() -> %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    pthread_exit(NULL);
} 
