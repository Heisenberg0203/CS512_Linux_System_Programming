#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int i=97,count=0;
while(1){
	if(count<5)	
	{
		char str[8] = "5_filex";
		str[6]=i;
		int fd1 = creat(str,0644);
		if(fd1>=0){
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}
}
getchar();
return 0;
}

//total 0
//lrwx------ 1 rushikesh rushikesh 64 Sep 27 13:13 0 -> /dev/pts/0
//lrwx------ 1 rushikesh rushikesh 64 Sep 27 13:13 1 -> /dev/pts/0
//lrwx------ 1 rushikesh rushikesh 64 Sep 27 13:13 2 -> /dev/pts/0
//l-wx------ 1 rushikesh rushikesh 64 Sep 27 13:13 3 -> /home/rushikesh/Desktop/lsp/handsonlist1/5_filea
//l-wx------ 1 rushikesh rushikesh 64 Sep 27 13:13 4 -> /home/rushikesh/Desktop/lsp/handsonlist1/5_fileb
//l-wx------ 1 rushikesh rushikesh 64 Sep 27 13:13 5 -> /home/rushikesh/Desktop/lsp/handsonlist1/5_filec
//l-wx------ 1 rushikesh rushikesh 64 Sep 27 13:13 6 -> /home/rushikesh/Desktop/lsp/handsonlist1/5_filed
//l-wx------ 1 rushikesh rushikesh 64 Sep 27 13:13 7 -> /home/rushikesh/Desktop/lsp/handsonlist1/5_filee
