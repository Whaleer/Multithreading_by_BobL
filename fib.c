#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int fib(int n) {
    if (n < 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}


void *p_fib(void *arg) {
    int *p = arg;
    int *res = malloc(sizeof (int));
    *res = fib(*p);
    return res;
}

int main() {
    pthread_t pthread;
    int arg = 10;

    pthread_create(&pthread, NULL, p_fib, (void *) &arg);
    int * res;
    pthread_join(pthread, (void *) &res);
    printf("res: %d\n", *res);
    return 0;
}