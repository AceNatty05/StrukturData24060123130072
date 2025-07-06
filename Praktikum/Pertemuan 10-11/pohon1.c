/* File       : pohon1.c */
/* Deskripsi  : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal    : 25/11/2024*/

#include "pohon1.h"

/* DEFINISI bintree kosong = NIL =S ( ) */

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E) { //representasi fisik fungsi
    //kamus lokal
    bintree P;
    //algoritm
    P = (bintree) malloc(sizeof(node));
    if (P != NIL) {
        info(P)  = E;
        left(P)  = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P) {
    //kamus lokal
    //algoritma
    if (*P != NIL) {
        left(*P)  = NIL;
        right(*P) = NIL;
    }
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //Kamus Lokal
    bintree P;
    //Algoritma
    P = Alokasi(akar);
    if (P != NIL) { // berhasillll
        // akar(P) = akar;   
        left(P) = left;
        right(P) = right;                                                    
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P) {
    //Kamus Lokal
    //Algoritma
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    //kamus lokal
    //Algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //Kamus lokal
    //algortima
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
    //kamus lokal
    //algoritma
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    //kamus lokal
    //algoritma
    if (P == NIL) {
        return false;
    }
    else {
        return /*P != NIL &&*/ left(P) == NIL && right(P) == NIL;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    //kamus lokal
    //algoritma
    if (P == NIL) {
        return false;
    }
    else {
        return P != NIL && left(P) != NIL && right(P) != NIL;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    //kamus lokal
    //algoritma
    if (P == NIL) {
        return false;
    }
    else {
        return P != NIL && left(P) != NIL && right(P) == NIL;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    //kamus lokal
    //algoritma
    if (P == NIL) {
        return false;
    }
    else {
        return P != NIL && left(P) == NIL && right(P) != NIL;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        printf("( )");
    }
    else {
        printf("%c(", GetAkar(P));
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        return 1 + NbElm(GetLeft(P)) + NbElm(GetRight(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // basis 0
        return 0;
    }
    else {
        if (IsDaun(P)) { // basis 1
            return 1;
        }
        else {
            return NbDaun(GetLeft(P)) + NbDaun(GetRight(P));
        }
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    //kamus lokal
    //algoritma
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (IsDaun(P)) {
            return 0;
        }
        else {
            return max2(1+Tinggi(GetLeft(P)), 1+Tinggi(GetRight(P)));
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // basis 0
        return false;
    }
    else {
        if (GetAkar(P) == X) { // basis 1, akar tree saat ini = X
            return true;
        }
        else {
            return SearchX(GetLeft(P), X) || SearchX(GetRight(P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    //kamus lokal
    bintree L, R;

    //algoritma
    if (SearchX(*P, X)) { // ditemukan X di tree P
        if (GetAkar(*P) == X) {
            info(*P) = Y;
        }
        else {
            L = GetLeft(*P);
            R = GetRight(*P);
            // V2 paling kiri & paling atas levelnya 
            if (SearchX(L, X)) {
                UpdateX(&L, X, Y);
            }
            else {
                UpdateX(&R, X, Y);
            }
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (GetAkar(P) == X) {
            return 1 + CountX(GetLeft(P),X) + CountX(GetRight(P),X);
        }
        else {
            return CountX(GetLeft(P),X) + CountX(GetRight(P),X);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    }
    else {
        if (IsDaun(P)) {
            return true;
        }
        else {
            return IsUnerLeft(P) && IsSkewLeft(GetLeft(P));
        }
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    }
    else {
        if (IsDaun(P)) {
            return true;
        }
        else {
            return IsUnerRight(P) && IsSkewRight(GetRight(P));
        }
    }
}

/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixV2(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        printf("( )");
    }
    else {
        printf("%c", GetAkar(P));
        if (GetLeft(P) != NIL || GetRight(P) != NIL) { // ada child di salah satunya
            printf("(");
            PrintPrefixV2(GetLeft(P));
            printf(",");
            PrintPrefixV2(GetRight(P));
            printf(")");    
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    //kamus lokal
    boolean L, R;
    //algoritma
    if (SearchX(P,X)) { // jika ditemukan X
        if (GetAkar(P) == X) {
            return 1;
        }
        else {
            L = SearchX(GetLeft(P),X);
            R = SearchX(GetLeft(P),X);
            if (L && R) { // ditemukan 2 ssisi
                return 1 + min2(LevelX(GetLeft(P),X), LevelX(GetRight(P),X));
            }
            else {
                if (L) {// ditemukan di kiri
                    return 1 + LevelX(GetLeft(P),X);
                }
                else { // ditemukan di kanan
                    return 1 + LevelX(GetLeft(P),X);
                }
            }
        }
    }
    else { // jika tidak ditemukan return 0
        return 0;
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // basis 0
        return 0;
    }
    else {
        if (T == 1) { // basis siji
            return 1;
        }
        else { // cari di kanan kirinya
            return CountLevelT(GetLeft(P),T-1) + CountLevelT(GetRight(P),T-1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // BASIS 0
        return '#';
    }
    else {
        if (IsDaun(P)) { // BASIS 1
            return GetAkar(P);
        }
        else { // masih ada tree di kanan / kiri
            if (GetLeft(P) != NIL) { // di kiri ada cabang
                return GetDaunTerkiri(GetLeft(P));
            }
            else {
                return GetDaunTerkiri(GetRight(P));
            }
        }
    }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return (float) 0.0;
    }
    else {
        return (float) CountX(P,X)/NbElm(P);
    }
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // basis ndol
        return 0;
    }
    else {
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O'|| 
            info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
            return 1 + CountVocal(GetLeft(P)) + CountVocal(GetRight(P));
        }
        else {
            return CountVocal(GetLeft(P)) + CountVocal(GetRight(P));
        }
    }
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
    //kamus lokal 
    int MAX, A, L, R;
    char a, l, r;
    //algoritma
    if (IsEmptyTree(P)) {
        return '#';
    }
    else {
        a = GetAkar(P);
        l = Modus(GetLeft(P));
        r = Modus(GetRight(P));
        A = CountX(P, a);
        L = CountX(P, l);
        R = CountX(P, r);
        MAX = max2(A,max2(L,R));
        if (MAX == A) {
            return a;
        }
        else if (MAX == L) {
            return l;
        }
        else {
            return r;
        }
    }
}


// FUNGSI TAMBAHAN
/* function min2(int a, int b)->integer
{mengembalikan nilai minimal dari a atau b}*/
int min2(int a, int b) {
    //kamus lokal
    //algoritma
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

/* procedure PrintPostfix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara postfix linier ringkas} */
/*contoh: (( ),C,( )),A,(( ),B,( ))*/
void PrintPostfix(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        printf("( )");
    }
    else {
        printf("(");
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")%c", GetAkar(P));
    }
}

/* procedure PrintInfix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara infix linier ringkas} */
void PrintInfix(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        printf("( )");
    }
    else {
        printf("(");
        PrintPrefix(GetLeft(P));
        printf(",%c,", GetAkar(P));
        PrintPrefix(GetRight(P));
        printf(")");
    }
}

/*Procedure ShowStat(input L:bintree)
{I.S.: -  
 F.S.: Muncul status L di layar
 Proses : Menampilkan status bintree. Khusus driver }*/
void ShowStat(bintree P) {
    //kamus lokla
    //algoritma
    PrintPrefixV2(P);
    printf("\n-- IsEmpty = "); YESorYES(IsEmptyTree(P)); 
    printf("\n-- IsDaun = "); YESorYES(IsDaun(P)); 
    printf("\n-- IsBiner = "); YESorYES(IsBiner(P)); 
    printf("\n-- IsUnerLeft = "); YESorYES(IsUnerLeft(P));
    printf("\n-- IsUnerRight = "); YESorYES(IsUnerRight(P)); 
    printf("\n-- IsSkewLeft = "); YESorYES(IsSkewLeft(P)); 
    printf("\n-- IsSkewRight = "); YESorYES(IsSkewRight(P)); 
    printf("\n-- NbElm = %d", NbElm(P));
    printf("\n-- NbDaun = %d", NbDaun(P));
    printf("\n-- Tinggi = %d", Tinggi(P));
    printf("\n-- NVocal = %d", CountVocal(P));
    printf("\n-- Modus = %c\n", Modus(P));
}

/*Procedure YESorYES(input b: boolean)
{I.S.: -  
 F.S.: Muncul YA atau TIDAK di layar
 Proses : Menampilkan YA jika true, TIDAK jika false. Khusus driver }*/
void YESorYES(boolean b) {
    //Kamus Lokal
    //Algoritma
    if (b) {
        printf("YA");
    }
    else {
        printf("TIDAK");
    }
}

/*Procedure DeleteTree(input P: bintree)
{I.S.: -  
 F.S.: Seluruh elemen tree terhapus
 Proses : Menghapus keseluruhan elemen tree. Khusus driver }*/
void DeleteTree(bintree *P) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        DeleteTree(&left(*P));
        DeleteTree(&right(*P));
        Dealokasi(P);
    }
}

/*Procedure ShowMenu ()
{I.S.: -  
 F.S.: -
 Proses : Menampilkan pilihan menu
 Khusus driver }*/
void ShowMenu () {
    //kamus lokal
    //algoritma
    printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi            *****\n");
    printf("   M    : Menampilkan pilihan menu\n");
    printf("   Q    : Keluar dari driver\n");
    printf("   1    : PrintPrefix\n");
    printf("   2    : PrintInfix\n");
    printf("   3    : PrintPostfix\n");
    printf("   4    : SearchX\n");
    printf("   5    : UpdateX\n");
    printf("   6    : CountX\n");
    printf("   7    : LevelX\n");
    printf("   8    : CountLevelT\n");
    printf("   9    : GetDaunTerkiri\n");
    printf("   10   : FrekuensiX\n");
    printf("   11   : ShowStat\n");
}