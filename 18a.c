#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("db",O_RDWR|O_CREAT|O_TRUNC,0644);


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

	  for(int i=0;i<3;i++){
	    db[i].train_number=i+1;
	    db[i].ticket_count=0;
	  }

	  struct flock lock;
	  lock.l_type = F_WRLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start=0;
	  lock.l_len =0;
	  lock.l_pid = getpid();
	  printf("Entering Critial Section and Setting Database\n");
	  fcntl(fd,F_SETLKW,&lock);
	  write(fd,db,sizeof(db));
	  printf("Inside Critical section,Press enter to conitnue\n");
	  getchar();
	  printf("Database setup complete\n");
	  lock.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&lock);
	  printf("--FINISH--\n");
  }
  return 0;	
}
