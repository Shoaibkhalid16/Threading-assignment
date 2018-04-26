#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];

void* sum_array(void* arg)
{
	int start=(int)arg;
	int end=start+100;
	int i,sum=0;
	for(i=start;i<end;i++)
	{
		sum=sum+arr[i];
	}
	return (void *)sum;
}

int main()
{
	int i;
	void* ans[10];
	for(i=0;i<1000;i++)
	{
		arr[i]=i;
	}
	pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	pthread_create(&t1,NULL,sum_array,(void*)0);
	pthread_create(&t2,NULL,sum_array,(void*)100);
	pthread_create(&t3,NULL,sum_array,(void*)200);
	pthread_create(&t4,NULL,sum_array,(void*)300);
	pthread_create(&t5,NULL,sum_array,(void*)400);
	pthread_create(&t6,NULL,sum_array,(void*)500);
	pthread_create(&t7,NULL,sum_array,(void*)600);
	pthread_create(&t8,NULL,sum_array,(void*)700);
	pthread_create(&t9,NULL,sum_array,(void*)800);
	pthread_create(&t10,NULL,sum_array,(void*)900);
	
	pthread_join(t1,&ans[0]);
	pthread_join(t2,&ans[1]);
	pthread_join(t3,&ans[2]);
	pthread_join(t4,&ans[3]);
	pthread_join(t5,&ans[4]);
	pthread_join(t6,&ans[5]);
	pthread_join(t7,&ans[6]);
	pthread_join(t8,&ans[7]);
	pthread_join(t9,&ans[8]);
	pthread_join(t10,&ans[9]);
	
	int total=0;
	for(i=0;i<10;i++)
	{
		total+=(int)ans[i];
	}
	printf("The Sum of all threads is: %d",total);
	return 0;
}

