#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
  execl("/bin/ls","ls","-rl",NULL);    	
  return 0;

}
