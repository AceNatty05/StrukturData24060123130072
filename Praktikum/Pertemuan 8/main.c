/* File         : main.c */
/* Deskripsi    : driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama   : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal      : 06/11/2024*/

#include "list2.c"

int main() {
    //KAMUS
    char C, D, E[10], Input[10];
    address P;
    List2 Senarai, Copy;

    //ALGORITMA

    // CreateList
    CreateList(&Senarai); 

    // InsertVFirst & InsertVLast
    InsertVFirst(&Senarai,'A'); InsertVFirst(&Senarai,'B'); InsertVFirst(&Senarai,'C'); InsertVFirst(&Senarai,'D');
    InsertVLast(&Senarai,'E'); InsertVLast(&Senarai,'F'); InsertVLast(&Senarai,'G'); InsertVLast(&Senarai,'H');
    PrintList(Senarai); printf("\n");
    printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // DeleteVFirst
    // DeleteVFirst(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVFirst(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVFirst(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVFirst(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // DeleteVLast
    // DeleteVLast(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVLast(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVLast(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // DeleteVLast(&Senarai,&C);  
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // Predikat IsEmptyList & IsOneElm
    // if (IsEmptyList(Senarai)) {
    //     printf("List Kosong\n");
    // } else {
    //     if (IsOneElm(Senarai)) {
    //         printf("List satu elemen\n");
    //     } else {
    //         printf("List lebih dari 1 elemen\n");
    //     }
    // }

    // // DeleteX
    // printf("Masukkan X : "); scanf(" %c", &C);
    // DeleteX(&Senarai,C);
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // SearchX
    // printf("Masukkan X: "); scanf(" %c", &C);
    // SearchX(Senarai, C, &P);
    // if (info(P) == C) {
    //     printf("%c ditemukan di Senarai di address %p\n", C, P);
    // }
    // else {
    //     printf("%c tidak ditemukan di Senarai\n", C);
    // }

    // // UpdateX
    // printf("Masukkan X : "); scanf(" %c", &C);
    // printf("Masukkan Y : "); scanf(" %c", &D);
    // UpdateX(&Senarai,C,D);
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // Invers
    // printf("Invers\n");
    // Invers(&Senarai);
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // Untuk testing CountX
    // InsertVFirst(&Senarai,'A'); InsertVLast(&Senarai,'A'); InsertVFirst(&Senarai,'A'); InsertVLast(&Senarai,'A'); 
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // CountX & FrekuensiX
    // printf("Masukkan X : "); scanf(" %c", &C);
    // printf("Banyak elemen %c dalam Senarai : %d dengan frekuensi %.2f\n", C, CountX(Senarai,C), FrekuensiX(Senarai,C));

    // CountVocal & CountNG

    // // Insert/DeleteVAfter/Before
    // printf("Masukkan X : "); scanf(" %c", &C);
    // printf("Masukkan V : "); scanf(" %c", &D);
    // InsertVAfterX(&Senarai,C,D);
    // InsertVBeforeX(&Senarai,C,D);
    // DeleteVAfterX(&Senarai,C,&D);
    // DeleteVBeforeX(&Senarai,C,&D);
    // PrintList(Senarai); printf("\n");
    // printf("Panjang Senarai : %d\n", NbElm(Senarai));

    // // SearchAllX
    // printf("Masukkan X : "); scanf(" %c", &C);
    // SearchAllX(Senarai,C); printf("\n");

    // Insert
    printf("Masukkan X : "); scanf(" %s", &E); C = E[0];
    InsertVFirst(&Senarai,C); ShowStat(Senarai);

    ShowStat(Senarai);

    DeleteList(&Senarai);
    PrintList(Senarai); printf("\n");
    printf("Panjang Senarai : %d\n", NbElm(Senarai));

    return 0;
}