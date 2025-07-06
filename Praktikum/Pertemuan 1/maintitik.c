/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 29 Agustus 2024*/
/***********************************/
#include <stdio.h>
#include "titik.c"

int main() {
	// Kamus Main
	Titik A, B;
	int Ax, Ay, Bx, By;
	
	// Algoritma
	printf("*****Halo, ini driver modul Titik*****\n");
	makeTitik(&A); makeTitik(&B);

	// Input Absis Ordinat
	printf("Masukan absis titik A: ");
	scanf ("%d", &Ax); setAbsis(&A,Ax);
	printf("Masukan ordinat titik A: ");
	scanf ("%d", &Ay); setOrdinat(&A,Ay);
	printf("Telah dibuat Titik A = (%d,%d)\n", getAbsis(A), getOrdinat(A));

	printf("Masukan absis titik B: ");
	scanf ("%d", &Bx); setAbsis(&B,Bx);
	printf("Masukan ordinat titik B: ");
	scanf ("%d", &By); setOrdinat(&B,By);
	printf("Telah dibuat Titik B = (%d,%d)\n", getAbsis(B), getOrdinat(B));

	printf("*****Mengecek apakah Titik A dan B merupakan titik origin*****\n");
	printf("Titik A merupakan ");
	if(isOrigin(A)){
		printf("titik origin\n");
	}
	else{
		printf("bukan titik origin\n");
	}
	printf("Titik B merupakan ");
	if(isOrigin(B)){
		printf("titik origin\n");
	}
	else{
		printf("bukan titik origin\n");
	}
	
	printf("*****Mengecek kuadran dan jarak Titik A dan B*****\n");
	printf("Titik A berada di kuadaran: %d\n", Kuadran(A));
	printf("Titik B berada di kuadaran: %d\n", Kuadran(B));
	printf("Jarak Titik A dengan Titik B = %f\n", Jarak(A,B));

	return 0;
}
