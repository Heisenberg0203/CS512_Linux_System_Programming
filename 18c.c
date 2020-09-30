#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
extern int errno;

int main(int argc, char * argv[]){

  int fd = open("db",O_RDWR);


  if (fd==-1)
  {
	perror("Error occured in open\n");
	printf("%d\n",errno);

  }
  else{
	  struct database{
	  int train_number;
	  int ticket_count;
	  } ;

	  struct database db;

	  printf("Enter Train Number {1,2,3} to book\n");
	  int train_no;
	  scanf("%d%*c",&train_no);
	  if(train_no<1&&train_no>3){
		  printf("Invalid details\n");
		  return -1;
	  }



	  //lock
	  struct flock lock;
	  lock.l_type = F_WRLCK;
	  lock.l_whence = SEEK_SET;
	  lock.l_start=(train_no-1)*sizeof(db);
	  lock.l_len =sizeof(db);
	  lock.l_pid = getpid();
	  fcntl(fd,F_SETLKW,&lock);
	  printf("Ticket booking is now available\n");
	  //reading current values 
	  lseek(fd,(train_no-1)*sizeof(db),SEEK_SET);
	  read(fd,&db,sizeof(db));
	  printf("Current ticket count %d Press enter to book\n",db.ticket_count);
	  getchar();
	  //booking ticket and updating db
	  db.ticket_count++;
	  lseek(fd,-sizeof(db),SEEK_CUR);
	  write(fd,&db,sizeof(db));
	  printf("Your ticket number is %d Press enter to confirm\n", db.ticket_count);
	  getchar();
	  lock.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&lock);
	  printf("--FINISH--\n");
  }
  return 0;	
}
