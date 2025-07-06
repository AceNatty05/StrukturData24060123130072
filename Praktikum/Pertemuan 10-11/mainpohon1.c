/* File       : pohon1.h */
/* Deskripsi  : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari */
/* Tanggal    : 25/11/2024*/

#include "pohon1.c"

int main () {
    //KAMUS
    char Input[10],Input2[10], Menu[10]; // untuk menghindari error saat input lebih dari 1 karakter
    bintree A, B, C, D; 

    //ALGORITMA

    // Inisialisasi
    strcpy(Menu, "0");
    A = Tree('U', NIL, Tree('V', Tree('U', NIL, NIL), Tree('V', Tree('W', NIL, NIL), Tree('E', Tree('V', NIL, NIL), Tree('W', Tree('E', NIL, NIL), Tree('V', Tree('W', NIL, NIL), Tree('E', NIL, NIL)))))));
    B = Tree('O', NIL, Tree('N', Tree('Y', NIL, NIL), Tree('E', Tree('T', NIL, NIL), Tree('E', Tree('N', NIL, NIL), Tree('Y', Tree('E', NIL, NIL), Tree('V', Tree('W', NIL, NIL), Tree('E', NIL, NIL)))))));
    C = Tree('U', NIL, Tree('G', Tree('W', NIL, NIL), Tree('E', Tree('M', NIL, NIL), Tree('U', Tree('B', NIL, NIL), Tree('W', Tree('E', NIL, NIL), Tree('M', NIL, NIL))))));
    D = Tree('O', NIL, Tree('S', Tree('A', NIL, NIL), Tree('S', NIL, NIL)));

    // Loop Menu
    printf("SELAMAT DATANG DI DRIVER POHON 1 ~Natasya\n");
    printf("Awalnya tersedia 4 Tree dengan detail sebagai berikut: \n");
    printf("\n***** Tree A:"); PrintPrefixV2(A);
    printf("\n***** Tree B:"); PrintPrefixV2(B);
    printf("\n***** Tree C:"); PrintPrefixV2(C);
    printf("\n***** Tree D:"); PrintPrefixV2(D); printf("\n\n");
    ShowMenu(); printf("\n");
    while (strcmp(Menu, "Q") != 0) {
        printf("** Masukan pilihan menu: ");
		scanf (" %s", &Menu); printf("\n");
    
        if      (strcmp(Menu, "1") == 0) {
            printf("   1    : PrintPrefix\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Tree A = "); PrintPrefix(A); 
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Tree B = "); PrintPrefix(B); 
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Tree C = "); PrintPrefix(C); 
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Tree D = "); PrintPrefix(D); 
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "2") == 0) {
            printf("   2    : PrintInfix\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Tree A = "); PrintInfix(A); 
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Tree B = "); PrintInfix(B); 
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Tree C = "); PrintInfix(C); 
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Tree D = "); PrintInfix(D); 
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "3") == 0) {
            printf("   3    : PrintInfix\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Tree A = "); PrintPostfix(A); 
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Tree B = "); PrintPostfix(B); 
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Tree C = "); PrintPostfix(C); 
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Tree D = "); PrintPostfix(D); 
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "4") == 0) {
            printf("   4    : SearchX\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Apakah %c ditemukan di List A = ", Input[0]); 
                YESorYES(SearchX(A,Input[0]));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Apakah %c ditemukan di List B = ", Input[0]); 
                YESorYES(SearchX(B,Input[0])); 
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Apakah %c ditemukan di List C = ", Input[0]); 
                YESorYES(SearchX(C,Input[0]));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Apakah %c ditemukan di List D = ", Input[0]); 
                YESorYES(SearchX(D,Input[0]));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "5") == 0) {
            printf("   5    : UpdateX\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("\nMasukkan Y = %s"); scanf(" %s", &Input2);
                UpdateX(&A, Input[0], Input2[0]); 
                printf("Setelah UpdateX = "); PrintPrefixV2(A);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("\nMasukkan Y = %s"); scanf(" %s", &Input2);
                UpdateX(&A, Input[0], Input2[0]); 
                printf("Setelah UpdateX = "); PrintPrefixV2(B); 
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("\nMasukkan Y = %s"); scanf(" %s", &Input2);
                UpdateX(&A, Input[0], Input2[0]); 
                printf("Setelah UpdateX = "); PrintPrefixV2(C);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("\nMasukkan Y = %s"); scanf(" %s", &Input2);
                UpdateX(&A, Input[0], Input2[0]); 
                printf("Setelah UpdateX = "); PrintPrefixV2(D);
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "6") == 0) {
            printf("   6    : CountX\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Banyak elemen %c pada pohon A = %d", Input[0], CountX(A,Input[0]));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Banyak elemen %c pada pohon B = %d", Input[0], CountX(B,Input[0]));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Banyak elemen %c pada pohon C = %d", Input[0], CountX(C,Input[0]));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Banyak elemen %c pada pohon D = %d", Input[0], CountX(D,Input[0]));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "7") == 0) {
            printf("   7    : LevelX\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Elemen %c ditemukan di pohon A pada level = %d", Input[0], LevelX(A,Input[0]));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Elemen %c ditemukan di pohon B pada level = %d", Input[0], LevelX(B,Input[0]));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Elemen %c ditemukan di pohon C pada level = %d", Input[0], LevelX(C,Input[0]));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Elemen %c ditemukan di pohon D pada level = %d", Input[0], LevelX(D,Input[0]));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "8") == 0) {
            printf("   8    : CountLevelT\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan T = %s"); scanf(" %s", &Input);
                printf("Banyaknya elemen di level %c adalah = %d", Input[0], CountLevelT(A,Input[0]));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan T = %s"); scanf(" %s", &Input);
                printf("Banyaknya elemen di level %c adalah = %d", Input[0], CountLevelT(B,Input[0]));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan T = %s"); scanf(" %s", &Input);
                printf("Banyaknya elemen di level %c adalah = %d", Input[0], CountLevelT(C,Input[0]));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan T = %s"); scanf(" %s", &Input);
                printf("Banyaknya elemen di level %c adalah = %d", Input[0], CountLevelT(D,Input[0]));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "9") == 0) {
            printf("   9    : GetDaunTerkiri\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Pohon A = "); PrintPrefixV2(A);
                printf("\nDaun terkiri di pohon A = %c", GetDaunTerkiri(A));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nDaun terkiri di pohon B = %c", GetDaunTerkiri(B));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nDaun terkiri di pohon C = %c", GetDaunTerkiri(C));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nDaun terkiri di pohon D = %c", GetDaunTerkiri(D));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "10") == 0) {
            printf("   10   : FrekuensiX\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Awalnya Pohon A = "); PrintPrefixV2(A);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Frekuensi elemen %c pada pohon A = %f", Input[0], FrekuensiX(A,Input[0]));
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B = "); PrintPrefixV2(B);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Frekuensi elemen %c pada pohon B = %f", Input[0], FrekuensiX(B,Input[0]));
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C = "); PrintPrefixV2(C);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Frekuensi elemen %c pada pohon C = %f", Input[0], FrekuensiX(C,Input[0]));
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D = "); PrintPrefixV2(D);
                printf("\nMasukkan X = %s"); scanf(" %s", &Input);
                printf("Frekuensi elemen %c pada pohon D = %f", Input[0], FrekuensiX(D,Input[0]));
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "11") == 0) {
            printf("   11   : ShowStat\n");
            printf("** Pilihan pohon : "); scanf(" %s", &Input);
            if      (strcmp(Input, "A") == 0) {
                printf("Pohon A:"); ShowStat(A);
            }
            else if (strcmp(Input, "B") == 0) {
                printf("Pohon B:"); ShowStat(B);
            }
            else if (strcmp(Input, "C") == 0) {
                printf("Pohon C:"); ShowStat(C);
            }
            else if (strcmp(Input, "D") == 0) {
                printf("Pohon D:"); ShowStat(D);
            }
            else {
                printf("Tidak ada tree %s. Hanya ada tree A, B, C, D", Input);
            }
        }
        else if (strcmp(Menu, "M") == 0) {
            ShowMenu();
        }
        else if (strcmp(Menu, "Q") == 0) {
            printf("Keluar dari driver pohon 1 ~~~");
        }
        else {
            printf("Tidak ada menu %s", Menu);
        }

        printf("\n\n");
    }

    DeleteTree(&A); DeleteTree(&B); DeleteTree(&C); DeleteTree(&D);

    return 0;
}