/* File : list3.c */
/* Deskripsi : body ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 16/11/2024*/

#include "list3.h"

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) { //representasi fisik fungsi
    //Kamus Lokal
    address P;
    //Algoritma
    P = (address) malloc(sizeof(Elm));
    if (P != NIL) { // berhasil memperoleh ruang memori
        info(P) = E;
		next(P) = NIL;
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    //kamus Lokal
    //Algoritma
    if ((*P) != NIL) {
		next(*P) = NIL;
        prev(*P) = NIL;
	}
	free(*P);
	(*P) = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
    //Kamus Lokal
    //Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
    //Kamus Lokal
    //Algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List3) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List3 L) {
    //Kamus Lokal
    //Algoritma
    return First(L) != NIL && prev(First(L)) == NIL && next(First(L)) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
    //Kamus Lokal
    address P;
    //Algoritma
    printf("Isi list : ");
    P = First(L);
    if (P != NIL) {
        while (P != NIL) {
            printf(" %c ", info(P));
            P = next(P);
        }
    }
    else {
        printf(" KOOOOOSOOOOOONGGG");
    }
    printf("\n");
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    while (P != NIL) {
        Count++;
        P = next(P);
    }
    return Count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
    //Kamus Lokal
    address A;
    //Algoritma
    A = Alokasi(V);
    if (A != NIL) {
        if (!IsEmptyList(*L)) {
            next(A) = First(*L);
            prev(First(*L)) = A;
        }
        First(*L) = A;
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
    //Kamus Lokal
    address P, A;
    //Algoritma
    A = Alokasi(V);
    if (A != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = A;
        }
        else {
            P = First(*L);
            while (next(P) != NIL) {
                P = next(P);
            }
            next(P) = A;
            prev(A) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
    //Kamus Lokal
    address P;
    //Algoritma
    *V = '#';
    P = First(*L);
    if (P != NIL) {
        if (next(P) == NIL && prev(P) == NIL) {
            First(*L) = NIL;
        }
        else {
            First(*L) = next(P);
            prev(next(P)) = NIL;
        }
        *V = info(P);
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
    //Kamus Lokal
    address P;
    //Algoritma
    *V = '#';
    P = First(*L);
    if (P != NIL) {
        if (prev(P) == NIL && next(P) == NIL) { // one elm
            First(*L) = NIL;
        }
        else {
            while (next(P) != NIL) {
                P = next(P);
            }
            next(prev(P)) = NIL;
        }
        *V = info(P);
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(*L);
    if (P != NIL) {
        while (next(P) != NIL && info(P) != X) { // elm terakhir tidak dicek
            P = next(P);
        }
        if (info(P) == X) {
            if (P == First(*L)) { // elemen first
                if (next(P) == NIL && prev(P) == NIL) { // oneelm
                    First(*L) = NIL;
                }
                else { // not one elm
                    First(*L) = next(P);
                    prev(next(P)) = NIL;
                }
            }
            else { // tengah ato akhir
                if (next(P) == NIL) { // last elm
                    next(prev(P)) = NIL;
                }
                else { // di tengah-tengah
                    prev(next(P)) = prev(P);
                    next(prev(P)) = next(P);
                }
            }
            Dealokasi(&P);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
    //kamus Lokal
    address P;
    //Algoritma
    *A = NIL; // sterilkan
    P = First(L);
    if (P != NIL) {
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            *A = P;
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(*L);
    if (P != NIL) {
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) { // ditemukan
            info(P) = Y;
        }
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    //Kamus Lokal
    int i;
    address P, Q;
    List3 temp;
    //Algoritma
    CreateList(&temp);
    if (NbElm(*L) > 1) { // nb elm > 1
        P = First(*L);
        do { // membuat list temporary yang infonya invers dari list awal
            InsertVFirst(&temp,info(P));
            P = next(P);
        } while (P != NIL);
        P = First(*L); 
        Q = First(temp);
        do { // menyamakan info dari list awal dengan info list temporary
            info(P) = info(Q);
            P = next(P);
            Q = next(Q);
        } while (P != NIL);
        DeleteList(&temp);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
    //Kamus Lokal
    address P, A;
    //Algoritma
    P = First(*L);
    if (P != NIL && prev(P) != NIL && next(P) != NIL) { // bukan empty/one elm
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            A = Alokasi(V);
            if (A != NIL) {
                if (next(P) == NIL) { // last elm
                    prev(A) = P;
                    next(P) = A; 
                }
                else { // P ada tengah2
                    prev(A) = P;
                    next(A) = next(P);
                    prev(next(P)) = A;
                    next(P) = A;
                }
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
    //Kamus Lokal
    address A, P;
    //ALgoritma
    P = First(*L);
    if (P != NIL && prev(P) != NIL && next(P) != NIL) { // bukan empty / one elm
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            A = Alokasi(V);
            if (A != NIL) { // berhasil alokasi
                if (P == First(*L)) {
                    next(A) = P;
                    prev(P) = A;
                    First(*L) = A;
                }
                else { // di tengah2 / last
                    prev(A) = prev(P);
                    next(A) = P;
                    next(prev(P)) = A;
                    prev(P) = A;
                }
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
    //Kamus Lokal
    address P, Q; // Q yang dihapus
    //ALgoritma
    *V = '#';
    P = First(*L);
    if (P != NIL && prev(P) != NIL && next(P) != NIL) { // list dg elm < 2 tidak akan ada perubahan
        while (next(next(P)) != NIL && info(P) != X) { // berhenti di elm ke-2 terakhir karena jika elm terakhir = X tidak ada yang dihapus setelahnya
            P = next(P);
        }
        if (info(P) == X) {
            Q = next(P);
            if (next(Q) == NIL) { // Q elm terakhir
                next(P) = NIL;
            }
            else { // Q di tengah2
                prev(next(Q)) = P;
                next(P) = next(Q);
            }
            *V = info(Q);
            Dealokasi(&Q);
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
    //Kamus Lokal
    address O, P; // O yang dihapus
    //Algoritma
    *V = '#';
    P = First(*L);
    if (P != NIL && prev(P) != NIL && next(P) != NIL) { // list dg elm < 2 tidak akan ada perubahan
        do {
            P = next(P);
        } while (next(P) != NIL && info(P) != X); // elm pertama tidak dicek (tidak ada beforenya)
        if (info(P) == X) {
            O = prev(P);
            if (O == First(*L)) { // yang dihapus elm first
                First(*L) = P;
                prev(P) = NIL;
            }
            else { // di tengah2
                next(prev(O)) = P;
                prev(P) = prev(O);
            }
            *V = info(O);
            Dealokasi(&O);
        }
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
    //kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            Count++;
        }
        P = next(P);
    }
    return Count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
    //Kamus Lokal
    //Algoritma
    if (!IsEmptyList(L)) {
        return (float)CountX(L,X)/NbElm(L);
    }
    else { // kosong return 0,0
        return (float)0.0;
    }
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
    //kamus Lokal
    int Max;
    address P;
    //ALgoritma
    Max = 0;
    P = First(L);
    while (P != NIL) {
        if (CountX(L,info(P)) > Max) {
            Max = CountX(L,info(P));
        }
        P = next(P);
    }
    return Max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
    //kamus Lokal
    int Max;
    char C;
    address P;
    //Algoritma
    Max = 0; C = '#'; // list kosong mengembalikan #
    P = First(L);
    while (P != NIL) {
        if (CountX(L,info(P)) > Max) {
            Max = CountX(L,info(P));
            C = info(P);
        }
        P = next(P);
    }
    return C;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
    //kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    while (P != NIL) {
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O'|| 
            info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
            Count++;
        }
        P = next (P);
    }
    return Count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL) {
        while (next(P) != NIL) { // elemen terakhir tidak dicek, tidak ada afternya
            if (info(P) == 'N' && info(next(P)) == 'G') {
                Count++;
            }
            P = next (P);
        }
    }
    return Count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
    //Kamus Lokal
    address P;
    //Algoritma
    printf("Posisi %c:", X);
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            printf(" %p ", P);
        }
        P = next(P);
    }
    printf("\n");
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
    //Kamus Lokal
    int Count;
    address P, A;
    //Algoritma
    P = First(*L);
    while (P != NIL) {
        A = P;
        P = next(P);
        if (info(A) == X) {
            if (A == First(*L)) { // elemen first
                if (P == NIL && prev(A) == NIL) { // oneelm
                    First(*L) = NIL;
                }
                else { // not one elm
                    First(*L) = P;
                    prev(P) = NIL;
                }
            }
            else { // tengah ato akhir
                if (P == NIL) { // last elm
                    next(prev(A)) = NIL;
                }
                else { // di tengah-tengah
                    prev(P) = prev(A);
                    next(prev(A)) = P;
                }
            }
            Dealokasi(&A);
        }
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
    //Kamus Lokal
    address P;
    //Algoritma
    DeleteList(L); //sterilkan
    if (First(L1) != NIL) { // L1 tidak kosong
        First(*L) = First(L1);
        if (First(L2) != NIL) { // L2 juga tidak kosong
            P = First(*L);
            while (next(P) != NIL) {
                P = next(P);
            }
            next(P) = First(L2);
            prev(First(L2)) = P;
        }
    }
    else { // L1 kosong
        if (First(L2) != NIL) { // L2 tidak kosong
            First(*L) = First(L2);
        }
    }
} 

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
    //Kamus Lokal
    int nHalf;
    address P;
    //Algoritma
    DeleteList(L1); DeleteList(L2);
    P = First(L);
    if (P != NIL) { // jika L kosong maka L1 L2 juga kosong
        if (prev(P) == NIL && next(P) == NIL) { // L one elm, elm pindah ke L2
            First(*L2) = First(L);
        }
        else { // NbElm(L) > 1, NbElm(L1) <= NbElm(L2)
            nHalf = NbElm(L)/2; // NbElm(L) div 2
            P = First(L);
            First(*L2) = P;
            while (nHalf > 0) {
                P = next(P);
                nHalf--;
            }
            First(*L2) = P;
            next(prev(P)) = NIL; // memotong
            prev(P) = NIL;
        }
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
    //Kamus Lokal
    address P;
    //Algoritma
    DeleteList(L2); // sterilkan
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L2,info(P));
    }
}

/*********** OPERATORS ***********/

/*Procedure DeleteList(input/output L:List3)
{I.S.: L terdefinisi;  
 F.S.: semua elemen L dihapus dari memory, L list kosong;
 Proses : Menghapus elemen-elemen List L dari memory. 
 Tidak perlu ditulis di notasi, khusus implementasi di C }*/
void DeleteList(List3 *L) {
    //Kamus Lokal
    address P, A;
    //Algoritma
    P = First(*L);
    while (P != NIL) {
        A = P;
        Dealokasi(&A);
        P = next(P);
    }
    First(*L) = NIL;
}

/*Procedure PrintAddressList(input L:List2)
{I.S.: -  
 F.S.: semua address elemen L muncul di layar
 Proses : Memunculkan address tiap elemen L ke layar }*/
void PrintAddressList(List3 L) {
    //kamus lOkal
    address P;
    //Algoritma
    printf("Address :");
    P = First(L);
    if (P != NIL) {
        do {
            printf(" %p ", P);
            P = next(P);
        } while (P != NIL);
    }
    else {
        printf(" NOT FOUND");
    }
    printf("\n");
}

/*Procedure ShowMenu ()
{I.S.: -  
 F.S.: -
 Proses : Menampilkan pilihan menu
 Khusus driver }*/
void ShowMenu () {
    //Kamus Lokal
    //Algoritma
    printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi            *****\n");
    printf("   M    : Menampilkan pilihan menu\n");
    printf("   Q    : Keluar dari driver\n");
    printf("   1    : InsertVFirst\n");
    printf("   2    : InsertVLast\n");
    printf("   3    : InsertVAfterX\n");
    printf("   4    : InsertVBeforeX\n");
    printf("   5    : DeleteVFirst\n");
    printf("   6    : DeleteVLast\n");
    printf("   7    : DeleteVAfterX\n");
    printf("   8    : DeleteVBeforeX\n");
    printf("   9    : DeleteX\n");
    printf("   10   : DeleteAllX\n");
    printf("   11   : SearchX\n");
    printf("   12   : SearchAllX\n");
    printf("   13   : UpdateX\n");
    printf("   14   : CountX & FrekuensiX\n");
    printf("   15   : CountVocal\n");
    printf("   16   : CountNG\n");
    printf("   17   : Maxmember & Modus\n");
    printf("   18   : Invers\n");
    printf("   19   : ConcatList\n");
    printf("   20   : SplitList\n");
    printf("   21   : CopyList\n");
}

/*Procedure ShowStat(input L:List2)
{I.S.: -  
 F.S.: Muncul status L di layar
 Proses : Menampilkan status list. Khusus driver }*/
void ShowStat(List3 L) {
    //Kamus Lokal
    //Algoritma
    PrintList(L); PrintAddressList(L);
    printf("Panjang : %d\n", NbElm(L));
    printf("IsEmptyList : "); YESorYES(IsEmptyList(L));
    printf("IsOneElm : "); YESorYES(IsOneElm(L));
}

/*Procedure YESorYES(input b: boolean)
{I.S.: -  
 F.S.: Muncul YA atau TIDAK di layar
 Proses : Menampilkan YA jika true, TIDAK jika false. Khusus driver }*/
void YESorYES(boolean b) {
    //Kamus Lokal
    //Algoritma
    if (b) {
        printf("YA\n");
    }
    else {
        printf("TIDAK\n");
    }
}