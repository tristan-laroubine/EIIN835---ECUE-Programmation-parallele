//
// Created by trist on 10/03/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

struct tablo {
    int * tab;
    int size;
};

void generateEmptyArray(struct tablo *s, int size) {
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    for(i=0; i<size; i++) {
        s->tab[i]=0;
    }
}
void generateAleaArray(struct tablo *s, int size) {
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++) {
        s->tab[i]=rand() % 1000;
    }
}
void generateCoursArray(struct tablo *s, int size) {
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    s->tab[0] = 20;
    s->tab[1] = -4;
    s->tab[2] = 82;
    s->tab[3] = 12;
}
void copieFirstArrayAtTheSecondEnd(struct tablo *first, struct tablo *second) {
    int i;
    for(i=first->size; i<=second->size; i++) {
        second->tab[i]=first->tab[i-first->size];
    }
}

void montee(struct tablo * a, int m) {
    for (int l = m-1; l >= 0; l--)
        for (int j = pow(2, l); j <= (pow(2, l+1)-1); j++)
            a->tab[j] = a->tab[2*j] + a->tab[2*j+1];
}

void descente(struct tablo * a, struct tablo * b, int m) {
    for (int l = 1; l <= m; l++) {
        for (int j = pow(2,l); j <= (pow(2,l+1)-1); j++) {
            if (j % 2 == 0)
                b->tab[j]=b->tab[j/2];
            else
                b->tab[j] = b->tab[(j-1)/2] + a->tab[j-1];
        }
    }
}
void finale(struct tablo * a, struct tablo * b, int m) {
    for (int j = pow(2,m); j <= (pow(2,m+1)-1); j++)
        b->tab[j] = b->tab[j] + a->tab[j];
}

int main(int argc, char **argv) {
    struct tablo * initiale = malloc(sizeof(struct tablo));
    struct tablo * seconde = malloc(sizeof(struct tablo));
    int size = pow(2, atoi(argv[1]));
    generateCoursArray(initiale, size);
    generateEmptyArray(seconde, (2 * size));
    copieFirstArrayAtTheSecondEnd(initiale, seconde);
    printArray(initiale);
    printArray(seconde);
}