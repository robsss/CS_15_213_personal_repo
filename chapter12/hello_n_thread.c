#include "csapp.h"
#include <pthread.h>

void *thread(void *vargp); /* Thread routine prototype */

int main(int argc, char **argv)
{
    pthread_t *tid_arr;
   
    /* Check input argument */
    if (argc != 2)
    {
        printf("usage: %s n \n", argv[0]);
        exit(0);
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please provide a positive integer for the number of threads.\n");
        exit(0);
    }
    // allocate the unknow size array before execution on heap
    tid_arr = Malloc(n * sizeof(pthread_t));
    
    //pthread_t tid_arr[n]; /* Array to hold thread IDs */
    /* Create thread and wait for it to finish */
    for(int i = 0; i < n ; i++) {
        Pthread_create(&tid_arr[i], NULL, thread, NULL);

    }

    for(int i = 0; i < n; i++) {
        Pthread_join(tid_arr[i], NULL);
    }

    exit(0);
}

void *thread(void *vargp)
{
    printf("Hello, World!\n");
    return NULL;
}
