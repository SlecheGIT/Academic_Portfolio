#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool seq = false;
short int cont_process = 0;

typedef struct process {
    int time;
    struct process *next;
}process;

typedef struct escalonador {
    int priority;
    int arrival_time;
    struct process *cpu_bursts; // Lista encadeada de CPU bursts
    
    // int tempo_execucao;
    // int tempo_restante;
    // int tempo_espera;
    // int tempo_resposta;
    // int tempo_finalizacao;

    struct escalonador *next;
}escalonador;

void insert_process( process **head, int cpu_burst);
void remove_process( process **head);
void insert_escalonador(escalonador **head, int priority, int arrival_time, process **cpu_bursts);
void dealloc(escalonador **head);
void read_file(const char *file_name, escalonador **head);

void ler(escalonador **head) {

    escalonador *aux = *head;
    while (aux != NULL) {
        printf("Escalonador: Priority: %d, Arrival Time: %d\n", aux->priority, aux->arrival_time);
        process *ini = aux->cpu_bursts;
        while (ini != NULL) 
        {
            printf("CPU Burst: %d\n", ini->time);
            ini = ini->next; // Avança para o próximo CPU burst
        }
        printf("\n");
        aux = aux->next;
    }
    return;
}

void fcfs(escalonador **head) {
    escalonador *escalonador_aux = *head;
    process *process_aux = NULL;
    int algTime = 0;
    short int loop = 0; //contar em qual loop está, para saber se é processo ou I/O
    int **queue_ready = malloc(sizeof(int*) * cont_process);
    int *queue_ready = malloc(sizeof(int*) * cont_process);

    while (escalonador_aux != NULL)
    {
        queue_ready[loop] = &escalonador_aux->arrival_time;
        loop++;
    }
    loop = 0;
    int *ptr = escalonador_aux->arrival_time;
    while (escalonador_aux != NULL) {
        escalonador_aux = escalonador_aux->next;
        if(*ptr > escalonador_aux->arrival_time) {
            ptr = &escalonador_aux->arrival_time;
        }
    }
    
    printf("FCFS: %d[", cont_process);

    while (escalonador_aux != NULL) {

        if (escalonador_aux->cpu_bursts == NULL)
            dealloc(&escalonador_aux);
        else
        {
            if ((loop % 2) == 0) // tempo de i/o
            {
                
            }
        }
        
        
        loop++;
    }
}

int main (int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Uso: %s <arquivo> <tamanho do quantum> <opcional -seq>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 4)
        seq = true;
    
    char *NameFile = argv[1];
    // int quantum = atoi(argv[2]);
    escalonador *start_escalonador = NULL;

    read_file(NameFile, &start_escalonador);


    
    
    ler(&start_escalonador);
    dealloc(&start_escalonador);
    
    return EXIT_SUCCESS;
}

void insert_process( process **head, int cpu_burst) {
    
    if (*head == NULL){
         process *new_process = malloc(sizeof( process));
        new_process->next = NULL;
        new_process->time = cpu_burst;
        *head = new_process;
        return;
    }
    else {
        insert_process(&((*head)->next), cpu_burst);
    }
}
void remove_process( process **head){
    if (*head != NULL) {
         process *remove = *head;
        *head = (*head)->next;
        free(remove);
    }
    return;
}

void insert_escalonador( escalonador **head, int priority, int arrival_time,  process **cpu_bursts) {
    if (*head == NULL) {
        escalonador *new_escalonador = malloc(sizeof( escalonador));
        new_escalonador->priority = priority;
        new_escalonador->arrival_time = arrival_time;
        new_escalonador->cpu_bursts = *cpu_bursts;
        new_escalonador->next = NULL;
        *head = new_escalonador;
    }
    else {
        insert_escalonador(&((*head)->next), priority, arrival_time, &(*cpu_bursts));
    }
    return;
}

void dealloc(escalonador **head){
    if (*head == NULL) 
        return;
    
    escalonador *remove_escalonador;
    process *remove_cpu_bursts;

    while (*head != NULL) 
    {     
        while ((*head)->cpu_bursts != NULL) {
            remove_cpu_bursts = (*head)->cpu_bursts;
            (*head)->cpu_bursts = (*head)->cpu_bursts->next;
            free(remove_cpu_bursts);
        }

        remove_escalonador = *head;
        *head = (*head)->next;

        free(remove_escalonador);
    }
}

void read_file(const char *file_name, escalonador **head) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int priority, arrival_time;
    char read='\n', string[32];
    process *cpu_bursts = NULL;

    while (!feof(file))
    {
        while (read != EOF) 
        {
            if (read == '\n')
                fscanf(file, "%d %d ", &priority, &arrival_time);
            read = fgetc(file);
            
            if(isdigit(read))
                strncat(string, &read, 1); // Adiciona o caractere lido à string
            else 
            { //se (read == ' ') || (read == '\n') || (read == EOF)
                int time;
                if (strlen(string) > 0) 
                    time = atoi(string);
                else
                    time = 0; // Se nao houver valor define como 0
                    
                insert_process(&cpu_bursts, time);
                memset(string, 0, sizeof(string));

                if ((read == '\n') || (read == EOF)) {
                    insert_escalonador(head, priority, arrival_time, &cpu_bursts);
                    priority = 0;
                    arrival_time = 0; 
                    cont_process++;
                    cpu_bursts = NULL;
                }
            }
        }
    }

    fclose(file);
}