#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("db",O_RDWR);


  if (fd==-1)
  {
	perror("Error occured in open\n");
	printf("%d\n",errno);

  }
  else{

	  //lock
	  struct flock lock;
	  lock.l_type = F_WRLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start=0;
	  lock.l_len =0;
	  lock.l_pid = getpid();
	  fcntl(fd,F_SETLKW,&lock);
	  printf("Inside Critical Section with Write Lock\n");
	  
	  printf(" Press enter to continue\n ");
	  getchar();
	  lock.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&lock);
	  close(fd);
	  printf("--FINISH--\n");
  }
  return 0;	
}
