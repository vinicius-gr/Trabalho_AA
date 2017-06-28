#include "ordenacoes.h"

void insertionSort(int vetor[], int tamVetor)
{
    int i, j, atual;
    for(i=1; i<tamVetor; i++)
    {
        atual = vetor[i];
        j=i-1;

        while((j>=0)&&(atual < vetor[j]))
        {
            vetor[j+1] = vetor[j];
            j=j-1;
        }
        vetor[j+1]=atual;
    }
}
