#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(){

ssize_t ret;

char buf[17];
buf[16]='\0';
int len = sizeof(buf)-1;
int fd1 = open("7_f1.txt",O_RDONLY);
int fd2 = open("7_f2.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
while((ret  = read(fd1,buf,len))!=0){

if(ret!=-1)
{
	write(fd2,buf,ret);
}
else
	printf("error %d",errno);

}

return 0;	
}

