/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 04 November 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"

int main(){
  //KAMUS
  char C, D;
  address A;
  List1 W;
  List1 X;
  List1 Y;
  List1 Z;

  //ALGORITMA
  printf("~~~~~ Selamat Datang di Driver List 1 ~~~~~\n");
  printf("~~~~~ SELAMAT MEMBACA ~~~~~\n\n");

  // Inisialisasi List
  printf("~~~~~ CreateList ~~~~~\n");
  CreateList(&W); CreateList(&X); CreateList(&Y); CreateList(&Z);
  if(IsEmptyList(W) && IsEmptyList(X) && IsEmptyList(Y) && IsEmptyList(Z)){
    printf("List W, X, Y, Z berhasil dibuat\n\n");
  }

  // InsertVFirst, InsertVLast
  printf("~~~~~ InsertVFirst & InsertVLast ~~~~~\n");
  printf("List X InsertVFirst 3 kali dengan char A, B, C menghasilkan :\nX : ");
  InsertVFirst(&X,'A'); InsertVFirst(&X,'B'); InsertVFirst(&X,'C');
  PrintList(X); printf("\n");
  printf("Kemudian List X InsertVLast 3 kali dengan char D, E, F menghasilkan :\nX : ");
  InsertVLast(&X, 'D'); InsertVLast(&X, 'E'); InsertVLast(&X, 'F');  
  PrintList(X); printf("\n\n");

  // DeleteVFirst & DeleteVLast
  printf("~~~~~ DeleteVFirst & DeleteVLast ~~~~~\n");
  printf("Sebelum itu, InsertVLast List Y dan Z dengan char dari string AYAM GEPREK\n");
  InsertVLast(&Y, 'A'); InsertVLast(&Y, 'Y'); InsertVLast(&Y, 'A'); InsertVLast(&Y, 'M');  
  InsertVLast(&Z, 'G'); InsertVLast(&Z, 'E'); InsertVLast(&Z, 'P'); InsertVLast(&Z, 'R'); InsertVLast(&Z, 'E'); InsertVLast(&Z, 'K'); 
  printf("Y : "); PrintList(Y); printf("\n");     
  printf("Z : "); PrintList(Z); printf("\n");
  printf("Setelah DeleteVFirst List Y dan DeleteVFirst List Z masing-masing 2 kali, List Y & Z menjadi :\n");
  DeleteVFirst(&Y,&C); DeleteVFirst(&Y,&C); DeleteVLast(&Z,&C); DeleteVLast(&Z,&C);
  printf("Y : "); PrintList(Y); printf("\n");     
  printf("Z : "); PrintList(Z); printf("\n\n");

  // NbELm
  printf("Banyak elemen List X : %d\n", NbElm(X));
  printf("Banyak elemen List Y : %d\n", NbElm(Y));
  printf("Banyak elemen List Z : %d\n\n", NbElm(Z));

  // SearchX
  printf("~~~~~ SearchX ~~~~~\n");
  printf("Mencari elemen pada List Z\nMasukkan elemen yang dicari : ");
  scanf(" %c", &C); SearchX(Z,C,&A); // ADAorTIDAK(A != NIL); 
  if(info(A) == C){
    printf("%c ADA di List Z, ditemukan di alamat memory %p\n\n", info(A), A);
  }
  else{
    printf("TIDAK ADA\n\n");
  }

  // UpdateX
  printf("~~~~~ UpdateX ~~~~~\n");
  printf("Mengganti elemen A pertama pada List X menjadi B\nMasukkan A : ");
  scanf(" %c", &C); printf("Masukkan B : "); scanf(" %c", &D);
  printf("Awalnya List X : \n");
  printf("X : "); PrintList(X); printf("\n"); 
  UpdateX(&X,C,D);
  printf("Setelah UpdateX : \n");
  printf("X : "); PrintList(X); printf("\n\n");

  // Invers
  printf("~~~~~ Invers ~~~~~\n");
  printf("List X awalnya :\n");
  printf("X : "); PrintList(X); printf("\n");
  printf("Setelah Invers menjadi :\n");
  Invers(&X);
  printf("X : "); PrintList(X); printf("\n\n");

  // CountX & FrekuensiX
  printf("~~~~~ CountX & FrekuensiX ~~~~~\n"); 
  printf("Menghitung banyaknya elemen A dan frekuensinya pada List X, Y, Z\nElemen A : ");
  scanf(" %c", &C);
  printf("Elemen %c muncul pada list X sebanyak %d kali dengan frekuensi %.2f\n", C, CountX(X,C), FrekuensiX(X,C));
  printf("Elemen %c muncul pada list Y sebanyak %d kali dengan frekuensi %.2f\n", C, CountX(Y,C), FrekuensiX(Y,C));
  printf("Elemen %c muncul pada list Z sebanyak %d kali dengan frekuensi %.2f\n\n", C, CountX(Z,C), FrekuensiX(Z,C));

  // SearchAllX
  printf("~~~~~ SearchAllX ~~~~~\n"); 
  printf("Mencari posisi semua elemen A di List X, Y, Z\nMasukkan elemen A : ");
  scanf(" %c", &C);
  printf("Posisi elemen %c pada List X : ", C); SearchAllX(X,C); printf("\n");
  printf("Posisi elemen %c pada List Y : ", C); SearchAllX(Y,C); printf("\n");
  printf("Posisi elemen %c pada List Z : ", C); SearchAllX(Z,C); printf("\n");

  // UpdateAllX
  printf("~~~~~ UpdateAllX ~~~~~\n");
  printf("Mengganti semua elemen A menjadi B pada list Z\nMasukkan nilai A : ");
  scanf(" %c", &C); printf("Masukkan nilai B : "); scanf(" %c", &D);
  printf("List Z awalnya :\nZ : "); PrintList(Z); printf("\n");
  UpdateAllX(&Z,C,D); 
  printf("Setelah diupdate menjadi :\nZ : "); PrintList(Z); printf("\n\n");

  // InsertVAfter
  printf("~~~~~ InsertVAfter ~~~~~\n");
  printf("Menambah elemen setelah V dengan elemen A pada List X\nMasukkan nilai V : ");
  scanf(" %c", &C); printf("Masukkan nilai A : "); scanf(" %c", &D);
  printf("List X awalnya :\nX : "); PrintList(X); printf("\n");
  InsertVAfter(&X,C,D);
  printf("Setelah diupdate menjadi :\nX : "); PrintList(X); printf("\n\n");

  // MaxMember & Modus
  printf("~~~~~ MaxMember & Modus ~~~~~\n");
  printf("Huruf yang paling sering muncul pada List X adalah %c dengan kemunculan sebanyak %d kali\n", Modus(X), MaxMember(X));
  printf("Huruf yang paling sering muncul pada List Y adalah %c dengan kemunculan sebanyak %d kali\n", Modus(Y), MaxMember(Y));
  printf("Huruf yang paling sering muncul pada List Z adalah %c dengan kemunculan sebanyak %d kali\n\n", Modus(Z), MaxMember(Z));

  // ConcatList
  printf("~~~~~ ConcatList ~~~~~\n");
  printf("Membuat List W yang merupakan gabungan dari List Y dan Z\n");
  ConcatList(Y,Z,&W);
  printf("W : "); PrintList(W); printf("\n\n");

  // SplitList
  printf("~~~~~ SplitList ~~~~~\n");
  printf("Memisahkan List X menjadi List Y dan Z\n");
  SplitList(X,&Y,&Z);
  printf("Y : "); PrintList(Y); printf("\n");
  printf("Z : "); PrintList(Z); printf("\n\n");

  // CopyList
  printf("~~~~~ CopyList ~~~~~\n");
  printf("Menyalin List W ke List X\n");
  CopyList(W,&X);
  printf("X : "); PrintList(X); 
  printf("\nMemastikan bahwa perubahan pada List W tidak berpengaruh ke List X dengan memasukkan sembarang elemen ke List W\nMasukkan sembarang elemen : ");
  scanf(" %c", &C); printf("List W dan X setelah InsertVLast\nW : "); 
  InsertVLast(&W,C);
  PrintList(W); printf("\n");
  printf("X : "); PrintList(X); printf("\n\n");

  printf("~~~~~ AKHIR DARI DRIVER LIST 1 ~~~~~\n");
  printf("~~~~~ Menghapus semua elemen dari semua list dari memory ~~~~~\n");
  DeleteList(&W); DeleteList(&X); DeleteList(&Y); DeleteList(&Z);
  return 0;
}