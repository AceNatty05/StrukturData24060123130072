/* File         : list2.c */
/* Deskripsi    : body ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama   : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal      : 10/11/2024*/

#include "list2.h"

/*================== PROTOTYPE =======================*/
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
    //KAmus LOkal
    //ALgoritma
    if ((*P) != NIL) {
		next(*P) = NIL;
	}
	free(*P);
	(*P) = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    //Kamus Lokal
    //ALgoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
    //Kamus LOkal
    //ALgoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
    //Kamus LOkal
    //ALgoritma
    return First(L) != NIL && next(First(L)) == First(L);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
    //Kamus Lokal
    address P;
    //Algoritma
    printf("Isi list : ");
    P = First(L);
    if (P != NIL) { // tidak kwasong
        do{
            printf(" %c ", info(P));
            P = next(P);
        } while (P != First(L));
    }
    else {
        printf(" KOPONG");
    }
    printf("\n");
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    if (!IsEmptyList(L)) {
        Count = 1; // elemen terakhir tidak akan dihitung
        P = First(L);
        while (next(P) != First(L)) {
            Count++;
            P = next(P);
        }
        return Count;
    }
    else { // list kosong, return Count (0)
        return 0;
    }

}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
    //Kamus Lokal
    address A, P;
    //Algoritma                         
    A = Alokasi(V); 
    if(A != NIL) {
        P = First(*L);
        if (P != NIL) {
            while (next(P) != First(*L)) {
                P = next(P);
            }
            next(A) = First(*L);
            First(*L) = A;
            next(P) = First(*L);
        }
        else {
            First(*L) = A;
            next(A) = A;
        }
    }
    else {
        printf("Tidak berhasil mendapatkan alamat untuk %c\n", V);
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
    //Kamus Lokal
    address A, P;
    //Algoritma
    A = Alokasi(V);
    if (A != NIL) { // berhasil mendapatkan address untuk A
        if (First(*L) != NIL) { // bukan list kosong
            P = First(*L);
            while (next(P) != First(*L)) {
                P = next(P);
            }
            next(P) = A;
            next(A) = First(*L);
        } 
        else { // list kosong
            First(*L) = A;
            next(A) = A;
        }
    }
    else {
        printf("Tidak berhasil mendapatkan alamat untuk %c\n", V);
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(*L);
    if (P != NIL) { // tidak kosong
        *V = info(P);
        if (!IsOneElm (*L)) { // model repeat until (do while) bisa error saat oneelm
            do {
                P = next(P);
            } while (next(P) != First(*L));
            next(P) = next(First(*L));
            P = First(*L); // P sudah tidak dipakai lagi, sekarang kita gunakan sebagai wadah address Elemen pertama
            First(*L) = next(P); 
            Dealokasi(&P);
        }
        else {
            Dealokasi(&P);
            First(*L) = NIL;
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    //Kamus Lokal
    address P, Prec;
    //Algoritma
    P = First(*L);
    if (P != NIL) {
        if (!IsOneElm(*L)) {
            do {
                Prec = P;
                P = next(P);
            } while (next(P) != First(*L));
            *V = info(P);
            Dealokasi(&P);
            next(Prec) = First(*L);
        }
        else {
            *V = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    //Kamus Lokal
    address O, P, Q; // P untuk menunjuk elm saat ini, O dan Q menunjuk elm sebelum & sesudah P
    //Algoritma
    SearchX(*L,X,&P);
    if (P != NIL) { // jika ditemukan X
        if (IsOneElm(*L)) { // hanya ada 1 elemen --> kosong
            Dealokasi(&P);
            First(*L) = NIL;
        }
        else { // banyak elm, cari posisi O
            Q = next(P);
            O = First(*L); // pencarian mulai dari elm pertama, case terburuk P adalah First elm
            while (next(O) != P) {
                O = next(O);
            }
            if (P == First(*L)) {
                First(*L) = Q;
            }
            Dealokasi(&P);
            next(O) = Q;
        }
    }


    // P = First(*L);
    // if (P != NIL) { // tidak kwasong
    //     if (!IsOneElm(*L)) { // bukan Oneelm
    //         if (info(P) == X) { // X ditemukan di elemen pertama 
    //             do {
    //                 O = P;
    //                 P = next(P);
    //             } while (next(O) != First(*L)); // mencari lokasi last elm (elm sebelum first, sirkular)
    //             Q = next(P);
    //             Dealokasi(&P);
    //             First(*L) = Q;
    //             next(O) = Q;    
    //         }
    //         else { // X mungkin ada di elm kedua hingga terakhir
    //             do {
    //                 O = P;
    //                 P = next(P);
    //             } while (next(P) != First(*L) && info(P) != X); 
    //             Q = next(P);
    //             if (info(P) == X) { // cek apakah X ditemukan yang ditandai dengan elm = X ditunjuk P
    //                 Dealokasi(&P);
    //                 next(O) = Q;
    //             }
    //         }
    //     }
    //     else { // OneElm
    //         if (info(P) == X) { // satu elemen, cek apakah elemen satu2nya = X
    //             Dealokasi(&P);
    //             First(*L) = NIL; // bisa juga langsung createlist tapi kemungkinan akan ganti addressnya
    //         }
    //     }
    // }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    //Kamus Lokal
    address P;
    //Algoritma
    *A = NIL; // pastikan steril 
    P = First(L);
    if (P != NIL) { // bukan list kosong
        while (next(P) != First(L) && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            *A = P;
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    //Kamus Lokal
    address P;
    //Algoritma
    SearchX(*L,X,&P);
    if (P != NIL) { // X pertama saja yang diganti
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    //Kamus Lokal
    address P;
    List2 temp;
    //Algoritma
    P = First(*L);
    CreateList(&temp);
    if (P != NIL) {
        do {
            InsertVFirst(&temp,info(P));
            P = next(P);
        } while (P != First(*L));
    }
    DeleteList(L); // Pastikan L dihapus dari memory, tidak perlu ditulis di notasi
	// PrintList(*L); // buat ngecek list L beneran kosong belum
    *L = temp;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL) {
        do {
            if (info(P) == X) {
                Count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    //Kamus Lokal
    //Algoritma
    if (!IsEmptyList(L)) {
        return (float)CountX(L,X)/NbElm(L);
    }
    else {
        return (float)0.0;
    }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL) {
        do {
            if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O'|| 
                info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
                Count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    //Kamus Lokal
    int Count;
    address P;
    //Algoritma
    Count = 0;
    if (NbElm(L) > 1) { // bisa juga not isempty & not isoneelm
        P = First(L);
        do {
            if (info(P) == 'N' && info(next(P)) == 'G') {
                Count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    //Kamus Lokal
    address P, Q, R; // Q untuk address V
    //Algoritma
    P = First(*L);
    if (P != NIL) {
        while (next(P) != First(*L) && info(P) != X) {
            P = next(P);
        }
        R = next(P); // P R --> P Q R
        if (info(P) == X) {
            Q = Alokasi(V);
            if (Q != NIL) { // pastikan berhasil dapat lokasi
                next(P) = Q;
                next(Q) = R;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    //Kamus Lokal
    address N, O, P; // O untuk address V
    //Algoritma
    SearchX(*L,X,&P);
    if (P != NIL) { // X ada di list
        O = Alokasi(V);
        if (O != NIL) { // jika berhasil alokasi baru cari lokasi elm sebelum X
            N = P;
            do {
                N = next(N);
            } while (next(N) != P);
            if (P == First(*L)) {
                First(*L) = O;
            }
            next(N) = O;
            next(O) = P;
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    //Kamus Lokal
    address P, Q, R; // P nunjuk X, Q nunjuk V yang dihapus
    //Algoritma
    *V = '#'; // asumsi jika tidak ditemukan V = '#'
    SearchX(*L,X,&P);
    if (P != NIL) { // X ditemukan di list
        if (NbElm(*L) > 1 && P != NIL) { // elm > 1 
            Q = next(P);
            R = next(Q);
            *V = info(Q);
            if (Q == First(*L)) {
                First(*L) = R;
            }
            Dealokasi(&Q);
            next(P) = R;
        }
        else { // one elm
            *V = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    //Kamus Lokal
    address N, O, P; // O untuk address V
    //Algoritma
    *V = '#'; // asumsi jika tidak ditemukan V = '#'
    SearchX(*L,X,&P);
    if (P != NIL) { //X ditemukan di list
        if (NbElm(*L) > 1) { // elm > 1
            O = First(*L);
            do {
                N = O;
                O = next(O);
            } while (next(O) != P); 
            if (O == First(*L)) { // yang dihapus elm pertama (O), N last elm
                First(*L) = P;
            }
            *V = info(O);
            Dealokasi(&O);
            next(N) = P;
        }
        else { // one elm
            *V = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        }
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    //Kamus Lokal
    address P;
    //Algoritma 
    SearchX(*L,X,&P);
    while (P != NIL) { // hapus hingga tidak ditemukan X
        DeleteX(L,X);
        SearchX(*L,X,&P);
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    //Kamus Lokal
    int i; // counter incremen
    address P;
    //Algoritma
    printf("Posisi :");
    i = 0; // counter dimulai dari 0
    P = First(L);
    if (P != NIL) {
        do {
            i++;
            if (info(P) == X) {
                printf(" %d ", i);
            }
            P = next(P);
        } while (P != First(L));
    }
    printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    //Kamus Lokal
    int Max;
    address P;
    //Algoritma
    Max = 0;
    P = First(L);
    if (P != NIL) {
        do {
            if (CountX(L,info(P)) > Max) {
                Max = CountX(L,info(P));
            }
            P = next(P);
        } while (P != First(L));
    }
    return Max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    //Kamus Lokal
    int Max;
    char C;
    address P;
    //Algoritma
    Max = 0; C = '#'; // list kosong mengembalikan pager
    P = First(L);
    if (P != NIL) {
        do {
            if (CountX(L,info(P)) > Max) {
                Max = CountX(L,info(P));
                C = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }
    return C;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    //Kamus Lokal
    address P;
    //Algoritma
    DeleteList(L); // sterilkan
    P = First(L1);
    if (P != NIL) {
        do {
            InsertVLast(L,info(P));
            P = next(P);
        } while (P != First(L1));
    }
    P = First(L2);
    if (P != NIL) {
        do {
            InsertVLast(L,info(P));
            P = next(P);
        } while (P != First(L2));
    }
} 

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    //Kamus Lokal
    int nHalf;
    address P;
    //Algoritma
    DeleteList(L1); DeleteList(L2); // sterilkan
    P = First(L);
    if (P != NIL) {
        nHalf = NbElm(L)/2; // NbElm(L) div 2
        do {
            if (NbElm(*L1) < nHalf) { // NbElm(L1) <= NbElm(L2), jika ganjil L2 lebih panjang
                InsertVLast(L1,info(P));
            }
            else { // sisanya lempar ke L2
                InsertVLast(L2,info(P));
            }
            P = next(P);
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    //kamus Lokal
    address P;
    //Algoritma
    DeleteList(L2); // sterilkan
    P = First(L1);
    if (P != NIL) {
        do {
            InsertVLast(L2,info(P));
            P = next(P);
        } while(P != First(L1));
    }
}

/*********** OPERATORS ***********/

/*Procedure DeleteList(input/output L:List2)
{I.S.: L terdefinisi;  
 F.S.: semua elemen L dihapus dari memory, L list kosong;
 Proses : Menghapus elemen-elemen List L dari memory. 
 Tidak perlu ditulis di notasi, khusus implementasi di C }*/
void DeleteList(List2 *L){
	//kamus Lokal
	address P, Q;
	//Algoritma
	P = First(*L);
    if (P != NIL) {
        do { 
        Q = P;
        P = next(P);
		Dealokasi(&Q);
	    } while (P != First(*L));
        // bisa juga memanggil DeleteVFirst/Last sebanyak ukuran list
        First(*L) = NIL;
    }
}

/*Procedure PrintAddressList(input L:List2)
{I.S.: -  
 F.S.: semua address elemen L muncul di layar
 Proses : Memunculkan address tiap elemen L ke layar }*/
void PrintAddressList(List2 L) {
    //kamus lOkal
    address P;
    //Algoritma
    printf("Address elemen list : ");
    P = First(L);
    if (P != NIL) {
        do {
            printf(" %p ", P);
            P = next(P);
        } while (P != First(L));
    }
    else {
        printf(" NGGAK ADA DI MANA PUN");
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
void ShowStat(List2 L) {
    //Kamus Lokal
    //Algoritma
    PrintList(L);
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