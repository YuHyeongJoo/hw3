  
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
int pthread_mutex_lock(pthread_mutex_t *mu){
	int ind =0;
	pthread_t id = pthread_self();
	int kkk = open("ddtrace", O_WRONLY | O_SYNC) ;
	int addr = mu;
	int (*lock)(pthread_mutex_t *mutex);
	write(kkk, &ind,4);
	write(kkk,&addr,4);
	write(kkk, &id,4);
	printf("sended\n");
	lock = dlsym(RTLD_NEXT,"pthread_mutex_lock");
	int err = lock(mu);	
	close(kkk);
	return err;	
}
//int pthread_mutex_lock(pthread_mutex_t *mu){
//	
//}
