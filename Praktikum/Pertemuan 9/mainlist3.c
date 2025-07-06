/* File : mainlist3.c */
/* Deskripsi : driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 16/11/2024*/

#include "string.h"
#include "list3.c"

int main () {
    //KAMUS 
    char X, V, Y, Input[10], Menu[10]; // untuk handling input user yang kadang tidak sesuai ukurannya
    address a, b, c;
    List3 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P;
    //ALGORITMA

    // Inisialisasi
    strcpy(Menu, "0");
    CreateList(&A); CreateList(&B); CreateList(&C); CreateList(&D); 
    CreateList(&E); CreateList(&F); CreateList(&G); CreateList(&H);
    CreateList(&I); CreateList(&J); CreateList(&K); CreateList(&L);
    CreateList(&M); CreateList(&N); CreateList(&O); CreateList(&P);
    
    // Mengisi beberapa list untuk persediaan
    InsertVLast(&A,'B'); InsertVLast(&A,'U'); InsertVLast(&A,'B'); InsertVLast(&A,'U'); InsertVLast(&A,'R');
    InsertVLast(&B,'A'); InsertVLast(&B,'Y'); InsertVLast(&B,'A'); InsertVLast(&B,'M');
    InsertVLast(&C,'A'); InsertVLast(&C,'Z');
    InsertVLast(&D,'X');

    InsertVLast(&E,'U'); InsertVLast(&E,'V'); InsertVLast(&E,'U'); InsertVLast(&E,'V'); InsertVLast(&E,'W'); InsertVLast(&E,'E'); InsertVLast(&E,'V'); InsertVLast(&E,'W'); InsertVLast(&E,'E'); InsertVLast(&E,'V'); InsertVLast(&E,'W'); InsertVLast(&E,'E'); 
    InsertVLast(&F,'O'); InsertVLast(&F,'N'); InsertVLast(&F,'Y'); InsertVLast(&F,'E'); InsertVLast(&F,'T'); InsertVLast(&F,'E'); InsertVLast(&F,'N'); InsertVLast(&F,'Y'); InsertVLast(&F,'E'); InsertVLast(&F,'V'); InsertVLast(&F,'W'); InsertVLast(&F,'E');
    InsertVLast(&G,'U'); InsertVLast(&G,'G'); InsertVLast(&G,'W'); InsertVLast(&G,'E'); InsertVLast(&G,'M'); InsertVLast(&G,'U'); InsertVLast(&G,'H'); InsertVLast(&G,'W'); InsertVLast(&G,'E'); InsertVLast(&G,'M');
    InsertVLast(&H,'O'); InsertVLast(&H,'S'); InsertVLast(&H,'O'); InsertVLast(&H,'S');

    InsertVLast(&I,'N'); InsertVLast(&I,'G'); InsertVLast(&I,'A'); InsertVLast(&I,'N'); InsertVLast(&I,'G'); InsertVLast(&I,'B'); InsertVLast(&I,'C'); InsertVLast(&I,'N'); InsertVLast(&I,'G');
    InsertVLast(&J,'X'); InsertVLast(&J,'N'); InsertVLast(&J,'G'); InsertVLast(&J,'Y'); InsertVLast(&J,'N'); InsertVLast(&J,'G'); InsertVLast(&J,'Z'); InsertVLast(&J,'N'); InsertVLast(&J,'G'); InsertVLast(&J,'W');
    InsertVLast(&K,'G'); InsertVLast(&K,'N'); InsertVLast(&K,'G'); InsertVLast(&K,'M'); InsertVLast(&K,'N'); InsertVLast(&K,'O'); InsertVLast(&K,'N');
    InsertVLast(&L,'G'); InsertVLast(&L,'N');

    // Loop Menu
    ShowMenu(); printf("\n");
    while (strcmp(Menu, "Q") != 0) {
        printf("** Masukan pilihan menu: ");
		scanf (" %s", &Menu); printf("\n");
    
        if     (strcmp(Menu, "1") == 0) {
            printf("   1    : InsertVFirst\n");
            printf("Tersedia 4 list untuk InsertVFirst\n");
            printf("List A :\n"); PrintList(A);
            printf("List B :\n"); PrintList(B);
            printf("List C :\n"); PrintList(D);
            printf("List D :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(A,&M); InsertVFirst(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(B,&M); InsertVFirst(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(D,&M); InsertVFirst(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(O,&M); InsertVFirst(&M,X); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "2") == 0) {
            printf("   2    : InsertVLast\n");
            printf("Tersedia 4 list untuk InsertVLast\n");
            printf("List A :\n"); PrintList(A);
            printf("List B :\n"); PrintList(B);
            printf("List C :\n"); PrintList(D);
            printf("List D :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(A,&M); InsertVLast(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(B,&M); InsertVLast(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(D,&M); InsertVLast(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); 
                X = Input[0]; CopyList(O,&M); InsertVLast(&M,X); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "3") == 0) {
            printf("   3    : InsertVAfterX\n");
            printf("Tersedia 5 list untuk InsertVAfterX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(E,&M); InsertVAfterX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(F,&M); InsertVAfterX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(G,&M); InsertVAfterX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(H,&M); InsertVAfterX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(O,&M); InsertVAfterX(&M,X,V); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "4") == 0) {
            printf("   4    : InsertVBeforeX\n");
            printf("Tersedia 5 list untuk InsertVBeforeX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(E,&M); InsertVBeforeX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(F,&M); InsertVBeforeX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(G,&M); InsertVBeforeX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(H,&M); InsertVBeforeX(&M,X,V); ShowStat(M);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan V : "); scanf(" %s", &Input); V = Input[0];
                CopyList(O,&M); InsertVBeforeX(&M,X,V); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "5") == 0) {
            printf("   5    : DeleteVFirst\n");
            printf("Tersedia 5 list untuk DeleteVFirst\n");
            printf("List A :\n"); PrintList(A);
            printf("List B :\n"); PrintList(B);
            printf("List C :\n"); PrintList(C);
            printf("List D :\n"); PrintList(D);
            printf("List E :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(A,&M); DeleteVFirst(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(B,&M); DeleteVFirst(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(C,&M); DeleteVFirst(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(D,&M); DeleteVFirst(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(O,&M); DeleteVFirst(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "6") == 0) {
            printf("   6    : DeleteVLast\n");
            printf("Tersedia 5 list untuk DeleteVLast\n");
            printf("List A :\n"); PrintList(A);
            printf("List B :\n"); PrintList(B);
            printf("List C :\n"); PrintList(C);
            printf("List D :\n"); PrintList(D);
            printf("List E :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(A,&M); DeleteVLast(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(B,&M); DeleteVLast(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(C,&M); DeleteVLast(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(D,&M); DeleteVLast(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(O,&M); DeleteVLast(&M,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "7") == 0) {
            printf("   7    : DeleteVAfterX\n");
            printf("Tersedia 6 list untuk DeleteVAfterX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); DeleteVAfterX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "8") == 0) {
            printf("   8    : DeleteVBeforeX\n");
            printf("Tersedia 6 list untuk DeleteVBeforeX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); DeleteVBeforeX(&M,X,&V); ShowStat(M);
                printf("Isi V : %c\n", V);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "9") == 0) {
            printf("   9    : DeleteX\n");
            printf("Tersedia 6 list untuk DeleteX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); DeleteX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); DeleteX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); DeleteX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); DeleteX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); DeleteX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); DeleteX(&M,X); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "10") == 0) {
            printf("   10   : DeleteAllX\n");
            printf("Tersedia 6 list untuk DeleteAllX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); DeleteAllX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); DeleteAllX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); DeleteAllX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); DeleteAllX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); DeleteAllX(&M,X); ShowStat(M);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); DeleteAllX(&M,X);ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "11") == 0) {
            printf("   11   : SearchX\n");
            printf("Tersedia 6 list untuk SearchX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); SearchX(M,X,&a);
                if (a != NIL) { // ketemu
                    printf("Karakter %c ditemukan di list %s di address %p\n", info(a), Input, a);
                }
                else {
                    printf("Karakter %c tidak ditemukan di list %s\n", info(a), Input);
                }
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "12") == 0) {
            printf("   12   : SearchAllX\n");
            printf("Tersedia 6 list untuk SearchAllX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M); SearchAllX(M,X);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); SearchAllX(M,X);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); SearchAllX(M,X);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); SearchAllX(M,X);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); SearchAllX(M,X);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); SearchAllX(M,X);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "13") == 0) {
            printf("   13   : UpdateX\n");
            printf("Tersedia 6 list untuk UpdateX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(E,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(F,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(G,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(H,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(D,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                printf("** Masukkan Y : "); scanf(" %s", &Input); Y = Input[0];
                CopyList(O,&M); UpdateX(&M,X,Y); ShowStat(M);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "14") == 0) {
            printf("   14   : CountX & FrekuensiX\n");
            printf("Tersedia 6 list untuk CountX & FrekuensiX\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(E,&M);
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(F,&M); 
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(G,&M); 
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(H,&M); 
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else if (strcmp(Input, "E") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(D,&M); 
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else if (strcmp(Input, "F") == 0) {
                printf("** Masukkan X : "); scanf(" %s", &Input); X = Input[0];
                CopyList(O,&M); 
                printf("Banyak elemen %c dalam list %s adalah %d dengan frekuensi %.2f\n", X, Input, CountX(M,X), FrekuensiX(M,X));
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "15") == 0) {
            printf("   15   : CountVocal\n");
            printf("Tersedia 6 list untuk CountVocal\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(E,&M);
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(F,&M); 
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(G,&M); 
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(H,&M); 
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(D,&M); 
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else if (strcmp(Input, "F") == 0) {
                CopyList(O,&M); 
                printf("Banyak elemen vocal dalam list %s adalah %d\n", Input, CountVocal(M));
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "16") == 0) {
            printf("   16   : CountNG\n");
            printf("Tersedia 6 list untuk CountNG\n");
            printf("List A :\n"); PrintList(I);
            printf("List B :\n"); PrintList(J);
            printf("List C :\n"); PrintList(K);
            printf("List D :\n"); PrintList(L);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(I,&M);
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(J,&M); 
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(K,&M); 
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(L,&M); 
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(D,&M); 
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else if (strcmp(Input, "F") == 0) {
                CopyList(O,&M); 
                printf("Banyak NG dalam list %s adalah %d\n", Input, CountNG(M));
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "17") == 0) {
            printf("   17   : Maxmember & Modus\n");
            printf("Tersedia 6 Maxmember & Modus\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(D);
            printf("List F :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(E,&M);
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(F,&M); 
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(G,&M); 
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(H,&M); 
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(D,&M); 
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else if (strcmp(Input, "F") == 0) {
                CopyList(O,&M); 
                printf("Pada list %s Modusnya adalah %c dengan kemunculan %d kali\n", Input, Modus(M), MaxMember(M));
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "18") == 0) {
            printf("   18   : Invers\n");
            printf("Tersedia 6 list untuk Invers\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(A);
            printf("List F :\n"); PrintList(B);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(E,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M); 
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(F,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M);  
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(G,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M);   
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(H,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M);   
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(D,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M);  
            }
            else if (strcmp(Input, "F") == 0) {
                CopyList(O,&M); printf("Awalanya list %s:\n", Input); ShowStat(M); 
                Invers(&M); printf("Setelah Invers list %s menjadi:\n", Input); ShowStat(M);    
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "19") == 0) {
            printf("   19   : ConcatList\n");
            printf("Tersedia 6 list untuk ConcatList\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(A);
            printf("List F :\n"); PrintList(B);
            printf("Pilihan ConcatList\n");
            printf(" 1 : A dengan B\n");
            printf(" 2 : C dengan D\n");
            printf(" 2 : E dengan F\n");
            printf("** Pilihan Concat : "); scanf(" %s", &Input);
            if      (strcmp(Input, "1") == 0) {
                CopyList(E,&M); CopyList(F,&N); printf("Awalnya list A dan B:\n"); ShowStat(M); ShowStat(N); 
                printf("Lalu setelah keduanya concat ke list P menjadi:\n"); ConcatList(M,N,&P); ShowStat(P);    
            }
            else if (strcmp(Input, "2") == 0) {
                CopyList(G,&M); CopyList(H,&N); printf("Awalnya list C dan D:\n"); ShowStat(M); ShowStat(N); 
                printf("Lalu setelah keduanya concat ke list P menjadi:\n"); ConcatList(M,N,&P); ShowStat(P);   
            }
            else if (strcmp(Input, "3") == 0) {
                CopyList(A,&M); CopyList(B,&N); printf("Awalnya list E dan F:\n"); ShowStat(M); ShowStat(N); 
                printf("Lalu setelah keduanya concat ke list P menjadi:\n"); ConcatList(M,N,&P); ShowStat(P);    
            }
            else {
                printf("Tidak ada pilihan %s\n", Input);
            }
        }
        else if(strcmp(Menu, "20") == 0) {
            printf("   20   : SplitList\n");
            printf("Tersedia 5 list untuk SplitList ke list M dan N\n");
            printf("List A :\n"); PrintList(A);
            printf("List B :\n"); PrintList(B);
            printf("List C :\n"); PrintList(C);
            printf("List D :\n"); PrintList(D);
            printf("List E :\n"); PrintList(O);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(A,&P); printf("Awalnya list %s:\n", Input); ShowStat(P);
                printf("Setelah itu displit ke list M dan N menjadi:\n"); 
                SplitList(P,&M,&N); ShowStat(M); ShowStat(N);
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(B,&P); printf("Awalnya list %s:\n", Input); ShowStat(P);
                printf("Setelah itu displit ke list M dan N menjadi:\n"); 
                SplitList(P,&M,&N); ShowStat(M); ShowStat(N);
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(C,&P); printf("Awalnya list %s:\n", Input); ShowStat(P);
                printf("Setelah itu displit ke list M dan N menjadi:\n"); 
                SplitList(P,&M,&N); ShowStat(M); ShowStat(N);
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(D,&P); printf("Awalnya list %s:\n", Input); ShowStat(P);
                printf("Setelah itu displit ke list M dan N menjadi:\n"); 
                SplitList(P,&M,&N); ShowStat(M); ShowStat(N);
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(O,&P); printf("Awalnya list %s:\n", Input); ShowStat(P);
                printf("Setelah itu displit ke list M dan N menjadi:\n"); 
                SplitList(P,&M,&N); ShowStat(M); ShowStat(N);
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "21") == 0) {
            printf("   21   : CopyList\n");
            printf("Tersedia 6 list untuk CopyList ke list M\n");
            printf("List A :\n"); PrintList(E);
            printf("List B :\n"); PrintList(F);
            printf("List C :\n"); PrintList(G);
            printf("List D :\n"); PrintList(H);
            printf("List E :\n"); PrintList(A);
            printf("List F :\n"); PrintList(B);
            printf("** Pilihan list : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                CopyList(E,&M); 
                printf("List A :\n"); PrintList(E); PrintAddressList(E);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);
            }
            else if (strcmp(Input, "B") == 0) {
                CopyList(F,&M); 
                printf("List B :\n"); PrintList(F); PrintAddressList(F);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);
            }
            else if (strcmp(Input, "C") == 0) {
                CopyList(G,&M); 
                printf("List C :\n"); PrintList(G); PrintAddressList(G);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);  
            }
            else if (strcmp(Input, "D") == 0) {
                CopyList(H,&M); 
                printf("List D :\n"); PrintList(H); PrintAddressList(H);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);    
            }
            else if (strcmp(Input, "E") == 0) {
                CopyList(A,&M); 
                printf("List E :\n"); PrintList(A); PrintAddressList(A);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);  
            }
            else if (strcmp(Input, "F") == 0) {
                CopyList(B,&M); 
                printf("List F :\n"); PrintList(B); PrintAddressList(B);
                printf("List M :\n"); PrintList(M); PrintAddressList(M);  
            }
            else {
                printf("Tidak ada pilihan list %s\n", Input);
            }
        }
        else if(strcmp(Menu, "M") == 0) {
            ShowMenu();
        }
        else if(strcmp(Menu, "Q") == 0) {
            DeleteList(&A); DeleteList(&B); DeleteList(&C); DeleteList(&D); 
            DeleteList(&E); DeleteList(&F); DeleteList(&G); DeleteList(&H);
            DeleteList(&I); DeleteList(&J); DeleteList(&K); DeleteList(&L);
            DeleteList(&M); DeleteList(&N); DeleteList(&O);
            printf("Keluar dari driver......\n");
        }
        else {
            printf("Tidak ada pilihan menu %s\n", Menu);
        }
        printf("\n");
    }

    // DEMI KESELAMATAN MEMORIKU YANG TIDAK SEBERAPA ITU
    DeleteList(&A); DeleteList(&B); DeleteList(&C); DeleteList(&D); 
    DeleteList(&E); DeleteList(&F); DeleteList(&G); DeleteList(&H);
    DeleteList(&I); DeleteList(&J); DeleteList(&K); DeleteList(&L);
    DeleteList(&M); DeleteList(&N); DeleteList(&O); DeleteList(&P);

    return 0;
}