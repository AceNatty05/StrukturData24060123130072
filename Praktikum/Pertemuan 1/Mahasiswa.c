#include "Mahasiswa.h"

// KONSTRUKTOR

Mhs MakeMhs(char nAMA[], char nIM[], float iPK, char pRODI[]){
    Mhs M;
    strcpy(M.nama,nAMA);
    strcpy(M.nim,nIM);
    M.ipk = iPK;
    strcpy(M.prodi,pRODI);
    return M;
}

// SELEKTOR

char* getNama(Mhs M){
    return M.nama;
}

char* getNim(Mhs M){
    return M.nim;
}

float getIpk(Mhs M){
    return M.ipk;
}

char* getProdi(Mhs M){
    return M.prodi;
}