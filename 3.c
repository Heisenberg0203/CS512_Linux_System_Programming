#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(){

int fd = creat("3_file.txt",0644);

if (fd==-1)
{
	perror("Error occured during create call\n");
	printf("%d\n",errno);
	return 0;
}

printf("fd: %d \n",fd);
getchar();



return 0;	
}

