#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("db",O_RDONLY);
  


  if (fd==-1)
  {
	perror("Error occured in open\n");
	printf("%d\n",errno);

  }
  else{
	  struct database{
	  int train_number;
	  int ticket_count;
	  } ;

	  struct database db[3];
	  
	  read(fd,db,sizeof(db));
	  for(int i=0;i<3;i++){
	    printf("Train Number %d, Ticket Number %d\n",db[i].train_number,db[i].ticket_count);
	  }

	  printf("--FINISH--\n");
  }
  return 0;	
}
