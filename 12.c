#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;
int main(int argc, char * argv[]){

int fd = open(argv[1],O_WRONLY);

if (fd==-1)
{
	perror("Error occured during create call\n");
	printf("%d\n",errno);
	return 0;
}

printf(" fd: %d \n",fd);
int status = fcntl(fd,F_GETFL)&O_ACCMODE;
if(status==0)
printf("status: read \n");
else if (status==1)
printf("status: write \n");
else
printf("status: read/write\n");
getchar();



return 0;	
}

