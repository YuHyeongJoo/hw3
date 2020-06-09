#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
pthread_mutex_t k,t;

void *fun(void *data){
	pthread_mutex_lock(&k);
	sleep(3);
        pthread_mutex_unlock(&k);

}

void *fun2(void *data){
        pthread_mutex_lock(&t);
        pthread_mutex_unlock(&t);
	pthread_mutex_lock(&k);
	pthread_mutex_unlock(&k);

}




int main(){
	pthread_t a,b;
	pthread_create(&a,NULL,fun,NULL);
	sleep(1);
	pthread_create(&b,NULL,fun2,NULL);
	pthread_join(a, NULL);
	pthread_join(b,NULL);

}
