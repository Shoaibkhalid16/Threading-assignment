#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mut;
int pthread_mutes_lock(pthread_mutex_t *mut);
int pthread_mutes_unlock(pthread_mutex_t *mut);
int sum=0;

void* sum_array(void* arg)
{
	int start=(int)arg;
	int end=start+1000;
	int i;
	for(i=start;i<end;i++)
	{
		pthread_mutex_lock(&mut);
		sum++;
		pthread_mutex_unlock(&mut);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	pthread_create(&t1,NULL,sum_array,(void*)0);
	pthread_create(&t2,NULL,sum_array,(void*)1000);
	pthread_create(&t3,NULL,sum_array,(void*)2000);
	pthread_create(&t4,NULL,sum_array,(void*)3000);
	pthread_create(&t5,NULL,sum_array,(void*)4000);
	pthread_create(&t6,NULL,sum_array,(void*)5000);
	pthread_create(&t7,NULL,sum_array,(void*)6000);
	pthread_create(&t8,NULL,sum_array,(void*)7000);
	pthread_create(&t9,NULL,sum_array,(void*)8000);
	pthread_create(&t10,NULL,sum_array,(void*)9000);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	pthread_join(t6,NULL);
	pthread_join(t7,NULL);
	pthread_join(t8,NULL);
	pthread_join(t9,NULL);
	pthread_join(t10,NULL);
	
	pthread_mutex_destroy(&mut);
	
	printf("The Sum of all threads is: %d",sum);
	return 0;
}

