//
//  programa_fork.c
//  
//
//  Created by Luis Armando Chávez Soto on 17/04/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  /* waitpid */
#include <math.h>


#define clear() printf("\033[H\033[J")

void serieFibonaccio(int iteraciones);
void raices();
void suma();

int main(){
    clear();

    // Identificador
    pid_t pid;
    int i;
    
    // Verificamos proceso padre
    printf("Proceso padre: %d\n\n",getppid());
    
    // Ciclo para la creación del los procesos, asi mismo la asignación de tareas para cada proceso
    for (i = 0; i < 3; ++i) {
        pid = fork();
        if (pid) {
            
            // Ponemos al padre a esperar cada proceso hijo
            int status;
            wait(&status);
            
            continue;
        } else if (pid == 0) {
            //printf("Hijo (%d): %d\n", i + 1, getpid());
            switch (i) {
                case 0:
                    sleep(2);
                    clear();
                    printf("---> Raiz (1er Proceso PID: %d)\n",getpid());
                    raices();
                    break;
                case 1:
                    sleep(3);
                    clear();
                    printf("---> Fibonacci (2do Proceso PID: %d)\n",getpid());
                    int iteraciones = obtenerNumeroFibo();
                    serieFibonaccio(iteraciones);
                    break;
                case 2:
                    sleep(3);
                    clear();
                    printf("---> Suma de los elementos de un arreglo (3er Proceso PID: %d)\n",getpid());
                    suma();
                    break;
                    
            }
            
            break;
        } else {
            printf("Error Fork\n");
            exit(1);
        }
    }
}

// Respectivas funciones para Fibonacci, Raices y suma de los elementos de un arreglo.

int obtenerNumeroFibo(){
    int num;
    do{
        printf("Necesitamos que nos des un numero de iteraciones para la serie de Fibonacci (0-99): \n");
        scanf("%d",&num);
        
        if (num < 0 || num > 99) {
            //clear();
            printf("\n\n *** Error con numero de iteraciones deseadas ***\n\n\n");
        }
        
    }while (num < 0 || num > 99);

    return num;
}

void serieFibonaccio(int iteraciones){

    int i;
    int prim = 0;
    int segu = 1;
    int sig;
    
    printf("Serie: \n");
    
    for (i = 0; i < iteraciones; i++) {
        if (i <= 1) {
            sig = i;
        }else{
            sig = prim + segu;
            prim = segu;
            segu = sig;
        }
        printf("%d - ",sig);
    }
    
    printf("\n\n\n");

}

void raices(){
    
    int tamanio;
    do {
        printf("Tamaño del arreglo (1 - 20): \n");
        scanf("%d",&tamanio);
        
        if (tamanio < 1 || tamanio > 20) {
            //clear();
            printf("\n\n *** Error con el tamanio del arreglo deseado ***\n\n\n");
        }
        
    } while (tamanio < 1 || tamanio > 20);
    
    int arreglo [tamanio];
    int i;
    
    printf("\nLlene el arreglo con valores entre 0 y 99\n");
    
    int dato;
    for (i = 0; i < tamanio ; i++) {
        
        do {
            printf("\nArreglo[%d] - ",i);
            scanf("%d",&dato);
            
            if (dato < 0 || dato > 99) {
                //clear();
                printf("\n\n *** Error con el dato, fuera de rango ***\n\n\n");
            }else{
                arreglo[i] = dato;
            }
            
        } while (dato < 0 || dato > 99);
        
    }
    
    
    printf("\nArreglo lleno.\n");
    
    printf("Iteracion \tValor \tRaiz\n");
    for (i = 0; i < tamanio; i++) {
        if (arreglo [i] < 0) {
            printf("Arreglo[%d] \t%d \tMath ERROR",i,arreglo[i]);
        }else{
            printf("Arreglo[%d] \t%d \t%f",i, arreglo[i],sqrt(arreglo[i]));
        }
        printf("\n");
    }


    printf("\n\n\n");

    

}

void suma(){
    int tamanio;
    do {
        printf("Tamaño del arreglo (1 - 20): \n");
        scanf("%d",&tamanio);
        
        if (tamanio < 1 || tamanio > 20) {
            //clear();
            printf("\n\n *** Error con el tamanio del arreglo deseado ***\n\n\n");
        }
        
    } while (tamanio < 1 || tamanio > 20);
    
    int arreglo [tamanio];
    int i;
    
    printf("\nLlene el arreglo con valores entre 0 y 99\n");
    
    int dato;
    for (i = 0; i < tamanio ; i++) {
        
        do {
            printf("\nArreglo[%d] - ",i);
            scanf("%d",&dato);
            
            if (dato < 0 || dato > 99) {
                //clear();
                printf("\n\n *** Error con el dato, fuera de rango ***\n\n\n");
            }else{
                arreglo[i] = dato;
            }
            
        } while (dato < 0 || dato > 99);
        
    }
    printf("\nArreglo lleno.\n");
    
    int dat = 0;
    
    for (i = 0; i < tamanio; i++) {
        dat = dat + arreglo[i];
    }
    
    printf("Sumatoria de los elementos del arreglo: %d",dat);
    
    printf("\n\n\n");
}


