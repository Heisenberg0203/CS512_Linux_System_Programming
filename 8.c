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
int fd = open("8_f.txt",O_RDONLY);

while((ret  = read(fd,buf,len))!=0){

if(ret!=-1)
{
	if(ret<len)
		buf[ret]='\0';
	printf("%s",buf);
}
else
	printf("error %d",errno);

}

return 0;	
}

