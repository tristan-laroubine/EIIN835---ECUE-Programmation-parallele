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
void quicksort(struct tablo * ta, int index_min, int index_max) {
    int i,j;
    int v, t;
    if (index_max-index_min<2) return;
    //partition
    v = ta->tab[index_min];
    i=index_min;
    j=index_max;
    for(;;) {
        while (++i < index_max && ta->tab[i] < v);
        while (--j >= index_min && ta->tab[j] > v);
        if (i>=j) break;
        t = ta->tab[i]; ta->tab[i] = ta->tab[j]; ta->tab[j]=t;
    }
    t=ta->tab[i-1];
    ta->tab[i-1]=ta->tab[index_min];
    ta->tab[index_min]=t;
#ifdef _OPENMP
    if(index_max == ta->size) {
            printf("nthreads %d\n", omp_get_num_threads());
        }
        omp_set_max_active_levels(10000);
#endif
#pragma omp parallel sections
    {
#pragma omp section
        {
            quicksort(ta, index_min, i);
        }
#pragma omp section
        {
            quicksort(ta, i, index_max );
        }
    }

}
void printArray(struct tablo * tmp) {
    printf("---- Array of size %i ---- \n", tmp->size);
    int size = tmp->size;
    int i;
    for (i = 0; i < size; ++i) {
        printf("%i ", tmp->tab[i]);
    }
    printf("\n");
}
struct tablo * allocateTablo(int size) {
    struct tablo * tmp = malloc(sizeof(struct tablo));
    tmp->size = size;
    tmp->tab = malloc(size*sizeof(int));
    return tmp;
}
void generateArray(struct tablo * s) {
    s->size=8;
    s->tab=malloc(s->size*sizeof(int));
    s->tab[0]=3;
    s->tab[1]=1;
    s->tab[2]=7;
    s->tab[3]=0;
    s->tab[4]=4;
    s->tab[5]=1;
    s->tab[6]=6;
    s->tab[7]=3;
}
void generateSortedArray(struct tablo *s, int size) {
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    for(i=0; i<size; i++) {
        s->tab[i]=i;
    }
}
void generateReverseSortedArray(struct tablo *s, int size) {
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    for(i=0; i<size; i++) {
        s->tab[i]=size-i;
    }
}
void generateReverseSortedArrayRand(struct tablo *s, int size) {
    srand(time(NULL));
    s->size=size;
    s->tab=malloc(size*sizeof(int));
    int i;
    for(i=0; i<size; i++) {
        s->tab[i]=rand() % 1000;
    }
}
int main(int argc, char **argv) {
    struct tablo * tmp = malloc(sizeof(struct tablo));
    generateReverseSortedArray(tmp, atoi(argv[1]));
    // printArray(tmp);
    quicksort(tmp,0, tmp->size);
}