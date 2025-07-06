/* File : mainpohon3.c */
/* Deskripsi : driver body ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130072 & Natasya Amelia Candrasari*/
/* Tanggal : 06/12/2024*/

#include "pohon3.c"

int main () {
    /*KAMUS GERROBARRU*/
    List1 O, P, Q;
    bintree3 a, b, c, A, B, C, D, E, F, G, H, I, J;

    /*ALGORITMA*/

    CreateList(&O); CreateList(&P); CreateList(&Q); 

    /*POHON A FOR ANTI TUMBANG*/
    J = Tree3(NIL, 'J', false, NIL, NIL);
    I = Tree3(NIL, 'I', false, NIL, NIL);
    H = Tree3(NIL, 'H', false, NIL, NIL);
    G = Tree3(NIL, 'G', false, NIL, NIL);
    F = Tree3(NIL, 'F', false, J, NIL);
    E = Tree3(NIL, 'E', false, NIL, I);
    D = Tree3(NIL, 'D', false, H, NIL);
    C = Tree3(NIL, 'C', false, F, G);
    B = Tree3(NIL, 'B', false, D, E);
    A = Tree3(NIL, 'A', false, B, C);

    parent(J) = F;
    parent(I) = E;
    parent(H) = D;
    parent(G) = C;
    parent(F) = C;
    parent(E) = B;
    parent(D) = B;
    parent(C) = A;
    parent(B) = A;

    a = A; /*pindahkan pohon*/

    J = Tree3(NIL, 'J', false, NIL, NIL);
    I = Tree3(NIL, 'I', false, NIL, NIL);
    H = Tree3(NIL, 'J', false, NIL, NIL);
    G = Tree3(NIL, 'G', false, NIL, NIL);
    F = Tree3(NIL, 'J', false, J, NIL);
    E = Tree3(NIL, 'E', false, I, NIL);
    D = Tree3(NIL, 'D', false, NIL, H);
    C = Tree3(NIL, 'C', false, F, G);
    B = Tree3(NIL, 'B', false, D, E);
    A = Tree3(NIL, 'A', false, B, C);

    parent(J) = F;
    parent(I) = E;
    parent(H) = D;
    parent(G) = C;
    parent(F) = C;
    parent(E) = B;
    parent(D) = B;
    parent(C) = A;
    parent(B) = A;

    b = A; /*pindahkan*/

    I = Tree3(NIL, 'I', false, NIL, NIL);
    H = Tree3(NIL, 'J', false, NIL, NIL);
    G = Tree3(NIL, 'G', false, NIL, NIL);
    F = Tree3(NIL, 'J', false, I, NIL);
    E = Tree3(NIL, 'E', false, NIL, H);
    D = Tree3(NIL, 'D', false, NIL, G);
    C = Tree3(NIL, 'C', false, F, NIL);
    B = Tree3(NIL, 'B', false, D, E);
    A = Tree3(NIL, 'A', false, B, C);

    parent(I) = F;
    parent(H) = E;
    parent(G) = D;
    parent(F) = C;
    parent(E) = B;
    parent(D) = B;
    parent(C) = A;
    parent(B) = A;

    c = A; /*pindahkan*/

    printf("***** ***** SELAMAT DATANG DI DRIVER POHON3 ~Natasya ***** *****");

    // printDFS
    printf("\n\n***** ***** ***** printDFS ***** ***** *****");
    printf("\nPohon A: "); printDFS(a);
    printf("\nPohon B: "); printDFS(b);
    printf("\nPohon C: "); printDFS(c);

    printf("\n\n***** ***** ***** printPathX ***** ***** *****");
    printf("\nprintPathX Pohon B dengan X adalah 'J':\n"); printPathX(b,'J'); resetVisited(&b);

    printf("\n***** ***** ***** printPathDaunX ***** ***** *****");
    printf("\nprintPathDaunX Pohon B dengan X adalah 'J':\n"); printPathDaunX(b,'J'); resetVisited(&b);

    printf("\n***** ***** ***** printAllPaths ***** ***** *****");
    printf("\nprintAllPaths Pohon B:\n"); printAllPaths(a); resetVisited(&a);

    printf("\n***** ***** ***** NbElmTree ***** ***** *****");
    printf("\nNbElmTree Pohon A = %d", NbElmTree(a)); 
    printf("\nNbElmTree Pohon B = %d", NbElmTree(b)); 
    printf("\nNbElmTree Pohon C = %d", NbElmTree(c)); 

    printf("\n\n***** ***** ***** NbDaun ***** ***** *****");
    printf("\nNbDaun Pohon A = %d", NbDaun(a)); 
    printf("\nNbDaun Pohon B = %d", NbDaun(b)); 
    printf("\nNbdaun Pohon C = %d", NbDaun(c)); 

    printf("\n\n***** ***** ***** Tinggi ***** ***** *****");
    printf("\nTinggi Pohon A = %d", Tinggi(a)); 
    printf("\nTinggi Pohon B = %d", Tinggi(b)); 
    printf("\nTinggi Pohon B = %d", Tinggi(c)); 

    printf("\n\n***** ***** ***** Level ***** ***** *****");
    printf("\nLevel Pohon A = %d", Level(a)); 
    printf("\nLevel Pohon B = %d", Level(b)); 
    printf("\nLevel Pohon C = %d", Level(c)); 

    printf("\n\n***** ***** ***** CountLevelT ***** ***** *****");
    printf("\nCountLevelT Pohon A pada level 3 = %d", CountLevelT(a,3)); 
    printf("\nCountLevelT Pohon B pada level 2 = %d", CountLevelT(b,2)); 
    printf("\nCountLevelT Pohon C pada level 4 = %d", CountLevelT(c,4)); 

    printf("\n\n***** ***** ***** PrintLevel ***** ***** *****");
    printf("\nPrintLevel Pohon A pada level 3: "); PrintLevel(a,3);
    printf("\nPrintLevel Pohon B pada level 2: "); PrintLevel(b,2);
    printf("\nPrintLevel Pohon C pada level 4: "); PrintLevel(c,4);
    
    printf("\n\n***** ***** ***** PrintBFS ***** ***** *****");
    printf("\nPrintBFS Pohon A: "); PrintBFS(a);
    printf("\nPrintBFS Pohon B: "); PrintBFS(b);
    printf("\nPrintBFS Pohon C: "); PrintBFS(c);

    printf("\n\n***** ***** ***** Fconcat ***** ***** *****");
    printf("\nTerdapat 2 List P dan Q dengan detail:");
    P = LinearPrefix(a); printf("\nIsi list P: "); PrintList(P); printf("\nAddress: "); PrintAddressList(P);
    Q = LinearPosfix(b); printf("\nIsi list Q: "); PrintList(Q); printf("\nAddress: "); PrintAddressList(Q);
    O = Fconcat(P,Q); printf("\nLalu list O hasil Fconcat P dan Q\n"); 
    PrintList(O); printf("\nAddress: "); PrintAddressList(O);
    printf("\nList aslinya menjadi: ");
    printf("\nIsi list P: "); PrintList(P); printf("\nAddress: "); PrintAddressList(P);
    printf("\nIsi list Q: "); PrintList(Q); printf("\nAddress: "); PrintAddressList(Q);

    printf("\n\n***** ***** ***** LinearPrefix ***** ***** *****");
    DeleteList(&O); DeleteList(&P); DeleteList(&Q);
    printf("\nLinearPrefix Pohon A:"); O = LinearPrefix(a); PrintList(O);
    printf("\nLinearPrefix Pohon B:"); P = LinearPrefix(b); PrintList(P);
    printf("\nLinearPrefix Pohon C:"); Q = LinearPrefix(c); PrintList(Q);

    printf("\n\n***** ***** ***** LinearPosfix ***** ***** *****");
    DeleteList(&O); DeleteList(&P); DeleteList(&Q);
    printf("\nLinearPosfix Pohon A:"); O = LinearPosfix(a); PrintList(O);
    printf("\nLinearPosfix Pohon B:"); P = LinearPosfix(b); PrintList(P);
    printf("\nLinearPosfix Pohon C:"); Q = LinearPosfix(c); PrintList(Q);

    printf("\n\n***** ***** ***** LinearInfix ***** ***** *****");
    DeleteList(&O); DeleteList(&P); DeleteList(&Q);
    printf("\nLinearInfix Pohon A:"); O = LinearInfix(a); PrintList(O);
    printf("\nLinearInfix Pohon B:"); P = LinearInfix(b); PrintList(P);
    printf("\nLinearInfix Pohon C:"); Q = LinearInfix(c); PrintList(Q);

    printf("\n\n***** ***** ***** LinearBreadthFS ***** ***** *****");
    DeleteList(&O); DeleteList(&P); DeleteList(&Q);
    printf("\nLinearBreadthFS Pohon A:"); O = LinearBreadthFS(a); PrintList(O);
    printf("\nLinearBreadthFS Pohon B:"); P = LinearBreadthFS(b); PrintList(P);
    printf("\nLinearBreadthFS Pohon C:"); Q = LinearBreadthFS(c); PrintList(Q);

    return 0;
}