#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int argc, char **argv){
  
  int pid = fork();
  if(pid==0){
    printf("Child process %d\n",getpid());
    printf("creating daemon process \n");
    setsid();
    chdir("/");
    //daemon(0,1);
    umask(0);
    while(1){
    printf("Daemon process is running everyday at this time\n");
    sleep(10); 
    }
  }
  else{
    printf("Parent process %d\n",getpid());
    return 0;
  }
  return 0;

}
