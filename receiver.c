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
	int fd = open("channel", O_RDONLY | O_SYNC) ;

	char s[128] ;
	int k,sum=0;
	while(1){
		int y;
		read(fd,&y,4);	
		if(y==-1) {
                        sum++;
                        break;
                }
	
		read(fd,&k,4);
		printf("%d is received\n",k);
		sum= sum+k;
	}
	printf("%d\n",sum);
	close(fd) ;
	return 0 ;
}
