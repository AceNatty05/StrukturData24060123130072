/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h> 
#include "matriks_yogi.c"

int main() {
	/*kamus*/
	Matriks A,B,C,D,E;
	Matriks X1,Y1,X2,Y2,X3,Y3,Z1,Z2,Z3;
	int Apapun,pilih;
	int add,edit,baris,kolom;
	int cek,count;
	
	/*algoritma*/

	/* Asumsi Awal */
	printf("Selamat datang dalam Driver Utama Matriks\n");
	printf("Berikut adalah asumsi kami untuk matriks\n");
	printf("1. matriks dapat bolong ditengah\n");
	
	initMatriks(&A);
	initMatriks(&B);
	initMatriks(&C);
	initMatriks(&D);
	initMatriks(&E);

	addX(&A, 7, 2, 3);
	addX(&A, 2, 3, 1);
	viewMatriks(A);
	printf("Matriks tersebut memiliki %d baris dan %d kolom\n",getNBaris(A),getNKolom(A));

	printf("ketik sebuah angka untuk lanjut : ");
	scanf("%d", &Apapun);
	printf("2. matriks penuh adalah ketika dalam dimensi ixj, semuanya ada isinya\n");
	viewMatriks(A);
	printf("Matriks diatas tidak penuh\n");
	isiMatriksRandom(&A,3,3);
	viewMatriks(A);
	printf("Matriks diatas penuh\n");
	printf("ketik sebuah angka untuk lanjut : ");
	scanf("%d", &Apapun);

	printf("===================================================================\n");

	/* Isi matriks Random */
	printf("kami akan mengisi sebanyak x baris dan y kolom matriks B, random\n");
	printf("masukkan nilai x dan y berurutan : \n");
	int x,y;
	scanf("%d %d", &x, &y);

	printf("awalnya matriks B : \n");
	printMatriks(B);
	isiMatriksRandom(&B,x,y);
	printf("sekarang matriks B : \n");
	printMatriks(B);
	printf("=================================================================\n");

	/* isEmptyMatriks */
	/* isFullMatriks */
	printf("Anda sudah mengisi Matriks B dengan baris : %d dan kolom : %d\n", getNBaris(B), getNKolom(B));
	printf("pilih 1 atau 2\n");
	printf("1 untuk apakah B kosong : 2 untuk apakah B penuh\n");
	printf("pilih sekarang 1 atayu 2: ");
	scanf("%d", &pilih);
	if(pilih==1){
		if(isEmptyMatriks(B)==1){
			printf("matriks B kosong\n");
		} else{
			printf("matriks B tidak kosong\n");
		}
	} else if(pilih==2){
		if(isFullMatriks(B)==1){
			printf("matriks B penuh\n");
		} else{
			printf("matriks B tidak penuh\n");
		}
	} else{
		printf("Harap masukkan inputan yang benar\n");
	}
	printf("=================================================================\n");

	/* addX */
	printf("Matriks C berikut kosong, anda dapat menambahkan satu elemen\n");
	printf("matriks C awalnya: \n");
	printMatriks(C);
	printf("masukkanlah sebuah elemen tersebut ke dalam C, elemen : \n");
	scanf("%d",&add);
	printf("pada baris dan kolom berapa anda ingin elemen tersebut ada\n");
	scanf("%d %d", &baris, &kolom);

	addX(&C, add, baris, kolom);
	printf("sekarang matriks C : \n");
	printMatriks(C);
	printf("=================================================================\n");

	/* editX */
	printf("Matriks D berikut penuh, anda dapat mengedit satu elemen D\n");
	printf("matriks D awalnya: \n");
	isiMatriksRandom(&D,10,10);
	printMatriks(D);
	printf("masukkanlah elemen yang akan mengedit D : \n");
	scanf("%d",&edit);
	printf("pada baris dan kolom berapa anda ingin elemen mengedit D\n");
	scanf("%d %d", &baris, &kolom);

	editX(&D, edit, baris, kolom);
	printf("sekarang matriks D : \n");
	printMatriks(D);
	printf("=================================================================\n");

	/* PopulateMatriks */
	printf("silahkan isi sendiri elemen elemen matriks E berikut\n");
	printf("masukkan baris dan kolom maksimal yang anda ingin isi\n");
	printf("tulis -999, jika anda ingin elemen pada baris i dan kolom j kosong\n");
	scanf("%d %d", &x, &y);
	printf("awalnya matriks E : \n");
	printMatriks(E);
	populateMatriks(&E,x,y);
	printf("sekarang matriks E : \n");
	printMatriks(E);

	/* isEmptyMatriks */
	/* isFullMatriks */
	printf("Anda sudah mengisi Matriks E dengan baris : %d dan kolom : %d\n", getNBaris(E), getNKolom(E));
	printf("pilih 1 atau 2\n");
	printf("1 untuk cek apakah E kosong : 2 untuk cek apakah E penuh\n");
	printf("pilih sekarang 1 atayu 2: ");
	scanf("%d", &pilih);
	if(pilih==1){
		if(isEmptyMatriks(E)==1){
			printf("matriks E kosong\n");
		} else{
			printf("matriks E tidak kosong\n");
		}
	} else if(pilih==2){
		if(isFullMatriks(E)==1){
			printf("matriks E penuh\n");
		} else{
			printf("matriks E tidak penuh\n");
		}
	} else{
		printf("Harap masukkan inputan yang benar\n");
	}
	printf("=================================================================\n");

	/* SearchX */
	/* CountX */
	printf("Anda sudah mengisi Matriks E dengan baris : %d dan kolom : %d\n", getNBaris(E), getNKolom(E));
	printf("Kali ini kami akan mencari apakah suatu integer, elemen dari E\n");
	printf("masukkan elemen tersebut : \n");
	scanf("%d", &cek);
	int bari=0;
	int col=0;
	searchX(E, cek, &bari,&col);
	if(bari!=-999){
		printf("%d ada pada baris ke-%d dan kolom ke-%d pada matriks E\n",cek, bari,col);
	}else{
		printf("%d tidak ada di matriks E\n",cek);
	}

	printf("=================================================================\n");
	printf("Kali ini kami akan menghitung kemunculan suatu integer pada matriks E\n");
	printf("masukkan elemen tersebut : \n");
	scanf("%d", &count);
	printf("kemunculan %d pada matriks E ada sebanyak %d\n",count, countX(E,count));

	printf("=================================================================\n");
	printf("Kali ini anda harus menghapus suatu integer pada matriks E\n");
	printf("masukkan elemen tersebut : \n");
	scanf("%d", &count);
	printf("matriks E awalnya :\n");
	viewMatriks(E);
	delX(&E,count);
	printf("matriks E sekarang : \n");
	viewMatriks(E);
	printf("=================================================================\n");

	/* AddMatriks */
	printf("kali ini akan ada penjumlahan dua matriks\n");
	printf("agar cepat kami akan mengisi random matriks X1 dan Y1\n");
	initMatriks(&X1);
	initMatriks(&Y1);
	printf("masukkan baris dan kolom X1 berurutan : \n");
	int bar,kol;
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&X1,bar,kol);
	printf("masukkan baris dan kolom Y1 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&Y1,bar,kol);

	printf("Matriks X1 adalah : \n");
	viewMatriks(X1);
	printf("Matriks Y1 adalah : \n");
	viewMatriks(Y1);
	printf("hasil tambah keduanya adalah : \n");
	viewMatriks(addMatriks(X1,Y1));
	printf("=================================================================\n");

	/* subMatriks */
	printf("kali ini akan ada pengurangan dua matriks\n");
	printf("agar cepat kami akan mengisi random matriks X2 dan Y2\n");
	initMatriks(&X2);
	initMatriks(&Y2);
	printf("masukkan baris dan kolom X2 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&X2,bar,kol);
	printf("masukkan baris dan kolom Y2 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&Y2,bar,kol);

	printf("Matriks X2 adalah : \n");
	viewMatriks(X2);
	printf("Matriks Y2 adalah : \n");
	viewMatriks(Y2);
	printf("hasil kurang keduanya adalah : \n");
	viewMatriks(subMatriks(X2,Y2));
	printf("=================================================================\n");

	/* kaliMatriks */
	printf("kali ini akan ada perkalian dua matriks\n");
	printf("agar cepat kami akan mengisi random matriks X3 dan Y3\n");
	initMatriks(&X3);
	initMatriks(&Y3);
	printf("masukkan baris dan kolom X3 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&X3,bar,kol);
	printf("masukkan baris dan kolom Y3 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	isiMatriksRandom(&Y3,bar,kol);

	printf("Matriks X3 adalah : \n");
	viewMatriks(X3);
	printf("Matriks Y3 adalah : \n");
	viewMatriks(Y3);
	printf("hasil kali keduanya adalah : \n");
	viewMatriks(kaliMatriks(X3,Y3));
	printf("=================================================================\n");

	/* AddMatriks */
	printf("kali ini akan ada perkalian skalar dan  matriks\n");
	printf("agar cepat kami akan mengisi random matriks Z1\n");
	initMatriks(&Z1);
	printf("masukkan baris dan kolom Z1 berurutan : \n");
	scanf("%d %d", &bar, &kol);
	printf("masukkan skalarnya : \n");
	isiMatriksRandom(&Z1,bar,kol);
	scanf("%d", &bar);

	printf("Matriks Z1 adalah : \n");
	viewMatriks(Z1);
	printf("skalarnya adalah : ");
	printf("%d\n", bar);
	printf("hasil kalinya adalah : \n");
	viewMatriks(kaliSkalarMatriks(Z1,bar));
	printf("=================================================================\n");

	/* getSumMatriks */
	/* getAverageMat */
	/* getMinMatriks */
	/* getMaxMatriks */
	printf("sekarang isilah sendiri lagi matriks Z2\n");
	printf("masukkan baris dan kolom maksimal yang anda ingin isi\n");
	printf("tulis -999, jika anda ingin elemen pada baris i dan kolom j kosong\n");
	initMatriks(&Z2);
	int s,k;
	scanf("%d %d", &s, &k);
	populateMatriks(&Z2, s, k);
	printf("sekarang matriks Z2 : \n");
	viewMatriks(Z2);

	printf("jumlah semua elemen matriks Z2 adalah %d\n",getSumMatriks(Z2));
	printf("Rata rata elemen matriks Z2 adalah %f\n",getAverageMatriks(Z2));
	printf("elemen terkecil matriks Z2 adalah %d\n",getMinMatriks(Z2));
	printf("elemen terbesar elemen matriks Z2 adalah %d\n",getMaxMatriks(Z2));

	/* transposeMatriks */
	printf("ketik sebuah angka untuk lanjut : ");
	scanf("%d", &Apapun);
	printf("sekarang matriks Z2 : \n");
	viewMatriks(Z2);
	printf("kami akan melakukan transposeMatriks Z2\n");
	transposeMatriks(&Z2);
	printf("Matriks Z2 sekarang : \n");
	viewMatriks(Z2);

	/* getTransposeMatriks */
	printf("jika Z2 ditranspose 2 kali lagi maka : \n");
	printf("ini pertama kali Z2 ditrasnpose lagi\n");
	viewMatriks(getTransposeMatriks(Z2));
	printf("ini ketika Z2 ditranspose kan lagi\n");
	viewMatriks(getTransposeMatriks(getTransposeMatriks(Z2)));


	/*isiMatriksIdentitas*/
	initMatriks(&Z3);
	isiMatriksIdentitas(&Z3,3);
	viewMatriks(Z3);
    return 0;
}
