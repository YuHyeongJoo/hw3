#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int arr[5]={0,0,0,0,0};
int o=0;
int main ()
{
	int fd = open(".ddtrace", O_RDONLY | O_SYNC ) ;

	char s[128] ;
	int k;
	
		int sum, y;
	while(1){
//		sum =-10;
//		while(sum==-10){
//			read(fd,&sum,4);
//		}
	o++;
		read(fd,&y,4);
		read(fd,&y,4);	
		printf("first: %d\n",y);	
		read(fd,&k,4);	
		printf("second :%d\n",k);
		read(fd,&k,4);
		printf("%d is received\n",k);

	}
	close(fd) ;
	return 0 ;
}
