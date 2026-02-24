#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h> 

typedef struct No {
    int valor;
    struct No *proximo;
    sem_t sem; 
    int etapa;        
} No;

No *L = NULL;
sem_t trava_lista;

bool leitura_concluida = false;
bool filtro_par_concluido = false;
bool filtro_primo_concluido = false;

void adicionarNo(No **head, int valor_lido);
void freeList(No **head);
bool eh_primo(int n);

void *thread1_filtra_par() {
    while (true) 
    {
        No *anterior = NULL;
        No *atual = NULL;
        No *no_para_liberar = NULL;
        bool executa = false;

        sem_wait(&trava_lista); 

        No *percursor = L;
        while (percursor != NULL) 
        {
            sem_wait(&percursor->sem);
            if (percursor->etapa == 0) 
            {
                atual = percursor;
                executa = true;
                break; 
            }
            sem_post(&percursor->sem);
            anterior = percursor;
            percursor = percursor->proximo;
        }

        if (executa) 
        {
            if ((atual->valor > 2) && (atual->valor % 2 == 0)) 
            {
                if (anterior == NULL) L = atual->proximo;
                else anterior->proximo = atual->proximo;
                no_para_liberar = atual; 
            } else 
            {
                atual->etapa = 1;
            }
            sem_post(&atual->sem); 
        }
        
        sem_post(&trava_lista); 

        if (no_para_liberar) 
        {
            sem_destroy(&no_para_liberar->sem);
            free(no_para_liberar);
        }

        if (!executa && leitura_concluida) 
        {
            break; 
        }
        
        if (!executa) sched_yield(); 
    }
    filtro_par_concluido = true;
    pthread_exit(NULL);
}

void *thread2_filtra_primo() {
    while (true) {
        No *anterior = NULL;
        No *atual = NULL;
        No *no_para_liberar = NULL;
        bool executa = false;

        sem_wait(&trava_lista);

        No *percursor = L;
        while (percursor != NULL) 
        {
            sem_wait(&percursor->sem);
            if (percursor->etapa == 1) 
            {
                atual = percursor;
                executa = true;
                break;
            }
            sem_post(&percursor->sem);
            anterior = percursor;
            percursor = percursor->proximo;
        }

        if (executa) 
        {
            if (!eh_primo(atual->valor)) 
            {
                if (anterior == NULL) L = atual->proximo;
                else anterior->proximo = atual->proximo;
                no_para_liberar = atual;
            } else 
            {
                atual->etapa = 2;
            }
            sem_post(&atual->sem);
        }

        sem_post(&trava_lista);

        if (no_para_liberar) 
        {
            sem_destroy(&no_para_liberar->sem);
            free(no_para_liberar);
        }

        if (!executa && filtro_par_concluido) 
        {
            break;
        }

        if (!executa) sched_yield();
    }
    filtro_primo_concluido = true;
    pthread_exit(NULL);
}

void *thread3_imprime_primos() {
    printf("\n");
    bool primeira_impressao = true;
    while (true) {
        No *atual = NULL;
        bool executa = false;

        sem_wait(&trava_lista); 

        No *percursor = L;
        while (percursor != NULL) 
        {
            sem_wait(&percursor->sem);
            if (percursor->etapa == 2) 
            {
                atual = percursor;
                executa = true;
                break;
            }
            sem_post(&percursor->sem);
            percursor = percursor->proximo;
        }
        
        if (executa) 
        {
            if (!primeira_impressao) 
                printf(" ");
            printf("%d", atual->valor);
            primeira_impressao = false;
            
            atual->etapa = 3; 
            sem_post(&atual->sem);
        }
        
        sem_post(&trava_lista);

        if (!executa && filtro_primo_concluido) 
        {
            break;
        }

        if (!executa) sched_yield();
    }
    printf("\n\n");
    pthread_exit(NULL);
}

int main() {
    FILE *arquivo = fopen("in.txt", "r");
    if (!arquivo) {
        perror("\nArquivo nao encontrado!\n\n");
        return -1;
    }
    
    pthread_t thread1, thread2, thread3;
    int valor_lido;

    sem_init(&trava_lista, 0, 1);

    pthread_create(&thread1, NULL, thread1_filtra_par, NULL);
    pthread_create(&thread2, NULL, thread2_filtra_primo, NULL);
    pthread_create(&thread3, NULL, thread3_imprime_primos, NULL);

    while (fscanf(arquivo, "%d", &valor_lido) == 1) 
    {
        adicionarNo(&L, valor_lido);
    }
    fclose(arquivo);

    leitura_concluida = true;
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    sem_destroy(&trava_lista);
    freeList(&L);

    return 0;
}

void adicionarNo(No **head, int valor_lido) {
    No *novo_no = malloc(sizeof(No));

    novo_no->valor = valor_lido;
    novo_no->proximo = NULL;
    novo_no->etapa = 0; 
    sem_init(&novo_no->sem, 0, 1);

    sem_wait(&trava_lista);
    if (*head == NULL) {
        *head = novo_no;
    } else {
        No *atual = *head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
    sem_post(&trava_lista);
}

void freeList(No **head) {
    No *atual = *head;
    No *proximo_no;
    while (atual != NULL) {
        proximo_no = atual->proximo;
        sem_destroy(&atual->sem);
        free(atual);
        atual = proximo_no;
    }
    *head = NULL;
}

bool eh_primo(int n) {
    if (n < 2) 
        return false;

    if (n == 2) 
        return true;

    for (int i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}