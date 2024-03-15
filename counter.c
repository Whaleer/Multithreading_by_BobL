#include "stdio.h"
#include "pthread.h"

#define N 10

int cnt;
pthread_mutex_t lock;

void *incr(void *arg) {

    pthread_mutex_lock(&lock);
    for (int i = 0; i < 1e5; ++i) {
        cnt++;
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}


int main() {

    pthread_t pthreads[N];
    pthread_mutex_init(&lock, NULL);


    for (int i = 0; i < N; ++i) {
        pthread_create(&pthreads[i], NULL, incr, NULL);
    }

    for (int i = 0; i < N; ++i) {
        pthread_join(pthreads[i], NULL);
    }
    printf("cnt : %d\n", cnt);
    pthread_mutex_destroy(&lock); // 释放锁

    return 0;
}