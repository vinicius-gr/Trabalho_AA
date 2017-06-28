#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define NOMES "arranjos\\nomes.txt"
#define MEDIA 5


int *preenche_vetor (char *nome, int *size);
void printar_array (int tam, int *vet);


void heapsort(int arr[], int size);


void radixSort(int vetor[], int tamVetor);


void quicksort(int arr[], int len);


void insertionSort(int vetor[], int tamVetor);

void le_ordena_grava (void funcao_ordenacao(int *arr, int tam), FILE *tempos, FILE *reader);

void countingsort(int *vetor, int size);
