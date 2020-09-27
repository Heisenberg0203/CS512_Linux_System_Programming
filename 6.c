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

while((ret  = read(1,buf,len))!=0){

if(ret!=-1)
{
	write(2,buf,ret);
}
else
	printf("error %d",errno);

}

return 0;	
}

