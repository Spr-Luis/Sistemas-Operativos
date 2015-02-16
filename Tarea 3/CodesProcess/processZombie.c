#include <stdlib.h> 

// Para sistemas Linux
//#include </usr/include/x86_64-linux-gnu/sys/types.h>
// Para sistemas Unix
#include <sys/types.h>

#include <unistd.h>

int main () 
{
  pid_t child_pid; 

  child_pid = fork  (); 

  if (child_pid > 0)  
  {
    sleep (60); 
  } 
  else 
  {
    exit (0); 
  } 

  return 0; 
} 


