#include <stdio.h>

int Tes(int T[]){
    for(int i = 0; i < 10; i++){
        return T[i];
    }
}

int main(){
    int T[] = {9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 0};
    Tes(T);
}