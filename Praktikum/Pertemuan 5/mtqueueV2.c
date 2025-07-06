/* Program   : mtqueue.c */
/* Deskripsi : Driver Program Tqueue model 1 */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 27//09/2024*/

#include "tqueue.c"

void populateRandomQueue(tqueue *Q, int N){
    /*Kamus Lokal*/
    int i;
    // char randomChar = 'a' + (rand() % 26); // Fungsi rand huruf kecil 
    // char randomUppercase = 'A' + (rand() % 26); // Huruf kapital acak
    // char randomDigit = '0' + (rand() % 10); // Angka acak
    // char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    // int length = sizeof(characters) - 1;
    // char randomChar = characters[rand() % length]; // Memunculkan karakter acak dari array characters


    /*Algoritma*/
    i = N;
    while(!isFullQueue(*Q) && i>0){
        enqueue(Q,'a' + (rand() % 26));
        i--;
    }
}

void populateManualQueue(tqueue *Q, int N){
    /*Kamus Lokal*/
    /*Algoritma*/
}

void YesORYes(boolean b){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(b){
        printf("YA\n");
    }
    else{
        printf("TIDAK\n");
    }
}

int main(){
    /*KAMUS*/
    int i;
    char a, b, c;
    tqueue A, B, C;

    /*ALGORITMA*/

    printf("SELAMAT DATANG DRIVER PROGRAM TQUEUE MODEL 1\n\n");

    // Inisialisasi
    createQueue(&A); createQueue(&B); createQueue(&C);

    // Queue awal
    printf("----- INFORMASI AWAL QUEUE -----\nElemen - melambangkan elemen kosong\nWadah maksimal menampung 10 elemen\n\n");

    printf("***** Queue A *****\n"); 
    printf("Wadah: "); printQueue(A);
    printf("Queue: "); viewQueue(A);
    printf("Size: %d\n", sizeQueue(A));
    printf("\n***** Queue B *****\n"); 
    printf("Wadah: "); printQueue(A);
    printf("Queue: "); viewQueue(A);
    printf("Size: %d\n", sizeQueue(A));
    printf("\n***** Queue B *****\n");
    printf("Wadah: "); printQueue(A);
    printf("Queue: "); viewQueue(A);
    printf("Size: %d\n", sizeQueue(A));
    printf("\nKetiga Queue merupakan QUEUE KOSONG\n\n");

    printf("----- MEMULAI PENGISIAN QUEUE -----\n\n"); 

    printf("***** Queue A *****\nQueue A akan diisi huruf kecil random sebanyak 6 elemen\n");
    populateRandomQueue(&A,6);
    printf("Wadah: "); printQueue(A);
    printf("Queue: "); viewQueue(A);
    printf("Size: %d\n", sizeQueue(A));
    printf("Apakah Queue kosong?\nJawaban: "); YesORYes(isEmptyQueue(A));
    printf("Apakah Queue penuh?\nJawaban: "); YesORYes(isFullQueue(A));
    printf("Apakah Queue berisi 1 elemen saja?\nJawaban: "); YesORYes(isOneElement(A));

    printf("\n***** Queue B *****\nQueue B akan diisi random berapa elemen?\nJawaban: ");
    scanf (" %d", &i); populateRandomQueue(&B,i); 
    printf("Wadah: "); printQueue(B);
    printf("Queue: "); viewQueue(B);
    printf("Size: %d\n", sizeQueue(B));
    printf("Apakah Queue kosong?\nJawaban: "); YesORYes(isEmptyQueue(B));
    printf("Apakah Queue penuh?\nJawaban: "); YesORYes(isFullQueue(B));
    printf("Apakah Queue berisi 1 elemen saja?\nJawaban: "); YesORYes(isOneElement(B));

    printf("\n***** Queue B *****\nQueue C akan diisi secara manual sebanyak berapa elemen?\nJawaban: ");
    printf("Wadah: "); printQueue(A);
    printf("Queue: "); viewQueue(A);
    printf("Size: %d\n", sizeQueue(A));


    return 0;
}