#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
 
  execlp("ls","ls","-rl",NULL);    	
  return 0;

}
