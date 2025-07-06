/* File : pohon3.c */
/* Deskripsi : body ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 06/12/2024*/

#include "pohon3.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree3 Alokasi3 (infotype E) { //representasi fisik fungsi
    //kamus lokal
    bintree3 P;
    //algoritm
    P = (bintree3) malloc(sizeof(node3));
    if (P != NIL) {
        parent(P) = NIL;
        info(P)  = E;
        visited(P) = false;
        left(P)  = NIL;
        right(P) = NIL;
    }
    return P;
}

/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
    /*kamus lokal*/
    bintree3 P;
    /*algoritma*/
    P = Alokasi3(X);
    if (P != NIL) { /*berhasil alokasi*/
        parent(P) = A;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 *P) {
    /*kamus lokal*/
    /*algoritma*/
    if(*P != NIL) { /*klo bukan kwasong*/
        visited(*P) = false;
        resetVisited(&left(*P));
        resetVisited(&right(*P));
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (P == NIL) {
        return false;
    }
    else { /*P != NIL*/
        return left(P) == NIL && right(P) == NIL;
    }
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (P == NIL) {
        return false;
    }
    else { /*P != NIL*/
        return left(P) == NIL && right(P) == NIL;
    }
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (P == NIL) {
        return false;
    }
    else { /*P != NIL*/
        return left(P) != NIL && right(P) == NIL;
    }
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (P == NIL) {
        return false;
    }
    else { /*P != NIL*/
        return left(P) == NIL && right(P) != NIL;
    }
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (IsEmptyTree(P)) {
        printf("( )");
    }
    else {
        printf("%c(", akar(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
    /*kamus lokal*/
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        if (visited(P)) { /*sudah dikunjungi, berarti ketemu*/
            printPathX(parent(P),X); /*print parentnya duls*/
            printf("%c ", akar(P));
        }
        else {
            if (akar(P) == X) {
                printPathX(parent(P),X); /*print mundur, sek tuo sek*/
                printf("%c\n", akar(P));
            } /*misal masih ada X yang laen, LANJOOT*/
            visited(P) = true; /*tandai*/
            printPathX(left(P),X);
            printPathX(right(P),X);
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
    /*kamus lokal*/
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        if (visited(P)) { /*sudah dikunjungi, berarti ketemu*/
            printPathDaunX(parent(P),X);
            printf("%c ", akar(P));
        }
        else {
            if (IsDaun(P)) {
                if (akar(P) == X) {
                    printPathDaunX(parent(P),X); /*print mundur*/
                    printf("%c\n", akar(P));
                } /*else akar != X, biarin byar byur*/
            }
            else {
                visited(P) = true; /*tandai*/
                printPathDaunX(left(P),X);
                printPathDaunX(right(P),X);
            }
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        if (visited(P)) { /*basis*/
            printAllPaths(parent(P));
            printf("%c ", akar(P));
        }
        else {
            if (IsDaun(P)) { /*basis 1*/
                printAllPaths(parent(P));
                printf("%c\n", akar(P));
            }
            else {
                visited(P) = true; /*tandai biar ga lari*/
                printAllPaths(left(P));
                printAllPaths(right(P));
            }
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
    /*kamus lokal*/
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (IsDaun(P)) {
            return 1;
        }
        else {
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (IsDaun(P)) {
            return 0;
        }
        else {
            return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
        }
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar = 1 }*/
int Level (bintree3 P) {
    /*kamus lokal*/
    /*algoritma*/
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        return 1 + Max2(Level(left(P)), Level(right(P)));
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
    /*kamus lokal*/
    /*algoritma*/
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (T == 1) {
            return 1;
        }
        else {
            return CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
        }
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
    /*kamus lokal*/
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", akar(P));
        }
        else {
            PrintLevel(left(P),N-1);
            PrintLevel(right(P),N-1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
    /*kamus lokal*/
    int i, L;
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        L = Level(P); /*level max = tinggi + 1*/
        for (i=1; i<=L; i++) { /*traversal dari 1 - L*/
            PrintLevel(P,i); 
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {
    /*kamus lokal*/
    address P;
    /*algoritma*/
    if (!IsEmptyList(Tambahan)) { /*klo kosong biarin*/
        if (IsEmptyList(*Asli)) {
            First(*Asli) = First(Tambahan);
        }
        else {
            P = First(*Asli);
            while(next(P) != NIL) {
                P = next(P);
            }
            next(P) = First(Tambahan);
        }
    }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan) {
    /*kamus lokal*/
    address P;
    List1 H; /*H for HASIL*/
    /*algoritma*/
    CreateList(&H);
    P = First(Asli);
    while(P != NIL){
        InsertVLast(&H,info(P));
        P = next(P);
    }
    P = First(Tambahan);
    while(P != NIL) {
        InsertVLast(&H,info(P));
        P = next(P);
    }
    return H;
} 

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P) {
    /*kamus lokal*/
    List1 H;
    /*algoritma*/
    CreateList(&H);
    if(!IsEmptyTree(P)) {
        InsertVLast(&H, akar(P));
        Pconcat(&H,LinearPrefix(left(P)));
        Pconcat(&H,LinearPrefix(right(P)));
    }
    return H;
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P) {
    /*kamus lokal*/
    List1 H;
    /*algoritma*/
    CreateList(&H);
    if(!IsEmptyTree(P)) {
        Pconcat(&H,LinearPosfix(left(P)));  
        Pconcat(&H,LinearPosfix(right(P)));
        InsertVLast(&H, akar(P));
    }
    return H;
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P) {
    /*kamus lokal*/
    List1 H;
    /*algoritma*/
    CreateList(&H);
    if(!IsEmptyTree(P)) {
        Pconcat(&H,LinearInfix(left(P)));
        InsertVLast(&H, akar(P));
        Pconcat(&H,LinearInfix(right(P)));
    }
    return H;
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P) {
    /*kamus lokal*/
    int i,L; /*L max*/
    List1 H;
    /*algoritma*/
    CreateList(&H);
    L = Level(P);
    for (i=1; i<=L; i++) {
        LinearLevelT(P, &H, i);
    }
    return H;
}

/****FUNGSI TAMBAHAN DEMI HIDUP YANG LEBIH BAIK****/

/*function Max2 (a : integer, b : integer) -> integer
{mengembalikan nilai yang max dari a dan b}*/
int Max2 (int a, int b) {
    /*kamus lokal*/
    /*algoritma*/
    if (a >= b) {
        return a;
    } 
    else {
        return b;
    }
}

/*procedure LinearLevelT (input P : bintree3, output L : List1, input T : integer)
 {I.S. : -}
 {F.S. : Terbentuk List1 L yang berisi node-node level T dari bintree3 P}*/
void LinearLevelT (bintree3 P, List1 *L, int T) {
    /*kamus lokal*/
    /*algoritma*/
    if (!IsEmptyTree(P)) {
        if (T == 1) {
            InsertVLast(L, akar(P));
        }
        else {
            LinearLevelT(left(P), L, T-1);
            LinearLevelT(right(P),L, T-1);
        }
    }
}