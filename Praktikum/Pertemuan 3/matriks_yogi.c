/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
/* include matriks.h & boolean.h */

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            (*M).cell[i][j] = -999;
        }
    } 
    (*M).nkolom = 0;
    (*M).nbaris = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
   {mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    /* Kamus Lokal */
    int i, j;
    int count = 0;
    int isRowFilled;

    /* Algoritma */
    for (i = 1; i <= 10; i++) {
        isRowFilled = 0;
        for (j = 1; j <= 10; j++) {
            if (M.cell[i][j] != -999) {
                isRowFilled = 1;  // Baris ini terisi
                break;
            }
        }
        if (isRowFilled) {
            count = i;  // Simpan indeks baris terakhir yang terisi
        }
    }
    return count;
}

/* function getNKolom(M: Matriks) -> integer
   {mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    /* Kamus Lokal */
    int i, j;
    int count = 0;
    int isColumnFilled;

    /* Algoritma */
    for (j = 1; j <= 10; j++) {
        isColumnFilled = 0;
        for (i = 1; i <= 10; i++) {
            if (M.cell[i][j] != -999) {
                isColumnFilled = 1;  // Kolom ini terisi
                break;
            }
        }
        if (isColumnFilled) {
            count = j;  // Simpan indeks kolom terakhir yang terisi
        }
    }
    return count;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++) {
        for(j = 1; j <= getNKolom(M); j++) {
            if(M.cell[i][j] != -999) {
                return false; // Ada elemen yang terisi
            }
        }
    }
    return true; // Semua elemen kosong
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++) {
        for(j = 1; j <= getNKolom(M); j++) {
            if(M.cell[i][j] == -999) {
                return false; // Ada elemen yang kosong
            }
        }
    }
    return true; // Semua elemen terisi
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    *row = -999; // Default jika tidak ditemukan
    *col = -999; // Default jika tidak ditemukan
    
    if(!isEmptyMatriks(M)) {
        for(i = 1; i <= getNBaris(M); i++) {
            for(j = 1; j <= getNKolom(M); j++) {
                if(M.cell[i][j] == X) {
                    *row = i;
                    *col = j;
                    break;
                }
            } break;
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X) {
    /* Kamus Lokal */
    int i, j;
    int Count = 0;

    /* Algoritma */
    if(!isEmptyMatriks(M)) {
        for(i = 1; i <= getNBaris(M); i++) {
            for(j = 1; j <= getNKolom(M); j++) {
                if(M.cell[i][j] == X) {
                    Count++;
                }
            }
        }
    }
    return Count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col) {
    /* Kamus Lokal */
    /* Algoritma */
    if(row <= 10 && col <= 10 && (*M).cell[row][col] == -999) {
        (*M).cell[row][col] = X;
        (*M).nbaris = getNBaris(*M);
        (*M).nkolom = getNKolom(*M);
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX(Matriks *M, int X, int row, int col) {
    /* Kamus Lokal */
    /* Algoritma */
    if(row <= 10 && col <= 10) {
        (*M).cell[row][col] = X;
        (*M).nbaris = getNBaris(*M);
        (*M).nkolom = getNKolom(*M);
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell}*/
void delX(Matriks *M, int X) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 1; i <= getNBaris(*M); i++) {
        for(j = 1; j <= getNKolom(*M); j++) {
            if((*M).cell[i][j] == X) {
                (*M).cell[i][j] = -999;
                (*M).nbaris = getNBaris(*M);
                (*M).nkolom = getNKolom(*M);
                return; // Keluar dari loop setelah elemen ditemukan dan dihapus
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y}
    {maksimal x dan y adalah 10} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    if(x <= 10 && y <= 10) {
        for(i = 1; i <= x; i++) {
            for(j = 1; j <= y; j++) {
                editX(M, rand()%1000, i, j);
            }
        }
    } else {
        for(i = 1; i <= 10; i++) {
            for(j = 1; j <= 10; j++) {
                editX(M, rand()%1000, i, j);
            }
        }
    }
    (*M).nbaris = getNBaris(*M);
    (*M).nkolom = getNKolom(*M);
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    if(n <= 10) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(i == j) {
                    editX(M, 1, i, j);
                } else {
                    editX(M, 0, i, j);
                }
            }
        }
    } else {
        for(i = 1; i <= 10; i++) {
            for(j = 1; j <= 10; j++) {
                if(i == j) {
                    editX(M, 1, i, j);
                } else {
                    editX(M, 0, i, j);
                }
            }
        }
    }
    (*M).nbaris = getNBaris(*M);
    (*M).nkolom = getNKolom(*M);
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} 
{Matrik diasumsikan hanya menerima integer, jika kolom ke-i,j sudah terisi, maka ditimpa }*/
void populateMatriks(Matriks *M, int x, int y) {
    /* Kamus Lokal */
    int i, j;
    int masukan;

    /* Algoritma */
    if(x <= 10 && y <= 10) {
        for(i = 1; i <= x; i++) {
            for(j = 1; j <= y; j++) {
                printf("Masukkan elemen Matriks baris ke-%d dan kolom ke-%d: ", i, j);
                scanf("%d", &masukan);
                editX(M, masukan, i, j);
            }
        }
        (*M).nbaris = x;
        (*M).nkolom = y;
    } else {
        printf("Maksimal matriks yang bisa Anda isi adalah 10x10\n");
        for(i = 1; i <= 10; i++) {
            for(j = 1; j <= 10; j++) {
                printf("Masukkan elemen Matriks baris ke-%d dan kolom ke-%d: ", i, j);
                scanf("%d", &masukan);
                editX(M, masukan, i, j);
            }
        }
        (*M).nbaris = 10;
        (*M).nkolom = 10;
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 1; i <= 10; i++){
        printf("|");
        for(j = 1; j <= 10; j++){
            printf(" %4d ", M.cell[i][j]);  // Menentukan lebar kolom 4 karakter
        }
        printf("|\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++) {
        printf("|");
        for(j = 1; j <= getNKolom(M); j++) {
            if(M.cell[i][j] == -999) {
                printf(" %4s ", "X"); // Kosongkan jika elemen -999
            } else {
                printf(" %4d ", M.cell[i][j]); 
            }
        }
        printf("|\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    /* Kamus Lokal */
    int i, j;
    int Sum;
    Matriks Hsl;

    /* Algoritma */
    initMatriks(&Hsl);
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom) {
        Hsl.nbaris = M1.nbaris;
        Hsl.nkolom = M1.nkolom;

        for (i = 1; i <= Hsl.nbaris; i++) {  
            for (j = 1; j <= Hsl.nkolom; j++) {  
                if (M1.cell[i][j] == -999 && M2.cell[i][j] == -999) {
                    Sum = -999;
                } else if (M1.cell[i][j] == -999) {
                    Sum = M2.cell[i][j];  
                } else if (M2.cell[i][j] == -999) {
                    Sum = M1.cell[i][j]; 
                } else {
                    Sum = M1.cell[i][j] + M2.cell[i][j]; 
                }
                Hsl.cell[i][j] = Sum; 
            }
        }
    } else {
        // Matriks tidak sesuai
        initMatriks(&Hsl);
        printf("Dimensi Matriks tidak sesuai\n");
    }
    return Hsl;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    /* Kamus Lokal */
    int i, j;
    int Difference;
    Matriks Hsl;

    /* Algoritma */
    initMatriks(&Hsl);
    if(getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)){
        Hsl.nbaris = getNBaris(M1);
        Hsl.nkolom = getNKolom(M1);

        for(i = 1; i <= Hsl.nbaris; i++){
            for(j = 1; j <= Hsl.nkolom; j++){
                if (M1.cell[i][j] == -999 && M2.cell[i][j] == -999) {
                    Difference = -999;
                } else if (M1.cell[i][j] == -999) {
                    Difference = -M2.cell[i][j];
                } else if (M2.cell[i][j] == -999) {
                    Difference = M1.cell[i][j];
                } else {
                    Difference = M1.cell[i][j] - M2.cell[i][j];
                }
                Hsl.cell[i][j] = Difference; 
            }
        }
    } else {
        initMatriks(&Hsl);
        printf("Dimensi Matriks tidak sesuai\n");
    }
    return Hsl;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2, memperhatikan elemen kosong (-999)} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    /* Kamus Lokal */
    int i, j, k;
    int Sum;
    Matriks Hsl;

    /* Algoritma */
    initMatriks(&Hsl);
    if(getNKolom(M1) == getNBaris(M2)){
        Hsl.nbaris = getNBaris(M1);
        Hsl.nkolom = getNKolom(M2);

        for(i = 1; i <= Hsl.nbaris; i++){
            for(j = 1; j <= Hsl.nkolom; j++){
                Sum = -999;
                for(k = 1; k <= getNKolom(M1); k++){
                    if (M1.cell[i][k] != -999 && M2.cell[k][j] != -999) {
                        Sum += M1.cell[i][k] * M2.cell[k][j];
                    } else if (M1.cell[i][k] == -999 && M2.cell[k][j] != -999) {
                        Sum += M2.cell[k][j]; 
                    } else if (M1.cell[i][k] != -999 && M2.cell[k][j] == -999) {
                        Sum += M1.cell[i][k]; 
                    } 
                }
                Hsl.cell[i][j] = Sum; 
            }
        }
    } else {
        initMatriks(&Hsl);
        printf("Dimensi Matriks tidak sesuai untuk perkalian\n");
    }
    return Hsl;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    /* Kamus Lokal */
    int i, j;
    int Result;
    Matriks Hsl;

    /* Algoritma */
    initMatriks(&Hsl);
    Hsl.nbaris = getNBaris(M1);
    Hsl.nkolom = getNKolom(M1);

    for(i = 1; i <= Hsl.nbaris; i++){
        for(j = 1; j <= Hsl.nkolom; j++){
            if (M1.cell[i][j] == -999) {
                Result = -999;  // Jika elemen kosong, tetap kosong
            } else {
                Result = M1.cell[i][j] * x;
            }
            Hsl.cell[i][j] = Result; 
        }
    }
    return Hsl;
}

/* OPERASI STATISTIKA */
/* function getSumMatriks (M:Matriks) -> integer 
{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;
    int Sum = 0;    /* Menyimpan hasil penjumlahan */

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++){
        for(j = 1; j <= getNKolom(M); j++){
            if(M.cell[i][j] != -999){   /* Hanya hitung elemen yang valid */
                Sum += M.cell[i][j];
            }
        }
    }
    return Sum;
}

/* function getAverageMatriks (M:Matriks) -> real 
{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;
    int Sum = 0;
    int Count = 0;    /* Menyimpan jumlah elemen valid */

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++){
        for(j = 1; j <= getNKolom(M); j++){
            if(M.cell[i][j] != -999){   /* Hanya hitung elemen yang valid */
                Sum += M.cell[i][j];
                Count++;
            }
        }
    }
    if(Count > 0){
        return (float)Sum / Count;
    } else {
        return 0.0;    /* Menghindari pembagian dengan nol jika matriks kosong */
    }
}

/* function getMaxMatriks (M:Matriks) -> integer
{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;
    int Max = -999;  

    /* Algoritma */
    for(i = 1; i <= getNBaris(M); i++){
        for(j = 1; j <= getNKolom(M); j++){
            if(M.cell[i][j] != -999 && M.cell[i][j] > Max){   /* Hanya hitung elemen yang valid */
                Max = M.cell[i][j];
            }
        }
    }
    return Max;
}

/* function getMinMatriks (M:Matriks) -> integer
{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;
    int Min ; 

    /* Algoritma */
    Min = 9999999;
    if(!isEmptyMatriks(M)){
        for(i = 1; i <= getNBaris(M); i++){
            for(j = 1; j <= getNKolom(M); j++){
                if(M.cell[i][j] != -999 && M.cell[i][j] < Min){   /* Hanya hitung elemen yang valid */
                    Min = M.cell[i][j];
                }
            }
        }
    }
    return Min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
{I.S.: M terdefinisi}
{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
/* procedure transposeMatriks(input/output M: Matriks)
    {I.S.: M terdefinisi}
    {F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
    {proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    /* Kamus Lokal */
    int i, j;
    Matriks Temp;   /* Matriks sementara untuk menyimpan hasil transpose */

    /* Algoritma */
    initMatriks(&Temp);  /* Inisialisasi matriks sementara */
    Temp.nbaris = getNKolom(*M);
    Temp.nkolom = getNBaris(*M);

    /* Salin elemen dari M ke Temp dengan transpose */
    for (i = 1; i <= getNBaris(*M); i++) {
        for (j = 1; j <= getNKolom(*M); j++) {
            addX(&Temp, (*M).cell[i][j], j, i);  /* Tukar baris dan kolom */
        }
    }

    /* Update matriks M dengan hasil transpose */
    *M = Temp;
}

/* function getTransposeMatriks(M: Matriks) -> Matriks
    {menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    /* Kamus Lokal */
    int i, j;
    Matriks Temp;   /* Matriks sementara untuk menyimpan hasil transpose */

    /* Algoritma */
    initMatriks(&Temp);  /* Inisialisasi matriks sementara */
    Temp.nbaris = getNKolom(M);
    Temp.nkolom = getNBaris(M);

    /* Salin elemen dari M ke Temp dengan transpose */
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
                    Temp.cell[j][i] = M.cell[i][j];;  /* Tukar baris dan kolom */
        }
    }

    return Temp;
}

