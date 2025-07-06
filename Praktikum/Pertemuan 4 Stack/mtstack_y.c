/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123130106/Muhammad Yoga Aminudin */
/* Tanggal   : 20/09/2024 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "tstack_y.c"

int main(){	
    /* kamus main */
	Tstack G;
	Tstack O;
	Tstack L;
	Tstack D;
	Tstack Xi, Yi, Zi;
	Tstack Babel, Zuma;
	char C,H,A,P,T,E,R; /* Karakter */
	int N;
	char PStr[20]; /* untuk isPalindrome */
	char PKrg[20]; /* untuk pencocokan kurung */
	char X;  /* Variabel Pop */
	
	/* algoritma */
    /* createStack */

	createStack(&G);
	createStack(&O);
	createStack(&L);
	createStack(&D);
	createStack(&Xi); createStack(&Yi); createStack(&Zi);
	createStack(&Babel); createStack(&Zuma);

	printf("Selamat datang di Driver Stack!\n");
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	printf("===================================================================\n");

    /* push */

	printf("Awalnya stack G adalah : \n");
	printStack(G);
	push(&G,'S');
	printf("\n Karalter 'S' akan di Push kedalam G\n");
	printf("Sekarang Stack G adalah : \n");
	printStack(G);
	C = 'I'; H = 'N'; A = 'N'; P = 'E'; T = 'R';
	push(&G, C); push(&G, H); push(&G, A); push(&G, P); push(&G, T); push(&G, '|'); push(&G, 'M');
	push(&G,'A'); push(&G, 'N');
	printf("\nsemua Karakter yang dipush adalah 'SINNER|MAN'(Nina SImone)\n");
	printf("Dan Sekarang Stack G menjadi : \n");
	printStack(G); printf("\n");
	printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);

    /* pop */

	pushRandom(&O,10);
	printf("Awalnya Stack O adalah : \n");
	printStack(O);
	printf("\ntop O yaitu '%c' akan di POP\n",infotop(O));
	printf("juga X awalnya variabel kosong\n");
	pop(&O,&X);
	printf("Sekarang Stack O : \n");
	printStack(O);
	printf("\ndan X sekarang bernilai : '%c'\n",X);
	pop(&O,&X); pop(&O,&X); pop(&O, &X); pop(&O,&X); pop(&O,&X); pop(&O,&X);
	printf("Setelah dipop 6x lagi Sekarang Stack O : \n");
	printStack(O);
	printf("\nserta X sekarang bernilai : '%c'\n",X);
	printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* isEmptyStack && isFullStack */

	printf("kita memiliki 3 buah stack : G,O,L\n");
	printf("G : "); printStack(G); printf("\n");
	printf("O : "); printStack(O); printf("\n");
	printf("L : "); printStack(L); printf("\n");
	printf("Apakah G penuh?\n");
	if(isFullStack(G)==1){
	    printf("Stack G Penuh\n");
	} else {
	    printf("Stack G tidak Penuh\n");
	}
	printf("Apakah O penuh?\n");
	if(isFullStack(O)==1){
	    printf("Stack O Penuh\n");
	} else {
	    printf("Stack O tidak Penuh\n");
	}
	printf("Apakah L penuh?\n");
	if(isFullStack(L)==1){
	    printf("Stack L Penuh\n");
	} else {
	    printf("Stack L tidak Penuh\n");
	}
	printf("Apakah O Kosong?\n");
	if(isEmptyStack(O)==1){
	    printf("Stack O Kosong\n");
	} else {
	    printf("Stack O tidak Kosong\n");
	}
	printf("Apakah L Kosong?\n");
	if(isEmptyStack(L)==1){
	    printf("Stack L Kosong\n");
	} else {
	    printf("Stack L tidak Kosong\n");
	}
	printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* printStack viewStack*/
	
	printf("berikut adalah keseluruhan dari stack : (printStack)\n");
	printf("G : "); printStack(G); printf("\n");
	printf("O : "); printStack(O); printf("\n");
	printf("L : "); printStack(L); printf("\n");
	
	printf("berikut adalah tampilan stack,hanya elemen yang tak kosong\n");
	printf("G : "); viewStack(G); printf("\n");
	printf("O : "); viewStack(O); printf("\n");
	printf("L : "); viewStack(L); printf("\n");
	printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* isPalindrom */

	/* {isPalindrom(l) memeriksa apakah string l palindrom }
	{Pengecekan menggunakan aplikasi Stack}*/
	
	boolean isPalindrom(char str[]) {
    /* Kamus Lokal */
    Tstack T;
    int length = strlen(str);
    int i;   /* indeks string dari 0 */
    char X;  /* untuk menyimpan hasil pop dari stack */

    /* Algoritma */
    createStack(&T);
    // Push setengah karakter ke dalam stack
    for (i = 0; i < length / 2; i++) {
        push(&T, str[i]);
    }// Cek sisa string
    for (i = (length + 1) / 2; i < length; i++) {
        if (isEmptyStack(T)) {
            return false;  // Stack kosong, bukan palindrom
        }
        pop(&T, &X); // Ambil karakter dari stack
        if (str[i] != X) {
            return false;  // Jika ada karakter yang tidak sama
        }
    }
    return true;  // Jika semua karakter sama
    }

    /* Aplikasi isPalindrome*/
    printf("Kami akan mengecek apakah Kata/Kalimat berikut palindrom\n");
    printf("'ALAM MALA' : ");
    if(isPalindrom("ALAM MALA")){
        printf("YA, 'ALAM MALA' adalah palindrom\n");
    } else {
        printf("BUKAN, 'ALAM MALA' bukan palindrom\n");
    }
    printf("'ATMA AVES' : ");
    if(isPalindrom("ATMA AVES")){
        printf("YA, 'ATMA AVES' adalah palindrom\n");
    } else {
        printf("BUKAN, 'ATMA AVES' bukan palindrom\n");
    }
    printf("sekarang masukkan kata/kalimat(max 10 char) :\n");
    scanf(" %s", &PStr);
    printf("kami akan cek apakah '%s' adalah Palindrom\n", PStr);
    if(isPalindrom(PStr)){
        printf("YA, '%s' adalah palindrom\n", PStr);
    } else {
        printf("BUKAN, '%s' bukan palindrom\n",PStr);
    }
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /*function isKurungPAS (exp: string) -> boolean

    {mengembalikan true jika tanda kurung dalam ekspresi seimbang} */
    boolean isKurungPAS(char exp[]) {
        /* Kamus Lokal */
        Tstack T;
        int i;
        char ch;
    
        /* Algoritma */
        createStack(&T);
    
        for (i = 0; exp[i] != '\0'; i++) {
            // Cek apakah karakter adalah tanda kurung pembuka
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
                push(&T, exp[i]);
            } 
            // Cek apakah karakter adalah tanda kurung penutup
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
                if (isEmptyStack(T)) {
                    return false;  // Tidak ada pasangan buka
                }
                ch = infotop(T); 
                pop(&T, &ch);  // Ambil elemen teratas
    
                // Cek pasangan kurung sesuai
                if ((exp[i] == ')' && ch != '(') ||
                    (exp[i] == '}' && ch != '{') ||
                    (exp[i] == ']' && ch != '[')) {
                    return false;  // Pasangan tidak cocok
                }
            }
        }
    
        return isEmptyStack(T);  // Stack harus kosong jika semua pasangan cocok
    }
    /* Aplikasi isKurungPAS*/
    printf("Kami akan mengecek apakah Notasi berikut valid\n");
    printf("'[](){}12{}' : ");
    if(isKurungPAS("[](){}12{}")){
        printf("YA, '[](){}12{}' VALID\n");
    } else {
        printf("BUKAN, '[](){}12{}' TIDAK VALID\n");
    }
    printf("'[lo]{ba[k}]mrh()' : ");
    if(isKurungPAS("[lo]{ba[k}]mrh()")){
        printf("YA, '[lo]{ba[k}]mrh()' VALID\n");
    } else {
        printf("BUKAN, '[lo]{ba[k}]mrh()' TIDAK VALID\n");
    }
    printf("sekarang masukkan notasi(max 10 char) :\n");
    scanf(" %s", &PKrg);
    printf("kami akan cek apakah '%s' notasi yang valid\n", PKrg);
    if(isPalindrom(PStr)){
        printf("YA, '%s' VALID\n", PKrg);
    } else {
        printf("BUKAN, '%s' TIDAK VALID\n",PKrg);
    }
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* pushN */

    printf("Kami memiliki stack D yang dapat anda isi sendiri\n");
    printf("awalnya satck D :\n");
    printStack(D); printf("\n");
    printf("Stack ini awalnya kosong, berapa jumlah \nelemen anda ingin isi : \n");
    scanf(" %d",&N);
    printf("selamat mengisi stack D!\n");
    pushN(&D,N);
    printf("Selesai!, Sekarang D berisi : \n");
    printStack(D); printf("\n");
	printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* pushRandom */

    printf("Kami memiliki stack Xi, Yi, Zi yang akan kami isi random\n");
    printf("awalnya stack stack tersebut adalah:\n");
    printf ("Xi : "); printStack(Xi); printf("\n");
    printf ("Yi : "); printStack(Yi); printf("\n");
    printf ("Zi : "); printStack(Zi); printf("\n");
    printf("Stack Stack ini awalnya kosong, berapa jumlah \nelemen anda ingin isi : \n");
    scanf(" %d",&N);
    srand(time(NULL));
    pushRandom(&Xi,N); pushRandom(&Yi,N); pushRandom(&Zi,N); 
    printf("setelah diisi random stack stack tersebut menjadi :\n");
    printf ("Xi : "); printStack(Xi); printf("\n");
    printf ("Yi : "); printStack(Yi); printf("\n");
    printf ("Zi : "); printStack(Zi); printf("\n");
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* PushBabel1 */
	
	printf("Kami memiliki stack Babel yang dapat anda isi sendiri/random\n");
	printf("awalnya stack Babel tersebut adalah:\n");
    printf ("Babel : "); printStack(Babel); printf("\n");
	printf("Ketik 1 jika ingin Random dan 2 jika ingin isi sendiri\n");
	printf("Pilih Opsi : ");
    scanf(" %d",&N);
    if(N==1){
        printf("Berapa jumlah elemen yang ingin anda isi ?\n");
        printf("elemen : ");
        scanf(" %d",&N);
        pushRandom(&Babel, N);
    }else if(N==2){
        printf("Berapa jumlah elemen yang ingin anda isi ?\n");
        printf("elemen : ");
        scanf(" %d",&N);
        pushN(&Babel, N);
    } else{
        printf("masukkan yang benar,ULANGI Dari awal semuanya\n");
    }
    printf("Sekarang stack Babel tersebut adalah:\n");
    printf ("Babel : "); printStack(Babel); printf("\n");
    printf("SELAMAAT BERMAIN !\n");
    printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	printf("Babel : menumpuk top atau menghapus semua elemen\n");
	printf("masukkan elemen yang ingin kamu masukkan : \n");
	scanf(" %c",&R);
	pushBabel1(&Babel, R);
	printf("Sekarang stack Babel tersebut adalah:\n");
    printf ("Babel : "); printStack(Babel); printf("\n");
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* PushZuma */
	
    printf("Kami memiliki stack Zuma yang dapat anda isi sendiri/random\n");
    printf("Awalnya stack Zuma tersebut adalah:\n");
    printf("Zuma : "); printStack(Zuma); printf("\n");
    printf("Ketik 1 jika ingin Random dan 2 jika ingin isi sendiri\n");
    printf("Pilih Opsi : ");
    scanf(" %d", &N);
    if (N == 1) {
        printf("Berapa jumlah elemen yang ingin anda isi ?\n");
        printf("elemen : ");
        scanf(" %d", &N);
        pushRandom(&Zuma, N);
    } else if (N == 2) {
        printf("Berapa jumlah elemen yang ingin anda isi ?\n");
        printf("elemen : ");
        scanf(" %d", &N);
        pushN(&Zuma, N);
    } else {
        printf("Masukkan yang benar, ULANGI Dari awal semuanya\n");
    }
    
    printf("Sekarang stack Zuma tersebut adalah:\n");
    printf("Zuma : "); printStack(Zuma); printf("\n");
    printf("SELAMAT BERMAIN !\n");
    printf("Ketik sebuah karakter dan enter untuk lanjut\n");
    printf("ENTER HERE : "); scanf(" %c", &R);
    printf("Zuma : menumpuk top atau menghapus semua elemen\n");
    printf("Masukkan elemen yang ingin kamu masukkan : \n");
    scanf(" %c", &R);
    pushZuma(&Zuma, R);
    printf("Sekarang stack Zuma tersebut adalah:\n");
    printf("Zuma : "); printStack(Zuma); printf("\n");
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
    /* reverseStack */

	printf("kamu akan mereverse stack stack berikut :\n");
	printf ("Xi : "); printStack(Xi); printf("\n");
    printf ("Yi : "); printStack(Yi); printf("\n");
    printf ("Zi : "); printStack(Zi); printf("\n");
    
    reverseStack(&Xi); reverseStack(&Yi); reverseStack(&Zi);
    
    printf("Sekarang stack stack tersebut berubah menjadi : \n");
    printf ("Xi : "); printStack(Xi); printf("\n");
    printf ("Yi : "); printStack(Yi); printf("\n");
    printf ("Zi : "); printStack(Zi); printf("\n");
    
    printf("===================================================================\n");
	
	printf("ketik sebuah karakter dan enter untuk lanjut\n");
	printf("ENTER HERE : "); scanf(" %c",&R);
	
	printf("=======================PROGRAM SELESAI=================");

    return 0;
}