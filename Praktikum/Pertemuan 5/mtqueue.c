/* Program   : mtqueue.c */
/* Deskripsi : Driver Program Tqueue model 1 */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 27//09/2024*/

#include <string.h>
#include "tqueue.c"

// void populateRandomQueue(tqueue *Q, int N){
//     /*Kamus Lokal*/
//     int i;
//     // char randomChar = 'a' + (rand() % 26); // Fungsi rand huruf kecil 
//     // char randomUppercase = 'A' + (rand() % 26); // Huruf kapital acak
//     // char randomDigit = '0' + (rand() % 10); // Angka acak
//     // char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//     // int length = sizeof(characters) - 1;
//     // char randomChar = characters[rand() % length]; // Memunculkan karakter acak dari array characters


//     /*Algoritma*/
//     i = N;
//     while(!isFullQueue(*Q) && i>0){
//         enqueue(Q,'a' + (rand() % 26));
//         i--;
//     }
// }

// void populateManualQueue(tqueue *Q, int N){
//     /*Kamus Lokal*/
//     /*Algoritma*/
// }

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

void kondisiQueue(tqueue Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    printf("Wadah: "); printQueue(Q); printf("\n");
    printf("Queue: "); viewQueue(Q); printf("\n");
    printf("Head: %d\n", head(Q)); 
    printf("Tail: %d\n", tail(Q));
    printf("Size: %d\n", sizeQueue(Q));
    printf("InfoHead: %c\n", infoHead(Q));
    printf("InfoTail: %c\n", infoTail(Q));
    printf("Apakah Queue kosong?\nJawaban: "); YesORYes(isEmptyQueue(Q));
    printf("Apakah Queue penuh?\nJawaban: "); YesORYes(isFullQueue(Q));
    printf("Apakah Queue berisi 1 elemen saja?\nJawaban: "); YesORYes(isOneElement(Q));
}

void Menu5(tqueue *Q1, tqueue *Q2, char c){
    /*Kamus Lokal*/
    /*Algoritma*/
    viewQueue(*Q1); printf(" <~~~~ [ %c ]\n", c);
    viewQueue(*Q2); printf(" <~~~~ [ %c ]\n", c);
    enqueue2(Q1,Q2,c); printf("Menjadi\n");
    viewQueue(*Q1); printf("\n");
    viewQueue(*Q2); printf("\n");
}

void Menu6(tqueue *Q1, tqueue *Q2, char *c){
    /*Kamus Lokal*/
    /*Algoritma*/
    viewQueue(*Q1); printf("\n");
    viewQueue(*Q2); printf("\n");
    dequeue2(Q1,Q2,c); printf("Menjadi\n");
    viewQueue(*Q1); printf(" ~~~~> [ %c ]\n", c);
    viewQueue(*Q2); printf(" ~~~~> [ %c ]\n", c);
}

int main(){
    /*KAMUS*/
    int i;
    char c, Menu, ChoiceQ, Choice2;
    tqueue A, B, C;

    /*ALGORITMA*/

    printf("SELAMAT DATANG DRIVER PROGRAM TQUEUE MODEL 1\n\n");

    // Inisialisasi
    Menu = '0';
    createQueue(&A); createQueue(&B); createQueue(&C);

    // Informasi Awal
    printf("----- ----- ASUMSI & INFORMASI AWAL ----- -----\nMerupakan Queue karakter\nElemen - melambangkan elemen kosong\nWadah maksimal menampung 10 elemen\nTerdapat TIGA Queue yang disediakan yaitu A, B, dan C\nDriver program Queue model 1 ini dibuat secara dinamis\n\n");

    printf("***** Queue A *****\n"); 
    printf("Wadah: "); printQueue(A); printf("\n");
    printf("Queue: "); viewQueue(A); printf("\n");
    printf("Size: %d\n", sizeQueue(A));
    printf("\n***** Queue B *****\n"); 
    printf("Wadah: "); printQueue(A); printf("\n");
    printf("Queue: "); viewQueue(A); printf("\n");
    printf("Size: %d\n", sizeQueue(A));
    printf("\n***** Queue B *****\n");
    printf("Wadah: "); printQueue(A); printf("\n");
    printf("Queue: "); viewQueue(A); printf("\n");
    printf("Size: %d\n", sizeQueue(A));
    printf("\nKetiga Queue awalnya merupakan QUEUE KOSONG\n\n");

    printf("----- ----- MEMULAI PROGRAM QUEUE ----- -----\n\n"); 
    // Pilihan Menu
    printf("----- ----- MENAMPILKAN MENU YANG BISA DIPILIH ----- -----\n");
    printf("---- MENU ----- ----- DESKRIPSI -----\n");
    printf("       1      : Menampilkan kondisi Queue\n");
    printf("       2      : Enqueue tipe 0 Queue\n");
    printf("       3      : Dequeue tipe 0 Queue\n");
    printf("       4      : Enqueue tipe 1 Queue\n");
    printf("       5      : Enqueue tipe 2 Queue\n");
    printf("       6      : Dequeue tipe 2 Queue\n");
    // printf("       7      : Enqueue N times random\n");
    // printf("       8      : Enqueue N times manual\n");
    printf("       Q      : Keluar dari program\n\n");

    // Loop Menu
    while(Menu != 'Q'){
        printf("Menu yang dipilih: "); scanf(" %c", &Menu);
        printf("\n");

        if     (Menu == '1'){
            printf("       1      : Menampilkan kondisi Queue\n");
            printf("Terdapat Queue A, B, dan C\nQueue yang dipilih: ");
            scanf (" %c", &ChoiceQ);
            
            if(ChoiceQ == 'A'){
                kondisiQueue(A);
            }
            else if(ChoiceQ == 'B'){
                kondisiQueue(B);
            }
            else if(ChoiceQ == 'C'){
                kondisiQueue(C);
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        else if(Menu == '2'){
            printf("       2      : Enqueue tipe 0 Queue\nCiri khas: Tipe 0 tidak ada ciri khas\n");
            printf("Terdapat Queue A, B, dan C\nQueue yang dipilih: ");
            scanf (" %c", &ChoiceQ);
            printf("Elemen untuk enqueu: "); scanf(" %c", &c);

            if(ChoiceQ == 'A'){
                viewQueue(A); printf(" <~~~~ [ %c ]", c);
                enqueue(&A,c); viewQueue(A); printf("\n");
            }
            else if(ChoiceQ == 'B'){
                viewQueue(B); printf(" <~~~~ [ %c ]", c);
                enqueue(&B,c); viewQueue(B); printf("\n");
            }
            else if(ChoiceQ == 'C'){
                viewQueue(C); printf(" <~~~~ [ %c ]", c);
                enqueue(&C,c); viewQueue(C); printf("\n");
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        else if(Menu == '3'){
            printf("       3      : Dequeue tipe 0 Queue\nCiri khas: Tipe 0 tidak ada ciri khas\n");
            printf("Terdapat Queue A, B, dan C\nQueue yang dipilih: ");
            scanf (" %c", &ChoiceQ);

            if(ChoiceQ == 'A'){
                viewQueue(A); printf("\n"); dequeue(&A,&c);
                viewQueue(A); printf(" ~~~~> [ %c ]\n", c);
            }
            else if(ChoiceQ == 'B'){
                viewQueue(B); printf("\n"); dequeue(&B,&c);
                viewQueue(B); printf(" ~~~~> [ %c ]\n", c);
            }
            else if(ChoiceQ == 'C'){
                viewQueue(C); printf("\n"); dequeue(&C,&c);
                viewQueue(C); printf(" ~~~~> [ %c ]\n", c);
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        else if(Menu == '4'){
            printf("       4      : Enqueue tipe 1 Queue\nCiri khas: Jika Queue penuh, enqueue head\n");
            printf("Terdapat Queue A, B, dan C\nQueue yang dipilih: ");
            scanf (" %c", &ChoiceQ);
            printf("Elemen untuk enqueu: "); scanf(" %c", &c);

            if(ChoiceQ == 'A'){
                viewQueue(A); printf(" <~~~~ [ %c ]\n", c);
                enqueue1(&A,c); viewQueue(A); printf("\n");
            }
            else if(ChoiceQ == 'B'){
                viewQueue(B); printf(" <~~~~ [ %c ]\n", c);
                enqueue1(&B,c); viewQueue(B); printf("\n");
            }
            else if(ChoiceQ == 'C'){
                viewQueue(C); printf(" <~~~~ [ %c ]\n", c);
                enqueue1(&C,c); viewQueue(C); printf("\n");
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        else if(Menu == '5'){
            printf("       5      : Enqueue tipe 2 Queue\nCiri khas: Terdapat 2 queue, enqueue ke queue terpendek\n");
            printf("Elemen untuk enqueu: "); scanf(" %c", &c);
            printf("Terdapat Queue A, B, dan C\n");
            printf("Pilih 2 Queue\nQueue 1 yang dipilih: "); scanf (" %c", &ChoiceQ); 

            if     (ChoiceQ == 'A'){
                printf("Queue 2 yang dipilih: "); scanf (" %c", &ChoiceQ);
                if     (ChoiceQ == 'A'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else if(ChoiceQ == 'B'){
                    Menu5(&A,&B,c);
                }
                else if(ChoiceQ == 'C'){
                    Menu5(&A,&C,c);
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else if(ChoiceQ == 'B'){
                printf("Queue 2 yang dipilih: "); scanf (" %c", &ChoiceQ);
                if     (ChoiceQ == 'A'){
                    Menu5(&B,&A,c);
                }
                else if(ChoiceQ == 'B'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else if(ChoiceQ == 'C'){
                    Menu5(&B,&C,c);
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else if(ChoiceQ == 'C'){
                if     (ChoiceQ == 'A'){
                    Menu5(&C,&A,c);
                }
                else if(ChoiceQ == 'B'){
                    Menu5(&C,&B,c);
                }
                else if(ChoiceQ == 'C'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        else if(Menu == '6'){
            printf("       6      : Dequeue tipe 2 Queue\nCiri khas: Terdapat 2 queue, dequeue queue terpanjang\n");
            printf("Terdapat Queue A, B, dan C\nPilih 2 Queue\nQueue 1 yang dipilih: ");
            scanf (" %c", &ChoiceQ); 

            if     (ChoiceQ == 'A'){
                printf("Queue 2 yang dipilih: "); scanf (" %c", &ChoiceQ);
                if     (ChoiceQ == 'A'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else if(ChoiceQ == 'B'){
                    Menu6(&A,&B,&c);
                }
                else if(ChoiceQ == 'C'){
                    Menu6(&A,&C,&c);
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else if(ChoiceQ == 'B'){
                printf("Queue 2 yang dipilih: "); scanf (" %c", &ChoiceQ);
                if     (ChoiceQ == 'A'){
                    Menu6(&B,&A,&c);
                }
                else if(ChoiceQ == 'B'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else if(ChoiceQ == 'C'){
                    Menu6(&B,&C,&c);
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else if(ChoiceQ == 'C'){
                if     (ChoiceQ == 'A'){
                    Menu6(&C,&A,&c);
                }
                else if(ChoiceQ == 'B'){
                    Menu6(&C,&B,&c);
                }
                else if(ChoiceQ == 'C'){
                    printf("Harus 2 Queue yang berbeda\n");
                }
                else{
                    printf("Tidak ada Queue %c\n", ChoiceQ);
                }
            }
            else{
                printf("Tidak ada Queue %c\n", ChoiceQ);
            }

            printf("\n");
        }
        // else if(Menu == '7')
        // else if(Menu == '8')
        else if(Menu == 'Q'){
            printf("Keluar dari program.... .\n\n");
        }
    
    }

    return 0;
}