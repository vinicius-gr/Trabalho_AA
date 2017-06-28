#include "ordenacoes.h"

int main()
{
    FILE *reader = fopen(NOMES, "r");
    FILE *tempos;

    int op;

    do
    {
        printf("1 - heap-sort\n");
        printf("2 - merge-sort\n");
        printf("3 - quick-sort\n");
        printf("4 - bucket-sort\n");
        printf("5 - radix-sort\n");
        printf("6 - insertion-sort\n");
        printf("7 - counting-sort\n");
        printf("0 - sair\n\n");

        fflush(stdin);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            tempos = fopen("tempos\\heapsort.txt", "w");
            le_ordena_grava_tempo(heapsort,tempos,reader);
            break;

        case 2:
            tempos = fopen("tempos\\mergesort.txt", "w");
            break;

        case 3:
            tempos = fopen("tempos\\quicksort.txt", "w");
            le_ordena_grava_tempo(quicksort, tempos,reader);
            break;

        case 4:
            tempos = fopen("tempos\\bucketsort.txt", "w");
            break;

        case 5:
            tempos = fopen("tempos\\radixsort.txt", "w");
            le_ordena_grava_tempo(radixSort, tempos, reader);
            break;

        case 6:
            tempos = fopen("tempos\\insertionsort.txt", "w");
            le_ordena_grava_tempo(insertionSort, tempos,reader);
            break;

        case 7:
            tempos = fopen("tempos\\coutingsort.txt", "w");
            break;
        }
    }
    while (op != 0);

    fclose(reader);
    fclose(tempos);

    return 0;
}
