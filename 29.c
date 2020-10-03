#include<stdio.h>
#include<unistd.h>
#include<sched.h>
int main(int argc, char **argv){
   
   struct sched_param param;
   
   int policy = sched_getscheduler(0);
   printf(" current policty: %d\n",policy);
   sched_getparam(0,&param);
   printf(" current priority: %d\n",param.sched_priority);
   
   //modifying policy and priority to RR and 22
   param.sched_priority = 88;
   int ret = sched_setscheduler(0,SCHED_RR,&param);
   if(ret==-1)
	   printf("Error in sched_setscheduler\n");
   else{
	   policy = sched_getscheduler(0);	   
	   printf(" new policy: %d\n",policy);	;
           sched_getparam(0,&param);
           printf(" new priority: %d\n",param.sched_priority);
          
   }   
   return 0;

}
