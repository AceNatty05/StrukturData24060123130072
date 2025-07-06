/* File : pohon2.c */
/* Deskripsi : body ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal : 28/11/2024 */

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang, mirip file explorer} */
void PrintTreeInden( bintree P, int H ) { // ASUMSI H HEIGHT POHON
    //kamus lokal
    int i;
    //algoritma
    if (!IsEmptyTree(P)) {
        for (i=0; i<H; i++) {
            printf("\t");
        }
        printf("%c\n",GetAkar(P));
        PrintTreeInden(GetLeft(P), H+1);
        PrintTreeInden(GetRight(P),H+1);
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N) {
    //kamus lokal
    //algoritma 
    if (!IsEmptyTree(P)) {
        if (N == 1) { // basis siji
            printf("%c\t", GetAkar(P));
        }
        else { // cari di kanan kirinya
            PrintLevel(GetLeft(P),N-1);
            PrintLevel(GetRight(P),N-1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    //kamus lokal
    char C[5]; // untuk menghindari error saat user memberi input lebih dari 1 karakter 
    //algoritma
    if (n == 0) {
        return NIL;
    }
    else { 
        printf("Masukkan node: "); scanf(" %s", &C);
        // sisa (n-1) dibagi 2, NbElm(kiri) <= NbElm(kanan)
        return Tree(C[0], BuildBalanceTree((n-1)/2), BuildBalanceTree((n-1) - ((n-1)/2)));
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    //kamus lokal
    if (IsEmptyTree(P)) {
        return true;
    }
    else {
        if (IsDaun(P)) {
            return true;
        }
        else { // NbElm(L) <= NbElm(R)
            return (NbElm(GetLeft(P)) == NbElm(GetRight(P)) 
                    || NbElm(GetLeft(P)) == (NbElm(GetRight(P)) - 1)) 
                    && IsBalanceTree(GetLeft(P)) && IsBalanceTree(GetRight(P));
        } 
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            left(*P) = Alokasi(X);
        }
        else { // masih ada cabang di kanan / kiri
            if (GetLeft(*P) != NIL) { // di kiri masih ada cabang
                AddDaunTerkiri(&left(*P),X);
            }
            else {
                AddDaunTerkiri(&right(*P),X);
            }
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. : P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. : P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), 
         atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) { // pohon kosong ga ngapa2in
        if (IsDaun(*P)) { // merupakan daun
            if (GetAkar(*P) == X) {
                if (Kiri) {
                    left(*P) = Alokasi(X);
                }
                else {
                    right(*P) = Alokasi(X);
                }
            } // else, GetAkar(*P) != X, tidak lanjut pencariannya
        }
        else { // bukan daun
            AddDaun(&left(*P),X,Y,Kiri);
            AddDaun(&right(*P),X,Y,Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(*P)) { // cek apakah ada di simpul X di P saat di driver saja
        *P = Alokasi(X);
    }
    else {
        if (rand()%2 == 0) { // percayakan saja ke fungsi random
            InsertX(&left(*P),X);
        }
        else {
            InsertX(&right(*P),X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            *X = GetAkar(*P);
            Dealokasi(P);
        }
        else {
            if (GetLeft(*P) != NIL) { // ada cabang kiri
                DelDaunTerkiri(&left(*P), X);
            }
            else {
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
    else {
        *X = '#';
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            if (GetAkar(*P) == X) {
                Dealokasi(P);
            } // else, akar(*P) != X biarin
        }
        else {
            DelDaun(&left(*P),X);
            DelDaun(&right(*P),X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    //kamus lokal
    bintree A, L, R;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            if (IsDaun(*P)) {
                Dealokasi(P);
            }
            else {
                if (IsBiner(*P)) { // kuharus gimana...
                    L = GetLeft(*P);
                    R = GetRight(*P);
                    Dealokasi(P);
                    DeleteX(&L,X);
                    DeleteX(&R,X);
                    *P = L; // left jadi root baru
                    InsertTreeTerkiri(P,R); // right dicarikan posisi baru
                }
                else { // UnerLeft/Right
                    if (IsUnerLeft(*P)) {
                        A = GetLeft(*P);
                    }
                    else { // UnerRight
                        A = GetRight(*P);
                    }
                    Dealokasi(P);
                    DeleteX(&A,X);
                    *P = A;
                }
            }
        }
        else {
            DeleteX(&left(*P),X);
            DeleteX(&right(*P),X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            akar(*P) = Y;
        }
        UpdateAllX(&left(*P),X,Y);
        UpdateAllX(&right(*P),X,Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
char maxTree(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return '-'; // nilai ASCIII '-' = 45, huruf 'A'~'Z' -> 65~90 dan 'a'~'z' -> 97~122 
    }
    else{
        return maxchar(GetAkar(P) , maxchar( maxTree(GetLeft(P)) , maxTree(GetRight(P)) ));
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
char minTree(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return '~'; // nilai ASCIII '~' = 126, huruf 'A'~'Z' -> 65~90 dan 'a'~'z' -> 97~122 
    }
    else{
        return minchar(GetAkar(P) , minchar( minTree(GetLeft(P)) , minTree(GetRight(P)) ));
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // basis 0
        return false;
    }
    else {
        if (GetAkar(P) == X) { // basis 1
            return true;
        }
        else {
            if (GetAkar(P) > X) { // X mungkin di kirinya
                return BSearch(GetLeft(P),X);
            }
            else { // mungkin X di kanan
                return BSearch(GetRight(P),X);
            }
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) { // jadi simpul baru 
        return Alokasi(X);
    }
    else {
        if (GetAkar(P) > X) { // X lebih kicik, di kirinya
            left(P) = InsSearch(GetLeft(P),X);
        }
        else { // X lebih besar, di kanannya
            right(P) = InsSearch(GetRight(P),X);
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    //kamus lokal
    bintree A, L, R;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            if (IsDaun(*P)) {
                Dealokasi(P);
            }
            else {
                if (IsBiner(*P)) {
                    L = GetLeft(*P);
                    R = GetRight(*P);
                    Dealokasi(P);
                    *P = L;
                    InsBSTX(P,R);
                }
                else { // uner
                    if (IsUnerLeft(*P)) {
                        A = GetLeft(*P);
                    }
                    else {
                        A = GetRight(*P);
                    }
                    Dealokasi(P);
                    *P = A;
                }
            }
        }
        else {
            if (GetAkar(*P) > X) { // kekiri e
                DelBtree(&left(*P),X);
            }
            else {
                DelBtree(&right(*P),X);
            }
        }
    }
}

/*procedure InsBSTX (input/output P : BinTree, input X : bintree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : P menjadi binary search tree dengan simpul BST X  }
{ Proses : Mencari lokasi yang tepat untuk BST X di BST P.
           Prosedure pembantu DelBtree.
           Sudah dipastikan akar(P) < minTree(X). P awalnya left, X right }*/
void InsBSTX(bintree *P, bintree X) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(*P)) {
        *P = X;
    }
    else {
        if (IsDaun(*P)) {
            right(*P) = X;
        }
        else { 
            if (GetRight(*P) != NIL) { // di kanan exist
                InsBSTX(&left(*P),X);
            }
            else {
                InsBSTX(&right(*P),X);
            }
        }
    }
}

/*function IsBSearch (P : BinTree) → boolean
{ Mengembalikan true jika P BST. Selain itu false }*/
boolean IsBSearch(bintree P) {
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return true;
    }
    else { // max kiri < akar & min kanan > akar & kiri BSearch & kanan BSearch
        return maxTree(GetLeft(P)) < GetAkar(P) && minTree(GetRight(P)) > GetAkar(P) 
               && IsBSearch(GetLeft(P)) && IsBSearch(GetRight(P));
    }
}

/*procedure MakeBSearch (input/output P : BinTree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : P menjadi binary search tree }
{ Proses : Mencari elemen yang membuat P bukan BSearch lalu memindahkannya }*/
void MakeBSearch(bintree *P) {
    //kamus lokal
    char C;
    //algoritma
    while (!IsBSearch(*P)) { //not (max kiri < akar & min kanan > akar)
        // pindah akar masalahnya
        if (maxTree(GetLeft(*P)) > GetAkar(*P)) {
            C = maxTree(GetLeft(*P));
            DelBtree(&left(*P),maxTree(GetLeft(*P))); // surprisingly DelBtree bisa dipake di sini padahal udah jelas ini bukan BSearch
            if (C != GetAkar(*P)) { // jika yang dihapus != akar, carikan posisi di P
                *P = InsSearch(*P,C);
            }
        }
        if (minTree(GetRight(*P)) < GetAkar(*P)) {
            C = minTree(GetRight(*P));
            DelBtree(&right(*P),minTree(GetRight(*P)));
            if (C != GetAkar(*P)) { // jika yang dihapus != akar, carikan posisi di P
                *P = InsSearch(*P,C);
            }
        }
        MakeBSearch(&left(*P));
        MakeBSearch(&right(*P));
    }
}

/*function BuildBSearchTree (int n) → bintree
{ Membuat BSearchTree dari input sebanyak n }*/
bintree BuildBSearchTree(int n) {
    //kamus lokal
    int i;
    char C[5]; // untuk menghindari error saat user memberi input lebih dari 1 karakter 
    bintree P;
    //algoritma
    P = NIL; // inisialisasi pohon kosong
    for (i=0 ; i<n; i++) {
        printf("Masukkan node: "); scanf(" %s", &C);
        if (!SearchX(P,C[0])) { // tidak ada node X di P
            P = InsSearch(P,C[0]);
        }
    }
    return P;
}

// PROSEDUR TAMBAHAN

/*procedure InsertTreeTerkiri (input/output P : BinTree, input X : bintree)
{ I.S. : Pohon binary search P tidak kosong }
{ F.S. : bintree X menjadi simpul kiri daun terkiri sebelumnya }
  Untuk membantu DeleteX */
void InsertTreeTerkiri(bintree *P, bintree X) {
    //kamau lokal
    bintree A;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            left(*P) = X;
        }
        else {
            if (GetLeft(*P) != NIL) {
                InsertTreeTerkiri(&left(*P),X);
            }
            else {
                InsertTreeTerkiri(&right(*P),X);
            }
        }
    }
}

/* function minchar(char a, char b) -> character
{mengembalikan nilai minimal dari a atau b}*/
char minchar(char a, char b) {
    //kamus lokal
    //algoritma
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

/* function maxchar(char a, char b) -> character
{mengembalikan nilai maksimal dari a atau b}*/
char maxchar(char a, char b) {
    //kamus lokal
    //algoritma
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

/* Procedure ShowMenu2 ()
{ I.S. : Sembarang }
{ F.S. : Muncul daftar menu di terminal }
{ Proses : Menampilkan daftar menu ke terminal }*/
void ShowMenu2 () {
    //kamus lokal
    //algoritma
    printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi            *****\n");
    printf("   M    : Menampilkan pilihan menu\n");
    printf("   Q    : Keluar dari driver\n");
    printf("   1    : PrintTreeInden\n");
    printf("   2    : PrintLevel\n");
    printf("   3    : BuildBalanceTree & IsBalanceTree\n");
    printf("   4    : AddDaunTerkiri\n");
    printf("   5    : AddDaun\n");
    printf("   6    : InsertX\n");
    printf("   7    : DelDaunTerkiri\n");
    printf("   8    : DelDaun\n");
    printf("   9    : DeleteX\n");
    printf("   10   : UpdateAllX\n");
    printf("   11   : BSearch\n");
    printf("   12   : InsSearch\n");
    printf("   13   : DelBtree\n");
}