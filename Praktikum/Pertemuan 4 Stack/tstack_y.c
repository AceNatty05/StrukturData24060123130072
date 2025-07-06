/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123130106/Muhammad Yoga Aminudin */
/* Tanggal   : 20/09/2024 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "tstack_y.h"
#include "boolean.h"

/*karakter kosong dilambangkan dengan '#'  */
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    for(i=1; i<=10; i++){
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top(Tstack T){
    /* Kamus */
    /* Algoritma */
    return T.top;
}

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop(Tstack T){
    /* Kamus */
    /* Algoritma */
    return T.wadah[T.top];
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return top(T)==0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    /* Kamus Lokal */
    /* Algoritma */
    return top(T)==10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    /* Kamus Lokal */
    /* Algoritma */
    if(!isFullStack(*T)){
        (*T).wadah[top(*T)+1] = E;
        (*T).top = top(*T)+1;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    /* Kamus Lokal */
    /* Algoritma */
    if(!isEmptyStack(*T)){
        *X = infotop(*T);
        (*T).wadah[top(*T)]='#';
        (*T).top = top(*T)-1;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    printf("[ ");
    for(i=1; i <= 9; i++){
        printf(" %c ;",T.wadah[i]);
    }
    printf(" %c",T.wadah[i]);
    printf(" ]");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    printf("[ ");
    for(i=1; i <= top(T)-1; i++){
        printf(" %c ;",T.wadah[i]);
    }
    printf(" %c",T.wadah[i]);
    printf(" ]");
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }
    {Asumsi: N dapat >= sisa wadah T}*/
void pushN (Tstack *T, int N){
    /* Kamus Lokal */
    char X;       /* simpan inputan */
    int i;

    /* Algoritma */
    if(isFullStack(*T)){
        printf("Stack Penuh\n");
    } else{
        for(i=1; i <= N && !isFullStack(*T); i++){
            printf("silahkan isi wadah ke-%d stack anda : ",i);
            scanf(" %c",&X); 
            push(T, X);
        }
    }
}

/*procedure pushRandom ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: top terisi dengan N elemen acak dari karakter tertentu kecuali '#' jika belum penuh }
    {Proses: mengisi elemen top baru N kali dengan karakter acak, bila belum penuh }
    {Asumsi: N dapat >= sisa wadah T} */
void pushRandom (Tstack *T, int N){
    /* Kamus Lokal */
    char X;       /* simpan inputan acak */
    int i;
    char allowedChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ*&^$()";  // Daftar karakter acak tanpa '#'
    int numAllowedChars = sizeof(allowedChars) - 1; 

    /* Algoritma */
    if(isFullStack(*T)){
        printf("Stack Penuh\n");
    } else{
        for(i = 1; i <= N && !isFullStack(*T); i++){
            X = allowedChars[rand() % numAllowedChars]; 
            push(T, X);
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    /* Kamus Lokal */
    int i;
    char X;

    /* Algoritma */
    if(!isFullStack(*T)){
        push(T,E);
    } else{
        for(i=top(*T); i>=1; i--){
            pop(T, &X); 
        }
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    if(!isEmptyStack(*T)){
        if(infotop(*T)==E){
            (*T).wadah[top(*T)]='#';
            (*T).top = top(*T)-1;
        } else{
            push(T,E);
        }
    }
}

/* TAMBAHAN */
/*procedure sortStack ( input/output T:Tstack )
    {I.S.: T terdefinisi dan tidak kosong }
    {F.S.: Elemen-elemen stack terurut }
    {Proses: Mengurutkan elemen-elemen stack secara ascending } */
void sortStack(Tstack *T){
    /* Kamus Lokal */
    int i, j;
    char temp;

    /* Algoritma */
    for(i = 1; i <= top(*T); i++){
        for(j = i + 1; j <= top(*T); j++){
            if((*T).wadah[i] > (*T).wadah[j]){
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            }
        }
    }
}

/*procedure reverseStack ( input/output T:Tstack )
    {I.S.: T terdefinisi dan tidak kosong }
    {F.S.: Urutan elemen stack terbalik }
    {Proses: Membalikkan urutan elemen dari top ke bawah} */
void reverseStack(Tstack *T){
    /* Kamus Lokal */
    int i, j;
    char temp;

    /* Algoritma */
    for(i = 1, j = top(*T); i < j; i++, j--){
        temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[j];
        (*T).wadah[j] = temp;
    }
}