/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123130072/Natasya Amelia Candrasari*/
/* Tanggal   : 04//10/2024*/

#include "tqueue2.h"

/*function isEmptyQueue2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head2(Q) == 0 && tail2(Q) == 0;
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head2(Q) == 1 && tail2(Q) == 5;
    // return sizeQueue2(Q) == 5; 
}

/*function isOneElement2(Q:tQueue2) -> boolean
    {mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return head2(Q) == tail2(Q) && head2(Q) != 0;
    // return sizeQueue2(Q) == 1; 
}

/*procedure createQueue2 ( output Q:tQueue2 )
    {I.S.: -}
    {F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    for(i=1; i<=10; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

// /*Function Head2(Q:Tqueue2) -> integer
//     {mengembalikan posisi elemen terdepan} */
// int head2(tqueue2 Q);

// /*Function Tail2(Q:Tqueue2) -> integer
//     {mengembalikan posisi elemen terakhir} */
// int tail2(tqueue2 Q);

/*Function InfoHead2(Q:Tqueue2) -> character
    {mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue2(Q)){ // Klo nggak kosong
        return Q.wadah[head2(Q)];
    } 
    else{
        return '#';
    }
}

/*Function InfoTail2(Q:Tqueue2) -> character
    {mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue2(Q)){ // Klo nggak kosong
        return Q.wadah[tail2(Q)];
    } 
    else{
        return '#';
    }
}

/*function sizeQueue2(Q:tQueue2)-> integer 
    {mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(isEmptyQueue2(Q)){
        return 0;
    }
    else{
        return tail2(Q) - head2(Q) + 1; 
    }
}

/*procedure printQueue2(input Q:tQueue2)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    for(i=1; i<=5; i++){ // print dari index 1 ke 5
        printf(" %c ", Q.wadah[i]);
    }
    printf("]\n");
}

/*procedure viewQueue2(input Q:tQueue2)
    {I.S.: Q terdefinisi}
    {F.S.: -}
    {proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("[");
    if(!isEmptyQueue2(Q)){
        for(i=head2(Q); i<=tail2(Q); i++){
            printf(" %c ", Q.wadah[i]);
        }
    }
    printf("]\n");
}

/*Function IsTailStop(Q:TQueue2) -> boolean
    {mengembalikan true jika Tail tidak dapat lagi geser}
    {karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    return tail2(Q) == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
    {I.S:Tail=kapasitas, head>1; F.S:head=1 }
    {Proses: mengembalikan Head ke indeks 1 }
    {Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    /*Kamus Lokal*/
    int i, sel, size; // Selisih untuk menghitung berapa jauh mereka mundur
    /*Algoritma*/
    // Dipanggil hanya saat enqueue & isTailStop memenuhi
    if(!isFullQueue2(*Q)){ // Jika tidak full kita reset head
        sel = head2(*Q) - 1;
        size = sizeQueue2(*Q);
        for(i=1; i<=size; i++){
            (*Q).wadah[i] = (*Q).wadah[i+sel];
            (*Q).wadah[i+sel] = '#'; // diganti elemen kosong
        }
        (*Q).head = 1;
        (*Q).tail = size;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
    {I.S.: E terdefinisi}
    {F.S.: elemen wadah Q bertambah 1 bila belum penuh}
    {proses: menambah elemen wadah Q, jika tail(Q)=kapasitas 
    maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    /*Kamus Lokal*/
    /*Algortima*/
    if(!isFullQueue2(*Q)){
        if(isEmptyQueue2(*Q)){
            (*Q).head = 1; // assign dengan 1 
        }
        if(isTailStop(*Q)){
            resetHead(Q);
        }
        (*Q).tail++;
        (*Q).wadah[tail2(*Q)] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
    {I.S.: }
    {F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
    {proses: mengurangi elemen wadah Q, bila 1 elemen, 
    maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyQueue2(*Q)){
        *E = infoHead2(*Q);
        (*Q).wadah[head2(*Q)] = '#';
        if(isOneElement2(*Q)){
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else{
            (*Q).head++;
        }
    }
    else{
        *E = '@';
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
    {I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
    {F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
    {proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
    maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    /*Kamus Lokal*/
    int i;
    char c;
    /*Algoritma*/
    i = 1;
    while(i <= N && !isFullQueue2(*Q)){
        printf("Elemen ke-%d : ", i);
        scanf (" %c", &c);
        enqueue2(Q,c);
        i++;
    }
    if(i <= N){
        printf("Tabel sudah penuh\n");
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
    {mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
    {ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2){
    /*Kamus Lokal*/
    int i, dif; // dif menampung selisih index head Q1 & Q2 
    /*Algoritma*/
    if(sizeQueue2(Q1) == sizeQueue2(Q2)){
        dif = head2(Q2) - head2(Q1);
        for(i=1; i<=sizeQueue2(Q1); i++){
            if(Q1.wadah[i] != Q2.wadah[i + dif]){ // Jika beda break (false)
                return false;
            }
        }
        return true; // jika tidak ada yang beda (belum ke break), true
    }
    else{ // beda size otomatis salah
        return false;
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
void PrintAll(tqueue2 Q){
    /*Kamus Lokal*/
    /*Algoritma*/
    printf("Print Queue: "); printQueue2(Q);
    printf("View Queue: "); viewQueue2(Q);
    printf("Head: %d\n", head2(Q));
    printf("Tail: %d\n", tail2(Q));
    printf("Size: %d\n", sizeQueue2(Q));
    printf("InfoHead: %c\n", infoHead2(Q));
    printf("infoTail: %c\n", infoTail2(Q));
    printf("Apakah Empty? "); YesORYes(isEmptyQueue2(Q)); 
    printf("Apakah Full? "); YesORYes(isFullQueue2(Q));
    printf("Apakah One Element? "); YesORYes(isOneElement2(Q));
}