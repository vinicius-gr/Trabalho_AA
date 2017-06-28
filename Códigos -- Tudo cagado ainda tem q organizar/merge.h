#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h> /* pela definição de uint64_t */
#include <time.h>
#include <float.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>
#define NOME 40
#define MAX 8192
#define BILHAO 1000000000L

#define CRONOMETRA(funcao,vetor,n, n2) {                          \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
   funcao(vetor,n, n2);                                           \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
   tempo_de_cpu = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
                  fim.tv_nsec - inicio.tv_nsec;               \
   }
#define CRONOMETRA1(funcao,vetor,n) {      }                    \
//   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);          \
//   funcao(vetor,n);                                           \
//   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);             \
//   tempo_de_cpu = BILHAO * (fim.tv_sec - inicio.tv_sec) +     \
//                  fim.tv_nsec - inicio.tv_nsec;               \
//   }

#define NUM_EXECS 5
typedef struct{
    int vetor[MAX];
    int topo;
}vet;
void mergeSort(int arr[], int p, int r);
void Merge(int arr[], int p, int q, int r);
void heapsort(int arr[], int size);
void quicksort(int arr[], int len);
void radixSort(int vetor[], int tamVetor);
int insertionSort(int vetor[], int tamVetor);

int *preenche_vetor (char *nome, int *size);
void printar_array (int tam, int *vet);
typedef struct{
    double buque[MAX/2];
    int topo;
    int flag;
}bucket;

void bucketSort(double vetor[], int tam);
int Counting_sort(int vetor[], int TAMANHO);
