#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>

#include <math.h>

#include <time.h>

void trocar(int32_t *x, int32_t *y)
{
    if (x != y)
    {
        int32_t aux = *x;
        *x = *y;
        *y = aux;
    }
}

void BubbleSort_original(int32_t *L, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (L[j] > L[j + 1])
                trocar(&L[j], &L[j + 1]);
}

void BubbleSort_melhorado(int32_t *L, int n)
{
    bool mudou = true;
    int j, guarda = n;
    --n;

    while (mudou)
    {
        j = 0, mudou = false;

        while (j < n)
        {
            if (L[j] > L[j+1])
            {
                trocar(&L[j], &L[j+1]);
                mudou = true;
                guarda = j;
            }
            ++j;
        }
        n = guarda;
    }
}

void InsertionSort(int32_t *L, int n)
{
    int32_t prov_valor;
    int j;
    for (int i = 1; i < n; i++)
    {
        prov_valor = L[i];
        j = i - 1;
        while ((j >= 0) && (prov_valor < L[j]))
        {
            L[j + 1] = L[j];
            --j;
        }
        L[j + 1] = prov_valor;
    }
}

void intercalar(int32_t *L, int32_t *tmp, int ini, int ini2, int fim2)
{
    int fim1 = ini2 - 1; // nro = 0; nro nao eh necessario
    int ini1 = ini;      // copia do inicial sem alterar

    int ind = 0;             

    while ((ini1 <= fim1) && (ini2 <= fim2))
    {
        if (L[ini1] < L[ini2])
        {
            tmp[ind] = L[ini1];
            ++ini1;
        }
        else
        {
            tmp[ind] = L[ini2];
            ++ini2;
        }
        ++ind; // ++nro;
    }
    while (ini1 <= fim1)
    {
        tmp[ind] = L[ini1];
        ++ini1, ++ind; // ++nro;
    }
    while (ini2 <= fim2)
    {
        tmp[ind] = L[ini2];
        ++ini2, ++ind; // ++nro;
    }
    for (int i = 0; i < ind /*ou nro*/; i++)
        L[i + ini] = tmp[i];

    // for (int i = ini; i <= fim2; i++) //sem utilizar nro ou ind no codigo
    //     L[i] = tmp[i-ini];
}

void Mergesort(int32_t *L, int32_t *tmp, int esq, int dir)
{
    if (esq < dir)
    {
        int centro = (esq + dir) / 2;
        Mergesort(L, tmp, esq, centro);
        Mergesort(L, tmp, centro + 1, dir);
        intercalar(L, tmp, esq, centro + 1, dir);
    }
}

void PIVO(int32_t *L, short op, int ini, int fim) {
    int pivo;
    int meio;

    if (op == 7)
    {
        meio  = (ini + fim) /2;
        if ((L[ini] > L[meio]) != ((L[ini] > L[fim])))
            pivo = ini;
        else
        if ((L[meio] > L[ini]) != ((L[meio] > L[fim])))
            pivo = meio;
        else
            pivo = fim; 
    }
    else
        pivo = ini + rand() % (fim - ini);
    
    trocar(&L[pivo], &L[fim]);
}

void QuickSort(int32_t *L, int ini, int fim, short op) {
    if ((fim - ini) < 2)
    {
        if ((fim - ini) == 1)
            if (L[ini] > L[fim])
                trocar(&L[ini], &L[fim]);
    }
    else
    {
        if (op != 5)
            PIVO(L, op, ini, fim);

        int i = ini, j = fim-1;
        int key = fim;

        while (j>=i)
        {
            while ((L[i] < L[key]) && (i <= j))
                ++i;
            while ((L[j] > L[key]) && (j >= i))
                --j;
            
            if (j>i)
            {
                trocar(&L[i], &L[j]);
                ++i, --j;
            }
        }
        trocar(&L[i], &L[fim]);
        
        QuickSort(L, ini, i-1, op);
        QuickSort(L, i+1, fim, op);
    }
}

void descer(int32_t *T, int i, int m) // reference Szwarcfiter pg 181
{ 
    int j = 2 * i;

    if(j<=m)
    {
        if(j<m)
        {
            if(T[j+1] > T[j])
                ++j;
        }
        if(T[i] < T[j])
        {
            trocar(&T[i], &T[j]);
            descer(T, j, m);
        }
    }
}

void arranjar(int32_t *T, int n) {
    for (int i = n / 2 ; i >= 0; i--)
        descer(T, i, n);
}

void HeapSort(int32_t *T, int n) {
    arranjar(T, n);
    int m = n;

    while (m > 0)
    {
        trocar(&T[0], &T[m]);
        --m;
        descer(T, 0, m);
    }
    
}

void verifica(int32_t *lista, int n) {
    bool pass = true;
    for (int i = -(n/2); i < n/2; i++)
    {
        // printf("\nvet[%d] = %d", i+(n/2), lista[i+(n/2)]);
        if (i != lista[i+(n/2)] )
            pass = false;
    }
    if (pass)
        printf("\n\n // certo \n");
    else
        printf("\n ! errado ! \n");
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if( argc != 4 ){
        printf("\nQuantidade de entradas invalida!\n");
        return 1;
    }

    FILE *filein = fopen(argv[2], "rb");
    if (!filein)
    {
        printf("\nArquivo inserido nao existe!\n");
        fclose(filein);
        return 0;
    }

    //lista[] = {9, -10, 6, -7, 4, 3, -6, -1, -2, 0, -4, -3, 7, -8, 2, -5, -9, 1, 5, 8};
    struct stat bytes;
    int32_t *lista, *tmp;
    int n;

    if (stat(argv[2], &bytes) != 1)
    {
        lista = malloc(bytes.st_size);
        n = bytes.st_size / sizeof(int32_t);

        for (int i = 0; fread(&lista[i], sizeof(int32_t), 1, filein) ; i++);
        // printf("\nvet = %d", lista[i]);
        fclose(filein);
    }
    else
    {
        printf("\nnão foi possivel medir o arquivo\n");
        fclose(filein);
        return 1;
    }

    int op = atoi(argv[1]);
    char algoritmos[8][50] = {
        "Bubble-sort original;",
        "Bubble-sort melhorado;",
        "Insertion-sort;",
        "Mergesort;",
        "Quicksort com pivo sendo o ultimo elemento;",
        "Quicksort com pivo sendo um elemento aleatorio;",
        "Quicksort com pivo sendo a mediana de tres;",
        "Heapsort;"
    };

    if ((op >= 1) && (op <= 8))
        printf("\n(%d) %s\n", op, algoritmos[op-1]);
    else {
        printf("\nAlgoritmo escolhido nao existe! (validos de 1 a 8)\n");
        return 1;
    }

    //------------------------------------
    //calculo do tempo nessa separacao
    time_t start,end;
    double time;
    start = clock();
    //------------------------------------
    switch (op)
    {
    case 1:
        BubbleSort_original(lista, n);
        break;
    
    case 2:
        BubbleSort_melhorado(lista, n);
        break;
        
    case 3:
        InsertionSort(lista, n);
        break;
    
    case 4:
        tmp = malloc(sizeof(int32_t) * bytes.st_size+1);
        Mergesort(lista, tmp, 0, n-1);
        free(tmp);
        break;

    case 5 :
        QuickSort(lista, 0, n-1, op);
        break;

    case 6:
        QuickSort(lista, 0, n-1, op);
        break;

    case 7:
        QuickSort(lista, 0, n-1, op);
        break;

    case 8:
        HeapSort(lista, n-1);
        break;
    }
    //------------------------------------
    end = clock() - start;
    time = (double)(end) / CLOCKS_PER_SEC;
    //------------------------------------
    
    printf("Tempo de execucao: %.3f segundos\n", time);

    FILE *fileout = fopen(argv[3], "wb");
    for (int i = 0; i < n; i++) 
        fwrite(&lista[i], sizeof(int32_t), 1, fileout);
    fclose(fileout);
    
    free(lista);
    // verifica(lista, n);
    return 0;
}