/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 20//09/2024*/
/***********************************/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "tstack.c"

boolean isPalindrom(char *T){
	/*Kamus Lokal*/
	int i, j;
	char e;
	Tstack temp;
	/*Algoritma*/
	createStack(&temp);
	j = strlen(T)-1; // index string start dari 0, -1
	for(i=0; i<=(strlen(T)/2)-1; i++){
		push(&temp, T[j]); // yang di belakang masuk stack
		if(T[i] == infotop(temp)){ // yang depan bandingin dg infotop temp
			pop(&temp, &e);
		}
		else{ // klo beda break 
			return false;
		}
		j--;
	}
	return true; 
}

int main(){	
	/*Kamus*/
	int N;
	Tstack A; // variabel A bertipe tStack
	char C[20], Menu[3], E;  // maks 19 huruf include spasi (untuk isPalindrom)
	
	/*ALGORITMA*/

	/*Inisialisasi*/
	createStack(&A);
	strcpy(Menu, "0");
	
	/*Menampilkan Pilihan Menu*/
	printf("***** Selamat Datang di Driver Program Stack *****\n");
	printf("***** ***** ***Menu yang Ditawarkan*** ***** *****\n");
	printf("Pilihan :               Deskripsi            *****\n");
	printf("   1    : Inisialisasi stack\n");
	printf("   2    : Mengeluarkan nilai top stack\n");
	printf("   3    : Mengeluarkan elemen top stack\n");
	printf("   4    : Mengecek apakah stack kosong\n");
	printf("   5    : Mengecek apakah stack penuh\n");
	printf("   6    : Push elemen ke top stack\n");
	printf("   7    : Pop elemen top stack\n");
	printf("   8    : Print stack\n");
	printf("   9    : View stack\n");
	printf("   10   : Mengecek apakah string Palindrom\n");
	printf("   11   : Push elemen sebanyak N\n");
	printf("   12   : Push Babel 1\n");
	printf("   13   : Push Zuma\n");
	printf("   Q    : Keluar program\n\n");

	/*Loop program*/
	while(strcmp(Menu, "Q") != 0){
		printf("~~ Masukan pilihan: ");
		scanf (" %s", &Menu);

		if     (strcmp(Menu, "1") == 0){
			printf("   1    : Inisialisasi stack\n");
			createStack(&A);
			printf("Stack berhasil dibuat\n");
		}
		else if(strcmp(Menu, "2") == 0){
			printf("   2    : Mengeluarkan nilai top stack\n");
			printf("Top stack: %d\n", top(A));
		}
		else if(strcmp(Menu, "3") == 0){
			printf("   3    : Mengeluarkan elemen top stack\n");
			printf("Elemen top stack : %c", infotop(A));
		}
		else if(strcmp(Menu, "4") == 0){
			printf("   4    : Mengecek apakah stack kosong\n");
			if(isEmptyStack(A)){
				printf("Stack kosong\n");
			}
			else{
				printf("Stack tidak kosong\n");
			}
		}
		else if(strcmp(Menu, "5") == 0){
			printf("   5    : Mengecek apakah stack penuh\n");
			if(isFullStack(A)){
				printf("Stack penuh\n");
			}
			else{
				printf("Stack tidak penuh\n");
			}
		}
		else if(strcmp(Menu, "6") == 0){
			printf("   6    : Push elemen ke top stack\n");
			if(!(isFullStack(A))){
				printf("$$ Masukkan elemen (character): "); scanf(" %c", &E);
				viewStack(A); printf("  %c ~~~~~ \n", E);
				push(&A,E);
				viewStack(A); printf("\n");				
			}
			else{
				printf("Stack sudah penuh. Pop satu elemen untuk push elemen baru\n");
			}
		}
		else if(strcmp(Menu, "7") == 0){
			printf("   7    : Pop elemen top stack\n");
			if(!(isEmptyStack(A))){
				viewStack(A); printf("\n");
				pop(&A,&E);
				viewStack(A); printf("  -----> ~~~ %c\n", E);				
			}
			else{
				printf("Stack kosong tidak ada elemen untuk pop\n");
			}
		}
		else if(strcmp(Menu, "8") == 0){
			printf("   8    : Print stack\n");
			printf("Menampilkan wadah stack seutuhnya\n");
			printStack(A); printf("\n");
		}
		else if(strcmp(Menu, "9") == 0){
			printf("   9    : View stack\n");
			printf("Menampilkan wadah stack yang terisi\n");
			viewStack(A); printf("\n");
		}
		else if(strcmp(Menu, "10") == 0){
			printf("   10   : Mengecek apakah string Palindrom\n");
			printf("Masukkan string (max 19 huruf tanpa spasi, ex: AYAM_GEPREK): "); scanf(" %s", &C);

			if(isPalindrom(C)){
				printf("String %s merupakan PALINDROM\n", C);
			}
			else{
				printf("String %s BUKAN PALINDROM\n", C);
			}
		}
		else if(strcmp(Menu, "11") == 0){
			printf("   11   : Push elemen sebanyak N\n");
			printf("$$ Masukkan N: "); scanf(" %d", &N);
			printf("Stack awal: "); viewStack(A); printf("\n");
			pushN(&A,N);
			printf("Stack akhir: "); viewStack(A); printf("\n");
		}
		else if(strcmp(Menu, "12") == 0){
			printf("   12   : Push Babel 1\n");
			printf("$$ Masukkan elemen (character): "); scanf(" %c", &E);
			pushBabel1(&A,E);
		}
		else if(strcmp(Menu, "13") == 0){
			printf("   13   : Push Zuma\n");
			printf("$$ Masukkan elemen (character): "); scanf(" %c", &E);
			pushZuma(&A,E);
		}
		else if(strcmp(Menu, "Q") == 0){
			printf("Keluar dari program ~~~~~\n");
		}
		else{
			printf("Tidak ada pilihan menu %s", Menu);
		}
	}

	return 0;
}
