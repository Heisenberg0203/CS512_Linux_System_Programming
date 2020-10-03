#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, char **argv){

 int ret=mknod("1_c_fifo",S_IFIFO,0);
 if(ret==-1)
 {
	 perror("Error occured");
}
 return 0;



}
