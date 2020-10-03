#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(int arc, char* argv[]){

off_t ret;

int fd = open(argv[1],O_RDWR);

//go to the end of file
ret = lseek(fd,0,SEEK_END);
printf("%ld\n",ret);
//write 10 bytes
write(fd,"hellofile ",10);
ret = lseek(fd,0,SEEK_CUR);
//move 1000000000 bytes ahead from current position
ret = lseek(fd,ret+10000000l,SEEK_SET);
printf("%ld\n",ret);
// write 10 bytes
write(fd,"hellofile ",10);

return 0;	
}


/*
0000000   T   h   i   s       i   s       t   h   e       b   e   g   i
0000020   n   n   i   n   g       o   f       f   i   l   e   .  \n   h
0000040   e   l   l   o   f   i   l   e      \0  \0  \0  \0  \0  \0  \0
0000060  \0  \0  \0   h   e   l   l   o   f   i   l   e       h   e   l
0000100   l   o   f   i   l   e      \0  \0  \0  \0  \0  \0  \0  \0  \0
0000120  \0   h   e   l   l   o   f   i   l   e    
0000133
*/
// -rw-rw-r-- 1 rushikesh rushikesh 91 Sep 28 03:12 10_f.txt
