/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 15/09/2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "matriks.c"

int main(){
	/*kamus*/
	int M, X, row, col; /*Untuk menyimpan input dan output*/
    float F; /*Untuk menyimpan output*/
    boolean B; /*Untuk menyimpan output*/
	Matriks M1, M2, temp;
	char input[3]; /*Untuk input pilihan menu*/

	/*ALGORITMA*/

    /*Inisialisasi*/
	strcpy(input, "0");
	initMatriks(&M1); initMatriks(&M2);

	/*Menampilkan pilihan menu*/
	printf("*****Selamat Datang di Driver Program Matriks*****\n");
	printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi            *****\n");
	printf("   1    : Inisialisasi matriks\n");
	printf("   2    : Mengecek baris matriks\n");
	printf("   3    : Mengecek kolom matriks\n");
	printf("   4    : Mengecek apakah matriks kosong\n");
	printf("   5    : Mengecek apakah matriks penuh\n");
	printf("   6    : Mencari keberadaan elemen X\n");
	printf("   7    : Menghitung banyak elemen X\n");
	printf("   8    : Menambah elemen X ke matriks\n");
	printf("   9    : Mengedit elemen menjadi X\n");
	printf("   10   : Menghapus satu elemen X\n");
	printf("   11   : Mengisi matriks sebesar BARIS kali KOLOM dengan angka random\n");
    printf("   12   : Mengisi matriks N kali N dengan matriks identitas\n");
	printf("   13   : Mengisi matriks sesuai inputan\n");
	printf("   14   : Menampilkan matriks sebenarnya\n");
	printf("   15   : Menampilkan matriks yang terisi\n");
	printf("   16   : Menjumlahkan dua matriks\n");
	printf("   17   : Mengurangkan dua matriks\n");
	printf("   18   : Mengalikan dua matriks\n");
	printf("   19   : Mengalikan matriks dengan skalar\n");
	printf("   20   : Menjumlahkan semua elemen matriks\n");
	printf("   21   : Menghitung rata-rata elemen matriks\n");
	printf("   22   : Mencari elemen terbesar matriks\n");
    printf("   23   : Mencari elemen terkecil matriks\n");
	printf("   24   : Mengubah matriks menjadi transposenya\n");
	printf("   25   : Mengeluarkan matrks hasil transposenya\n");
	printf("   Q    : Keluar program\n\n");

	/*Loop untuk memulai program*/
	while(strcmp(input, "Q") != 0){
		printf("@@ Masukan pilihan: ");
		scanf (" %s", &input);
		if     (strcmp(input, "1") == 0){
            printf("   1    : Inisialisasi matriks\n");
            printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    initMatriks(&M1);
                }
                else{
                    initMatriks(&M2);
                }
                printf("Inisialisasi matriks M%d berhasil\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
		else if(strcmp(input, "2") == 0){
            printf("   2    : Mengecek baris matriks\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    X = getNBaris(M1);
                }
                else{
                    X = getNBaris(M2);
                }
                printf("Banyak BARIS matriks M%d : %d\n", M, X);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
		else if(strcmp(input, "3") == 0){
            printf("   3    : Mengecek kolom matriks\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    X = getNKolom(M1);
                }
                else{
                    X = getNKolom(M2);
                }
                printf("Banyak KOLOM matriks M%d : %d\n", M, X);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "4") == 0){
            printf("   4    : Mengecek apakah matriks kosong\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    B = isEmptyMatriks(M1);
                }
                else{
                    B = isEmptyMatriks(M2);
                }
                
                if(B){
                    printf("Matriks M%d KOSONG\n", M);
                }
                else{
                    printf("Matriks M%d TIDAK KOSONG\n", M);
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "5") == 0){
            printf("   5    : Mengecek apakah matriks penuh\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    B = isFullMatriks(M1);
                }
                else{
                    B = isFullMatriks(M2);
                }
                
                if(B){
                    printf("Matriks M%d PENUH\n", M);
                }
                else{
                    printf("Matriks M%d TIDAK PENUH\n", M);
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "6") == 0){
            printf("   6    : Mencari keberadaan elemen X\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("Masukan X : "); scanf(" %d", &X);
                if(M == 1){
                    searchX(M1, X, &row, &col);
                }
                else{
                    searchX(M2, X, &row, &col);
                }

                if(row != -999){
                    printf("Letak elemen %d pada matriks M%d ada pada BARIS ke-%d dan KOLOM ke-%d\n", X, M, row, col);
                }
                else{
                    printf("Tidak ada elemen %d pada matriks M%d", X, M);
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "7") == 0){
            printf("   7    : Menghitung banyak elemen X\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                if(M == 1){
                    row = countX(M1, X);
                }
                else{
                    row = countX(M2, X);
                }
                printf("Banyak elemen %d pada matriks M%d = %d\n", X, M, row);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "8") == 0){
            printf("   8    : Menambah elemen X ke matriks\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                printf("@@ Baris : "); scanf(" %d", &row);
                printf("@@ Kolom : "); scanf(" %d", &col);
                if(M == 1){
                    addX(&M1, X, row, col);
                }
                else{
                    addX(&M2, X, row, col);
                }
                printf("Elemen %d berhasil ditambahkan pada matriks M%d\nPrint untuk mengecek\n", X, M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "9") == 0){
            printf("   9    : Mengedit elemen menjadi X\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                printf("@@ Baris : "); scanf(" %d", &row);
                printf("@@ Kolom : "); scanf(" %d", &col);
                if(M == 1){
                    editX(&M1, X, row, col);
                }
                else{
                    editX(&M2, X, row, col);
                }
                printf("Elemen %d berhasil diedit ke matriks M%d\nPrint untuk mengecek\n", X, M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "10") == 0){
            printf("   10   : Menghapus satu elemen X\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                if(M == 1){
                    searchX(M1, X, &row, & col);
                    if(row != -999){ /*Ditemukan*/
                        delX(&M1, X);
                    }
                }
                else{
                    searchX(M2, X, &row, & col);
                    if(row != -999){ /*Ditemukan*/
                        delX(&M2, X);
                    }
                }

                if(row != -999){
                    printf("Elemen %d berhasil dihapus dari matriks M%d\nPrint untuk mengecek\n", X, M);
                }
                else{
                    printf("Tidak ditemukan %d pada matriks M%d\n", X, M);
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "11") == 0){
            printf("   11   : Mengisi matriks sebesar BARIS kali KOLOM dengan angka random\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Baris : "); scanf(" %d", &row);
                printf("@@ Kolom : "); scanf(" %d", &col);
                if(M == 1){
                    isiMatriksRandom(&M1, row, col);
                }
                else{
                    isiMatriksRandom(&M2, row, col);
                }
                printf("Matriks M%d berhasil diisi secara random\nPrint untuk mengecek\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "12") == 0){
            printf("   12   : Mengisi matriks N kali N dengan matriks identitas\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan N : "); scanf(" %d", &X);
                if(M == 1){
                    isiMatriksIdentitas(&M1, X);
                }
                else{
                    isiMatriksIdentitas(&M2, X);
                }
                printf("Matriks M%d berhasil diisi dengan matriks identitas\nPrint untuk mengecek\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "13") == 0){
            printf("   13   : Mengisi matriks sesuai inputan\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                printf("@@ Baris : "); scanf(" %d", &row);
                printf("@@ Kolom : "); scanf(" %d", &col);
                if(M == 1){
                    populateMatriks(&M1, row, col);
                }
                else{
                    populateMatriks(&M2, row, col);
                }
                printf("Matriks M%d berhasil diisi\nPrint untuk mengecek\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "14") == 0){
            printf("   14   : Menampilkan matriks sebenarnya\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    printMatriks(M1);
                }
                else{
                    printMatriks(M2);
                }
                printf("telah ditampilkan matriks M%d\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "15") == 0){
            printf("   15   : Menampilkan matriks yang terisi\n");
			printf("@@ Matriks M1 atau M2\n@@ M");
			scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    viewMatriks(M1);
                }
                else{
                    viewMatriks(M2);
                }
                printf("telah ditampilkan matriks M%d\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "16") == 0){
            printf("   16   : Menjumlahkan dua matriks\n");
            // temp = addMatriks(M1, M2);
            if(!(isEmptyMatriks(addMatriks(M1, M2)))){
                printf("Menampilkan hasil PENJUMLAHAN matriks M1 dan M2\n");
                viewMatriks(addMatriks(M1, M2));
            }
            else{
                printf("Ukuran matriks tidak sama. Penjumlahan matriks tidak bisa dilakukan.\n");
            }
		}
        else if(strcmp(input, "17") == 0){
            printf("   17   : Mengurangkan dua matriks\n");
            // temp = addMatriks(M1, M2);
            if(!(isEmptyMatriks(subMatriks(M1, M2)))){
                printf("Menampilkan hasil PENGURANGAN matriks M1 dan M2\n");
                viewMatriks(addMatriks(M1, M2));
            }
            else{
                printf("Ukuran matriks tidak sama. Pengurangan matriks tidak bisa dilakukan.\n");
            }
		}
        else if(strcmp(input, "18") == 0){
            printf("   18   : Mengalikan dua matriks\n");
            if(!(isEmptyMatriks(kaliMatriks(M1, M2)))){
                printf("Menampilkan hasil PENGURANGAN matriks M1 dan M2\n");
                viewMatriks(kaliMatriks(M1, M2));
            }
            else{
                printf("Ukuran matriks tidak cocok. Perkalian matriks tidak bisa dilakukan.\n");
            }
		}
        else if(strcmp(input, "19") == 0){
            printf("   19   : Mengalikan matriks dengan skalar X\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                printf("@@ Masukan X : "); scanf(" %d", &X);
                if(M == 1){
                    temp = kaliSkalarMatriks(M1, X);
                }
                else{
                    temp = kaliSkalarMatriks(M2, X);
                }
                
                if(!(isEmptyMatriks(temp))){
                    printf("Menampilkan hasil PERKALIAN SKALAR matriks M%d\n", M);
                    viewMatriks(temp);
                }
                else{
                    printf("Matriks kosong, perkalian skalar matriks tidak bisa dilakukan.\n");
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "20") == 0){
            printf("   20   : Menjumlahkan semua elemen matriks\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    X = getSumMatriks(M1);
                    B = isEmptyMatriks(M1);
                }
                else{
                    X = getSumMatriks(M2);
                    B = isEmptyMatriks(M2);
                }
                
                if(!(B)){
                    printf("Menampilkan hasil PENJUMLAHAN elemen matriks M%d : %d\n", M, X);
                }
                else{
                    printf("Matriks kosong, tidak ada elemen untuk dijumlahkan.\n");
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "21") == 0){
            printf("   21   : Menghitung rata-rata elemen matriks\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    F = getAverageMatriks(M1);
                    B = isEmptyMatriks(M1);
                }
                else{
                    F = getAverageMatriks(M2);
                    B = isEmptyMatriks(M2);
                }
                
                if(!(B)){
                    printf("Menampilkan RATA-RATA elemen matriks M%d : %f\n", M, F);
                }
                else{
                    printf("Matriks kosong, tidak ada elemen untuk dihitung.\n");
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "22") == 0){
            printf("   22   : Mencari elemen terbesar matriks\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    X = getMaxMatriks(M1);
                    B = isEmptyMatriks(M1);
                }
                else{
                    X = getMaxMatriks(M2);
                    B = isEmptyMatriks(M2);
                }
                
                if(!(B)){
                    printf("Menampilkan NILAI TERBESAR matriks M%d : %d\n", M, X);
                }
                else{
                    printf("Matriks kosong, tidak ada elemen untuk dibandingkan.\n");
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "23") == 0){
            printf("   23   : Mencari elemen terkecil matriks\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    X = getMinMatriks(M1);
                    B = isEmptyMatriks(M1);
                }
                else{
                    X = getMinMatriks(M2);
                    B = isEmptyMatriks(M2);
                }
                
                if(!(B)){
                    printf("Menampilkan NILAI TERKECIL matriks M%d : %d\n", M, X);
                }
                else{
                    printf("Matriks kosong, tidak ada elemen untuk dibandingkan.\n");
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "24") == 0){
            printf("   24   : Mengubah matriks menjadi transposenya\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            if(M == 1 || M == 2){
                if(M == 1){
                    transposeMatriks(&M1);
                }
                else{
                    transposeMatriks(&M2);
                }
                
                printf("Matriks M%d telah diubah menjadi transposenya\nPrint untuk melihat.\n", M);
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
        else if(strcmp(input, "25") == 0){
            printf("   25   : Mengeluarkan matrks hasil transposenya\n");
            printf("@@ Matriks M1 atau M2\n@@ M"); scanf(" %d", &M);
            printf("Menampilkan transpose matriks M%d\n", M);
            if(M == 1 || M == 2){
                if(M == 1){
                    viewMatriks(getTransposeMatriks(M1));
                }
                else{
                    viewMatriks(getTransposeMatriks(M2));
                }
            }
            else{
                printf("Tidak ada pilihan matriks M%d\n", M);
            }
		}
		else{
			printf("Tidak ada pilihan menu %s\n", input);
		}
	}

	return 0;
}
