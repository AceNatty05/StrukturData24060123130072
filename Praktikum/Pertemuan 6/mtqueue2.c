/* Program   : mtqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 04//10/2024*/

#include "tqueue2.c"

int main(){
    /*KAMUS*/
    tqueue2 Q, N, A;
    char c;
    int X;

    /*ALGORITMA*/

    printf("\n***** SELAMAT DATANG DRIVER PROGRAM TQUEUE MODEL 2 *****\n");

    printf("\n***** Queue Q *****\n");

    createQueue2(&Q);
    enqueue2(&Q,'M'); enqueue2(&Q,'A'); enqueue2(&Q,'K'); enqueue2(&Q,'A'); enqueue2(&Q,'N');
    PrintAll(Q);

    createQueue2(&N);
    printf("\n\n***** Queue N *****\n");
    printf("Queue N akan diisi secara manual\n");
    printf("Berapa elemen untuk diisi ke Queue N (max 5)?\nBanyak elemen: ");
    scanf(" %d", &X);
    enqueue2N(&N,X);
    PrintAll(N);

    createQueue2(&A);
    printf("\n\n***** Queue A *****\n");
    enqueue2(&A,'K'); enqueue2(&A,'A'); enqueue2(&A,'M'); enqueue2(&A,'B'); enqueue2(&A,'I'); enqueue2(&A,'N'); enqueue2(&A,'G');
    dequeue2(&A,&c); dequeue2(&A,&c); dequeue2(&A,&c); dequeue2(&A,&c); 
    PrintAll(A);

    printf("\n\n***** Predikat isEqual *****\n");
    printf("\nKita akan membandingkan Queue Q dan A\n");
    createQueue2(&Q); 
    enqueue2(&Q,'P'); enqueue2(&Q,'I'); enqueue2(&Q,'K');
    printf("Queue Q: "); printQueue2(Q);

    createQueue2(&A);
    enqueue2(&A,'S'); enqueue2(&A,'A'); enqueue2(&A,'P'); enqueue2(&A,'I'); enqueue2(&A,'K'); 
    dequeue2(&A,&c); dequeue2(&A,&c);
    printf("Queue A: "); printQueue2(A);

    printf("Apakah Queue Q dan A Equal? "); YesORYes(isEqualQueue2(Q,A));
    return 0;
}