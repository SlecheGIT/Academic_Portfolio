#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

// Estruturas para Carro, Cliente e Venda
typedef struct
{
    char modelo[TAM];      // gol, celta, palio, ...
    char fabricante[TAM];  // chevrolet, fiat, ...
    int ano_modelo;        // 1980 � 2017
    char combustivel[TAM]; // alcool, gasolina, flex, diesel
    float preco_compra;
} INFO;

typedef struct
{
    int status;            // (-1 = slot vazio), (0 = Vendido), (1 = Disponivel)
    char placa[9];         // AAA-123
    char modelo[TAM];      // gol, celta, palio, ...
    char fabricante[TAM];  // chevrolet, fiat, ...
    int ano_fabricacao;    // 1980 � 2016
    int ano_modelo;        // 1980 � 2017
    char combustivel[TAM]; // alcool, gasolina, flex, diesel
    char cor[TAM];         // branca, prata, preta
    int opcional[TAM];     // ver matriz opcionais
    float preco_compra;
} CARRO;

typedef struct
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[TAM];
    char cep[11]; // 99.999-999
} ENDERECO;

typedef struct
{
    char telefone[14]; // 99 99999-9999
} TELEFONE;

typedef struct
{
    int status; //(-1 = slot vazio) (0 = cliente), (1 = Cliente com venda)
    char nome[TAM];
    char cpf[15]; // 999.999.999-99
    ENDERECO endereco;
    TELEFONE residencial;
    TELEFONE celular[5];
    float renda_mensal;
} CLIENTE;

typedef struct
{
    int dia, mes, ano;
} DATA;

typedef struct
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    DATA data_venda;
} VENDA_CARRO;

int qnt_car = 0;
int qnt_client = 0;
// Fun��es para Carro
CARRO inserirCarro()
{
    CARRO p;
    INFO tipos[21];

    strcpy(tipos[0].modelo, "Onix");
    strcpy(tipos[0].fabricante, "Chevrolet");
    tipos[0].ano_modelo = 2011;
    tipos[0].preco_compra = 60.000;

    strcpy(tipos[1].modelo, "S10");
    strcpy(tipos[1].fabricante, "Chevrolet");
    tipos[1].ano_modelo = 1997;
    tipos[1].preco_compra = 140.000;

    strcpy(tipos[2].modelo, "Palio");
    strcpy(tipos[2].fabricante, "Fiat");
    tipos[2].ano_modelo = 1991;
    tipos[2].preco_compra = 40.000;

    strcpy(tipos[3].modelo, "Strada");
    strcpy(tipos[3].fabricante, "Fiat");
    tipos[3].ano_modelo = 1998;
    tipos[3].preco_compra = 35.400;

    strcpy(tipos[4].modelo, "Corolla");
    strcpy(tipos[4].fabricante, "Toyota");
    tipos[4].ano_modelo = 2001;
    tipos[4].preco_compra = 105.00;

    strcpy(tipos[5].modelo, "Hillux");
    strcpy(tipos[5].fabricante, "Toyota");
    tipos[5].ano_modelo = 1994;
    tipos[5].preco_compra = 189.300;

    strcpy(tipos[6].modelo, "Gol");
    strcpy(tipos[6].fabricante, "Volkswagen");
    tipos[6].ano_modelo = 1991;
    tipos[6].preco_compra = 60.000;

    strcpy(tipos[7].modelo, "Saveiro");
    strcpy(tipos[7].fabricante, "Volkswagen");
    tipos[7].ano_modelo = 2008;
    tipos[7].preco_compra = 37.000;

    strcpy(tipos[8].modelo, "Voyage");
    strcpy(tipos[8].fabricante, "Volkswagen");
    tipos[8].ano_modelo = 1982;
    tipos[8].preco_compra = 173.000;

    strcpy(tipos[9].modelo, "Golf GTI");
    strcpy(tipos[9].fabricante, "Volkswagen");
    tipos[9].ano_modelo = 2015;
    tipos[9].preco_compra = 132.000;

    strcpy(tipos[10].modelo, "Dodge Challenger");
    strcpy(tipos[10].fabricante, "Dodge");
    tipos[10].ano_modelo = 2008;
    tipos[10].preco_compra = 550.000;

    strcpy(tipos[11].modelo, "Audi TT");
    strcpy(tipos[11].fabricante, "Audi");
    tipos[11].ano_modelo = 2012;
    tipos[11].preco_compra = 151.000;

    strcpy(tipos[12].modelo, "Mustang GT");
    strcpy(tipos[12].fabricante, "Ford");
    tipos[12].ano_modelo = 2015;
    tipos[12].preco_compra = 373.000;

    strcpy(tipos[13].modelo, "Fusca");
    strcpy(tipos[13].fabricante, "Volkswagen");
    tipos[13].ano_modelo = 1968;
    tipos[13].preco_compra = 50.000;

    strcpy(tipos[14].modelo, "Amarok");
    strcpy(tipos[14].fabricante, "Volkswagen");
    tipos[14].ano_modelo = 2015;
    tipos[14].preco_compra = 120.000;

    strcpy(tipos[15].modelo, "Supra");
    strcpy(tipos[15].fabricante, "Toyota");
    tipos[15].ano_modelo = 1994;
    tipos[15].preco_compra = 32.000;

    strcpy(tipos[16].modelo, "Nissan 350z");
    strcpy(tipos[16].fabricante, "Nissan");
    tipos[16].ano_modelo = 2007;
    tipos[16].preco_compra = 240.000;

    strcpy(tipos[17].modelo, "Saveiro Surf");
    strcpy(tipos[17].fabricante, "Volkswagen");
    tipos[17].ano_modelo = 2009;
    tipos[17].preco_compra = 42.000;

    strcpy(tipos[18].modelo, "Porshe Panamera");
    strcpy(tipos[18].fabricante, "Porshe");
    tipos[18].ano_modelo = 2008;
    tipos[18].preco_compra = 590.000;

    strcpy(tipos[19].modelo, "C3");
    strcpy(tipos[19].fabricante, "Citroen");
    tipos[19].ano_modelo = 2022;
    tipos[19].preco_compra = 63.000;

    strcpy(tipos[20].modelo, "HB20");
    strcpy(tipos[20].fabricante, "  Hyundai");
    tipos[20].ano_modelo = 2022;
    tipos[20].preco_compra = 74.300;

    int i;
    char status = 'c';
    char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char cores[][10] = {"vermelho", "verde", "azul", "branco", "preto", "cinza", "prata", "marrom", "amarelo"};
    char gas[][10] = {"gasolina", "alcool", "flex", "diesel"};
    char placa[10];

    // gerar placa
    for (int k = 0; k <= 2; k++)
    {
        i = rand() % 26;
        placa[k] = (letras[i] - 32);
    }
    placa[3] = '-';
    for (int k = 4; k < 8; k++)
        placa[k] = (rand() % 9) + '0';

    strcpy(p.placa, placa);

    // gerar carro
    i = rand() % 8;
    strcpy(p.modelo, tipos[i].modelo);
    strcpy(p.fabricante, tipos[i].fabricante);
    p.ano_modelo = tipos[i].ano_modelo;
    p.preco_compra = tipos[i].preco_compra;

    // gerar ano de fabricacao
    i = (rand() % 2) - 1;
    p.ano_fabricacao = p.ano_modelo + i;

    // gerar combustivel type
    i = rand() % 3;
    strcpy(p.combustivel, gas[i]);

    // gerar coloracao
    i = rand() % 8;
    strcpy(p.cor, cores[i]);

    // gerar opcionais
    strcpy(p.opcional, "\0");
    i = (rand() % 4) + 1;

    for (int k = 0; k < i; k++)
    {
        int vet[i];
        int cpy = 0;
        int z = rand() % 7;
        for (int c = 0; c < k; c++)
            if (vet[c] == z)
                cpy = 1;
        if (cpy != 1)
        {
            vet[k] = z;
            if (k != 0)
                strcat(p.opcional, ", ");
            strcat(p.opcional, opcionais[z]);
        }
    }

    printf("------------------------------------------------------------------------------");
    printf("\nPlaca: %s \
            \nModelo: %s \
            \nFabricante: %s \
            \nAno de Fabricacao: %d\
            \nAno do Modelo: %d\
            \nCombustivel: %s\
            \nCor: %s \
            \nOpcional: %s\
            \nPreco de Compra: %.3f mil\
            \n",
           p.placa, p.modelo, p.fabricante, p.ano_fabricacao, p.ano_modelo, p.combustivel, p.cor, p.opcional, p.preco_compra);
    printf("------------------------------------------------------------------------------\n");

    printf("Deseja que este carro seja inserido no sistema?\n (S/N) --> ");
    scanf("%c", &status);
    fflush(stdin);

    while ((status != 'S') && (status != 'N') && (status != 's') && (status != 'n'))
    {
        printf("\n\n opcao invalida (S/N)\n--> ");
        scanf("%c", &status);
        fflush(stdin);
    }
    if ((status == 's') || (status == 'S'))
    {
        p.status = 1, qnt_car++;
        printf("\n\nSalvo no sistema!\n");
    }
    return p;
}

int excluirCarro(CARRO garagem[])
{
    if (qnt_car == 0)
    {
        printf("Nao tem carros no cadastro!\n");
        return;
    }
    char placa[8];
    int veri = NULL;
    printf("Insira a Placa do carro que deseja excluir!\n--> ");
    scanf("%s", placa);
    fflush(stdin);
    for (int i = 0; i < TAM; i++)
    {
        veri = strstr(garagem[i].placa, placa);
        if (veri != NULL)
        {
            if (garagem[i].status == 0)
            {
                printf("\nO carro ja foi vendido!\n");
                return -1;
            }
            else if (garagem[i].status == 1)
            {
                printf("\nCarro Excluido do cadastro!\n");
                return i;
            }
        }
    }
    printf("\nNao tem carros com essa placa no cadastro!\n");
    return -1;
}

// Fun��es para Cliente
void listarCarrosOrdemCrescente(CARRO garagem[])
{
    CARRO aux1, aux2; // vari�vel tempor�ria
    int order[qnt_car];
    if (qnt_car == 0)
    {
        printf("Nao ha carros no cadastro!\n");
        return;
    }

    if (qnt_car > 0)
    {
        for (int i = 0; i < qnt_car - 1; i++)
        {
            for (int j = i + 1; j < qnt_car; j++)
            {
                if (strcmp(garagem[i].fabricante, garagem[j].fabricante) > 0)
                {
                    aux1 = garagem[i];
                    garagem[i] = garagem[j];
                    garagem[j] = aux1;
                }
                else if (strcmp(garagem[i].fabricante, garagem[j].fabricante) == 0)
                {
                    if (strcmp(garagem[i].modelo, garagem[j].modelo) > 0)
                    {
                        aux2 = garagem[i];
                        garagem[i] = garagem[j];
                        garagem[j] = aux2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        if (garagem[i].status == 1)
        {
            printf("------------------------------------------------------------------------------");
            printf("\nPlaca: %s \
                    \nModelo: %s \
                    \nFabricante: %s \
                    \nAno de Fabricacao: %d\
                    \nAno do Modelo: %d\
                    \nCombustivel: %s\
                    \nCor: %s \
                    \nOpcional: %s\
                    \nPreco de Compra: %.3f mil\
                    \n",
                   garagem[i].placa, garagem[i].modelo, garagem[i].fabricante,
                   garagem[i].ano_fabricacao, garagem[i].ano_modelo, garagem[i].combustivel,
                   garagem[i].cor, garagem[i].opcional, garagem[i].preco_compra);
            printf("------------------------------------------------------------------------------\n");
        }
    }
}

void listarCarrosOpcionais(CARRO garagem[])
{
    if (qnt_car == 0)
    {
        printf("Nao tem carros no cadastro!\n");
        return;
    }

    printf("      |  opicionais: |\
            \n\"cambio.automatico\", \"4.portas\"\
            \n\"vidros.eletricos\", \"banco.couro\"\
            \n\"sensor.estacionamento\", \"abs\"\
            \n\"ar.condicionado\", \"air.bag\"\n ");
    char op[8][TAM];
    int qnt = 0;

    printf("\nQual Opcional Deseja que seja listado?\n--> ");
    scanf("%s", op[qnt]);
    fflush(stdin);
    qnt++;
    do
    {
        printf("\nDeseja Outro opcional? Digite (N) para prosseguir\n--> ");
        scanf("%s", op[qnt]);
        fflush(stdin);
        qnt++;
    } while ((op[--qnt][0] != 'n') && (op[qnt][0] != 'N'));

    for (int k = 0; k < TAM; k++)
    {
        if (garagem[k].status == 1)
        {
            for (int i = 0; i < qnt; i++)
            {
                int *cont = NULL;
                cont = strstr(garagem[k].opcional, op[i]);

                if (cont != NULL)
                {
                    printf("------------------------------------------------------------------------------");
                    printf("\nPlaca: %s \
                            \nModelo: %s \
                            \nFabricante: %s \
                            \nAno de Fabricacao: %d\
                            \nAno do Modelo: %d\
                            \nCombustivel: %s\
                            \nCor: %s \
                            \nOpcional: %s\
                            \nPreco de Compra: %.3f mil\
                            \n",
                           garagem[k].placa, garagem[k].modelo, garagem[k].fabricante,
                           garagem[k].ano_fabricacao, garagem[k].ano_modelo, garagem[k].combustivel,
                           garagem[k].cor, garagem[k].opcional, garagem[k].preco_compra);
                }
            }
        }
    }
    printf("------------------------------------------------------------------------------\n");
}

void listarCarrosAnoFabricacao(CARRO garagem[])
{
    int ano = 0, confirm = 0;
    if (qnt_car == 0)
    {
        printf("Nao tem carros no cadastro!\n");
        return;
    }
    printf("Qual o ano de fabricação que deseja buscar?\n--> ");
    scanf("%d", &ano);
    fflush(stdin);
    for (int i = 0; i < TAM; i++)
    {
        if (garagem[i].status == 1)
        {
            if (garagem[i].ano_fabricacao == ano)
            {
                confirm = 1;
                printf("------------------------------------------------------------------------------");
                printf("\nPlaca: %s \
                        \nModelo: %s \
                        \nFabricante: %s \
                        \nAno de Fabricacao: %d\
                        \nAno do Modelo: %d\
                        \nCombustivel: %s\
                        \nCor: %s \
                        \nOpcional: %s\
                        \nPreco de Compra: %.3f mil\
                        \n",
                       garagem[i].placa, garagem[i].modelo, garagem[i].fabricante,
                       garagem[i].ano_fabricacao, garagem[i].ano_modelo, garagem[i].combustivel,
                       garagem[i].cor, garagem[i].opcional, garagem[i].preco_compra);
            }
        }
    }
    if (confirm == 0)
    {
        printf("Nao ha nenhum registro de carro fabricado nesse ano!\n");
        return;
    }
    printf("------------------------------------------------------------------------------\n");
}

// objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
// parametros: cpf o cpf sem os digitos verificadores
// retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[])
{
    int digito = 0;
    // implemente aqui
    for (int i = 0, c = 10; i < 9; i++, c--)
        digito += c * (cpf[i] - '0');

    if ((digito % 11) < 2)
        digito = 0;
    else
        digito = 11 - (digito % 11);
    return (digito);
}

// objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
// parametros: cpf sem os digitos verificadores
// retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[])
{
    int digito = 0;
    // implemente aqui
    for (int i = 0, c = 2; i < 9; i++, c++)
        digito += c * (cpf[i] - '0');

    if ((digito % 11) < 2)
        digito = 0;
    else
        digito = 11 - (digito % 11);
    //
    return (digito);
}

// gerar cliente
CLIENTE inserir_cliente()
{
    CLIENTE p;
    char status;
    char primeiro_nome[][20] = {"Bianca", "Gabriel", "Caio", "Ana", "Eduardo", "Clara", "Nilton", "Adriana",
                                "Beatriz", "Evellyn", "Gabriela", "Caua", "Hettore", "Maria", "Pedro", "Taylor",
                                "Lucas", "Luiza", "Laura", "Julia", "Julio", "Fabricio"};
    char sobrenome[][20] = {"Dantas", "Barros", "Silva", "Dias", "Gouveia", "Santos", "Nascimento", "Ribeiro",
                            "Labarce", "Vermieiro", "Rodrigues", "Abrams", "Swift", "Hugo", "Souza", "Sanchez",
                            "Anne", "Duarte", "Almeida", "Laplace", "Barbosa", "Castro"};
    char dd[][TAM] = {"61", "62", "65", "67", "82", "71", "85", "98", "83", "81", "86", "84", "79", "68", "96", "92", "91",
                      "69", "95", "63", "27", "31", "21", "11", "41", "51", "47"};
    char primeiro_digito_Celular[][TAM] = {"6", "7", "8", "9"};
    char primeiro_digito_Residencial[][TAM] = {"2", "3", "4", "5"};

    char estados[][TAM] = {"Distrito Federal", "Goias", "Mato Grosso", "Mato Grosso do Sul", "Alagoas", "Bahia", "Ceara",
                           "Maranhao", "Paraiba", "Penanambuco", "Piaui", "Rio Grande do Norte", "Sergipe", "Acre",
                           "Amapa", "Amazonas", "Para", "Rondonia", "Roraima", "Tocantins", "Espirito Santo",
                           "Minas Gerais", "Rio de Janeiro", "Sao Paulo", "Parana", "Rio Grande do Sul", "Santa Catarina"};
    char ruas[][TAM] = {"Sao José ", "Sao Paulo ", "Santo Antônio", "Avenida Brasil", "Sao Pedro",
                        "Sao Joao", "Sao Francisco", "Sete de Setembro", "Quinze de Novembro",
                        "Tiradentes", "Bela Vista", " Parana", "Castro Alvez", "Duque de Caxias",
                        "Santos Dummond", "Treze de Maio", "Rua das Flores"};
    char bairros[][TAM] = {"Ibirapuera", "Jardins", "Monte Libano", "Liberdade", "Santa Cruz", "Sao Jose", "Santa Felicidade",
                           "Boa Vista", "Centro", "Alvorada"};
    char primeiro_digit_CEP[][TAM] = {"70", "74", "78", "79", "57", "40", "60", "65", "58", "50", "64",
                                      "59", "49", "69", "68", "69", "66", "76", "69", "77", "29", "30", "20", "01", "80", "90", "88"};
    char cidades[26][3][TAM] = {
        {"Goiania", "Anapolis", "Rio Verde"},                     // Goias
        {"Cuiaba", "Varzea Grande", "Rondonopolis"},             // Mato Grosso
        {"Campo Grande", "Dourados", "Tres Lagoas"},             // Mato Grosso do Sul
        {"Maceio", "Arapiraca", "Palmeira dos Indios"},           // Alagoas
        {"Salvador", "Feira de Santana", "Vitoria da Conquista"}, // Bahia
        {"Fortaleza", "Caucaia", "Juazeiro do Norte"},            // Ceara
        {"São Luis", "Imperatriz", "Timon"},                     // Maranhão
        {"João Pessoa", "Campina Grande", "Santa Rita"},         // Paraíba
        {"Recife", "Jaboatao dos Guararapes", "Olinda"},          // Pernambuco
        {"Teresina", "Parnaíba", "Piripiri"},                    // Piauí
        {"Natal", "Mossoro", "Parnamirim"},                      // Rio Grande do Norte
        {"Aracaju", "Nossa Senhora do Socorro", "Lagarto"},      // Sergipe
        {"Rio Branco", "Cruzeiro do Sul", "Sena Madureira"},     // Acre
        {"Macapa", "Santana", "Laranjal do Jari"},               // Amapa
        {"Manaus", "Parintins", "Itacoatiara"},                  // Amazonas
        {"Belém", "Ananindeua", "Santarem"},                    // Para
        {"Porto Velho", "Ji-Parana", "Ariquemes"},               // Rondônia
        {"Boa Vista", "Rorainopolis", "Caracarai"},              // Roraima
        {"Palmas", "Gurupi", "Araguaína"},                       // Tocantins
        {"Vitoria", "Vila Velha", "Serra"},                      // Espírito Santo
        {"Belo Horizonte", "Uberlandia", "Contagem"},            // Minas Gerais
        {"Rio de Janeiro", "São Gonçalo", "Duque de Caxias"},    // Rio de Janeiro
        {"São Paulo", "Guarulhos", "Campinas"},                  // São Paulo
        {"Curitiba", "Londrina", "Maringa"},                    // Parana
        {"Porto Alegre", "Caxias do Sul", "Canoas"},            // Rio Grande do Sul
        {"Florianopolis", "Joinville", "Blumenau"}              // Santa Catarina
    };


    // variaveis de cpf
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char dig[12] = {};
    int r;

    // gerar nome
    int i, j;
    memset(p.nome, 0x0, sizeof(p.nome));

    i = (rand() % 21);
    j = (rand() % 20);

    strcat(p.nome, primeiro_nome[i]);
    strcat(p.nome, " ");
    strcat(p.nome, sobrenome[j]);
    // gerar CPF

    for (i = 0; i < 9; i++)
    {
        r = rand() % 9;
        dig[i] = numeros[r];
    }
    dig[9] = obtem_primeiro_digito_verificador(dig) + '0';
    dig[10] = obtem_segundo_digito_verificador(dig) + '0';

    p.cpf[0] = dig[0];
    p.cpf[1] = dig[1];
    p.cpf[2] = dig[2];
    p.cpf[3] = '.';
    p.cpf[4] = dig[3];
    p.cpf[5] = dig[4];
    p.cpf[6] = dig[5];
    p.cpf[7] = '.';
    p.cpf[8] = dig[6];
    p.cpf[9] = dig[7];
    p.cpf[10] = dig[8];
    p.cpf[11] = '-';
    p.cpf[12] = dig[9];
    p.cpf[13] = dig[10];
    p.cpf[14] = '\0';

    // gerar telefone celular

    memset(p.celular, 0x0, sizeof(p.celular));

    i = rand() % 25;
    j = rand() % 3;
    char final1[5];
    int AUX;

    strcat(p.celular, dd[i]);
    strcat(p.celular, " 9");
    strcat(p.celular, primeiro_digito_Celular[j]);
    AUX = 100 + (rand() % 899);
    itoa(AUX, final1, 10);
    strcat(p.celular, final1);
    strcat(p.celular, "-");
    AUX = 1000 + (rand() % 8999);
    itoa(AUX, final1, 10);
    strcat(p.celular, final1);

    // gerar telefone residencial
    strcpy(p.residencial.telefone, "\0");
    strcat(p.residencial.telefone, dd[i]);
    strcat(p.residencial.telefone, " ");
    strcat(p.residencial.telefone, primeiro_digito_Residencial[j]);
    AUX = 100 + (rand() % 899);
    itoa(AUX, final1, 10);
    strcat(p.residencial.telefone, final1);
    strcat(p.residencial.telefone, "-");
    AUX = 1000 + (rand() % 8999);
    itoa(AUX, final1, 10);
    strcat(p.residencial.telefone, final1);

    // gerar endereco
    // gera rua
    j = rand() % 16;
    strcpy(p.endereco.rua, ruas[j]);
    // gera numero
    p.endereco.numero = rand() % 10000;
    // gera bairro
    j = rand() % 9;
    strcpy(p.endereco.bairro, bairros[j]);
    // gera estado
    strcpy(p.endereco.estado, "\0");
    strcpy(p.endereco.estado, estados[i]); // gera estado
    // gera cidade
     if(i==0)
    strcpy(p.endereco.cidade,"Brasilia");
    else{
        j= rand()%2;
    strcpy(p.endereco.cidade,cidades[i-1][j]);
    }

    // gera CEP
    // memset(p.endereco.cep, 0x0, sizeof(p.endereco.cep));
    strcpy(p.endereco.cep, primeiro_digit_CEP[i]);
    AUX = 100 + (rand() % 899);
    itoa(AUX, final1, 10);
    strcat(p.endereco.cep, final1);
    strcat(p.endereco.cep, "-");
    AUX = 100 + (rand() % 899);
    itoa(AUX, final1, 10);
    strcat(p.endereco.cep, final1);

    // gerar renda mensal
    p.renda_mensal = 1000 + (rand() % 20000);

    printf("------------------------------------------------------------------------------");
    printf("\nNome: %s\
            \nCPF: %s\n\
            \nEndereco: \
            \nRua -> %s\
            \nNumero -> %d\
            \nBairro -> %s\
            \nCidade-> %s\
            \nEstado-> %s\
            \nCEP-> %s \n\
            \nTelefone Residencial: %s\
            \nTelefone Celular: %s \
            \nRenda Mensal: %3.f \
            \n",
           p.nome, p.cpf, p.endereco.rua, p.endereco.numero, p.endereco.bairro,p.endereco.cidade, p.endereco.estado, p.endereco.cep, p.residencial.telefone, p.celular, p.renda_mensal);
    printf("------------------------------------------------------------------------------\n");

    printf("Deseja que este cliente seja inserido no sistema?\n (S/N) --> ");
    scanf("%c", &status);
    fflush(stdin);

    while ((status != 'S') && (status != 'N') && (status != 's') && (status != 'n'))
    {
        printf("\n\n opcao invalida (S/N)\n--> ");
        scanf("%c", &status);
        fflush(stdin);
    }
    if ((status == 's') || (status == 'S'))
    {
        p.status = 0, qnt_client++;
        printf("\n\nSalvo no sistema!\n");
    }
    return p;
}

int excluirCliente(CLIENTE ficha[])
{
    if (qnt_client == 0)
    {
        printf("Nao tem Clientes no cadastro!\n");
        return 0;
    }
    char cpf[15];
    int veri = NULL;
    printf("Insira o cpf do cliente que deseja excluir!\n");
    printf("INSIRA NO PADRAO (999.999.999-99)\n--> ");
    scanf("%s", cpf);
    fflush(stdin);
    for (int i = 0; i < TAM; i++)
    {
        if (ficha[i].status == 0)
        {
            veri = strstr(ficha[i].cpf, cpf);
            if (veri != NULL)
            {
                if (ficha[i].status == 1)
                {
                    printf("\n  | Não foi possivel apagar |");
                    printf("\nO Cliente ja Realizou uma compra!\n");
                    return -1;
                }
                else if (ficha[i].status == 0)
                {
                    printf("\nCliente Excluido do cadastro!\n");
                    ficha[i].status = -1;
                    return i;
                }
            }
        }
    }
    printf("\nNao tem Clientes com esse cpf no cadastro!\n");
    return -1;
}

void listarClienteOrdemCrescente(CLIENTE p[])
{
    CLIENTE aux;
    if (qnt_client == 0)
    {
        printf("Nao tem Clientes no cadastro!\n");
        return;
    }

    if (qnt_client > 0)
    {
        for (int i = 0; i < qnt_client - 1; i++)
        {
            for (int j = i + 1; j < qnt_client; j++)
            {
                if (strcmp(p[i].nome, p[j].nome) > 0)
                {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        if (p[i].status == 0)
        {
            printf("------------------------------------------------------------------------------");
            printf("\nNome: %s \
                    \nCPF:  %s\
                    \nEndereco: \
                    \nRua: %s\
                    \nNumero: %d\
                    \nBairro: %s\
                    \nCidade:  \
                    \nEstado: %s\
                    \nCEP: %s \
                    \nTelefone Residencial: %s\
                    \nTelefone Celular: %s \
                    \nRenda Mensal: %3.f \
                    \n",
                   p[i].nome, p[i].cpf, p[i].endereco.rua, p[i].endereco.numero, p[i].endereco.bairro, p[i].endereco.estado, p[i].endereco.cep, p[i].residencial.telefone, p[i].celular, p[i].renda_mensal);
        }
    }
    printf("------------------------------------------------------------------------------\n");
}

void listarsalario(CLIENTE p[]){


}

int main()
{
    CARRO garagem[TAM];
    CLIENTE ficha[TAM];
    int opcao = 0, i = 0, status = -1;
    char op = 'z';
    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        garagem[i].status = -1;
        ficha[i].status = -1;
    }

    do
    {
        printf("--------------------------\n");
        printf("      MENU PRINCIPAL\n");
        printf("--------------------------\n\n");
        printf("1. Carro\n");
        printf("2. Cliente\n");
        printf("3. Venda\n");
        printf("4. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            do
            {
                system("cls");
                printf("--------------------\n");
                printf("     1. Carro\n");
                printf("--------------------\n");
                printf("a. Inserir um carro no cadastro\n");
                printf("b. Excluir um carro do cadastro\n");
                printf("c. Listar os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo\n");
                printf("d. Listar os carros disponiveis para a venda por selecao de um ou mais opcionais\n");
                printf("e. Listar os carros disponiveis para a venda por selecao da faixa de ano de fabricacao\n");
                printf("f. Voltar\n");
                scanf("%c", &op);
                fflush(stdin);

                switch (op)
                {
                case 'a':
                    system("cls");
                    i = 0;
                    while ((garagem[i].status != -1) && (i < TAM))
                        i++;
                    garagem[i] = inserirCarro();
                    system("pause");
                    break;

                case 'b':
                    system("cls");
                    status = excluirCarro(garagem);
                    if (status >= 0)
                        garagem[status].status = -1;
                    status = -1;
                    system("pause");
                    break;

                case 'c':
                    system("cls");
                    listarCarrosOrdemCrescente(garagem);
                    system("pause");
                    break;

                case 'd':
                    system("cls");
                    listarCarrosOpcionais(garagem);
                    system("pause");
                    break;

                case 'e':
                    system("cls");
                    listarCarrosAnoFabricacao(garagem);
                    system("pause");
                    break;

                case 'f':
                    printf("Voltando ao menu...\n");
                    system("pause");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    system("pause");
                }
                system("cls");
            } while ((op != 'f') && (op != 'F'));

            break;

        case 2:
            do
            {
                system("cls");
                printf("--------------------\n");
                printf("     2. Cliente\n");
                printf("--------------------\n");
                printf("a. Inserir um cliente no cadastro\n");
                printf("b. Excluir um cliente do cadastro\n");
                printf("c. Listar os clientes do cadastro ordenados crescentemente pelo nome\n");
                // printf("d. Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal\n");
                printf("d. Voltar\n");
                scanf("%c", &op);
                fflush(stdin);

                switch (op)
                {
                case 'a':
                    system("cls");
                    i = 0;
                    while ((ficha[i].status != -1) && (i < TAM))
                        i++;
                    ficha[i] = inserir_cliente();
                    system("pause");
                    break;

                case 'b':
                    system("cls");
                    excluirCliente(ficha);
                    system("pause");
                    break;

                case 'c':
                    system("cls");
                    listarClienteOrdemCrescente(ficha);
                    if (status >= 0)
                        ficha[status].status = -1;
                    status = -1;
                    system("pause");
                    break;

                case 'd':
                    printf("Voltando ao menu...\n");
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    system("pause");
                }
            } while ((op != 'd') && (op != 'D'));
            break;
        case 3:
            // chamar funcoes relacionadas a Venda
            do{
                system("cls");
                printf("--------------------\n");
                printf("     2. Venda\n");
                printf("--------------------\n");
                printf("a. Inserir uma venda \n");
                printf("b. Excluir uma venda  \n");
                /*
                printf("c. Listar os carros vendidos de um determinado fabricante, ordenados crescentemente pelo modelo \
                    \n(as seguintes informações devem aparecer: modelo, placa, ano fabricação e nome cliente)\n");
                printf("d. Listar os carros vendidos de um determinado modelo, ordenados crescentemente pelo ano de fabricação \
                    \n(as seguintes informações devem aparecer: ano de fabricação, placa e nome cliente)\n");
                printf("e. Informar a quantidade de carros vendidos com o valor totalizado dos preços vendidos f. Informar o lucro total das vendas\n");
                */

                printf("c. Voltar ao menu\n--> ");
                scanf("%c", &op);
                fflush(stdin);
                system("cls");
                switch (op)
                {
                case 'a':
                    /* code */
                    break;
                case 'b':
                    /* code */
                    break;
                case 'c':
                    printf("Voltando ao menu...\n");
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    system("pause");
                    break;
                }
                
            } while((op != 'c') && (op != 'C'));
            break;

        case 4:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
