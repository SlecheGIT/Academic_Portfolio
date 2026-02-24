#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h> 

void leitura_arquivo(const char *arquivo_entrada, int **vet, int *tam){

    FILE *arquivo = fopen(arquivo_entrada, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    
    fseek(arquivo, 0, SEEK_END);
    *tam = ftell(arquivo) / sizeof(int);
    fseek(arquivo, 0, SEEK_SET);

    *vet = malloc(*tam * sizeof(int)+1);
    fread(*vet, sizeof(int), *tam, arquivo);

    fclose(arquivo);
}

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
    int tam;
    int *vetor;

    leitura_arquivo(argv[1], &vetor, &tam); 

    int subvetor = tam/processos;
    int restante = tam%processos;

    // criando memoria compartilhada
    int shm_id = shmget(IPC_PRIVATE, processos * sizeof(int), IPC_CREAT | 0666);
    int *memoria_compartilhada = (int *)shmat(shm_id, NULL, 0); // abexando memoria compartilhada
    if (memoria_compartilhada == (int *)-1) {
        perror("Erro ao criar memoria compartilhada");
        return -1;
    }
    
    for (int i = 0; i < processos; i++)
    {
        if (fork() == 0)
        {
            int sub_total = 0;
            int inicio = i * subvetor; 
            int fim = (i+1) * subvetor;
            if (i == (processos - 1))
                fim += restante;

            while (inicio < fim)
            {
                sub_total += vetor[inicio];
                inicio++;
            }
            memoria_compartilhada[i] = sub_total;

            shmdt(memoria_compartilhada);
            exit(0);
        }
        
    }

    // Processo inicial soma os resultados dos filhos
    for (int i = 0; i < processos; i++) {
        wait(NULL);
        total += memoria_compartilhada[i];
    }

    printf("\n| Soma total: %i |\n\n", total);

    // Liberar memória compartilhada
    shmdt(memoria_compartilhada);
    shmctl(shm_id, IPC_RMID, NULL);

    free(vetor);
    return 0;
}