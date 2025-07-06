#include <stdio.h>
#include "tabel.c"
/*Deskripsi : driver ADT tabel integer*/
/* Deskripsi : Mengaplikasikan Type dan Primitif dari ADT Tabel*/
/* NIM/Nama  : 24060123130106/Muhammad Yoga Aminudin */
/* Tanggal   : 07/September/2024 */
/***********************************/

int main() {
	/*kamus*/
	Tabel T1;
	Tabel T2;
	Tabel T3;
	Tabel T4;
	
	/*algoritma*/
	//createTable(&T1);
	createTable(&T1);
	createTable(&T2);
	createTable(&T3);
	createTable(&T4);
	printf("Tabel T1 tellah dibuat\n");
	printf("Tabel T2 tellah dibuat\n");
	printf("======================================================\n");

	//getSize(T1)
	printf("Tabel T1 awalnya berukuran %d\n", getSize(T1));
	printf("Tabel T2 awalnya berukuran %d\n", getSize(T2));
	printf("======================================================\n");

	//searchX(T,X)
	printf("coba kita cari angka 7 dalam T1\n");
	if(searchX(T1,7)==0){
		printf("7 bukan elemen dari T1\n");
	} else {
		printf("7 terletak pada wadah ke-%d dalam T1\n",searchX(T1,7));
	} printf("======================================================\n");

	//addXTable(&T1,6);
	//isi Tabel T1: berpola
	int N;
	printf("Kami akan menambahkan random T1 dengan N elemen\n");
	printf("masukkan N : ");
	do {
		scanf("%d",&N);
		if(N < 0 || N > 10){
			printf("input tidak valid, masukkan angka lain: ");
			while(getchar() != '\n');
		}
	} while( N < 0 || N > 10);
	printf("Kami akan mengisi Tabel T1 sebanyak %d kali\n", N);
	for(int i=1;i<=N;i++){
		addXTable(&T1,i%5+N%7+1);
	}
	printf("------------------------------------------------------\n");
	//isi Tabel T2: berpola 
	int M;
	printf("Kami akan menambahkan random T2 dengan M elemen\n");
	printf("masukkan M : ");
	do {
		scanf("%d",&M);
		if(M < 0 || M > 10){
			printf("input tidak valid, masukkan lagi: ");
			while(getchar() != '\n');
		}
	} while( M < 0 || M > 10);

	printf("Kami akan mengisi Tabel T2 sebanyak %d kali\n", M);
	for(int i=1;i<=M;i++){
		addXTable(&T2,(M-i)+(i*2)%(N/2+1)+1);
	} printf("======================================================\n");

	//printTable;
	printf("Tabel T1 sekarang berukuran %d\n", getSize(T1));
	printf("Tabel T1 : ");
	printTable(T1);
	printf("Tabel T2 sekarang berukuran %d\n", getSize(T2));
	printf("Tabel T2 : ");
	printTable(T2);

	printf("======================================================\n");

	//isEmptyTable, isFullTable
	printf("apakah T1 adalah tabel kosong? ");
	if(isEmptyTable(T1)==0){
		printf("Tidak, T1 bukan tabel kosong\n");
	} else {
		printf("Iya, T1 adalah tabel kosong\n");

	} printf("------------------------------------------------------\n");
	printf("apakah T2 adalah tabel kosong? ");
	if(isEmptyTable(T2)==0){
		printf("Tidak, T2 bukan tabel kosong\n");
	} else {
		printf("Iya, T2 adalah tabel kosong\n");
		
	} printf("------------------------------------------------------\n");
	
	printf("apakah T1 adalah tabel Penuh? ");
	if(isFullTable(T1)==0){
		printf("Tidak, T1 bukan tabel Penuh\n");
	} else {
		printf("Iya, T1 adalah tabel Penuh\n");
		
	} printf("------------------------------------------------------\n");
	printf("apakah T2 adalah tabel Penuh? ");
	if(isFullTable(T2)==0){
		printf("Tidak, T2 bukan tabel Penuh\n");
	} else {
		printf("Iya, T2 adalah tabel Penuh\n");
		
	} printf("======================================================\n");

	//countEmpty
	printf("T1 memiliki sebanyak %d elemen yang kosong, size : %d\n",countEmpty(T1),getSize(T1));
	printf("T2 memiliki sebanyak %d elemen yang kosong, size : %d\n",countEmpty(T2),getSize(T2));

	//viewTable(T1);
	printf("semua elemen tidak kosong dari T1 :\n");
	viewTable(T1);
	printf("semua elemen tidak kosong dari T2 :\n");
	viewTable(T2);
	printf("======================================================\n");

	//populate1(&T3,N);
	printf("menggunakan populate 1\n");
	printf("silahkan isi sendiri elemen T3 sebanyak X(X>0) kali: \n");
	int X;
	printf("masukkan X: ");
	do {
		scanf("%d",&X);
		if(X < 1 || X > 10){
			printf("input tidak valid, masukkan lagi: ");
			while(getchar() != '\n');
		}
	} while( X < 1 || X > 10);
	populate1(&T3,X);
	printf("======================================================\n");

	//searchX
	int c;
	printf("kami akan mencari satu elemen dalam T3\n");
	printf("masukkan elemen tersebut : ");
	scanf("%d",&c);
	if(searchX(T3,c)==0){
		printf("%d bukan elemen dari T3\n",c);
	} else {
		printf("%d terletak pada wadah ke-%d dalam T3\n",c,searchX(T3,c));
	} printf("======================================================\n");

	//countX
	int d;
	printf("kami akan menghitung kemunculan satu elemen dalam T3\n");
	printf("masukkan elemen tersebut : ");
	scanf("%d",&d);
	if(countX(T3,d)==0){
		printf("%d bukan elemen dari T3\n",d);
	}else {
		printf("%d muncul sebanyak %d kali dalam T3\n", d,countX(T3,d));
	} printf("======================================================\n");

	//delXTable
	int e;
	printf("kami akan menghapus kemunculan satu elemen dalam T3\n");
	printf("masukkan elemen tersebut : ");
	scanf("%d",&e);
	if(searchX(T3,e)==0){
		printf("%d bukan elemen dari T3\n",e);
	}else {
		printf("Tabel T3 sebelumnya : ");
		printTable(T3);
		delXTable(&T3,e);
		printf("Tabel T3 sekarang : ");
		printTable(T3);
	} printf("======================================================\n");

	//delAllXTable
	int f;
	printf("kami akan menghapus semua kemunculan elemen dalam T3\n");
	printf("masukkan elemen tersebut : ");
	scanf("%d",&f);
	if(searchX(T3,f)==0){
		printf("%d bukan elemen dari T3\n",f);
	}else {
		printf("Tabel T3 sebelumnya : ");
		printTable(T3);
		delAllXTable(&T3,f);
		printf("Tabel T3 sekarang : ");
		printTable(T3);
	} printf("======================================================\n");

	//Populate2(&T4)
	printf("menggunakan populate 2\n");
	printf("silahkan isi sendiri elemen T4 : \n");
	populate2(&T4);
	printf("======================================================\n");

	int sum,max,min,modus; //simpan, hindari pemanggilan berulang
	float avg;
	//SumEl(T4)
	sum = SumEl(T4);
	printf("Jumlah semua elemen T4 adalah : ");
	if(sum==-999){
		printf("Tabel Kosong\n");
	} else {
		printf("%d\n",sum);  
	} printf("------------------------------------------------------\n");

	//AverageE1(T4)
	avg = AverageEl(T4);
	printf("rata rata elemen T4 adalah : ");
	if(avg==-999){
		printf("Tabel Kosong\n");
	} else {
		printf("%.2f\n", avg);
	} printf("------------------------------------------------------\n");

	//getMaxEl(T4)
	max = getMaxEl(T4);
	printf("elemen terbesar dari T4 adalah : ");
	if(max==-999){
		printf("Tabel Kosong\n");
	} else {
		printf("%d\n",max);
	} printf("------------------------------------------------------\n");

	//getMinE1(T4)
	min = getMinEl(T4);
	printf("elemen terkecil dari T4 adalah : ");
	if(min==-999){
		printf("Tabel Kosong\n");
	} else {
		printf("%d\n",min);
	} printf("------------------------------------------------------\n");

	//Modus(T4)
	modus = Modus(T4);
	printf("modus dari T4 adalah : ");
	if(modus==-999){
		printf("Tabel Kosong\n");
	} else {
		printf("%d\n",modus);
	} printf("======================================================\n");


	//sortAsc(T1);
	printf("T1 sebelum sort Asc : ");
	printTable(T1);
	printf("T1 setelah sort Asc : ");
	sortAsc(&T1);
	printTable(T1);
	printf("------------------------------------------------------\n");

	printf("T2 sebelum sort Asc : ");
	printTable(T2);
	printf("T1 setelah sort Asc : ");
	sortAsc(&T2);
	printTable(T2);
	printf("------------------------------------------------------\n");

	//sortDesc(T2);
	printf("T1 sebelum sort Desc : ");
	printTable(T1);
	printf("T1 setelah sort Desc : ");
	sortDesc(&T1);
	printTable(T1);
	printf("------------------------------------------------------\n");

	printf("T2 sebelum sort Desc : ");
	printTable(T2);
	printf("T2 setelah sort Desc : ");
	sortDesc(&T2);
	printTable(T2);
	printf("------------------------------------------------------\n");

printf("program selesai (alhamdulillah selesai)\n terimakasih :DD");
	return 0;
}
