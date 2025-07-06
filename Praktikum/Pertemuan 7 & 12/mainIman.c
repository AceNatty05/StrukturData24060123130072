/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : Muhammad Iman Sasongko */
/* Tanggal : Oktober 2024 */

#include <stdio.h>
#include "list1.h"
#include <string.h>
#include "list1.c"

int main() {
    List1 L, L1, L2;
    infotype X, Y;
    address A;
    int jumlah;
    float frekuensi;

    // Uji CreateList
    printf("Menguji CreateList...\n");
    CreateList(&L);
    if (IsEmptyList(L)) {
        printf("List berhasil dibuat dan kosong.\n");
    } else {
        printf("Gagal membuat list.\n");
    }

    

    // Uji InsertVFirst dan InsertVLast
    printf("Menguji InsertVFirst dan InsertVLast...\n");
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    PrintList(L);

    // Uji DeleteVFirst dan DeleteVLast
    printf("\nMenguji DeleteVFirst...\n");
    DeleteVFirst(&L, &X);
    printf("Elemen yang dihapus: %c\n", X);
    PrintList(L);

    printf("\nMenguji DeleteVLast...\n");
    DeleteVLast(&L, &X);
    printf("Elemen yang dihapus: %c\n", X);
    PrintList(L);

    // Uji SearchX
    printf("\nMenguji SearchX...\n");
    InsertVFirst(&L, 'D');
    InsertVLast(&L, 'E');
    SearchX(L, 'D', &A);
    if (A != NIL) {
        printf("Elemen 'D' ditemukan pada alamat: %p\n", A);
    } else {
        printf("Elemen 'D' tidak ditemukan.\n");
    }

    // Uji UpdateX
    printf("\nMenguji UpdateX...\n");
    UpdateX(&L, 'D', 'F');
    PrintList(L);

    // Uji Invers
    printf("\nMenguji Invers...\n");
    Invers(&L);
    PrintList(L);

    // Uji CountX dan FrekuensiX
    printf("\nMenguji CountX dan FrekuensiX...\n");
    jumlah = CountX(L, 'E');
    frekuensi = FrekuensiX(L, 'E');
    printf("Jumlah 'E': %d, Frekuensi: %.2f\n", jumlah, frekuensi);

    // Uji ConcatList
    printf("\nMenguji ConcatList...\n");
    CreateList(&L1);
    InsertVLast(&L1, 'X');
    InsertVLast(&L1, 'Y');
    ConcatList(L, L1, &L2);
    PrintList(L2);

    // Uji SplitList
    printf("\nMenguji SplitList...\n");
    SplitList(L2, &L, &L1);
    printf("List L setelah split:\n");
    PrintList(L);
    printf("\nList L1 setelah split:\n");
    PrintList(L1);

    // Uji CopyList
    printf("\nMenguji CopyList...\n");
    CopyList(L1, &L2);
    PrintList(L2);

    return 0;
}
