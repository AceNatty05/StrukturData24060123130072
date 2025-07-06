/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
// ASUMSI : -999 merupakan elemen kosong (NULL)
void initMatriks(Matriks *M){
    // Kamus Lokal
    int i,j;
    // Algoritma
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0; (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
// ASUMSI : Mengeluarkan berapa banyak baris yang minimal 1 elemennya tidak kosong (-999)
int getNBaris(Matriks M){
    // Kamus Lokal
    int i, j, count, countIsi;
    // Algoritma
    count = 0;
    for(i=1; i<=10; i++){ // cek dari baris lalu ke perkolom
        countIsi = 0;
        for(j=1; j<=10; j++){
            if(M.cell[i][j] != -999){
                countIsi++;
            }
        }
        if(countIsi != 0){
            count++;
        }
    }
    return count;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
// ASUMSI : Mengeluarkan berapa banyak baris yang minimal 1 elemennya tidak kosong (-999)
int getNKolom(Matriks M){
    int i, j, count, countIsi;
    // Algoritma
    count = 0;
    for(j=1; j<=10; j++){ // cek dari kolom lalu ke perbaris
        countIsi = 0;
        for(i=1; i<=10; i++){
            if(M.cell[i][j] != -999){
                countIsi++;
            }
        }
        if(countIsi != 0){
            count++;
        }
    }
    return count;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
// ASUMSI : Jika salah satu elemen saja bukan -999 (NULL) maka false
boolean isEmptyMatriks(Matriks M){
    // Kamus Lokal
    int i, j;
    // Algoritma
    /*
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            if(M.cell[i][j] != -999){
                return false;
            }
        }
    }
    return true;
    */
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
// ASUMSI : Jika salah satu elemen saja merupakan -999 (NULL) maka false
boolean isFullMatriks(Matriks M){
    // Kamus Lokal
    int i, j;
    // Algoritma
    /*
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            if(M.cell[i][j] == -999){
                return false;
            }
        }
    }
    return true;
    */
    return getNBaris(M) == 10 && getNKolom(M) == 10;
}


/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
// ASUMSI : row & col berisi indeks X yang pertama ditemukan jika ketemu
void searchX(Matriks M, int X, int *row, int *col){
    // Kamus Lokal
    int i, j;
    // Algoritma
    *row = -999; *col = -999; // Inisialisasi, jika nanti tidak ketemu maka keluar -999
    if(!(isEmptyMatriks(M))){
        for(i=1; i<=10; i++){
            for(j=1; j<=10; j++){
                if(M.cell[i][j] == X && *row == -999 && *col == -999){
                    *row = i; *col = j;
                }
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
// ASUMSI : jika tidak ada X dalam matriks maka keluar 0
int countX (Matriks M, int X){
    // Kamus Lokal
    int i, j, count;
    // Algoritma
    count = 0;
    if(!(isEmptyMatriks(M))){
        for(i=1; i<=10; i++){
            for(j=1; j<=10; j++){
                if(M.cell[i][j] == X){
                    count++;
                }
            }
        }
    }
    return count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
// ASUMSI : Jika elemen matriks pada baris row kolom col berupa -999 (NULL) maka diganti X, jika ada isinya biarkan
void addX (Matriks *M, int X, int row, int col){
    // Kamus Lokal
    // Algoritma
    if((*M).cell[row][col] == -999){
        (*M).cell[row][col] == X;
        (*M).nbaris = getNBaris(*M);
        (*M).nkolom = getNKolom(*M);
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
// ASUMSI : Tidak peduli apapun isi cell baris row kolom col, timpa dengan X
void editX (Matriks *M, int X, int row, int col){
    // Kamus Lokal
    // Algoritma
    (*M).cell[row][col] == X;
    (*M).nbaris = getNBaris(*M);
    (*M).nkolom = getNKolom(*M);
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
// ASUMSI : Jika X ketemu di elemen M, ganti dengan -999 (NULL)
void delX (Matriks *M, int X){
    // Kamus Lokal
    int row, col;
    // Algoritma
    searchX(*M, X, &row, &col);
    if(col != -999){ // cek row atau col sama saja, jika -999 berarti tidak ketemu
        (*M).cell[row][col] = -999;
        (*M).nbaris = getNBaris(*M);
        (*M).nkolom = getNKolom(*M);
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
// ASUMSI : Matriks sebesar x kali y ditiimpa dengan angka random jika sebelumnya elemennya -999 (NULL)
void isiMatriksRandom(Matriks *M, int x, int y){
    // Kamus Lokal
    int i, j;
    // ALgoritma
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            addX(*M, rand(), i, j);
            // (*M).cell[i][j] = rand();
        }
    }
    (*M).nbaris = getNBaris(*M);
    (*M).nkolom = getNKolom(*M);
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
// ASUMSI : cell dengan indeks baris != kolom diisi dengan -999 (NULL)
void isiMatriksIdentitas(Matriks *M, int n){
    // Kamus Lokal
    int i, j;
    // Algoritma
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i == j){
                (*M).cell[i][j] = 1; /*Tidak bisa menggunakan addX karena addX 
                mengharuskan cell pada baris row & kolom col tidak ada isinya*/
            }
            else{
                (*M).cell[i][j] = -999;
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
    {proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
// ASUMSI : inputan harus >0 (positif), cell yang sudah ada isinya (!= -999 ) tidak akan diganti isinya
void populateMatriks(Matriks *M, int x, int y){
    // Kamus Lokal
    int i, j, input;
    // Algoritma
    i = 1; j = 1; 
    printf("Masukkan input: "); scanf(" %d", &input);
    while
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M);

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M);

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2);

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2);

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2);

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x);

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M);

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M);

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M);

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M);

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M);

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M);