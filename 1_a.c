#include<unistd.h>
#include<stdio.h>
#include<errno.h>

int main(int argc, char **argv){

 int ret=symlink("1.txt","1_softlink.txt");
 if(ret==-1)
 {
	 perror("Error occured");
}
 return 0;



}
