  
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
	int (*lock)(pthread_mutex_t *mutex);
	lock = dlsym(RTLD_NEXT,"pthread_mutex_lock");
        int err = lock(mu);
	int ind =0;
	pthread_t id = pthread_self();
	int kkk = open(".ddtrace", O_WRONLY | O_SYNC) ;
	int addr = mu;
	sleep(1);
	write(kkk, &ind,4);
	write(kkk,&addr,4);
	printf("lock\naddress of mutex : %d\n",addr);
	write(kkk, &id,4);
	printf("thread id : %d\n",id);
	close(kkk);
	return err;	
}
int pthread_mutex_unlock(pthread_mutex_t *mu){
	int (*unlock)(pthread_mutex_t *mutex);
        unlock = dlsym(RTLD_NEXT,"pthread_mutex_unlock");
	int err = unlock(mu);
	int ind =1;
	int kk=open(".ddtrace", O_WRONLY | O_SYNC) ;
	pthread_t id = pthread_self();
	int addr = mu;
	sleep(1);
        write(kk, &ind,4);
        write(kk,&addr,4);
	printf("unlock\naddress of mutex : %d\n",addr);
        write(kk, &id,4);
        printf("thread id : %d\n",id);
	close(kk);
	return err;
	


}
