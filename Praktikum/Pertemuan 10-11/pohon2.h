/* File : pohon2.h */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : */
/* Tanggal : */

#ifndef pohon2_H
#define pohon2_H

// #include "boolean.h"
// #include "pohon1.h"
#include "pohon1.c"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H );

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N);

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n);

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P);

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X);

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri);

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X);

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X);

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X);

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X);

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y);

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
char maxTree(bintree P);

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
char minTree(bintree P);

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X);

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. 
  Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X);

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X);

/*procedure InsBSTX (input/output P : BinTree, input X : bintree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : P menjadi binary search tree dengan simpul BST X  }
{ Proses : Mencari lokasi yang tepat untuk BST X di BST P }*/
void InsBSTX(bintree *P, bintree X);

/*function IsBSearch (P : BinTree) → boolean
{ Mengembalikan true jika P BST. Selain itu false }*/
boolean IsBSearch(bintree P);

/*procedure MakeBSearch (input/output P : BinTree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : P menjadi binary search tree }
{ Proses : Mencari elemen yang membuat P bukan BSearch lalu memindahkannya }*/
void MakeBSearch(bintree *P);

/*function BuildBSearchTree (int n) → bintree
{ Membuat BSearchTree dari input sebanyak n }*/
bintree BuildBSearchTree(int n);

// PROSEDUR TAMBAHAN

/*procedure InsertTreeTerkiri (input/output P : BinTree, input X : bintree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : bintree X menjadi simpul kiri daun terkiri sebelumnya }*/
void InsertTreeTerkiri(bintree *P, bintree X);

/* function min2(char a, char b) -> character
{mengembalikan nilai minimal dari a atau b}*/
char minchar(char a, char b);

/* function maxchar(char a, char b) -> character
{mengembalikan nilai maksimal dari a atau b}*/
char maxchar(char a, char b);

/* Procedure ShowMenu2 ()
{ I.S. : Sembarang }
{ F.S. : Muncul daftar menu di terminal }
{ Proses : Menampilkan daftar menu ke terminal }*/
void ShowMenu2 (); 

#endif