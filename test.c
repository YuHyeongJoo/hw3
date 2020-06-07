#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <execinfo.h>
static int count = 0 ;
static int arr[10]= {0,0,0,0,0,0,0,0,0,0};
int rand()
{	arr[count]=1;
	for(int i=0; i<10; i++){
		printf("%d ",arr[i]);
}
	printf("\n");
	count++;
	return count ; 
}
	
