#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main(){

int fd = open("4b.txt",O_RDWR | O_CREAT | O_EXCL , S_IRWXU| S_IRGRP | S_IROTH);

if (fd==-1)
{
	perror("Error occured during open call");
	return 0;
}

printf("%d",fd);
getchar();



return 0;	
}

