//
// Created by trist on 10/03/2021.
//
#include <stdlib.h>
void loopTablo(int *a, int size){
    for (int i = 0; i < size; ++i) {
        *(a+i)  = 1;
    }
}

int main(int argc, char* argv[]){
    int taille = atoi(argv[1]);
    int* tab = malloc(sizeof(int[taille]));
    loopTablo(tab,taille);
}