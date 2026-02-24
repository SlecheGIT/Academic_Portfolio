#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *vetor;

void leitura_arquivo(const char *arquivo_entrada, int *tam);
void *soma_subvetor(void *info);

int main(int argc, char *argv[]) {

    
    if (argc != 3) {
        perror( "entrada: <arquivo> <numero de processos>");
        return -1;
    }

    int processos = atoi(argv[2]);
    if (processos <= 0) {
        perror("O número de processos deve ser > 0.");
        return -1;
    }

    int total = 0;
    int threads;
    int tam;
    
    threads = atoi(argv[2]);
    leitura_arquivo(argv[1], &tam);

    int subvetor = tam/threads;
    int restante = tam%threads;

    pthread_t threads_id[threads];
    for (int i = 0; i < threads; i++)
    {
        // um vetor de inteiros para passar os parametros que a thread vai precisar
        int *info = malloc(4 * sizeof(int));

        // o primeiro elemento eh o inicio do subvetor
        info[0] = i * subvetor; 

        // o segundo elemento eh o fim do subvetor
        info[1] = (i+1) * subvetor;
        if (i == (threads - 1)) // o ultimo calcula o restante
            info[1] += restante;
            
        //o terceiro elemento eh em qual thread estamos
        info[2] = i;
        
        pthread_create(&threads_id[i], NULL, soma_subvetor, (void *)info);
    }

    for (int i = 0; i < threads; i++)
    {
        int *resultado;
        pthread_join(threads_id[i], (void **)&resultado);
        total += *resultado;
        free(resultado);
    }
    printf("\n| Soma total: %i |\n\n", total);

    free(vetor);
    return 0;
}

void leitura_arquivo(const char *arquivo_entrada, int *tam){

    FILE *arquivo = fopen(arquivo_entrada, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(-1);
    }

    fseek(arquivo, 0, SEEK_END);
    *tam = ftell(arquivo) / sizeof(int);
    fseek(arquivo, 0, SEEK_SET);

    vetor = malloc(*tam * sizeof(int)+1);
    fread(vetor, sizeof(int), *tam, arquivo);

    fclose(arquivo);
}

void *soma_subvetor(void *info) {

    int *dados = (int *)info;
    int *soma = malloc(sizeof(long int));
    *soma = 0;

    for (int i = dados[0]; i < dados[1]; i++) {
        *soma += vetor[i];
    }
    free(info); 
    return (void *)soma;
}