#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("record",O_RDWR);


  if (fd==-1)
  {
	perror("Error occured in open\n");
	printf("%d\n",errno);

  }
  else{
	  struct database{
	  int ticket_count;
	  } ;

	  struct database db;


	  //lock
	  struct flock lock;
	  lock.l_type = F_WRLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start=0;
	  lock.l_len =0;
	  lock.l_pid = getpid();
	  fcntl(fd,F_SETLKW,&lock);
	  printf("Ticket booking is now available\n");
	  read(fd,&db,sizeof(db));
	  printf("Current ticket count %d Press enter to book\n ",db.ticket_count);
	  getchar();
	  //booking ticket and updating db
	  db.ticket_count++;
	  lseek(fd,0,SEEK_SET);
	  write(fd,&db,sizeof(db));
	  printf("Your ticket number is %d Press enter to confirm\n", db.ticket_count);
	  getchar();
	  lock.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&lock);
	  printf("--FINISH--\n");
  }
  return 0;	
}
