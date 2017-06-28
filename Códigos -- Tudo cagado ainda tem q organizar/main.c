#include "merge.h"
#define nomes "nomes.txt"


int main()
{
    int i;
    int array[MAX], size;
    double arrayD[MAX],teste;
    char nome[80];
    FILE *reader = fopen(nomes, "r");
    FILE *tempos;
    FILE *vetor;
//    struct timespec inicio, fim;
    uint64_t tempo_de_cpu;
    uint64_t soma;
    char nome2[100]="double/";

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

            tempos = fopen("tempos/heapsort.txt", "w");
            fscanf(tempos,"Tamanho\tt(ns)");
            while(!feof(reader))
            {
                fscanf(reader, "%s\n", &nome);
                size = 0;
                soma=0;
                vetor = fopen(nome, "r");
                for (i=0; i<NUM_EXECS; i++)
                {
                    while(!feof(vetor))
                    {
                        fscanf(vetor,"%d", &array[size]);
                        size++;
                    }
                    CRONOMETRA1(heapsort, array, size);
                    soma += tempo_de_cpu;
                    rewind(vetor);
                    if(i==0)
                        fprintf(tempos, "%d\t", size);
                    size=0;
                }
                //printa no arquivo de tempo
                fprintf(tempos, "%llu\n",
                        (long long unsigned int) (soma / (uint64_t) NUM_EXECS));
                fclose(vetor);
                close(tempos);

            }
            rewind(reader);
            break;
        }
    }
    while (op != 0);

    fclose(reader);
    fclose(tempos);

    return 0;
}
