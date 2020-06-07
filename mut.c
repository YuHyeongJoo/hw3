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
pthread_mutex_t t;

void *fun(void *data){
	pthread_mutex_lock(&t);
	 printf("lock\n");
	sleep(3);
        pthread_mutex_unlock(&t);

}

void *fun2(void *data){
        pthread_mutex_lock(&t);
         printf("lock2\n");
        pthread_mutex_unlock(&t);

}




int main(){
	pthread_t a,b;
	pthread_create(&a,NULL,fun,NULL);
	pthread_create(&b,NULL,fun2,NULL);
	pthread_join(a, NULL);
	pthread_join(b,NULL);

}
