#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define _REENTRANT

void* ThreadRoutine(void* arg) {
    int number = (intptr_t)arg;  // Konversi dari void* ke int
    for (int i = 0; i < 10; i++) {
        printf("Thread %d running %d\n", number, i);
        sleep(1); // Tidur selama 1 detik
    }
    return NULL;
}

int main(void) {
    pthread_t tid1, tid2;

    // Buat 2 thread
    pthread_create(&tid1, NULL, ThreadRoutine, (void*)(intptr_t)1);
    pthread_create(&tid2, NULL, ThreadRoutine, (void*)(intptr_t)2);

    // Detach thread 1
    pthread_detach(tid1);

    // Join thread 2 saja
    if (pthread_join(tid2, NULL) > 0) {
        printf("Unable to join thread 2\n");
    }

    printf("Parent finished\n");
    return 0;
}
