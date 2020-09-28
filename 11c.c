#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;
int main(int argc, char * argv[]){

int fd = open(argv[1],O_RDWR|O_APPEND);

if (fd==-1)
{
	perror("Error occured during create call\n");
	printf("%d\n",errno);
	return 0;
}

printf("old fd: %d \n",fd);
int fd2 = fcntl(fd,F_DUPFD);
printf("new fd: %d \n",fd2);

write(fd,"helloworld old fd\n ",18);
write(fd2,"helloworld new fd\n ",18);
getchar();



return 0;	
}

