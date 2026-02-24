#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 

void FIFO(const int sequencia_paginas[], const int sequencia_enderecos[], const int tam_sequencia, const int num_quadros, FILE *FileError) {
    fprintf(FileError, "FIFO:\n");

    int contErros = 0, quadro_atual = 0;

    int *quadros = malloc(num_quadros * sizeof(int));
    for (int i = 0; i < num_quadros; i++) 
        quadros[i] = -1; // -1 = quadro vazio
    
    for (int acesso = 0; acesso < tam_sequencia; acesso++)
    {
        quadro_atual = 0;
        while (quadro_atual < num_quadros)
        {
            if (quadros[quadro_atual] == sequencia_paginas[acesso]) // pagina esta na memoria, nao faz nada
                break; 
            else 
            if (quadros[quadro_atual] == -1)  // quadro vazio, insere a pagina
            {
                fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
                quadros[quadro_atual] = sequencia_paginas[acesso];
                contErros++;
                break;
            }
            quadro_atual++;
        }
        if (quadro_atual == num_quadros) // quadros cheios, substituir pagina mais antiga
        {
            quadro_atual = 0;
            while (quadro_atual < num_quadros - 1)
            {
                quadros[quadro_atual] = quadros[quadro_atual + 1];
                quadro_atual++;
            }
            quadros[num_quadros - 1] = sequencia_paginas[acesso];
            fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
            contErros++;
        }
    }
    free(quadros);
    printf("FIFO: %d erros (%.2f%%)\n", contErros, (float)contErros / tam_sequencia * 100.0);
}

void OPT(const int sequencia_paginas[], const int sequencia_enderecos[], const int tam_sequencia, const int num_quadros, FILE *FileError) {
    fprintf(FileError, "\nOPT:\n");

    int aux_acesso;
    int contErros = 0, quadro_atual = 0;
    int *prox_uso = malloc(num_quadros * sizeof(int));

    int *quadros = malloc(num_quadros * sizeof(int));
    for (int i = 0; i < num_quadros; i++) 
        quadros[i] = -1; // -1 = quadro vazio
    
    for (int acesso = 0; acesso < tam_sequencia; acesso++)
    {
        quadro_atual = 0;
        while (quadro_atual < num_quadros)
        {
            if (quadros[quadro_atual] == sequencia_paginas[acesso]) // pagina esta na memoria, nao faz nada
                break; 
            else 
            if (quadros[quadro_atual] == -1)  // quadro vazio, insere a pagina
            {
                fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
                quadros[quadro_atual] = sequencia_paginas[acesso];
                contErros++;
                break;
            }
            quadro_atual++;
        }
        if (quadro_atual == num_quadros) // quadros cheios, substituir pagina que sera usada mais tarde
        {   
            
            for (int i = 0; i < num_quadros; i++) 
                prox_uso[i] = INT_MAX; // -2 = proximo uso nao calculado

            quadro_atual = 0;
            while (quadro_atual < num_quadros) 
            {   
                aux_acesso = acesso + 1;
                while (aux_acesso < tam_sequencia)
                {
                    if (quadros[quadro_atual] == sequencia_paginas[aux_acesso])
                    {
                        prox_uso[quadro_atual] = aux_acesso;
                        break;
                    }
                    
                    aux_acesso++;
                }
                if (prox_uso[quadro_atual] == INT_MAX) // caso uma pagina nao seja maias acessada, nao precisa continuar procurando qual substituir
                    break;
                
                quadro_atual++;
            }
           
            int quadro_com_maior_acesso = 0;

            quadro_atual = 1;
            while (quadro_atual < num_quadros)
            {
                if(prox_uso[quadro_atual] > prox_uso[quadro_com_maior_acesso])
                    quadro_com_maior_acesso = quadro_atual;
                quadro_atual++;
            }
            quadros[quadro_com_maior_acesso] = sequencia_paginas[acesso];
            
                  
            fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
            contErros++;
        }
    }
    free(prox_uso);
    free(quadros);
    printf("OPT: %d erros (%.2f%%)\n", contErros, (float)contErros / tam_sequencia * 100.0);
}

void LRU(const int sequencia_paginas[], const int sequencia_enderecos[], const int tam_sequencia, const int num_quadros, FILE *FileError) {
    fprintf(FileError, "\nLRU:\n");

        int contErros = 0, quadro_atual = 0;

    int *quadros = malloc((num_quadros) * sizeof(int));
    for (int i = 0; i < num_quadros; i++) 
        quadros[i] = -1; // -1 = quadro vazio
    
    for (int acesso = 0; acesso < tam_sequencia; acesso++)
    {
        quadro_atual = 0;
        while (quadro_atual < num_quadros)
        {
            if (quadros[quadro_atual] == sequencia_paginas[acesso]) // pagina esta na memoria, altera a ordem do ultimo acessado
            {
                while (quadro_atual != 0)
                {
                    quadros[quadro_atual] = quadros[quadro_atual-1];
                    quadro_atual--;
                }
                quadros[quadro_atual] = sequencia_paginas[acesso];
                break; 
            } 
            else 
            if (quadros[quadro_atual] == -1)  // quadro vazio, insere a pagina
            {
                while (quadro_atual != 0){
                    quadros[quadro_atual] = quadros[quadro_atual-1];
                    quadro_atual--;
                }
                
                quadros[quadro_atual] = sequencia_paginas[acesso];
                contErros++;
                
                fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
                break;
            }
            quadro_atual++;
        }
        if (quadro_atual == num_quadros) // quadros cheios, substituir pagina mais antiga
        {
            quadros[num_quadros - 1] = sequencia_paginas[acesso];
            fprintf(FileError, "Erro de pagina no endereco %d, pagina %d\n", sequencia_enderecos[acesso], sequencia_paginas[acesso]);
            contErros++;
        }
    }
    free(quadros);
    printf("LRU: %d erros (%.2f%%)\n", contErros, (float)contErros / tam_sequencia * 100.0);
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("\nUso: %s <tam_pagina_bytes> <tam_memoria_bytes> <arquivo_sequencia>\n\n", argv[0]);
        return 1;
    }

    int tam_pagina = atoi(argv[1]);
    int tam_memoria = atoi(argv[2]);
    char *filename = argv[3];

    if (tam_pagina <= 0 || tam_memoria <= 0) {
        printf("\nErro: Tamanho da pagina e da memoria devem ser maiores que 0\n\n");
        return 1;
    }

    int num_quadros = tam_memoria / tam_pagina;
    if (num_quadros == 0) {
        printf("\nErro: Memoria insuficiente para criar um quadro de pagina\n\n");
        return 1;
    }

    FILE *file_in = fopen(filename, "r");
    if (!file_in) {
        perror("\nErro ao abrir o arquivo");
        return 1;
    }

    int *sequencia_enderecos = NULL;
    int tam_sequencia = 0;
    int capacidade = 128; // capacidade inicial
    sequencia_enderecos = malloc(capacidade * sizeof(int));

    int addr;
    while (fscanf(file_in, "%d", &addr) == 1) {
        if (tam_sequencia >= capacidade) {
            capacidade += 128;
            int *temp = realloc(sequencia_enderecos, capacidade * sizeof(int));
            if (!temp) {
                perror("Erro de realocacao de memoria");
                free(sequencia_enderecos);
                fclose(file_in);
                return 1;
            }
            sequencia_enderecos = temp;
        }
        sequencia_enderecos[tam_sequencia] = addr;
        tam_sequencia++;
    }
    fclose(file_in);

    if (tam_sequencia == 0) {
        printf("Arquivo de sequencia vazio.\n");
        free(sequencia_enderecos);
        return 0;
    }

    int *sequencia_paginas = malloc(tam_sequencia * sizeof(int));
    if (!sequencia_paginas) {
        perror("Erro de alocação de memória.\n");
        free(sequencia_enderecos);
        return 1;
    }
    for (int i = 0; i < tam_sequencia; i++)
        sequencia_paginas[i] = sequencia_enderecos[i] / tam_pagina;
    

    FILE *FileError = fopen("erros.out", "w");
    if (!FileError) {
        perror("Erro ao criar arquivo erros.out");
        free(sequencia_enderecos);
        free(sequencia_paginas);
        return 1;
    }

    printf("\nSimulando com %d quadros de página ( Página: %d, Memória: %d )\n", num_quadros, tam_pagina, tam_memoria);
    printf("Total de enderecos: %d\n\n", tam_sequencia);

    FIFO(sequencia_paginas, sequencia_enderecos, tam_sequencia, num_quadros, FileError);
    OPT(sequencia_paginas, sequencia_enderecos, tam_sequencia, num_quadros, FileError);
    LRU(sequencia_paginas, sequencia_enderecos, tam_sequencia, num_quadros, FileError );

    printf("\n");

    fclose(FileError);
    free(sequencia_enderecos);
    free(sequencia_paginas);

    return 0;
}