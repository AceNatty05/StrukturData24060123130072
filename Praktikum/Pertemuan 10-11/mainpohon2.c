/* File       : mainpohon2.h */
/* Deskripsi  : driver ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal    : 25/11/2024*/

#include "pohon2.c"

int main () {
    //KAMUS
    char Input[5], Input2[5], Input3[5], Menu[5], X; // untuk menghindari error saat input lebih dari 1 karakter
    bintree A, B, C, D, E, F, G, H, I, J, K, L, O;
    int n;
    
    //ALGORITMA

    // Inisialisasi
    strcpy(Menu, "0");

    // Tree biasa
    A = Tree('U', Tree('V', Tree('U', NIL, NIL), NIL), Tree('V', NIL, Tree('W', Tree('E', NIL, NIL), Tree('V', Tree('W', NIL, NIL), Tree('E', Tree('V', NIL, NIL), Tree('W', NIL, NIL))))));
    B = Tree('O', Tree('N', NIL, Tree('Y', NIL, NIL)), Tree('E', Tree('T', Tree('E', NIL, NIL), NIL), Tree('N', NIL, Tree('Y', Tree('E', NIL, NIL), Tree('V', Tree('W', NIL, NIL), Tree('E', NIL, NIL))))));
    C = Tree('U', Tree('G', NIL, Tree('W', NIL, NIL)), Tree('E', Tree('M', Tree('U', NIL, NIL), Tree('B', NIL, Tree('W', NIL, NIL))), Tree('E', NIL, Tree('M', NIL, NIL))));
    D = Tree('O', NIL, Tree('S', Tree('A', NIL, NIL), Tree('S', NIL, NIL)));

    // Tree balance
    E = Tree('M', Tree('G', Tree('C', Tree('A', NIL, NIL), Tree('E', NIL, Tree('F', NIL, NIL))), Tree('K', Tree('H', NIL, Tree('I', NIL, NIL)), Tree('L', NIL, NIL))), Tree('T', Tree('P', Tree('N', NIL, NIL), Tree('R', Tree('Q', NIL, NIL), NIL)), Tree('X', Tree('U', NIL, Tree('V', NIL, NIL)), Tree('Z', NIL, NIL))));
    F = Tree('I', Tree('D', Tree('B', Tree('A', NIL, NIL), Tree('C', NIL, NIL)), Tree('E', Tree('F', NIL, NIL), NIL)), Tree('M', Tree('J', Tree('G', NIL, NIL), NIL), Tree('N', Tree('K', NIL, NIL), Tree('L', NIL, NIL))));
    G = Tree('H', Tree('D', Tree('B', NIL, NIL), Tree('F', Tree('E', NIL, NIL), NIL)), Tree('N', Tree('L', Tree('J', NIL, NIL), NIL), Tree('Q', Tree('M', NIL, NIL), NIL)));
    H = Tree('O', Tree('F', Tree('C', Tree('A', NIL, NIL), Tree('E', NIL, NIL)), Tree('G', Tree('D', NIL, NIL), Tree('H', NIL, NIL))), Tree('V', Tree('Q', Tree('P', NIL, NIL), Tree('R', NIL, NIL)), Tree('Z', Tree('U', NIL, NIL), Tree('Y', NIL, NIL))));

    // BST 
    I = Tree('O', Tree('I', Tree('E', Tree('D', Tree('B', Tree('A', NIL, NIL), Tree('C', NIL, NIL)), NIL), NIL), Tree('M', Tree('J', NIL, Tree('K', NIL, Tree('L', NIL, NIL))), NIL)), Tree('T', NIL, Tree('V', Tree('U', NIL, NIL), Tree('Y', Tree('W', NIL, Tree('X', NIL, NIL)), Tree('Z', NIL, NIL)))));  
    J = Tree('M', Tree('F', Tree('D', Tree('B', NIL, NIL), Tree('C', NIL, NIL)), Tree('E', NIL, NIL)), Tree('R', Tree('O', Tree('L', NIL, NIL), Tree('P', NIL, NIL)), Tree('V', Tree('U', NIL, NIL), Tree('W', NIL, NIL))));
    K = Tree('M', Tree('F', Tree('D', Tree('B', NIL, NIL), Tree('C', NIL, NIL)), Tree('E', Tree('G', NIL, NIL), NIL)), Tree('R', Tree('O', Tree('L', NIL, NIL), NIL), Tree('S', Tree('P', NIL, NIL), Tree('T', NIL, NIL))));
    L = Tree('M', Tree('F', Tree('D', Tree('B', NIL, NIL), Tree('C', NIL, NIL)), NIL), Tree('T', Tree('P', NIL, NIL), Tree('V', Tree('U', NIL, NIL), Tree('W', NIL, NIL))));
    MakeBSearch(&J); MakeBSearch(&K); MakeBSearch(&L); // karena BSearchTree buatan GPT ga jelas, perbaiki dulu

    // Tree Kosong
    O = NIL;

    // Loop Program Utama
    printf("SELAMAT DATANG DI DRIVER POHON 2 ~Natasya\n\n");
    ShowMenu2(); printf("\n");
    while (strcmp(Menu, "Q") != 0) {
        printf("** Masukan pilihan menu: ");
		scanf (" %s", &Menu); printf("\n");

        if      (strcmp(Menu, "1") == 0) {
            printf("   1    : PrintTreeInden\n");
            printf("Tersedia pohon A hingga L untuk PrintTreeInden\n");
            printf("** Pilihan pohon: "); scanf(" %s", &Input);

            if      (strcmp(Input, "A") == 0) {
                PrintTreeInden(A,0);
            }
            else if (strcmp(Input, "B") == 0) {
                PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                PrintTreeInden(D,0);
            }
            else if (strcmp(Input, "E") == 0) {
                PrintTreeInden(E,0);
            }
            else if (strcmp(Input, "F") == 0) {
                PrintTreeInden(F,0);
            }
            else if (strcmp(Input, "G") == 0) {
                PrintTreeInden(G,0);
            }
            else if (strcmp(Input, "H") == 0) {
                PrintTreeInden(H,0);
            }
            else if (strcmp(Input, "I") == 0) {
                PrintTreeInden(I,0);
            }
            else if (strcmp(Input, "J") == 0) {
                PrintTreeInden(J,0);
            }
            else if (strcmp(Input, "K") == 0) {
                PrintTreeInden(K,0);
            }
            else if (strcmp(Input, "L") == 0) {
                PrintTreeInden(L,0);
            }
            else {
                printf("Tidak ada pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "2") == 0) {
            printf("   2    : PrintLevel\n");
            printf("Tersedia pohon A hingga L untuk PrintTreeInden\n");
            printf("** Pilihan pohon: "); scanf(" %s", &Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A dengan level max %d", Tinggi(A)+1); PrintTreeInden(A,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(A,n);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B dengan level max %d", Tinggi(B)+1); PrintTreeInden(B,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(B,n);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C dengan level max %d", Tinggi(C)+1); PrintTreeInden(C,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(C,n);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D dengan level max %d", Tinggi(D)+1); PrintTreeInden(D,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(D,n);
            }
            else if (strcmp(Input, "E") == 0) {
                printf("Awalnya pohon E dengan level max %d", Tinggi(E)+1); PrintTreeInden(E,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(E,n);
            }
            else if (strcmp(Input, "F") == 0) {
                printf("Awalnya pohon F dengan level max %d", Tinggi(F)+1); PrintTreeInden(F,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(F,n);
            }
            else if (strcmp(Input, "G") == 0) {
                printf("Awalnya pohon G dengan level max %d", Tinggi(G)+1); PrintTreeInden(G,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(G,n);
            }
            else if (strcmp(Input, "H") == 0) {
                printf("Awalnya pohon H dengan level max %d", Tinggi(H)+1); PrintTreeInden(H,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(H,n);
            }
            else if (strcmp(Input, "I") == 0) {
                printf("Awalnya pohon I dengan level max %d", Tinggi(I)+1); PrintTreeInden(I,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(I,n);
            }
            else if (strcmp(Input, "J") == 0) {
                printf("Awalnya pohon J dengan level max %d", Tinggi(J)+1); PrintTreeInden(J,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(J,n);
            }
            else if (strcmp(Input, "K") == 0) {
                printf("Awalnya pohon K dengan level max %d", Tinggi(K)+1); PrintTreeInden(K,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(K,n);
            }
            else if (strcmp(Input, "L") == 0) {
                printf("Awalnya pohon L dengan level max %d", Tinggi(L)+1); PrintTreeInden(L,0); 
                printf("** Masukkan Level : "); scanf(" %d", n); PrintLevel(L,n);
            }
            else {
                printf("Tidak ada pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "3") == 0) {
            printf("   3    : BuildBalanceTree & IsBalanceTree\n");
            printf("Membuat BalanceTree baru (Y) atau gunakan yang sudah tersedia (N)?\n** JAWABAN (Y/N) : "); scanf(" %s", Input);
            if (strcmp(Input, "Y") == 0) {
                DeleteTree(&O); // sterilkan barangkali sudah ada isinya
                O = BuildBalanceTree(n); PrintTreeInden(O,0); 
                printf("Telah dibuat pohon balance baru\nApakah pohon yang dibuat balance?\nJAWABAN : "); YESorYES(IsBalanceTree(O));
            }
            else {
                printf("Tersedia pilihan pohon E hingga H untuk IsBalanceTree\n** Pilihan pohon : "); scanf(" %s", Input);

                if      (strcmp(Input, "E") == 0) {
                    printf("Isi pohon E :\n"); PrintTreeInden(E,0); 
                    printf("Apakah pohon balance?\nJAWABAN : "); YESorYES(IsBalanceTree(E));
                }
                else if (strcmp(Input, "F") == 0) {
                    printf("Isi pohon F :\n"); PrintTreeInden(F,0); 
                    printf("Apakah pohon balance?\nJAWABAN : "); YESorYES(IsBalanceTree(F));
                }
                else if (strcmp(Input, "G") == 0) {
                    printf("Isi pohon G :\n"); PrintTreeInden(G,0); 
                    printf("Apakah pohon balance?\nJAWABAN : "); YESorYES(IsBalanceTree(G));
                }
                else if (strcmp(Input, "H") == 0) {
                    printf("Isi pohon H :\n"); PrintTreeInden(H,0); 
                    printf("Apakah pohon balance?\nJAWABAN : "); YESorYES(IsBalanceTree(H));
                }
                else {
                    printf("Tidak ada pilihan pohon %s", Input);
                }
            }
        }
        else if (strcmp(Menu, "4") == 0) {
            printf("   4    : AddDaunTerkiri\n");
            printf("Tersedia pilihan pohon A hingga D untuk AddDaunTerkiri\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A dengan daun terkiri '%c'\n", GetDaunTerkiri(A)); PrintTreeInden(A,0);
                printf("** Masukkan daun terkiri baru : "); scanf(" %s", Input); AddDaunTerkiri(&A,Input[0]);
                printf("Pohon A sekarang berubah menjadi : \n"); PrintTreeInden(A,0);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B dengan daun terkiri '%c'\n", GetDaunTerkiri(B)); PrintTreeInden(B,0);
                printf("** Masukkan daun terkiri baru : "); scanf(" %s", Input); AddDaunTerkiri(&B,Input[0]);
                printf("Pohon B sekarang berubah menjadi : \n"); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C dengan daun terkiri '%c'\n", GetDaunTerkiri(C)); PrintTreeInden(C,0);
                printf("** Masukkan daun terkiri baru : "); scanf(" %s", Input); AddDaunTerkiri(&C,Input[0]);
                printf("Pohon C sekarang berubah menjadi : \n"); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D dengan daun terkiri '%c'\n", GetDaunTerkiri(D)); PrintTreeInden(D,0);
                printf("** Masukkan daun terkiri baru : "); scanf(" %s", Input); AddDaunTerkiri(&D,Input[0]);
                printf("Pohon D sekarang berubah menjadi : \n"); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "5") == 0) {
            printf("   5    : AddDaun\n");
            printf("Tersedia pilihan pohon A hingga D untuk AddDaun\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0);
                printf("** Masukkan Daun X : "); scanf(" %s", Input); printf("** Masukkan node Y : "); scanf(" %s", Input2); 
                printf("Apakah Kiri?\n** JAWABAN(Y/N) : "); scanf(" %s", Input3); 
                AddDaun(&A, Input[0], Input2[0], (strcmp(Input3, "Y") == 0)); 
                printf("Pohon A sekarang berubah menjadi : \n"); PrintTreeInden(A,0); 
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0);
                printf("** Masukkan Daun X : "); scanf(" %s", Input); printf("** Masukkan node Y : "); scanf(" %s", Input2); 
                printf("Apakah Kiri?\n** JAWABAN(Y/N) : "); scanf(" %s", Input3); 
                AddDaun(&B, Input[0], Input2[0], (strcmp(Input3, "Y") == 0));
                printf("Pohon B sekarang berubah menjadi : \n"); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0);
                printf("** Masukkan Daun X : "); scanf(" %s", Input); printf("** Masukkan node Y : "); scanf(" %s", Input2); 
                printf("Apakah Kiri?\n** JAWABAN(Y/N) : "); scanf(" %s", Input3); 
                AddDaun(&C, Input[0], Input2[0], (strcmp(Input3, "Y") == 0));
                printf("Pohon C sekarang berubah menjadi : \n"); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D : \n"); PrintTreeInden(D,0);
                printf("** Masukkan Daun X : "); scanf(" %s", Input); printf("** Masukkan node Y : "); scanf(" %s", Input2); 
                printf("Apakah Kiri?\n** JAWABAN(Y/N) : "); scanf(" %s", Input3); 
                AddDaun(&D, Input[0], Input2[0], (strcmp(Input3, "Y") == 0));
                printf("Pohon D sekarang berubah menjadi : \n"); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "6") == 0) {
            printf("   6    : InsertX\n");
            printf("Tersedia pilihan pohon A hingga D untuk InsertX\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0);
                printf("** Masukkan node X : "); scanf(" %s", Input);
                if (!SearchX(A,Input[0])) { // bila tidak ditemukan
                    InsertX(&A,Input[0]); printf("Pohon A sekarang berubah menjadi : \n"); PrintTreeInden(A,0);
                }
                else {
                    printf("Ups, sudah ada %c di pohon A", Input[0]);
                }
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0);
                printf("** Masukkan node X : "); scanf(" %s", Input);
                if (!SearchX(B,Input[0])) { // bila tidak ditemukan
                    InsertX(&B,Input[0]); printf("Pohon B sekarang berubah menjadi : \n"); PrintTreeInden(B,0);
                }
                else {
                    printf("Ups, sudah ada %c di pohon B", Input[0]);
                }
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0);
                printf("** Masukkan node X : "); scanf(" %s", Input);
                if (!SearchX(C,Input[0])) { // bila tidak ditemukan
                    InsertX(&C,Input[0]); printf("Pohon C sekarang berubah menjadi : \n"); PrintTreeInden(C,0);
                }
                else {
                    printf("Ups, sudah ada %c di pohon C", Input[0]);
                }
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D : \n"); PrintTreeInden(D,0);
                printf("** Masukkan node X : "); scanf(" %s", Input);
                if (!SearchX(D,Input[0])) { // bila tidak ditemukan
                    InsertX(&D,Input[0]); printf("Pohon D sekarang berubah menjadi : \n"); PrintTreeInden(D,0);
                }
                else {
                    printf("Ups, sudah ada %c di pohon D", Input[0]);
                }
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "7") == 0) {
            printf("   7    : DelDaunTerkiri\n");
            printf("Tersedia pilihan pohon A hingga D untuk DelDaunTerkiri\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0); DelDaunTerkiri(&A,&X); 
                printf("Sekarang berubah tanpa daun '%c' menjadi :\n", X); PrintTreeInden(A,0);
                
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0); DelDaunTerkiri(&B,&X); 
                printf("Sekarang berubah tanpa daun '%c' menjadi :\n", X); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0); DelDaunTerkiri(&C,&X); 
                printf("Sekarang berubah tanpa daun '%c' menjadi :\n", X); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D: \n"); PrintTreeInden(D,0); DelDaunTerkiri(&D,&X); 
                printf("Sekarang berubah tanpa daun '%c' menjadi :\n", X); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "8") == 0) {
            printf("   8    : DelDaun\n");
            printf("Tersedia pilihan pohon A hingga D untuk DelDaun\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0); printf("** Masukkan daun X : "); scanf(" %s", Input);
                DelDaun(&A,Input[0]); printf("Sekarang berubah tanpa daun '%c' menjadi :\n", Input[0]); PrintTreeInden(A,0);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0); printf("** Masukkan daun X : "); scanf(" %s", Input);
                DelDaun(&B,Input[0]); printf("Sekarang berubah tanpa daun '%c' menjadi :\n", Input[0]); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0); printf("** Masukkan daun X : "); scanf(" %s", Input);
                DelDaun(&C,Input[0]); printf("Sekarang berubah tanpa daun '%c' menjadi :\n", Input[0]); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D : \n"); PrintTreeInden(D,0); printf("** Masukkan daun X : "); scanf(" %s", Input);
                DelDaun(&D,Input[0]); printf("Sekarang berubah tanpa daun '%c' menjadi :\n", Input[0]); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "9") == 0) {
            printf("   9    : DeleteX\n");
            printf("Tersedia pilihan pohon A hingga D untuk DeleteX\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                DeleteX(&A,Input[0]); printf("Sekarang berubah tanpa node '%c' menjadi :\n", Input[0]); PrintTreeInden(A,0);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                DeleteX(&B,Input[0]); printf("Sekarang berubah tanpa node '%c' menjadi :\n", Input[0]); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                DeleteX(&C,Input[0]); printf("Sekarang berubah tanpa node '%c' menjadi :\n", Input[0]); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D : \n"); PrintTreeInden(D,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                DeleteX(&D,Input[0]); printf("Sekarang berubah tanpa node '%c' menjadi :\n", Input[0]); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        } 
        else if (strcmp(Menu, "10") == 0) {
            printf("   10   : UpdateAllX\n");
            printf("Tersedia pilihan pohon A hingga D untuk UpdateAllX\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya pohon A : \n"); PrintTreeInden(A,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                printf("** Masukkan Y pengganti node X : "); scanf(" %s", Input2); UpdateAllX(&A,Input[0],Input2[0]);
                printf("Setelah merubah semua node '%c' menjadi '%c' pohonnya menjadi :\n", Input[0], Input2[0]); PrintTreeInden(A,0);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Awalnya pohon B : \n"); PrintTreeInden(B,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                printf("** Masukkan Y pengganti node X : "); scanf(" %s", Input2); UpdateAllX(&B,Input[0],Input2[0]);
                printf("Setelah merubah semua node '%c' menjadi '%c' pohonnya menjadi :\n", Input[0], Input2[0]); PrintTreeInden(B,0);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Awalnya pohon C : \n"); PrintTreeInden(C,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                printf("** Masukkan Y pengganti node X : "); scanf(" %s", Input2); UpdateAllX(&C,Input[0],Input2[0]);
                printf("Setelah merubah semua node '%c' menjadi '%c' pohonnya menjadi :\n", Input[0], Input2[0]); PrintTreeInden(C,0);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Awalnya pohon D : \n"); PrintTreeInden(D,0); printf("** Masukkan node X : "); scanf(" %s", Input);
                printf("** Masukkan Y pengganti node X : "); scanf(" %s", Input2); UpdateAllX(&D,Input[0],Input2[0]);
                printf("Setelah merubah semua node '%c' menjadi '%c' pohonnya menjadi :\n", Input[0], Input2[0]); PrintTreeInden(D,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "11") == 0) {
            printf("   11   : BSearch\n");
            printf("Tersedia pilihan pohon I hingga L untuk BSearch\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "I") == 0) {
                printf("Awalnya pohon I : \n"); PrintTreeInden(I,0); printf("** Masukkan node X yang dicari : "); scanf(" %s", Input);
                printf("Apakah node '%c' ada di pohon I?\nJAWABAN : ", Input[0]); YESorYES(BSearch(I,Input[0]));
            }
            else if (strcmp(Input, "J") == 0) {
                printf("Awalnya pohon J : \n"); PrintTreeInden(J,0); printf("** Masukkan node X yang dicari : "); scanf(" %s", Input);
                printf("Apakah node '%c' ada di pohon J?\nJAWABAN : ", Input[0]); YESorYES(BSearch(J,Input[0]));
            }
            else if (strcmp(Input, "K") == 0) {
                printf("Awalnya pohon K : \n"); PrintTreeInden(K,0); printf("** Masukkan node X yang dicari : "); scanf(" %s", Input);
                printf("Apakah node '%c' ada di pohon K?\nJAWABAN : ", Input[0]); YESorYES(BSearch(K,Input[0]));
            }
            else if (strcmp(Input, "L") == 0) {
                printf("Awalnya pohon L : \n"); PrintTreeInden(L,0); printf("** Masukkan node X yang dicari : "); scanf(" %s", Input);
                printf("Apakah node '%c' ada di pohon L?\nJAWABAN : ", Input[0]); YESorYES(BSearch(L,Input[0]));
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "12") == 0) {
            printf("   12   : InsSearch\n");
            printf("Tersedia pilihan pohon I hingga L untuk InsSearch\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "I") == 0) {
                printf("Awalnya pohon I : \n"); PrintTreeInden(I,0); printf("** Masukkan node X untuk ditambahkan : "); scanf(" %s", Input);
                if (!SearchX(I,Input[0])) { // if mboten enten
                    I = InsSearch(I,Input[0]); printf("Setelah penambahan node '%c' menjadi :\n", Input[0]); PrintTreeInden(I,0);
                }
                else {
                    printf("Ups, node '%c' sudah ada di pohon I", Input[0]);
                }
            }
            else if (strcmp(Input, "J") == 0) {
                printf("Awalnya pohon J : \n"); PrintTreeInden(J,0); printf("** Masukkan node X untuk ditambahkan : "); scanf(" %s", Input);
                if (!SearchX(J,Input[0])) { // if mboten enten
                    J = InsSearch(J,Input[0]); printf("Setelah penambahan node '%c' menjadi :\n", Input[0]); PrintTreeInden(J,0);
                }
                else {
                    printf("Ups, node '%c' sudah ada di pohon J", Input[0]);
                }
            }
            else if (strcmp(Input, "K") == 0) {
                printf("Awalnya pohon K : \n"); PrintTreeInden(K,0); printf("** Masukkan node X untuk ditambahkan : "); scanf(" %s", Input);
                if (!SearchX(K,Input[0])) { // if mboten enten
                    K = InsSearch(K,Input[0]); printf("Setelah penambahan node '%c' menjadi :\n", Input[0]); PrintTreeInden(K,0);
                }
                else {
                    printf("Ups, node '%c' sudah ada di pohon K", Input[0]);
                }
            }
            else if (strcmp(Input, "L") == 0) {
                printf("Awalnya pohon L : \n"); PrintTreeInden(L,0); printf("** Masukkan node X untuk ditambahkan : "); scanf(" %s", Input);
                if (!SearchX(L,Input[0])) { // if mboten enten
                    L = InsSearch(L,Input[0]); printf("Setelah penambahan node '%c' menjadi :\n", Input[0]); PrintTreeInden(L,0);
                }
                else {
                    printf("Ups, node '%c' sudah ada di pohon L", Input[0]);
                }
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "13") == 0) {
            printf("   13   : DelBtree\n");
            printf("Tersedia pilihan pohon I hingga L untuk DelBTree\n** Pilihan pohon : "); scanf(" %s", Input);

            if      (strcmp(Input, "I") == 0) {
                printf("Awalnya pohon I : \n"); PrintTreeInden(I,0); printf("** Masukkan node X untuk dihapus : "); scanf(" %s", Input);
                DelBtree(&I,Input[0]); printf("Pohon I setelah node '%c' dihapus :\n", Input[0]); PrintTreeInden(I,0);
            }
            else if (strcmp(Input, "J") == 0) {
                printf("Awalnya pohon J : \n"); PrintTreeInden(J,0); printf("** Masukkan node X untuk dihapus : "); scanf(" %s", Input);
                DelBtree(&J,Input[0]); printf("Pohon J setelah node '%c' dihapus :\n", Input[0]); PrintTreeInden(J,0);
            }
            else if (strcmp(Input, "K") == 0) {
                printf("Awalnya pohon K : \n"); PrintTreeInden(K,0); printf("** Masukkan node X untuk dihapus : "); scanf(" %s", Input);
                DelBtree(&K,Input[0]); printf("Pohon K setelah node '%c' dihapus :\n", Input[0]); PrintTreeInden(K,0);
            }
            else if (strcmp(Input, "L") == 0) {
                printf("Awalnya pohon L : \n"); PrintTreeInden(L,0); printf("** Masukkan node X untuk dihapus : "); scanf(" %s", Input);
                DelBtree(&L,Input[0]); printf("Pohon L setelah node '%c' dihapus :\n", Input[0]); PrintTreeInden(L,0);
            }
            else {
                printf("Tidak ada pilihan pohon %s", Input);
            }
        }
        else if (strcmp(Menu, "M") == 0) {
            ShowMenu2();
        }
        else if (strcmp(Menu, "Q") == 0) {
            printf("OTW menutup driver");
        }
        else {
            printf("Tidak ada menu %s", Menu);
        }

        printf("\n\n");
    }

    printf("Keluar dari driver");

    DeleteTree(&A); printf("."); DeleteTree(&B); printf("."); DeleteTree(&C); printf("."); DeleteTree(&D); printf(".");
    DeleteTree(&E); printf("."); DeleteTree(&F); printf("."); DeleteTree(&G); printf("."); DeleteTree(&H); printf(".");
    DeleteTree(&I); printf("."); DeleteTree(&J); printf("."); DeleteTree(&K); printf("."); DeleteTree(&L); printf(".");
    DeleteTree(&O); printf(".");

    return 0;
}