#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main(){

int fd = open("foo.txt",O_RDWR | O_CREAT , S_IRWXU| S_IRGRP | S_IROTH);

if (fd==-1)
{
	perror("Error occured during open call");
	return 0;
}

printf("%d",fd);
getchar();



return 0;	
}

