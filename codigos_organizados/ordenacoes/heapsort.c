#include <stdio.h>
#include "ordenacoes.h"

void swap (int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int total;

void heapify(int *arr, int i)
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

void heapsort(int *arr, int size)
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
