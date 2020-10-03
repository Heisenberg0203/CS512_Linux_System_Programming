#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
  char *envp[] = { "SOURCE=27c.c","TARGET=OUTPUT",NULL};
  execle("/bin/ls","ls","-rl",NULL,envp);    	
  return 0;

}
