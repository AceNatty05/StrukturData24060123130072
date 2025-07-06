/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 04 November 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address *P) {
	//kamus lokal
	
	//algoritma
	if ( (*P) != NIL ) {
		next(*P) = NIL;
	}
	free(*P);
	(*P) = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
	//kamus lokal
	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
	//Kamus Lokal
	//Algoritma
	return First(L) == NIL;
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L){
	//Kamus Lokal
	address P;
	//Algoritma
	P = First(L);
	while(P != NIL){
		printf("%c ", info(P));
		P = next(P);
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
	//Kamus Lokal
	int Count;
	address P;
	//Algoritma
	Count = 0;
	P = First(L);
	while(P != NIL){
		Count++;
		P =  next(P);
	}
	return Count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
	//Kamus Lokal
	address P; 
	//ALgoritma
	P = Alokasi(V);
	if(P != NIL){ // alokasi berhasil
		if(First(*L) == NIL){ // list kwasong
			First(*L) = P;
		}
		else{ 
			next(P) = First(*L);
			First(*L) = P;
		}
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
	//Kamus Lokal
	address P, Last; 
	//ALgoritma
	P = Alokasi(V);
	if(P != NIL){ // berhasil dapet lokesyen
		if(First(*L) == NIL){ // list kwasong
			First(*L) = P;
		}
		else{
			Last = First(*L);
			while(next(Last) != NIL){
				Last = next(Last);
			}
			next(Last) = P; // sudah ditemukan lokesyen terakhir
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	//Kamus Lokal
	address P;
	//Algoritma
	if(!IsEmptyList(*L)){
		P = First(*L);
		First(*L) = next(P);
		Dealokasi(&P);
	}
	else{
		*V = '#';
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	//Kamus Lokal
	address Last, Prec; 
	//ALgoritma
	if(!IsEmptyList(*L)){ // list kwasong
		Prec = NIL;
		Last = First(*L);
		while(next(Last) != NIL){ 
			Prec = Last;
			Last = next(Last);
		} // keluar while saat Last dalam kondisi 1 elemen (nextnya NIL)
		*V = info(Last);
		if(Prec != NIL){ // berarti tidak ada elemen pendahulu / list one element
			next(Prec) = NIL; // address ke last elemen (next(Prec)) dihapus
			Dealokasi(&Last);
		}
		else{ // berarti tidak ada elemen pendahulu / list one element
			First(*L) = NIL;
		}
	}
	else{
		*V = '#';
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
	//Kamus Lokal
	address P;
	//Algoritma
	*A = NIL; //inisialisasi, jika tidak ditemukan nilainy tetap NIL
	P = First(L);
	while(info(P) != X && next(P) != NIL){ // elemen terakhir tidak dicek
		P = next(P);
	}
	if(info(P) = X){
		*A = P;
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
	//Kamus Lokal
	address P;
	//Algoritma
	P = First(*L);
	while(info(P) != X && next(P) != NIL){
		P = next(P);
	}
	if(info(P) == X){
		info(P) = Y;
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L){
	//Kamus Lokal
	address P;
	List1 temp; // temporary list hasil invers
	//Algoritma
	P = First(*L);
	CreateList(&temp);
	while(P != NIL){
		InsertVFirst(&temp,info(P));
		P = next(P);
	}
	DeleteList(L); // Pastikan L dihapus dari memory, tidak perlu ditulis di notasi
	// PrintList(*L); // buat ngecek list L beneran kosong belum
	*L = temp;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
	//Kamus Lokal
	int Count;
	address P;
	//Algoritma
	Count = 0;
	P = First(L);
	while(P != NIL){
		if(info(P) == X){
			Count++;
		}
		P = next(P);
	}
	return Count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
	//Kamus Lokal
	// int N, NList;
	//Algoritma
	// N = CountX(L,X);
	// NList = NbElm(L);
	// return N/NList;
	return (float)CountX(L,X)/NbElm(L);
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
	//Kamus Lokal
	address P;
	List1 Lp; // list temporary dengan elemen yang ditunjuk P sebagai FirstELmt
	//Algoritma
	CreateList(&Lp);
	P = First(L);
	while(P != NIL){
		if(info(P) == X){
			First(Lp) = P; // membuat list dengan elemen yang ditunjuk P sebagai elemen pertama
			printf(" %d ", NbElm(L) - NbElm(Lp) + 1);
		}
		P = next(P);
	}
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y){
	//Kamus Lokal
	address P;
	//Algoritma
	P = First(*L);
	while(P != NIL){
		if(info(P) == X){
			info(P) = Y;
		}
		P = next(P);
	}

	// while(P != NIL){
	// 	if(info(P) == X){
	// 		UpdateX(L,X,Y);
	// 	}
	// }

	// for(i=1; i<=CountX(*L,X)){
	// 	UpdateX(L,X,Y);
	// }
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
	//Kamus Lokal
	address aV, aVA; // untuk menyimpan alamat elm berinfo V dan VA
	//Algoritma
	SearchX(*L,V,&aV); // temporary menyimpang address Elm berinfo V
	if(info(aV) = V){ // jika ditemukan V, temp berisi address Elm berinfo V
		aVA = Alokasi(VA);
		if(next(aV) == NIL){ // V elemen terakhir
			next(aV) = aVA;
		}
		else{ // V bukan last element
			next(aVA) = next(aV);
			next(aV) = aVA;
		}
	}
}

/*function MaxMember(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List1 L){
	//Kamus Lokal
	int Max;
	address P;
	//Algoritma
	Max = 0;
	P = First(L);
	while(P != NIL){
		if(CountX(L,info(P)) > Max){
			Max = CountX(L,info(P));
		}
		P = next(P);
	}
	return Max;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L){
	//Kamus Lokal
	int Max;
	address P;
	//Algoritma
	Max = MaxMember(L);
	P = First(L);
	while(P != NIL && CountX(L,info(P)) != Max){
		P = next(P);
	} // Jika ada beberapa elemen dengan jumlah Max, pilih yang pertama
	if(CountX(L,info(P)) == Max){ // list dengan > 0 elemen
		return info(P);
	}
	else{ // list dengan 0 elemen
		return '#';
	}
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L){
	//Kamus Lokal
	address P;
	//Algoritma
	DeleteList(L); // pastikan L kosong dulu, tidak ditulis di notasi
	P = First(L1);
	while(P != NIL){ // proses memasukkan elemen L1 ke L
		InsertVLast(L,info(P));
		P = next(P);
	}
	P = First(L2);
	while(P != NIL){ // proses memasukkan elemen L2 ke L
		InsertVLast(L,info(P));
		P = next(P);
	}
} 

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L. NbElm(L1) <= NbElm(L2) }*/
void SplitList(List1 L, List1 *L1, List1 *L2){
	//Kamus Lokal
	int nHalf;
	address P;
	//Algoritma
	DeleteList(L1); DeleteList(L2); // pastikan kosong sebelum diisi
	nHalf = NbElm(L)/2; // NbElm(L) div 2
	// F.S. NbElm(L1) <= NbElm(L2)
	P = First(L);
	while(P != NIL){
		if(NbElm(*L1) < nHalf){ // maks NbElm(L1) = nHalf
			InsertVLast(L1,info(P));
		} 
		else{ // Sisanya insert di L2
			InsertVLast(L2,info(P));
		}
		P = next(P);
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2){
	//kamus Lokal
	address P;
	//Algoritma
	DeleteList(L2); // Pastikan L2 sudah dikosongkan 
	P = First(L1);
	while(P != NIL){
		InsertVLast(L2,info(P));
		P = next(P);
	}
}

/*********** OPERATORS ***********/

/*Procedure DeleteList(input L1:List1, output L2:List1)
{I.S.: L terdefinisi;  
 F.S.: semua elemen L dihapus dari memory, L list kosong;
 Proses : Menghapus elemen-elemen List L dari memory. 
 Tidak perlu ditulis di notasi, khusus implementasi di C }*/
void DeleteList(List1 *L){
	//kamus Lokal
	address P;
	//Algoritma
	P = First(*L);
	while(P != NIL){ 
		First(*L) = next(P);
		Dealokasi(&P);
		P = First(*L);
	} // Bisa juga menggunakan DeleteVFirst
	// First(*L) = NIL;
}

/*procedure PrintAddressList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan address semua elemen list L} */
void PrintAddressList(List1 L){
	//Kamus Lokal
	address P;
	//Algoritma
	P = First(L);
	while(P != NIL){
		printf("%p ", P);
		P = next(P);
	}
}