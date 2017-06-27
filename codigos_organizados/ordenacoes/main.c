#include "ordenacoes.h"
#define nomes "nomes.txt"
#define media 3


int main()
{
    int i;
    int *vet, size;
    char nome[80];
    FILE *reader = fopen(nomes, "r");
    FILE *tempos;
    clock_t tempo;
    double time_taken;

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

            while(!feof(reader))
            {
                fscanf(reader, "%s\n", &nome);
                size = 0;
                time_taken = 0.0;

                for (i=0; i<media; i++)
                {
                    vet = preenche_vetor(nome, &size);
                    tempo = clock();
                    heapsort(vet, size);
                    tempo = clock() - tempo;

                    time_taken += ((double)tempo)/CLOCKS_PER_SEC;
                }


                fprintf(tempos, "%s: %f\n", nome, (time_taken/media));
            }
            break;

        case 2:
            tempos = fopen("tempos\\mergesort.txt", "w");
            break;

        case 3:
            tempos = fopen("tempos\\quicksort.txt", "w");

            while(!feof(reader))
            {
                fscanf(reader, "%s\n", &nome);
                size = 0;
                time_taken = 0.0;

                for (i=0; i<media; i++)
                {
                    vet = preenche_vetor(nome, &size);
                    tempo = clock();
                    quicksort(vet, size);
                    tempo = clock() - tempo;

                    time_taken += ((double)tempo)/CLOCKS_PER_SEC;
                }


                fprintf(tempos, "%s: %f\n", nome, (time_taken/media));
            }

            break;

        case 4:
            tempos = fopen("tempos\\bucketsort.txt", "w");
            break;

        case 5:
            tempos = fopen("tempos\\radixsort.txt", "w");

            while(!feof(reader))
            {
                fscanf(reader, "%s\n", &nome);
                size = 0;
                time_taken = 0.0;

                for (i=0; i<media; i++)
                {
                    vet = preenche_vetor(nome, &size);
                    tempo = clock();
                    radixSort(vet, size);
                    tempo = clock() - tempo;

                    time_taken += ((double)tempo)/CLOCKS_PER_SEC;
                }


                fprintf(tempos, "%s: %f\n", nome, (time_taken/media));
            }

            break;

        case 6:
            tempos = fopen("tempos\\insertionsort.txt", "w");

            while(!feof(reader))
            {
                fscanf(reader, "%s\n", &nome);
                size = 0;
                time_taken = 0.0;

                for (i=0; i<media; i++)
                {
                    vet = preenche_vetor(nome, &size);
                    tempo = clock();
                    insertionSort(vet, size);
                    tempo = clock() - tempo;

                    time_taken += ((double)tempo)/CLOCKS_PER_SEC;
                }

                fprintf(tempos, "%s: %f\n", nome, (time_taken/media));
            }

            break;
        }
    }
    while (op != 0);

    fclose(reader);
    fclose(tempos);

    return 0;
}
