#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : membuat body program tabel*/
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 07/09/2024*/
/***********************************/

/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
	// Kamus Lokal
	int i;
	// Algoritma
	(*T).size = 0;
	for(i = 1; i <= 10; i++){
		(*T).wadah[i] = -999;
	}
}

/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
	return T.size;
}

/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
	return T.size == 0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
	return T.size == 10;
}

/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> integer
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
int searchX (Tabel T, int X){
	// Kamus Lokal
	int i = 1;
	// Algoritma
	while(i < T.size && T.wadah[i] != X){
		i++;
	}
	if(T.wadah[i] == X){
		return i;
	}
	else{
		return -999;
	}
}

/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
int countX (Tabel T, int X){
	// Kamus Lokal
	int i, count = 0;
	// Algoritma
	for(i = 1; i <= 10; i++){
		if(T.wadah[i] == X){
			count++;
		}
	}
	return count;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
	// Kamus Lokal
	// Algoritma
	return 10 - getSize(T);
}

/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
	// Kamus Lokal
	// Algoritma
	if(!(isFullTable(*T))){
		(*T).size++;
		(*T).wadah[getSize(*T)] = X;
	}
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
	// Kamus Lokal
	int i, Pos;
	// Algoritma
	Pos = searchX(*T,X);
	if(!(isEmptyTable(*T)) && Pos != -999){ // Tidak kosong dan ditemukan
		for(i = Pos; i < getSize(*T); i++){
			(*T).wadah[i] = (*T).wadah[i + 1];
		}
		(*T).wadah[getSize(*T)] = -999;
		(*T).size--;
	}
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/

void delAllXTable (Tabel *T, int X){
	// Kamus Lokal
	// int i;
	// Algoritma
	while(!(isEmptyTable(*T)) && searchX(*T,X) != -999){ // Jika tabel tidak kosong dan masih ada X
		delXTable(T,X);
	}
	printf("Semua elemen %d sudah dihapus dari tabel\n");
}

/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel *T){
	// Kamus Lokal
	int i;
	// Algoritma
	printf("Tabel sebenarnya: [");
	for(i = 1; i <= 10; i++){
		printf("%d", (*T).wadah[i]);
		if(i < 10){
			printf(", ");
		}
	}
	printf("]\n");
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel *T){
	// Kamus Lokal
	int i;
	// Algoritma
	printf("Tabel terisi: [");
	for(i = 1; i <= getSize(*T); i++){
		printf("%d", (*T).wadah[i]);
		if(i < getSize(*T)){
			printf(", ");
		}
	}
	printf("]\n");
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
	// Kamus Lokal
	int input;
	// Algoritma
	while(!(isFullTable(*T)) && N != 0){
		printf("$$ Masukkan elemen: ");
		scanf(" %d", &input);
		if(input > 0){
			addXTable(T,input);
			N--;
		}
	}
	printf("Tabel sudah penuh atau input sudah N kali. Print tabel untuk mengecek\n");
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
	// Kamus Lokal
	int input = 1;
	// Algoritma
	while(input > 0 && !(isFullTable(*T))){
		printf("$$ Masukkan elemen: ");
		scanf(" %d", &input);
		addXTable(T,input);
	}
	printf("Tabel sudah penuh atau input <= 0. Print tabel untuk mengecek\n");
}

/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } 
	{Prekondisi: tabel tidak kosong}*/
int SumEl (Tabel T){
	// Kamus Lokal
	int i, sum;
	// ALgoritma
	sum = 0;// inisialisasi
	if(!(isEmptyTable(T))){
		for(i = 1; i <= getSize(T); i++){
			sum = sum + T.wadah[i];
		}
	}
	else{
		sum = -999;
	}
	return sum;
}

/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } 
	{Prekondisi: tabel tidak kosong}*/
float AverageEl (Tabel T){
	// Kamus lokal
	// Algoritma
	return (SumEl(T)/getSize(T)); // Prekondisi tabel tidak kosong
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
	// Kamus Lokal
	int i, max;
	// Algoritma
	max = T.wadah[1];// inisialisasi dengan elemen pertama, -999 jika kosong
	if(!(isEmptyTable(T))){
		for(i = 1; i <= getSize(T); i++){
			if(T.wadah[i] >  max){
				max = T.wadah[i];
			}
		}
	}
	return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
	// Kamus Lokal
	int i, min;
	// Algoritma
	min = T.wadah[1]; // Insialisasi dengan elemen pertama, -999 jika kosong
	if(!(isEmptyTable(T))){
		for(i = 1; i <= getSize(T); i++){
			if(T.wadah[i] <  min){
				min = T.wadah[i];
			}
		}
	}
	return min;
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
	// Kamus Lokal
	int   i, modus;
	// Algoritma
	modus = T.wadah[1]; // Insialisasi dengan elemen pertama, -999 jika kosong
	if(!(isEmptyTable(T))){ 
		for(i = 1; i <= getSize(T); i++){
			// Mengecek apakah elemen pada index ini muncul lebih banyak dari modus pada iterasi sebelumnya 
			if(countX(T, T.wadah[i]) > countX(T, modus)){ 
				modus = T.wadah[i];
			}
		}

	}
	return modus;
}

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
void sortAsc (Tabel *T){
	// Kamus Lokal
	int i, size;
	Tabel Temp;
	// Algoritma
	createTable(&Temp);
	if(getSize(*T) > 1){
		size = getSize(*T); // Harus diinisialisasi karena ukuran tabel tidak bisa dijadikan parameter loop
		for(i = 1; i <= size; i++){
			addXTable(&Temp, getMinEl(*T));
			delXTable(T, getMinEl(*T));
		}
		*T = Temp;
	}
	printf("Tabel sudah terurut naik. Print untuk mengecek\n");
}

/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
void sortDesc (Tabel *T){
	// Kamus Lokal
	int i, size;
	Tabel Temp;
	// Algoritma
	createTable(&Temp);
	if(getSize(*T) > 1){
		size = getSize(*T); // Harus diinisialisasi karena ukuran tabel tidak bisa dijadikan parameter loop
		for(i = 1; i <= size; i++){
			addXTable(&Temp, getMaxEl(*T));
			delXTable(T, getMaxEl(*T));
		}
		*T = Temp;
	}
	printf("Tabel sudah terurut turun. Print untuk mengecek\n");
}

#endif