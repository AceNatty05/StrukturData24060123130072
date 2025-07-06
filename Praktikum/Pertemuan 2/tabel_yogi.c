#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Program   : Tabel.c */
/* Deskripsi : Menyimpan Beberapa Primitif dari ADT Tabel*/
/* NIM/Nama  : 24060123130106/Muhammad Yoga Aminudin */
/* Tanggal   : 07/September/2024 */
/***********************************/

int Nil=-999;

/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
    void createTable (Tabel *T){
        /* kamus Lokal */
        int i;
        
        /* Algoritma */
        (*T).size=0;
        for(int i=1;i<=10;i++){
            (*T).wadah[i]=-999;
        }
    }

/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
    /* Kamus Lokal */

    /* Algoritma */
    int getSize (Tabel T){
        return T.size;
    }

/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
    /* Kamus Lokal */

    /* Algoritma */
    boolean isEmptyTable (Tabel T){
        return getSize(T)==0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
    /* Kamus Lokal */

    /* Algoritma */
    boolean isFullTable (Tabel T){
        return getSize(T)==10;
}

/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> boolean
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
    int searchX(Tabel T, int X) {
        /* Kamus Lokal */
        int i;

        /* Algoritma */
        for (i = 1; i <= getSize(T); i++) {
            if (T.wadah[i] == X) {
                return i;  
            }
        }
        return 0;  // tidak ditemukan
    }

/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
    int countX (Tabel T, int X){
        /* Kamu Lokal */
        int i;
        int sum; /*indeks terkecil*/
        
        /* Algoritma */
        sum =0;
        i = 1;
        for (i = 1; i <= getSize(T); i++) { // Mulai dari indeks 1
            if (T.wadah[i] == X) {
                sum++; // Tambah jika elemen bernilai X
            }
        }
        return sum;
    }

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
    int countEmpty (Tabel T){
        /* Kamu Lokal */
        int i;
        
        /* Algoritma */
        return 10-getSize(T);
    }

/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
    void addXTable (Tabel *T, int X){
        /* Kamus Lokal */

        /* Algoritma */
        if(!isFullTable(*T)){
            (*T).wadah[(*T).size+1]=X;
            (*T).size+=1;
        }
    }

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
    void delXTable (Tabel *T, int X){
        /* Kamus Lokal */
        int i;
        int pos; /* simpan nilai searchX, ga berulang */

        /* Algoritma */
        pos = searchX(*T, X); 

        if (pos != 0) {  
            for (i = pos; i < getSize(*T); i++) {
                (*T).wadah[i] = (*T).wadah[i + 1];
            }
            (*T).wadah[getSize(*T)] = -999;
            (*T).size -= 1;
        }
    }

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
    void delAllXTable (Tabel *T, int X){
        /* Kamu Lokal */
        int i;
        int pos; /* simpan nilai searchX, ga berulang */

        /* Algoritma */
        while ((pos = searchX(*T, X)) != 0) {
        // Geser 
            for (i = pos; i < getSize(*T); i++) {
                (*T).wadah[i] = (*T).wadah[i + 1];
            }
            (*T).size -= 1;
            (*T).wadah[getSize(*T) + 1] = -999;
        }
    }


/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
    void printTable (Tabel T){
        /*Kamus Lokal*/
        int i;

        /* Algoritma */
        printf("[ ");
        for(int i=1;i<=10;i++){
            printf("%d ",T.wadah[i]);
        }
        printf("]\n");
    }

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
    void viewTable (Tabel T){
        /*Kamus Lokal*/
        int i;

        /* Algoritma */
        i=1;
        printf("[ ");
        while(i<=getSize(T)){
            printf("%d ",T.wadah[i]);
            i++;
        }
        printf("]\n");
    }

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
    void populate1 (Tabel *T, int N){
        /* Kamus Lokal */
        int input, i;

        /* Algoritma */
        printf("masukkan angka angka >0 %d kali atau hingga tabel penuh :\n",N);
        if (isFullTable(*T)) {
            printf("Tabel sudah penuh\n");
        } else {
            for (i = 0; i < N; i++) {
                if (isFullTable(*T)) {
                    printf("Tabel sudah penuh\n");
                    break; 
                }
                printf("masukkan satu nilai elemen selanjutnya : ");
                do {
                    scanf("%d", &input);
                    if (input <= 0) {
                    printf("Input tidak valid, masukkan lagi : ");
                    }
                }  while (input <= 0);// Ulangi sampai input > 0
                (*T).wadah[(*T).size+1] = input;
                (*T).size += 1; 

                // Nampilin tiap pengisian
                printf("pengisian elemen ke-%d: ", (*T).size);
                printTable(*T);
                }
        }
    }

/*procedure populate2 ( input/output T:Tabel )
    {I.S.: T terdefinisi}
    {F.S.: T.wadah terisi beberapa elemen positif}
    {Proses: mengisi elemen T.wadah berulang, bila angka 
    dari keyboard <=0 maka berhenti, tidak diproses}
    {Syarat: angka-angka masukan keyboard > 0 }*/
    void populate2 (Tabel *T) {
        /* Kamus Lokal */
        int input;

        /* Algoritma */
        if (isFullTable(*T)) {
            printf("Tabel sudah penuh\n");
        } else {
            printf("Masukkan angka-angka positif (<= 0 untuk berhenti):\n");
            while (!isFullTable(*T)) {
                printf("Masukkan nilai elemen selanjutnya: ");
                scanf("%d", &input);

                if (isFullTable(*T)) {
                    printf("Tabel sudah penuh.\n");
                    break;
                } else if (input <= 0) {
                    printf("Angka <=0 terdeteksi, STOP\n");
                    break;
                } else{
                    (*T).wadah[(*T).size+1] = input;
                    (*T).size += 1;
                }

                // Nampilin tiap pengisian
                printf("Pengisian elemen ke-%d: ", (*T).size);
                printTable(*T);
            }
        }
    }
/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
    int SumEl (Tabel T){
        /* Kamus Lokal */
        int i;
        int sum;
        
        /* Algoritma */
        if(isEmptyTable(T)){
            return -999;
        } else{
            sum = 0;
            for( i=1; i<=getSize(T);i++ ){
                sum += T.wadah[i];
            } return sum;
        }
    }

/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
    float AverageEl(Tabel T){
        /* Kamus Lokal */
        int i;
        float sum;

        /* Algoritma */
        if(isEmptyTable(T)){
            return -999.0;
        } else{
            sum = 0;
            for( i=1; i<=getSize(T);i++ ){
                sum += T.wadah[i];
            } return (float)sum/getSize(T);
        }
    }

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
    int getMaxEl(Tabel T){
        /* Kamus Lokal */
        int i;
        int NilMax;

        /* Algoritma */
        if (isEmptyTable(T)) {
            return -999;
        } else {
            NilMax = T.wadah[1];
            for( i=2; i<=getSize(T);i++ ){
                if(NilMax < T.wadah[i]){
                    NilMax = T.wadah[i];
                }
            } return NilMax;
        }
    }

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl(Tabel T){
        /* Kamus Lokal */
        int i;
        int NilMin;

        /* Algoritma */
        if (isEmptyTable(T)) {
            return -999;
        }
        else {
            NilMin = T.wadah[1];
            for( i=2; i<=getSize(T);i++ ){
                if(NilMin > T.wadah[i]){
                    NilMin = T.wadah[i];
                }
            } return NilMin;
        }
    }

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
    int Modus (Tabel T){
        /* Kamus Lokal */
        int mds;       
        int maxCount;    /* Kemunculan elemen terbanyak*/
        int nowCount;    /* Pembanding kemunculan */

        /* Algoritma */
        if (isEmptyTable(T)) {
            return -999;
        }
        else{
            mds = T.wadah[0];
            maxCount = countX(T, mds);

            for (int i = 1; i <= T.size; i++) {
                nowCount = countX(T, T.wadah[i]);
                if (nowCount > maxCount) {
                    mds = T.wadah[i];
                    maxCount = nowCount;
                }
            }
            return mds;
        }
    }

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
    void sortAsc(Tabel *T) {
        /* Kamus Lokal */
        int i, j;
        int Temp;  /* Tukar harga */

        /* Algoritma */
        for (i = 1; i < getSize(*T); i++) { 
            for (j = 1; j <= getSize(*T) - i; j++) { 
                if ((*T).wadah[j] > (*T).wadah[j + 1]) { 
                    Temp = (*T).wadah[j];                    //Tukar
                    (*T).wadah[j] = (*T).wadah[j + 1];     
                    (*T).wadah[j + 1] = Temp;
                }
            }
        }
    }


/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
    void sortDesc(Tabel *T) {
        /* Kamus Lokal */
        int i, j;
        int Temp;  /* Tukar harga */

        /* Algoritma */
        for (i = 1; i < getSize(*T); i++) { 
            for (j = 1; j <= getSize(*T) - i; j++) { 
                if ((*T).wadah[j] < (*T).wadah[j + 1]) { 
                    Temp = (*T).wadah[j];
                    (*T).wadah[j] = (*T).wadah[j + 1];
                    (*T).wadah[j + 1] = Temp;
                }
            }
        }
    }

#endif