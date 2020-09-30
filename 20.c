#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main(int argc, char **argv){

  printf("Current priority: %d\n",getpriority(PRIO_PROCESS,0));
  int ret = setpriority(PRIO_PROCESS,0,5);
  printf("Priority Modified to %d using set priority\n", getpriority(PRIO_PROCESS,0));  
  
  printf("Priority Modified to %d using nice \n", nice(-10));  

  return 0;

}
