#include "tempos.h"

int i;
int array[MAX], size;
double arrayD[MAX],teste;
char nome[80];
struct timespec inicio, fim;
uint64_t tempo_de_cpu;
uint64_t soma;

void le_ordena_grava_tempo (void funcao_ordenacao(int *arr, int size), FILE *tempos, FILE *reader)
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

        for (i=0; i<NUM_EXECS; i++)
        {
            vet = preenche_vetor(nome, &size);
            CRONOMETRA1(funcao_ordenacao, vet, size);
            soma += tempo_de_cpu;
            rewind(vet);
        }

        fprintf(tempos, "%d \t %llu\n",size, (long long unsigned int) (soma / (uint64_t) NUM_EXECS));
    }
}
