/*
    ps af -o pid.ppid.stat.nice.uname.cmd.pmem.pcpu.time
 */


#include <unistd.h>		// Definición de Fork()

// Para sistemas Linux
//#include </usr/include/x86_64-linux-gnu/sys/types.h>
// Para sistemas Unix
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>

// Para sistemas Linux
//#include <x86_64-linux-gnu/sys/wait.h>
// Para sistemas Unix
#include <sys/wait.h>

#include <stdlib.h>

main()
{
    pid_t childpid; 
    int retval;     
    int status;     
	
    childpid = fork();
	
    if (childpid >= 0) 
    {
        // Proceso Hijo
        if (childpid == 0) 
        {
            printf("Hijo: Soy el Proceso HIJO!\n");
            printf("Hijo: Mi PID: %d\n", getpid());
            printf("Hijo: El PID de mi Padre es: %d\n", getppid());
            printf("Hijo: El valor de mi copia de childpid es: %d\n", childpid);
            printf("Hijo: Durmiendo por 1 segundo...\n");
            sleep(1);
            printf("Hijo: Ingresa un valor para salir (0 a 255): ");
            scanf(" %d", &retval);
	    printf("Hijo: Adios!\n");
	    exit(retval); 
	}
        // Proceso Padre
	else
	{
		printf("Padre: Soy el Proceso PADRE!\n");
		printf("Padre: Mi PID: %d\n", getpid());
		printf("Padre: El valor de mi copia de childpid es %d\n", childpid);
		printf("Padre: Ahora voy a esperar a mi proceso HIJO para salir.\n");
		wait(&status); 
		printf("Padre: Codigo de salida del Proceso HIJO es: %d\n", WEXITSTATUS(status)); // WEXITSTATUS() Macros del sistema de Wait (Lo que esta arrojando la salida del proceso)
		printf("Padre: Adios!\n");
		exit(0);  
	}
    }
    else 
    {
	perror("fork"); 
	exit(0);
    }
}
