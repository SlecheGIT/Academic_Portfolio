#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct
{
    long int id_reg;
    char placa[9];
    char modelo[TAM];
    char fabricante[TAM];
    int ano_fabricacao;
    int ano_modelo;
    char combustivel[TAM];
    char cor[TAM];
    int opcional[8];
    float preco_compra;
} CARRO;

char opcionais[][TAM] = {
    {"4.portas"},
    {"cambio.automatico"},
    {"vidros.eletricos"},
    {"abs"},
    {"air.bag"},
    {"ar.condicionado"},
    {"banco.couro"},
    {"sensor.estacionamento"}};

void quant_registro(const char *arquivo)
{
    FILE *file = fopen(arquivo, "rb");

    fseek(file, 0, SEEK_END);
    long tam_arquivo = ftell(file);
    int num_registros = tam_arquivo / sizeof(CARRO);
    fseek(file, 0, SEEK_SET);

    printf("\nO arquivo '%s' contem %d registros.\n\n", arquivo, num_registros);

    fclose(file);
}

void contarPorCombustivel(const char *arquivo)
{
    FILE *file = fopen(arquivo, "rb");

    fseek(file, 0, SEEK_END);
    long tam_arquivo = ftell(file);
    int num_registros = tam_arquivo / sizeof(CARRO);
    fseek(file, 0, SEEK_SET);

    int gasolinaCount = 0;
    int alcoolCount = 0;
    int flexCount = 0;
    int dieselCount = 0;

    for (int i = 0; i < num_registros; i++)
    {
        CARRO p;
        fread(&p, sizeof(CARRO), 1, file);

        if (strcmp(p.combustivel, "gasolina") == 0)
        {
            gasolinaCount++;
        }
        else if (strcmp(p.combustivel, "alcool") == 0)
        {
            alcoolCount++;
        }
        else if (strcmp(p.combustivel, "flex") == 0)
        {
            flexCount++;
        }
        else if (strcmp(p.combustivel, "diesel") == 0)
        {
            dieselCount++;
        }
    }

    printf("\nQuantidade de carros a gasolina: %d\n", gasolinaCount);
    printf("Quantidade de carros a alcool: %d\n", alcoolCount);
    printf("Quantidade de carros flex: %d\n", flexCount);
    printf("Quantidade de carros a diesel: %d\n\n", dieselCount);

    fclose(file);
}
void contar_opcional(const char *arquivo)
{
    FILE *file = fopen(arquivo, "rb");

    fseek(file, 0, SEEK_END);
    long tam_arquivo = ftell(file);
    int num_registros = tam_arquivo / sizeof(CARRO);
    fseek(file, 0, SEEK_SET);

    int portasCount = 0;
    int cambioCount = 0;
    int vidrosCount = 0;
    int absCount = 0;
    int airbagCount = 0;
    int arcondCount = 0;
    int bancoCount = 0;
    int sensorCount = 0;

    for (int i = 0; i < num_registros; i++)
    {
        CARRO p;
        fread(&p, sizeof(CARRO), 1, file);

        if (p.opcional[0] == 1)
        {
            portasCount++;
        }
        else if (p.opcional[1] == 1)
        {
            cambioCount++;
        }
        else if (p.opcional[2] == 1)
        {
            vidrosCount++;
        }
        else if (p.opcional[3] == 1)
        {
            absCount++;
        }
        else if (p.opcional[4] == 1)
        {
            airbagCount++;
        }
        else if (p.opcional[5] == 1)
        {
            arcondCount++;
        }
        else if (p.opcional[6] == 1)
        {
            bancoCount++;
        }
        else if (p.opcional[7] == 1)
        {
            sensorCount++;
        }
    }

    printf("\nQuantidade de carros com 4 portas: %d\n", portasCount);
    printf("Quantidade de carros com cambio automatico: %d\n", cambioCount);
    printf("Quantidade de carros com vidros eletricos: %d\n", vidrosCount);
    printf("Quantidade de carros com abs: %d\n", absCount);
    printf("Quantidade de carros com airbag: %d\n", airbagCount);
    printf("Quantidade de carros com ar condicionado: %d\n", arcondCount);
    printf("Quantidade de carros com banco de couro: %d\n", bancoCount);
    printf("Quantidade de carros com sensor de estacionamento: %d\n\n", sensorCount);

    fclose(file);
}

int compararPlacas(const void *a, const void *b)
{
    CARRO *carroA = (CARRO *)a;
    CARRO *carroB = (CARRO *)b;
    return strcmp(carroA->placa, carroB->placa); // comparar a placa de dois carros
}

int compararPLacas(const char *arquivo)
{
    FILE *file = fopen(arquivo, "rb");

    fseek(file, 0, SEEK_END);
    long tam_arquivo = ftell(file);
    int num_registros = tam_arquivo / sizeof(CARRO);
    fseek(file, 0, SEEK_SET);

    CARRO *carros = (CARRO *)malloc(num_registros * sizeof(CARRO)); // calcula o numero de registros no arquivo

    for (int i = 0; i < num_registros; i++)
    {
        fread(&carros[i], sizeof(CARRO), 1, file);
    }

    fclose(file);

    qsort(carros, num_registros, sizeof(CARRO), compararPlacas);
    FILE *ordFile = fopen("carro.ord", "wb");

    fwrite(carros, sizeof(CARRO), num_registros, ordFile);
    printf("-------------------------------\n");
    printf("Carros Ordenados e Armazenados!\n");
    printf("-------------------------------\n");

    fclose(ordFile);
    free(carros);

    return 0;
}

void ordenar_placas(const char *arquivo)
{
    FILE *arquivo_adcional = fopen(arquivo, "rb");

    if (arquivo_adcional == NULL)
    {
        printf("-------------------------------------\n");
        printf("-----------------ERRO----------------\n");
        printf("Carros nao ordenados anteriormente!!\n");
        printf("-------------------------------------");
        exit(EXIT_FAILURE);
    }

    fseek(arquivo_adcional, 0, SEEK_END);
    long tam_arquivo = ftell(arquivo_adcional);
    int num_registros = tam_arquivo / sizeof(CARRO);
    fseek(arquivo_adcional, 0, SEEK_SET);

    
    printf("Registros ordenados:\n");
     printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_registros; i++)
    {
        CARRO p;
        fread(&p, sizeof(CARRO), 1, arquivo_adcional);

        printf(" ID: %ld\n Placa: %s\n Modelo: %s\n Fabricante: %s\n Ano: %d\n Combustivel: %s\n Cor: %s\n Preco: %3.f \n",
               p.id_reg, p.placa, p.modelo, p.fabricante, p.ano_modelo, p.combustivel, p.cor, p.preco_compra);
        printf("-----------------------------------------------------------------------------------------------------\n");
        //  
    }

    fclose(arquivo_adcional);
}

int main()
{
    system("cls");
    const char *arquivo = "carro.dbf";
    int op;

    FILE *file = fopen(arquivo, "rb");
    if (file == NULL)
    {
        printf("-------------------------\n");
        printf("----------ERRO-----------\n");
        printf("Arquivo NAO localizado!!\n");
        printf("-------------------------");
        exit(EXIT_FAILURE);
    }
    do {
        printf("\n1. Informar quantos registros tem ''carro.dbf''.\n");
        printf("2. Ordenar os registros de ''carro.dbf'' de forma crescente pelo\
              \ncampo ''placa'' armazena-los no arquivo ''carro.ord''.\n");
        printf("3. Mostrar os registros de ''carro.ord''.\n");
        printf("4. Para cada tipo de combustivel informar a quantidade de carros.\n");
        printf("5. Para cada tipo de opcional informar a quantidade de carros.\n");
        printf("6. Finalizar programa\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        fflush(stdin);
            system("cls");

        switch (op)
        {
        case 1:
            quant_registro(arquivo);
            system("pause");
            system("cls");
            break;

        case 2:
            compararPLacas(arquivo);
            break;

        case 3:
            ordenar_placas("carro.ord");
            system("pause");
            system("cls");
            break;
        case 4:
            contarPorCombustivel(arquivo);
            system("pause");
            system("cls");
            break;
        case 5:
            contar_opcional(arquivo);
            system("pause");
            system("cls");
            break;
        case 6:
            printf("\nFinalizando o Programa!\n");
            return 0;
            break;
        default:
            printf("\n[ERRO] -> Opcao invalida!!\n\n");
            break;
        }
        
    } while (1);
    
    return 0;
}