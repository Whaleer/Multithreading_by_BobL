#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void *p_fib(void *arg) {
    int *p = arg;
    int *res = malloc(sizeof(int));
    if (*p < 2) {
        *res = 1;
        return res;
    }
    pthread_t pthread1;
    pthread_t pthread2;
    int arg1 = *p - 1;
    int arg2 = *p - 2;
    pthread_create(&pthread1, NULL, p_fib, (void *) &arg1); // spawn thread 1
    pthread_create(&pthread2, NULL, p_fib, (void *) &arg2); // spawn thread 2

    // sync
    int *res1;
    int *res2;
    pthread_join(pthread1, (void *) &res1);
    pthread_join(pthread2, (void *) &res2);
    *res = *res1 + *res2;

    // free
    free(res1);
    free(res2);

    return res;
}

int main() {
    pthread_t pthread;
    int arg = 5;

    pthread_create(&pthread, NULL, p_fib, (void *) &arg);

    int *res;
    pthread_join(pthread, (void *) &res);
    printf("res: %d\n", *res);
    return 0;
}