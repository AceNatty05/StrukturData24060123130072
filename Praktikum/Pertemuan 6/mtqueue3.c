/* Program   : mtqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 04//10/2024*/

#include "tqueue3.c"

int main(){
    /*KAMUS*/
    tqueue3 A, B, C;
    char c;
    int N;

    /*ALGORITMA*/
    printf("\n***** SELAMAT DATANG DRIVER PROGRAM TQUEUE MODEL 3 *****\n");
    
    printf("\n***** Queue A *****\n");
    createQueue3(&A);
    PrintAll(A);
    printf("----- Awalnya Queue A kosong -----\n");
    enqueue3(&A,'A'); enqueue3(&A,'Y'); enqueue3(&A,'A'); enqueue3(&A,'M');
    printf("----- Setelah dienqueue 4 kali Queue A menjadi -----\n");
    PrintAll(A);

    printf("\n***** Queue B *****\n");
    createQueue3(&B);
    printf("----- Awalnya Queue B kosong -----\n");
    printQueue3(B);
    printf("----- Setelah dienqueue 3 kali Queue B menjadi -----\n");
    enqueue3(&B,'G'); enqueue3(&B,'E'); enqueue3(&B,'P');
    printQueue3(B);
    printf("----- Lalu kita dequeue Queue B 2 kali menjadi -----\n");
    dequeue3(&B,&c); dequeue3(&B,&c); 
    printQueue3(B);
    printf("----- Terakhir kita enqueue 3 kali Queue B menjadi -----\n");
    enqueue3(&B,'R'); enqueue3(&B,'E'); enqueue3(&B,'K');
    PrintAll(B);

    printf("\n***** Queue C *****\n");
    createQueue3(&C);
    printf("----- Awalnya Queue C kosong -----\n");
    printQueue3(C);
    printf("----- Setelah dienqueue 5 kali Queue C menjadi -----\n");
    enqueue3(&C,'P'); enqueue3(&C,'E'); enqueue3(&C,'T'); enqueue3(&C,'I'); enqueue3(&C,'R');
    printQueue3(C);
    printf("----- Lalu kita dequeue Queue C 2 kali menjadi -----\n");
    dequeue3(&C,&c); dequeue3(&C,&c);
    PrintAll(C);

    printf("\n***** Kita coba isTailOverHead dan enqueue3E pada Queue B dan C *****\n");
    printf("----- Awalnya Queue B -----\n"); 
    PrintAll(B); printf("> Apakah Tail over Head? Jawaban: "); YesORYes(isTailOverHead(B));
    printf("Masukkan elemen E untuk enqueue3E pada Queue B: "); scanf(" %c",&c);
    enqueue3E(&B,c);
    printf("----- Setelah enqueue3E Queue B menjadi -----\n"); 
    PrintAll(B); printf("> Apakah Tail over Head? Jawaban: "); YesORYes(isTailOverHead(B));
    printf("----- Awalnya Queue C -----\n"); 
    PrintAll(C); printf("> Apakah Tail over Head? Jawaban: "); YesORYes(isTailOverHead(C));
    printf("Masukkan elemen E untuk enqueue3E pada Queue C: "); scanf(" %c",&c);
    enqueue3E(&C,c);
    printf("----- Setelah enqueue3E Queue C menjadi -----\n"); 
    PrintAll(C); printf("> Apakah Tail over Head? Jawaban: "); YesORYes(isTailOverHead(C));
     
    return 0;
}