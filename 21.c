#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
  
  int pid = fork();
  if(pid==0){
    printf("Child process %d\n",getpid()); 
  }
  else{
    printf("Parent process %d\n",getpid());
  }
  return 0;

}
