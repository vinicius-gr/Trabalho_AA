#include <stdio.h>

int getMax(int vetor[], int tamVetor)
{
    int max = vetor[0], i;
    for(i=1; i<tamVetor; i++)
    {
        if(vetor[i]>max)
        {
            max=vetor[i];
        }
    }
    return max;
}

void countSort(int vetor[], int tamVetor, int exp)
{
    int saida[tamVetor]; //vetor de saída
    int i, count[10] = {0};

    for(i=0; i<tamVetor; i++)
        count[(vetor[i]/exp)%10]++;

    for(i=1; i<10; i++)
        count[i]+=count[i-1];

    for(i=tamVetor-1; i>=0; i--)
    {
        saida[count[(vetor[i]/exp)%10]-1]=vetor[i];
        count[(vetor[i]/exp)%10]--;
    }

    for(i=0; i<tamVetor; i++)
        vetor[i]=saida[i];
}

void radixSort(int vetor[], int tamVetor)
{
    int m = getMax(vetor, tamVetor), exp;
    for(exp=1; m/exp>0; exp*=10)
        countSort(vetor, tamVetor, exp);
}
