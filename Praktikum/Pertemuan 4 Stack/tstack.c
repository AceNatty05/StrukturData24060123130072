/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 20//09/2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    for(i=1; i<=10; i++){
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    /*Kamus Lokal*/
    /*Algoritma*/
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    /*Kamus Lokal*/
    /*Algoritma*/
    return top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!(isFullStack(*T))){
        (*T).top++;
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!(isEmptyStack(*T))){
        *X = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        (*T).top--;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    if(!(isEmptyStack(T))){
        for(i=1; i<=10; i++){
            printf("%c", T.wadah[i]);
            if(i < top(T)){
                printf(" ,");
            }          
        }
    }
    printf("]");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    if(!(isEmptyStack(T))){
        for(i=1; i<=top(T); i++){
            printf("%c", T.wadah[i]);
            if(i < top(T)){
                printf(" ,");
            }
        }
    }
    printf("]");
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    /*Kamus Lokal*/
    int i;
    char input;
    /*Algoritma*/
    if(!(isFullStack(*T))){
        i=1; // inisialisasi
        while(i<=N && !(isFullStack(*T))){
            printf("$$ Masukkan karakter: "); 
            scanf(" %c", &input);
            // viewStack(*T); printf("  %c ~~~~~ \n", input);
            push(T,input);
            // viewStack(*T); printf("\n");
            i++;
        }
        if(i<=N){
            printf("OHH NOO, stack penuhh\n");
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if(!(isFullStack(*T))){
        viewStack(*T); printf("  %c ~~~~~ \n", E);
        push(T,E);
        viewStack(*T); printf("\n");
    }
    else{
        printf("OH NOO, stack penuhh\n");
        createStack(T);
        viewStack(*T); printf("~~~~ CLINGG\n");
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    /*Kamus Lokal*/
    char C;
    /*Algoritma*/
    if(infotop(*T) == E){
        printf("OHH NOO, %c ada di top stack\n", E);
        viewStack(*T); printf("\n");
        pop(T,&C);
        viewStack(*T); printf("  -----> ~~~ %c\n", E);
    }
    else if(!(isFullStack(*T))){
        viewStack(*T); printf("  %c ~~~~~ \n", E);
        push(T,E);
        viewStack(*T); printf("\n");
    }
    else{
        printf("Stack penuh\n");
    }
}