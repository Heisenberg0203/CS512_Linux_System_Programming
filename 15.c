#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
extern int errno;
extern char **environ;
int main(int argc, char * argv[]){

while(*environ!=NULL){
printf("%s\n",*environ);
environ=environ+1;
}

return 0;	
}

