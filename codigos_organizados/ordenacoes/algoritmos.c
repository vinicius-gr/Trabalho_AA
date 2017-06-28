#include "ordenacoes.h"


void le_ordena_grava_tempo (void funcao_ordenacao(int *arr, int tam), FILE *tempos, FILE *reader)
{
    int size, *vet, i;

    char nome[80];

    clock_t tempo;
    double time_taken;

    while(!feof(reader))
    {
        fscanf(reader, "%s\n", &nome);
        size = 0;
        time_taken = 0.0;

        for (i=0; i<MEDIA; i++)
        {
            vet = preenche_vetor(nome, &size);
            tempo = clock();
            funcao_ordenacao(vet, size);
            tempo = clock() - tempo;

            time_taken += ((double)tempo)/CLOCKS_PER_SEC;
        }


        fprintf(tempos, "%d\t%f\n", size, (time_taken/MEDIA));
    }
}
