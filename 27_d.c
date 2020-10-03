#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
  char *args[] = {"ls","-rl",NULL}; 
  execv("/bin/ls",args);    	
  return 0;

}
