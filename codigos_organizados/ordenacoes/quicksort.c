
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
