#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char **argv){
  
  int p,c1,c2,c3,status;
  printf("Parent pid: %d\n",getpid());
  
  if(!(c1=fork())){
    printf("Child 1 pid: %d\n",getpid()); 
  }
  else if (!(c2=fork())){
    printf("child 2 pid: %d\n",getpid());
    sleep(4);
  }
  else if (!(c3=fork())){
	  
  printf("child 3 pid: %d\n",getpid());	
 }
 else{
 
  printf(" Parent waiting for child pid %d\n",c2);
  waitpid(c2,&status,0);
  printf("Child %d completed execution with status %d\n",c2,status); 
 
 
 }

  return 0;

}
