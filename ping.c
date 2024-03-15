#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *pong(void *arg) {
    for (int i = 0; i < 100; ++i) {
        usleep(1000);
        printf("pong\n");
    }
    return NULL;
}

int main() {
    pthread_t pthread;
    pthread_create(&pthread, NULL, pong, NULL);
    for (int i = 0; i < 100; ++i) {
        usleep(1000);
        printf("ping\n");
    }
    pthread_join(pthread, NULL);


    return 0;
}