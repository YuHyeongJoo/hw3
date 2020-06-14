#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void fun(pthread_mutex_t *mu){
	int addr = mu;
	printf("hi %d\n",addr);
}
int main(){
	pthread_mutex_t t;
	fun(&t);
	fun(&t);
	return 0;

}
