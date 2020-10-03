#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("record",O_RDONLY);
  


  if (fd==-1)
  {
	perror("Error occured in open\n");
	printf("%d\n",errno);

  }
  else{
	  struct database{
	  int ticket_count;
	  } ;

	  struct database record;
	  
	  read(fd,&record,sizeof(record));
	    printf(" Ticket Number %d\n",record.ticket_count);

	  printf("--FINISH--\n");
  }
  return 0;	
}
