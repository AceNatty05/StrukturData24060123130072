#ifndef mahasiswa_H
#define mahasiswa_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char  nama[20]; // 19 digit
    char  nim[4]; // 3 digit
    float ipk;
    char  prodi[10]; // 9 digit
} Mhs;

typedef struct {
    Mhs wadah[101];
    int size;
} TabMhs;

// KONSTRUKTOR

Mhs MakeMhs(char nAMA[], char nIM[], float iPK, char pRODI[]);

// SELEKTOR

char* getNama(Mhs M);

char* getNim(Mhs M);

float getIpk(Mhs M);

char* getProdi(Mhs M);

#endif 