/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 04//10/2024*/

#include "tqueue3.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
    {mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head3(Q) == 0 && tail3(Q) == 0;
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
    {mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head3(Q) == tail3(Q)%5 + 1;
}

/*function isOneElement3(Q:tQueue3) -> boolean
    {mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head3(Q) != 0 && head3(Q) == tail3(Q);
}

/*procedure createQueue3 ( output Q:tQueue3)
    {I.S.: -}
    {F.S.: Q terdefinisi, kosong}
    {Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    for(i=1; i<=5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function InfoHead3(Q:tqueue3) -> character
    {mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue3(Q)){ // Klo nggak kosong
        return Q.wadah[head3(Q)];
    } 
    else{
        return '#';
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
    {mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue3(Q)){ // Klo nggak kosong
        return Q.wadah[tail3(Q)];
    } 
    else{
        return '#';
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer 
    {mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue3(Q)){
        if(tail3(Q) < head3(Q)){
            return tail3(Q) - head3(Q) + 6;
        }
        else{
            return tail3(Q) - head3(Q) + 1;
        }
    }
    else{ // Kosong
        return 0;
    }
}

/*procedure printQueue3(input Q:tQueue3)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    if(!isEmptyQueue3(Q)){ // Kata asprak print dari head ke head-1
        for(i=head3(Q); i<=head3(Q)+4; i++){
            printf(" %c ", Q.wadah[(i-1)%5+1]);
        }
    }
    else{
        for(i=1; i<=5; i++){
            printf(" %c ", Q.wadah[i]);
        }
    }
    printf("]\n");
}

/*procedure viewQueue3(input Q:tQueue3)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    if(!isEmptyQueue3(Q)){
        for(i=head3(Q); i<=head3(Q)+sizeQueue3(Q)-1; i++){
            printf(" %c ", Q.wadah[(i-1)%5+1]);
        }
    }
    printf("]\n");
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
    {I.S.: E terdefinisi}
    {F.S.: elemen wadah Q bertambah 1 bila belum penuh}
    {proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isFullQueue3(*Q)){
        if(isEmptyQueue3(*Q)){
            (*Q).head = 1;
        }
        (*Q).tail = (tail3(*Q)%5) + 1;
        (*Q).wadah[tail3(*Q)] = E; 
    }
}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
    {I.S.: }
    {F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
    {proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue3(*Q)){
        *E = infoHead3(*Q);
        (*Q).wadah[head3(*Q)] = '#';
        if(isOneElement3(*Q)){
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else{
            (*Q).head = (head3(*Q)%5)+1; 
        }
    }
    else{
        *E = ' ';
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
    {mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    /*Kamus LOkal*/
    /*Algoritma*/
    return tail3(Q) < head3(Q);
}

/*function countMember(Q:tQueue3, E:character) -> boolean
    {mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E){
    /*Kamus Lokal*/
    int i, count;
    /*Algoritma*/
    count = 0; // Inisialisasi
    if(!isEmptyQueue3(Q)){
        for(i=head3(Q); i<=head3(Q)+sizeQueue3(Q)-1; i++){
            if(Q.wadah[(i-1)%5+1] == E){
                count++;
            }
        }
        return count;
    }
    else{
        return count;
    }
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
    {I.S.: E terdefinisi}
    {F.S.: elemen wadah Q bertambah 1 bila belum penuh}
    {proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan 
    syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isFullQueue3(*Q) && countMember(*Q,E) == 0){ // Jika tidak full dan belum ada
        enqueue3(Q,E);
    }
}

/*procedure YesORYes(input b: boolean)
  untuk menampilkan "YA" atau 'TIDAK tergantung inputnya*/
void YesORYes(boolean b){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(b){
        printf("YA\n");
    }
    else{
        printf("TIDAK\n");
    }
}

/*procedure PrintAll(input Q: tqueue2)
    untuk mengeprint semuanya di driver (iya saya malas)*/
void PrintAll(tqueue3 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    printf("> Print Queue: "); printQueue3(Q);
    printf("> View Queue: "); viewQueue3(Q);
    printf("> Head: %d\n", head3(Q));
    printf("> Tail: %d\n", tail3(Q));
    printf("> Size: %d\n", sizeQueue3(Q));
    printf("> InfoHead: %c\n", infoHead3(Q));
    printf("> infoTail: %c\n", infoTail3(Q));
    printf("> Apakah Empty? "); YesORYes(isEmptyQueue3(Q)); 
    printf("> Apakah Full? "); YesORYes(isFullQueue3(Q));
    printf("> Apakah One Element? "); YesORYes(isOneElement3(Q));
}