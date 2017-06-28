#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <float.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>
#define NOME 40
#define MAX 8192
#define BILHAO 1000000000L

#define CRONOMETRA(funcao,vetor,n, n2) {                      \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(vetor,n, n2);                                       \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }
#define CRONOMETRA1(funcao,vetor,n) {                         \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(vetor,n);                                           \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }

#define NUM_EXECS 5
typedef struct{
    int vetor[MAX];
    int topo;
}vet;

#include "algoritmos.h"
#include "leitura.h"

void le_ordena_grava_tempo (void funcao_ordenacao(int *arr, int tam), FILE *tempos, FILE *reader);
