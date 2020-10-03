#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv,char **envp[]){
  execle("/bin/ls","ls","-rl",NULL,envp);    	
  return 0;

}
