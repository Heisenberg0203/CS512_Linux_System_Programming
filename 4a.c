#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(){

int fd = open("4a.txt",O_RDWR | O_CREAT);

if (fd==-1)
{
	perror("Error occured during open call\n");
	printf("%d\n",errno);
	return 0;
}

printf("fd: %d \n",fd);
getchar();



return 0;	
}

