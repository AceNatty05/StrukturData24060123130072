#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _REENTRANT

// Fungsi thread
void *ThreadRoutine(void *arg) {
    int number = *(int *)arg;  // Cast argumen ke int
    printf("thread %d running\n", number);
    sleep(number);  // Tunggu sesuai nomor thread
    printf("thread %d finish, joining...\n", number);
    return NULL;
}

int main(void) {
    int t;
    pthread_t tid[5];         // Array untuk menyimpan ID thread
    int args[5];              // Array untuk menyimpan argumen tiap thread

    // Membuat 4 thread
    for (t = 0; t < 5; t++) {
        args[t] = t + 1;      // Menyimpan nilai unik untuk setiap thread
        pthread_create(&tid[t], NULL, ThreadRoutine, &args[t]);
    }

    // Menunggu semua thread selesai
    for (t = 0; t < 5; t++) {
        pthread_join(tid[t], NULL);
    }

    printf("All kids joined, parent running\n");
    return 0;
}
