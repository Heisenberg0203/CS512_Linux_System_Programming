#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){
  int timeout=10;
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec=0;
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO,&readfds);

  int ret = select(STDIN_FILENO+1,&readfds,NULL,NULL,&tv);


  if (ret==-1)
  {
	perror("Error occured in select\n");
	printf("%d\n",errno);

  }
  else if (ret==0){
	printf("Timeout %d",timeout);

  }
  else{
		char buf[1024];
		int len = sizeof(buf)-1;
		int read_ret;
		read_ret=read(STDIN_FILENO,buf,len);
		if(read_ret==-1)
			perror("read");
		else
			write(STDOUT_FILENO,buf,read_ret);
  }
  return 0;	
}
