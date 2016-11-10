#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    int i = open("log.txt",O_CREAT | O_EXCL | O_WRONLY,0644);
    char *str = "Exit due to SIGINT \n";
    int success = write(i,str,20);
    if(success == -1)
      printf("error: %s - \n",strerror(errno));
    close(i);
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
