#include <pthread.h>
#define MAX 20
#define MAX_COUNT 30
int count =0;
pthread_mutex_t count_mutex;
pthread_cond_t count_max;
//int thread_id[3] = {0,1,2};


void* watch()
{
/* lock the variable */
pthread_mutex_lock(&count_mutex);
while(count <= MAX_COUNT)
{
/* using the condition variable for waiting for the event */
pthread_cond_wait(&count_max, &count_mutex);

}
/*unlock the variable*/
pthread_mutex_unlock(&count_mutex);
}
void* increment()
{
int i;
for(i=0; i< MAX ; i++)
{
/* lock the variable */
pthread_mutex_lock(&count_mutex);
count++;

/* for the condition notify the thread */
pthread_cond_signal(&count_max);
/*unlock the variable*/
pthread_mutex_unlock(&count_mutex);
}
}


void main()
{
	int i;

	pthread_mutex_init(&count_mutex, NULL);
	pthread_mutex_init(&count_max, NULL);


/* define the type to be pthread */
pthread_t threads[3];
/* create 3 threads*/
pthread_create(&threads[0], NULL, increment, 0);
pthread_create(&threads[1], NULL, increment, 1);
pthread_create(&threads[2], NULL, watch,2);


pthread_join(threads[0], 0);
pthread_join(threads[1], 1);
pthread_join(threads[2], 2);
}