#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char **argv){
  pid_t pid;
  double st_time = clock();
  pid=getpid();
  double end_time =clock();

  printf("Time to execute getpid for pid = %d is %f\n",pid,(end_time-st_time)/CLOCKS_PER_SEC);


  return 0;

}
