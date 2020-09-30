#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(int argc, char **argv){
  int parent=getpid();
  int pid = fork();
  if(pid==0){
	printf("child process: %d\n",getpid());
	return 0;
  }
  else{
  	printf("parent process: %d\n",getpid());
	sleep(100);
  }
  
  return 0;

}
