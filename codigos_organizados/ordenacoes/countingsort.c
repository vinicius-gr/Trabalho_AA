#include "ordenacoes.h"

void countingsort(int *vetor, int size)
{
    int max = vetor[0], i;

    for(i=1; i<size; i++)
    {
        if(vetor[i]>max)
        {
            max=vetor[i];
        }
    }

    int saida[size], *count;

    count = calloc(sizeof(int),max);

    for(i=1; i<size; i++)
        count[vetor[i]]++;

    for(i=1; i<max; i++)
        count[i]+=count[i-1];

    printf("\n\n");
    for(i=0; i<max; i++)
        printf("%d ", count[i]);
    printf("\n\n");

    for(i=size-1; i>0; i--)
    {
        saida[count[vetor[i]]] = vetor[i];
        count[vetor[i]]--;
    }

    for(i=0; i<size; i++)
        vetor[i]=saida[i];
}
