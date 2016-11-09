#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("Exit due to SIGINT \n");
    exit(1);
  }

  if (signo == SIGUSR1){
    printf("Parent pid: %d \n", getppid());
  }
}
      
int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  int pid;
  while (1){
    pid=getpid();
    printf("pid: %d \n", pid);
    sleep(1);
  }
  return 0;
}
