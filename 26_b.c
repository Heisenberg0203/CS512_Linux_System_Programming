#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv){
 
  execl("./26_a","hello world",NULL);    	
  return 0;

}
