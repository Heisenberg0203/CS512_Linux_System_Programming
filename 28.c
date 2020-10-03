#include<stdio.h>
#include<unistd.h>
#include<sched.h>
int main(int argc, char **argv){
 
   int max,min;
   printf("------FIFO--------\n");
   max = sched_get_priority_max(SCHED_FIFO);
   min = sched_get_priority_min(SCHED_FIFO);
   printf(" max priority: %d min priority: %d\n",max,min);
   printf("------RR--------\n");
   max = sched_get_priority_max(SCHED_RR);
   min = sched_get_priority_min(SCHED_RR);
   printf(" max priority: %d min priority: %d\n",max,min);
   return 0;

}
