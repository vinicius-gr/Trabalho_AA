void swap (int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

/////////////////
//  COUTING   //
///////////////


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



//////////////
//  HEAP   //
////////////

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

///////////////////
//  INSERTION   //
/////////////////


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

///////////////
//  QUICK   //
/////////////

void partition(int arr[], int a, int b)
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
        partition(arr, a, i - 1);
        partition(arr, i + 1, b);
    }
    else     // there is no left-hand-side
    {
        partition(arr, a + 1, b);
    }
}

void quicksort(int arr[], int len)
{
    partition(arr, 0, len - 1);
}


///////////////
//  RADIX   //
/////////////
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

void coutingsort_radix(int vetor[], int tamVetor, int exp)
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
        coutingsort_radix(vetor, tamVetor, exp);
}



