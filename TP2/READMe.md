#TP 2
## Utilisation de Valgrind
### valgrinTest.c
`gcc -o valgrinTest valgrinTest.c -g`

`valgrind -v ./valgrinTest 50`
## Sections Parallèles
### quicksort.c
`gcc -o quicksort quicksort.c -g`

```
lt913980@abel:~/EIIN835---ECUE-Programmation-parallele/TP2$ time ./quicksort 5000

real    0m0,032s
user    0m0,032s
sys     0m0,000s
lt913980@abel:~/EIIN835---ECUE-Programmation-parallele/TP2$ time ./quicksort 50

real    0m0,003s
user    0m0,001s
sys     0m0,002s
lt913980@abel:~/EIIN835---ECUE-Programmation-parallele/TP2$ time ./quicksort 5000

real    0m0,035s
user    0m0,035s
sys     0m0,000s
lt913980@abel:~/EIIN835---ECUE-Programmation-parallele/TP2$ time ./quicksort 10000

real    0m0,093s
user    0m0,092s
sys     0m0,001s

lt913980@abel:~/EIIN835---ECUE-Programmation-parallele/TP2$ time ./quicksort 100000

real    0m7,509s
user    0m7,494s
sys     0m0,012s
```

### avec Random
`gcc -o quicksortR quicksortRandom.c`

![GitHub Logo](../img/TD%202.1.PNG)

### with Open MP
`gcc -o quicksortOpenMp quickSortOpenMp.c`

