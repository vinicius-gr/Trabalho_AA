#include "merge.h"

void mergeSort(int arr[], int p, int r)
{
    if(p<r-1)
    {
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q, r);
        Merge(arr, p, q, r);
    }
}
void Merge(int arr[], int p, int q, int r)
{
    int i, j, k, *w;
    w = (int *) malloc((r-p)*sizeof(int));
    i=p;
    j=q;
    k=0;

    while(i<q && j<r)
    {
        if(arr[i]<=arr[j])
            w[k++]=arr[i++];
        else
            w[k++] = arr[j++];
    }
    while(i<q)
        w[k++]=arr[i++];
    while(j<r)
        w[k++]=arr[j++];
    for(i=p; i<r; ++i)
        arr[i]=w[i-p];
    free(w);

}
#include <stdio.h>

void swap (int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int total;

void heapify(int arr[], int i)
{
    int lft = i * 2;
    int rgt = lft + 1;
    int grt = i;

    if (lft <= total && arr[lft] > arr[grt]) grt = lft;
    if (rgt <= total && arr[rgt] > arr[grt]) grt = rgt;
    if (grt != i)
    {
        swap(arr, i, grt);
        heapify(arr, grt);
    }
}

void heapsort(int arr[], int size)
{
    total = size - 1;
    int i;

    for (i = total / 2; i >= 0; i--)
        heapify(arr, i);

    for (i = total; i > 0; i--)
    {
        swap(arr, 0, i);
        total--;
        heapify(arr, 0);
    }
}
int insertionSort(int vetor[], int tamVetor)
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
//    return (int *)vetor;
    return 0;
}

void quicksort0(int arr[], int a, int b)
{
    if (a >= b)
        return;

    int key = arr[a];
    int i = a + 1, j = b;
    while (i < j)
    {
        while (i < j && arr[j] >= key)
            --j;
        while (i < j && arr[i] <= key)
            ++i;
        if (i < j)
            swap(arr, i, j);
    }
    if (arr[a] > arr[i])
    {
        swap(arr, a, i);
        quicksort0(arr, a, i - 1);
        quicksort0(arr, i + 1, b);
    }
    else     // there is no left-hand-side
    {
        quicksort0(arr, a + 1, b);
    }
}

void quicksort(int arr[], int len)
{
    quicksort0(arr, 0, len - 1);
}
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
void bucketSort(double vetor[], int tam)
{
    bucket *b = (bucket *) malloc(tam*sizeof(bucket));
    int i, index,j;
    for(i=0; i<tam; i++){
        b[i].topo = 0;
        b[i].flag = 0;
    }

    for(i=0; i<tam; i++)
    {
        index = floor(tam*vetor[i]);
        b[index].buque[b[index].topo] = vetor[i];
        b[index].topo++;
    }


    for(i=0; i<tam; i++){
        index = floor(tam*vetor[i]);
        if(b[index].flag == 0){
            insertionSortD(b[index].buque, b[index].topo);
            b[index].flag=1;
        }

    }
    int g=0;
    for(i=0; i<tam; i++){
        if(b[i].topo!=0){
            for(j=0;j<b[i].topo; j++)
                vetor[g++] = b[i].buque[j];
        }
    }
    free(b);
}
void insertionSortD(double arr[], int n)
{
    int i, j;
    double key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int Counting_sort(int vetor[], int TAMANHO)
{
    int i, maior=0;
    for(i=0;i<TAMANHO;i++){
        if(vetor[i]>maior)
            maior=vetor[i];
    }
    int B[TAMANHO], C[maior+1];
    for(i = 0; i < maior+1; i++)
            C[i] = 0;
    for(i =0; i < TAMANHO; i++)
           C[vetor[i]] = C[vetor[i]] + 1;
    for(i = 1; i < maior+1; i++)
            C[i] = C[i] + C[i-1];
    for(i = TAMANHO-1; i >= 0; i--)
    {
          B[C[vetor[i]]-1] = vetor[i];
          C[vetor[i]] = C[vetor[i]] - 1;
    }
}
