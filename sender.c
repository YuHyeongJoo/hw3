#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int 
main ()
{
/*	if (mkfifo("channel", 0666)) {
		if (errno != EEXIST) {
			perror("fail to open fifo: ") ;
			exit(1) ;
		}
	}
*/	
	printf("kk-1\n");
	int fd = open("channel", O_WRONLY | O_SYNC) ;

		char s[128]= "hi my namer is hy" ;
		char newline ;
	printf("kk\n");
		
	//	if (s[0] == 0x0) 
	//		break ;
	for(int i=0; i<10; i++){
		int u =10;	
		 write(fd,&u , 4) ;
		write(fd,&i,4);
		write(fd,&i,4);
		printf("%d is sended\n",i);
	}
	int k=-1;
	write(fd,&k,4);
	close(fd) ;
	return 0 ;
}
