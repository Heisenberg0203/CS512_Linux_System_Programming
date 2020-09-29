#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
extern int errno;
int main(int argc, char * argv[]){

  struct stat sb;
  int ret = stat(argv[1],&sb);
  if (ret==-1)
  {
	perror("Error occured in stat\n");
	printf("%d\n",errno);
  }
  else{
		printf("%d\n",sb.st_mode);
		if((sb.st_mode&S_IFMT)==S_IFREG)
		  printf("Regular file\n");
		if((sb.st_mode&S_IFMT)==S_IFDIR)
		  printf("Directory\n");
		if((sb.st_mode&S_IFMT)==S_IFIFO)
		  printf("FIFO\n");
		if((sb.st_mode&S_IFMT)==S_IFLNK)
		  printf("Link File\n");
		if((sb.st_mode&S_IFMT)==S_IFCHR)
		  printf("Char file\n");
		if((sb.st_mode&S_IFMT)==S_IFBLK)
		  printf("Block file\n");
  }


return 0;	
}

