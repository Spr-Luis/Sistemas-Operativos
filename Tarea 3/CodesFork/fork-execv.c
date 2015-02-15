#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main()
{
    pid_t pid=fork();
    if (pid==0) 
    { 
        static char *argv[]={"echo","Procesos e Hilos en POSIX",NULL};
        execv("/bin/echo",argv);
        exit(EXIT_SUCCESS); 
	printf("No se imprimira\n");
    }
    else 
    { 
        waitpid(pid,0,0); 
    }
    return 0;
}
