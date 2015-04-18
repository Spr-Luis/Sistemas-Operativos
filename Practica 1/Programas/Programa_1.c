//
//  Programa_1.c
//  
//
//  Created by Luis Armando Chávez Soto on 17/04/15.
//
//

#include <stdio.h> 
#include <stdlib.h> 

int main(){
    int fork_return;
    int count = 0;
    
    printf("Proceso %d que invoca fork()\n", getpid() );
    fork_return = fork();

    //Cuando utilizamos la llamada al sistema fork, el proceso hijo creado es una copia exacta del padre (salvo por el PID y la memoria que ocupa). Al proceso hijo se le facilita una copia de las variables del proceso padre y de los descriptores de fichero. Es importante destacar que las variables del proceso hijo son una copia de las del padre (no se refieren físicamente a la misma variable), por lo que modificar una variable en uno de los procesos no se refleja en el otro.
    
    if( fork_return < 0) {
        printf("No fue posible crear el proceso hijo\n");
        exit(1);
    }
    
    system("ps");
    
    if( fork_return > 0) {
        
        printf("Proceso hijo creado %d.\n", fork_return);
        
        while( count++ < 800) {
            putchar('a');
            if(count % 80 == 0) {
                putchar('\n');
                sleep(2);
            }
        }
        
    }else {
        
        while(count++ < 800) {
            putchar('b');
            
            if(count % 80 == 0) {
                putchar('\n');
                sleep(2);
            }
        }
        
    }
}