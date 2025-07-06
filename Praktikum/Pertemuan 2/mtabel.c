#include <stdio.h>
#include <string.h>
#include "tabel.c"
/* Deskripsi : driver ADT tabel integer*/
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 07/09/2024*/
/***********************************/

int main(){
	// KAMUS GLOBAL
	Tabel T;
	int X; // untuk menyimpan input X dan N
	char input[3] ;
	// ALGORITMA
	// Pembuatan tabel
	strcpy(input, "0");
	createTable(&T); // Inisialisasi agar tidak erRAWR
	printf("***** Selamat Datang di Driver Program Tabel *****\n");
	printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi     *****\n");
	printf("   1    : Inisialisasi tabel baru\n");
	printf("   2    : Mengecek ukuran tabel\n");
	printf("   3    : Mengecek apakah tabel tidak terisi\n");
	printf("   4    : Mengecek apakah tabel penuh\n");
	printf("   5    : Mencari elemen X\n");
	printf("   6    : Menghitung banyak elemen X\n");
	printf("   7    : Menghitung wadah yang masih kosong\n");
	printf("   8    : Menambah elemen X\n");
	printf("   9    : Menghapus satu elemen X\n");
	printf("   10   : Menghapus semua elemen X\n");
	printf("   11   : Print tabel sebenarnya\n");
	printf("   12   : Print tabel terisi\n");
	printf("   13   : Mengisi tabel sebanyak N kali\n");
	printf("   14   : Mengisi tabel dengan elemen positif\n");
	printf("   15   : Menjumlahkan elemen tabel\n");
	printf("   16   : Menghitung rata-rata elemen tabel\n");
	printf("   17   : Mencari nilai maksimal tabel\n");
	printf("   18   : Mencari nilai minimal tabel\n");
	printf("   19   : Mencari modus tabel\n");
	printf("   20   : Menyortir naik tabel\n");
	printf("   21   : Menyortir turun tabel\n");
	printf("   Q    : Keluar program\n");

	while(strcmp(input, "Q") != 0){
		printf("@@ Masukan pilihan: ");
		scanf (" %s", &input);
		if     (strcmp(input, "1") == 0){
			createTable(&T);
			printf("Inisialisasi tabel berhasil\n");
		}
		else if(strcmp(input, "2") == 0){
			printf("Ukuran tabel: %d\n", getSize(T));
		}
		else if(strcmp(input, "3") == 0){
			if(isEmptyTable(T)){
				printf("Tabel kosong\n");
			}
			else{
				printf("Tabel tidak kosong\n");
			}
		}
		else if(strcmp(input, "4") == 0){
			if(isFullTable(T)){
				printf("Tabel penuh\n");
			}
			else{
				printf("Tabel tidak penuh\n");}
		}
		else if(strcmp(input, "5") == 0){
			printf("$$ Masukan X: ");
			scanf (" %d", &X);
			printf("Elemen %d pertama ada pada index ke-%d\n", X, searchX(T,X));
		}
		else if(strcmp(input, "6") == 0){
			printf("$$ Masukan X: ");
			scanf (" %d", &X);
			printf("Banyak elemen %d pada tabel: %d\n", X, countX(T,X));
		}
		else if(strcmp(input, "7") == 0){
			printf("Banyak wadah tidak terisi pada tabel: %d\n", countEmpty(T));
		}
		else if(strcmp(input, "8") == 0){
			printf("$$ Masukan X: ");
			scanf (" %d", &X);
			if(!(isFullTable(T))){
				addXTable(&T,X);
				printf("Elemen %d berhasil ditambahkan ke tabel. Print tabel untuk mengecek\n", X);
			}
			else{
				printf("Tabel sudah penuh. Hapus salah satu elemen tabel untuk menambahkan elemen baru\n");
			} 
				addXTable(&T,X);
		}
		else if(strcmp(input, "9") == 0){
			printf("$$ Masukan X: ");
			scanf (" %d", &X); 
			if(!(isEmptyTable(T))){ // Tidak kosong dan ditemukan
				delXTable(&T,X);
				printf("Satu elemen %d berhasil dihapus dari tabel. Print tabel untuk mengecek\n", X);
			}
			else{
				printf("Tabel kosong atau elemen tidak ada pada tabel. Tidak ada elemen untuk dihapus\n");
			}
		}
		else if(strcmp(input, "10") == 0){
			printf("$$ Masukan X: ");
			scanf (" %d", &X); 
			delAllXTable(&T,X);
		}
		else if(strcmp(input, "11") == 0){
			printTable(&T);
		}
		else if(strcmp(input, "12") == 0){
			viewTable(&T);
		}
		else if(strcmp(input, "13") == 0){
			printf("$$ Masukkan N: ");
			scanf(" %d", &X);
			populate1(&T,X);
		}
		else if(strcmp(input, "14") == 0){
			populate2(&T);
		}
		else if(strcmp(input, "15") == 0){
			if(SumEl(T) == -999){
				printf("Tabel tidak ada isinya\n");
			}
			else{
				printf("Jumlah elemen tabel: %d\n", SumEl(T));
			}
		}
		else if(strcmp(input, "16") == 0){
			if(isEmptyTable(T)){
				printf("Tabel tidak ada isinya. Tidak bisa menghitung rata-rata\n");
			}
			else{
				printf("Jumlah elemen tabel: %f\n", AverageEl(T));
			}
		}
		else if(strcmp(input, "17") == 0){
			if(getMaxEl(T) == -999){
				printf("Tabel tidak ada isinya. Tidak bisa mencari elemen terbesar\n");
			}
			else{
				printf("Elemen terbesar: %d\n", getMaxEl(T));
			}
		}
		else if(strcmp(input, "18") == 0){
			if(getMinEl(T) == -999){
				printf("Tabel tidak ada isinya. Tidak bisa mencari elemen terkecil\n");
			}
			else{
				printf("Elemen terkecil: %d\n", getMinEl(T));
			}
		}
		else if(strcmp(input, "19") == 0){
			if(Modus(T) == -999){
				printf("Tabel tidak ada isinya. Tidak bisa mencari modus\n");
			}
			else{
				printf("Modus pada tabel: %d\n", Modus(T));
			}
		}
		else if(strcmp(input, "20") == 0){
			sortAsc(&T);
		}
		else if(strcmp(input, "21") == 0){
			sortDesc(&T);
		}
		else if(strcmp(input, "Q") == 0){
			printf("Keluar dari program\n");
		}
		else{
			printf("Tidak ada pilihan %s\n", input);
		}
	}
	return 0;
}
