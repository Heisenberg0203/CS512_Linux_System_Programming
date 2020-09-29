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
		  printf("inode %ld\n",sb.st_ino);
		  printf("Number of hard link  %ld\n",sb.st_nlink);
		  printf("uid %d\n",sb.st_uid);
		  printf("gid %d\n",sb.st_gid);
		  printf("sid %ld\n",sb.st_size);
		  printf("Block size %ld\n",sb.st_blksize);
		  printf("Number of blocks %ld\n",sb.st_blocks);
		  printf("Access time %ld\n",sb.st_atime);
		  printf("Modification time %ld\n",sb.st_mtime);
		  printf("Change time %ld\n",sb.st_ctime);
  }


return 0;	
}

