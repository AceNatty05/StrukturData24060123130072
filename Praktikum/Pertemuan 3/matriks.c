/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 15/09/2024*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    /*Kamus Lokal*/
    int i,j;
    /*Algoritma*/
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
int getNBaris(Matriks M){
    /*Kamus Lokal*/
    /*Algoritma*/
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    /*Kamus Lokal*/
    /*Algoritma*/
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    /*Kamus Lokal*/
    /*Algoritma*/
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    /*Kamus Lokal*/
    /*Algoritma*/
    return getNBaris(M) == 10 && getNKolom(M) == 10;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    /*row & col untuk menyimpan indeks X pertama yang ditemukan*/
    *row = -999; *col = -999; /*Inisialisasi, jika nanti tidak ketemu maka keluar -999*/
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
int countX (Matriks M, int X){
    /*Kamus Lokal*/
    int i, j, count;
    /*Algoritma*/
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
void addX (Matriks *M, int X, int row, int col){
    /*Kamus Lokal*/
    /*Algoritma*/
    /*Penambahan X pada cell matriks tidak memengaruhi nbaris & nkolom*/
    if(!(isFullMatriks(*M)) && (*M).cell[row][col] == -999){
        (*M).cell[row][col] = X;
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col){
    /*Kamus Lokal*/
    /*Algoritma*/
    /*Penggantian isi cell dengan X tidak memengaruhi nbaris & nkolom*/
    (*M).cell[row][col] = X;
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    /*Kamus Lokal*/
    int row, col;
    /*Algoritma*/
    /*Penghapusan cell dengan isi X  tidak memengaruhi nbaris & nkolom*/
    searchX(*M, X, &row, &col); 
    if(col != -999){ // cek row atau col sama saja, jika -999 berarti tidak ketemu
        // editX(M, -999, row, col);
        (*M).cell[row][col] = -999;
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    /*Matriks x kali y diisi dengan angka random tidak peduli isi sebelumnya*/
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            editX(M, rand(), i, j); // editX akan mengubah nilai tidak peduli kosong atau tidak
        }
    }
    (*M).nbaris = x; (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i == j){
                editX(M, 1, i, j); /*Tidak bisa menggunakan addX karena addX 
                mengharuskan cell pada baris row & kolom col tidak ada isinya*/
            }
            else{
                editX(M, 0, i, j);
            }
        }
    }
    /*Setelah diisi, nbaris & nkolom berubah menjadi n*/
    (*M).nbaris = n; (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
    {proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    /*Kamus Lokal*/
    int i, j, input;
    /*Algoritma*/
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            printf("@@ Masukkan elemen: "); scanf(" %d", &input);
            /*Tidak peduli inputnya positif/negatif*/
            editX(M, input, i, j);
        }
    }
    /*nbaris & nkolom berubah menjadi x & y*/
    (*M).nbaris = x; (*M).nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    printf("\n");
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    printf("\n");
    for(i=1; i<=getNBaris(M); i++){
        for(j=1; j<=getNKolom(M); j++){
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
    {mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    int i, j;
    Matriks temp;  
    /*Algoritma*/
    initMatriks(&temp);
    /*Kedua matriks harus full sebesar nbaris kali nkolom, tidak ada yang kosong*/
    if(getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)){
        for(i=1; i<=getNBaris(M1); i++){
            for(j=1; j<=getNKolom(M1); j++){
                addX(&temp, M1.cell[i][j] + M2.cell[i][j], i, j);
            }
        }
        temp.nbaris = getNBaris(M1); 
        temp.nkolom = getNKolom(M1);
    }
    return temp; // Return matriks kosong jika ukurannya tidak sama
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
    {mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    int i, j;
    Matriks temp;  
    /*Algoritma*/
    initMatriks(&temp);
    /*Kedua matriks harus full sebesar nbaris kali nkolom, tidak ada yang kosong*/
    if(getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)){
        for(i=1; i<=getNBaris(M1); i++){
            for(j=1; j<=getNKolom(M1); j++){
                addX(&temp, M1.cell[i][j] - M2.cell[i][j], i, j);
            }
        }
        temp.nbaris = getNBaris(M1); 
        temp.nkolom = getNKolom(M1);
    }
    return temp; // Return matriks kosong jika ukurannya tidak sama
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
    {mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    int i, j, k;
    Matriks temp;
    /*Algoritma*/
    initMatriks(&temp);
    /*Kedua matriks harus full sebesar nbaris kali nkolom, tidak ada yang kosong*/
    if(getNKolom(M1) == getNBaris(M2)){
        for(i=1; i<=getNBaris(M1); i++){
            for(j=1; j<=getNKolom(M2); j++){
                for(k=1; k<=getNKolom(M1); k++){
                    editX(&temp, M1.cell[i][k] * M2.cell[k][j], i, j);
                }
            }
        }
        temp.nbaris = getNBaris(M1); 
        temp.nkolom = getNKolom(M2);
    }
    return temp; // Return matriks kosong jika ukurannya tidak cocok
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
    {mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M, int x){
    /*Kamus Lokal*/
    int i, j;
    Matriks temp;
    /*Algoritma*/
    initMatriks(&temp);
    /*Matriks harus full sebesar nbaris kali nkolom, tidak ada yang kosong*/
    if(!(isEmptyMatriks(M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        for(i=1; i<=getNBaris(M); i++){
            for(j=1; j<=getNKolom(M); j++){
                addX(&temp, M.cell[i][j] * x, i, j);
            }
        }
        temp.nbaris = getNBaris(M); 
        temp.nkolom = getNKolom(M);
    }
    return temp; // Return matriks kosong jika matriksnya kosong
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M){
    /*Kamus Lokal*/
    int i, j, sum;
    /*Algoritam*/
    sum = 0; /*Inisialisasi sum*/
    if(!(isEmptyMatriks(M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        for(i=1; i<=getNBaris(M); i++){
            for(j=1; j<=getNKolom(M); j++){
                sum = sum + M.cell[i][j];
            }
        }
    }
    return sum;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!(isEmptyMatriks(M))){
        return getSumMatriks(M)/(getNBaris(M)*getNKolom(M)); /*Tanpa memorisasi*/
    }
    else{
        return 0; /*Matriks kosong rata-rata kosong*/
    }
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M){
    /*Kamus Lokal*/
    int i, j, max;
    /*Algoritma*/
    max = M.cell[1][1]; /*inisialisasi dengan elemen pertama, -999 jika matriks kosong*/
    if(!(isEmptyMatriks(M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        for(i=1; i<=getNBaris(M); i++){
            for(j=1; j<=getNKolom(M); j++){
                if(M.cell[i][j] > max){
                    max = M.cell[i][j];
                }
            }
        }
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M){
    /*Kamus Lokal*/
    int i, j, min;
    /*Algoritma*/
    min = M.cell[1][1]; /*inisialisasi dengan elemen pertama, -999 jika matriks kosong*/
    if(!(isEmptyMatriks(M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        for(i=1; i<=getNBaris(M); i++){
            for(j=1; j<=getNKolom(M); j++){
                if(M.cell[i][j] < min){
                    min = M.cell[i][j];
                }
            }
        }
    }
    return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    /*Kamus Lokal*/
    int i, j;
    Matriks temp;
    /*Algoritma*/
    if(!(isEmptyMatriks(*M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        initMatriks(&temp);
        for(i=1; i<=getNBaris(*M); i++){
            for(j=1; j<=getNKolom(*M); j++){
                editX(&temp, (*M).cell[i][j], j, i);
            }
        }
        temp.nbaris = getNKolom(*M);
        temp.nkolom = getNBaris(*M);
        *M = temp;
    }
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    /*Kamus Lokal*/
    int i, j;
    Matriks temp;
    /*Algoritma*/
    initMatriks(&temp);
    if(!(isEmptyMatriks(M))){ /*Matriks kosong tidak perlu diapa-apakan*/
        for(i=1; i<=getNBaris(M); i++){
            for(j=1; j<=getNKolom(M); j++){
                editX(&temp, (M).cell[i][j], j, i);
            }
        }
        temp.nbaris = getNKolom(M);
        temp.nkolom = getNBaris(M);
    }
    return temp;
}