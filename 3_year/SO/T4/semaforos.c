/* 
    funcoes principais do estudo (threads e semaforos) em cima da main, secundarias (manipulacao de listas) embaixo
    o correto normalmente seria escolher uma abordagem, ou em cima ou embaixo da main, 
    porem para uma melhor separacao da proposta do exercicio, optei por essa abordagem
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>

#define name1 "/sem1"
#define name2 "/sem2"
#define name3 "/sem3"

struct List {
    int value;
    struct List *next;
} List;

struct List *L1 = NULL;
struct List *L2 = NULL;
struct List *L3 = NULL;

sem_t *sem1 = NULL;
sem_t *sem2 = NULL;
sem_t *sem3 = NULL;

void appendNode(struct List **head, int val);
void freeList(struct List **head);

void *thread1_filter_pair(void* arg){
    struct List *currentNode = NULL; // Ponteiro local para percorrer lista L1
    bool first = true;

    while (true) {
        // Espera por um sinal da main para um novo item da lista
        sem_wait(sem1);

        /* notas
        inicialmente tinha um sem_wait fora do while e outro no final porem estava dando algums problemas
        a estrutura que consegui resolver foi marcar a primeira ocorrencia e depois ir para o próximo nó
        imaginei que o erro estava em passar o endereco da lista quando estava vazia,
        porem ainda eh uma questao que precisa ser melhor entendida
        */
        if (first == true) {
            currentNode = L1;
            first = false;
        } else {
            currentNode = currentNode->next;
        }

        // se em algum momento o elemento for nulo a thread principal terminou 
        // o programa libera a proxima thread mais uma vez para poder identificar o termino quando a lista chegar ao final
        if (currentNode == NULL) {
            sem_post(sem2); // libera a próxima thread para que ela também possa terminar
            break;          // sai do loop
        }
        // filtra pares maiores que 2, excetuando o 2, proposicao negativa pra melhor vizualizacao de pares maiores que 2, em vez de excetuar diretamente o 2
        if (!((currentNode->value > 2) && (currentNode->value % 2 == 0))) { 
            appendNode(&L2, currentNode->value);
            sem_post(sem2); // sinaliza para a thread2 que um item está pronto
        }
    }
    pthread_exit(0);
}

void *thread2_filter_prime(void* arg){
    struct List *currentNode = NULL;
    bool first = true;

    while (true) {
        sem_wait(sem2);

        //esta mesma estrutura de controle de primeiro elemento foi utilizada em todas as threads
        if (first == true) {
            currentNode = L2;
            first = false;
        } else {
            currentNode = currentNode->next;
        }
        
        if (currentNode == NULL){
            sem_post(sem3);
            break;
        }
            
        bool is_prime = true;
        if (currentNode->value < 2) {
            is_prime = false;
        } else {
            for (int i = 2; i <= sqrt(currentNode->value); i++) 
            // por uma proposicao matematica nao tem chances de ter num divisor maior que a raiz quadrada do numero
                if (currentNode->value % i == 0) {
                    is_prime = false;
                    break;
                }
        }
        if (is_prime) {
            appendNode(&L3, currentNode->value);
            sem_post(sem3); // Sinaliza para a thread2 que um item está pronto
        }
    }
    pthread_exit(0);
}

void *thread3_print(void* arg){
    struct List *currentNode = NULL;
    bool first = true;

    printf("\n");
    while (true) {
        sem_wait(sem3);

        if (first == true) {
            currentNode = L3;
            first = false;
        } else {
            currentNode = currentNode->next;
        }
        
        if (currentNode == NULL){
            break;
        }
        printf("%d ", currentNode->value);
    }
    printf("\n\n");
    // o teste com 1000000 demorou cerca de 40 minutos para ser executado
    pthread_exit(0);
}

int main() {
    // thread principal(main) - Cria 3 threads iniciais e Le o arquivo e armazena na lista L1
    
    FILE *file = fopen("in.txt", "r");
    pthread_t thread1, thread2, thread3;
    int val;

    if(!file){
        perror("\nArquivo não encontrado!\n\n");
        return -1;
    }
    
    // esvazia os semaforos caso ja existam
    sem_unlink(name1);
    sem_unlink(name2); 
    sem_unlink(name3);

    // abre os semaforos de forma que estejam fechados inicialmente
    sem1 = sem_open(name1, O_CREAT, 0644, 0);
    sem2 = sem_open(name2, O_CREAT, 0644, 0);
    sem3 = sem_open(name3, O_CREAT, 0644, 0);   

    if ((sem1 == SEM_FAILED) || (sem2 == SEM_FAILED) || (sem3 == SEM_FAILED)) {
        perror("Falha em sem_open");
        exit(EXIT_FAILURE);
    }

    pthread_create(&thread1, NULL, (void *)thread1_filter_pair, NULL);
    pthread_create(&thread2, NULL, (void *)thread2_filter_prime, NULL);
    pthread_create(&thread3, NULL, (void *)thread3_print, NULL);

    // Para cada numero lido, adiciona na lista L1
    while (fscanf(file, "%d", &val) == 1) {
        appendNode(&L1, val);
        sem_post(sem1); 
    }
    sem_post(sem1); // libera a thread1 mais uma vez, para que ela possa identificar o fim da lista
    fclose(file);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    sem_unlink(name1);
    sem_unlink(name2); 
    sem_unlink(name3);

    freeList(&L1);
    freeList(&L2);
    freeList(&L3);
}

void appendNode(struct List **head, int val) { 
    // estrutura de alocacao simples
    // o problema eh que eu percorro a lista novamente toda vez que adiciono um elemento
    // poderia ser melhorado adicionando apenas a partir do ultimo elemento ou se fosse uma lista circular
    // porem como o foco era mais em semaforos e threads, deixei assim
    struct List *new_node = malloc(sizeof(struct List));
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct List *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void freeList(struct List **head) {
    if (!(*head)) return;

    struct List *current = *head;
    struct List *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}