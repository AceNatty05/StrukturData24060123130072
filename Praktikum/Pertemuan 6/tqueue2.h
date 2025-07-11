#ifndef tqueue2_H
#define tqueue2_H
#include "boolean.h" //ambil dari praktikum sebelumnya
#include <stdio.h>
#include <math.h>

/* Program   : tqueue2.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 04//10/2024*/
/***********************************/

/* type tQueue2 = < wadah: array [1..5] of character ,
				head: integer ,
				tail: integer >
{cara akses: Q:tQueue2, Q.head = head(Q) ...} */
typedef struct{
    char wadah[6]; //kapasitas 5 elemen 
    int head; 
    int tail; 
}tqueue2; // Kurapikan biar lebih rapi

/*function isEmptyQueue2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q);
 
/*function isFullQueue2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q);

/*function isOneElement2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q);

/*procedure createQueue2 ( output Q:tQueue2 )
    {I.S.: -}
    {F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q);

/*Function Head2(Q:Tqueue2) -> integer
    {mengembalikan posisi elemen terdepan} */
#define head2(Q) (Q).head //implementasi fisik macro

/*Function Tail2(Q:Tqueue2) -> integer
    {mengembalikan posisi elemen terakhir} */
#define tail2(Q) (Q).tail //implementasi fisik macro

/*Function InfoHead2(Q:Tqueue2) -> character
    {mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q);

/*Function InfoTail2(Q:Tqueue2) -> character
    {mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q);

/*function sizeQueue2(Q:tQueue2)-> integer 
    {mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q);

/*procedure printQueue2(input Q:tQueue2)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q);

/*procedure viewQueue2(input Q:tQueue2)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q);

/*Function IsTailStop(Q:TQueue2) -> boolean
    {mengembalikan true jika Tail tidak dapat lagi geser}
    {karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q);

/*Procedure ResetHead(input/output Q:TQueue2)
    {I.S:Tail=kapasitas, head>1; F.S:head=1 }
    {Proses: mengembalikan Head ke indeks 1 }
    {Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q);

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
    {I.S.: E terdefinisi}
    {F.S.: elemen wadah Q bertambah 1 bila belum penuh}
    {proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
    maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E);
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
    {I.S.: }
    {F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
    {proses: mengurangi elemen wadah Q, bila 1 elemen, 
    maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E);

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
    {I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
    {F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
    {proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
    maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N);

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
    {mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
    {ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2);

/*procedure YesORYes(input b: boolean)
    untuk menampilkan "YA" atau 'TIDAK tergantung inputnya*/
void YesORYes(boolean b);

/*procedure PrintAll(input Q: tqueue2)
    untuk mengeprint semuanya di driver(iya saya malas)*/
void PrintAll(tqueue2 Q);

#endif
