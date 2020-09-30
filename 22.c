#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(int argc, char **argv){
  int fd = open("22_file.txt",O_RDWR|O_CREAT|O_TRUNC,0644); 
  int parent=getpid();
  int pid = fork();
  if(pid==0){
   char buf[] = "This is written by child process\n";
   write(fd,buf,sizeof(buf));

  }
  else{
   char buf[] = "This is written by parent process\n";
   write(fd,buf,sizeof(buf));

  }
  
  while(waitpid(-1,NULL,WNOHANG)!=-1);
  if(parent==getpid()) 
  {
    lseek(fd,0,SEEK_SET);
    char newbuff[5];
    int ret;

    while((ret=read(fd,newbuff,sizeof(newbuff)))!=0){
      write(2,newbuff,ret);
    }
  }
  return 0;

}
