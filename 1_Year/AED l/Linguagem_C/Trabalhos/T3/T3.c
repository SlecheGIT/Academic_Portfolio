// includes...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

// variaveis saque
int notas[] = {500, 150, 50, 20, 10, 5, 2, 1};
int saquesRealizados[51] [50], contSaques[51][2];
int max_notas[8], total = 0;

// variaveis agencia
char conta_corrente[51] [10];

// variaveis do cpf
char cpfChar[51][15];
int numconta = 0;
char alterarDados[15];

void clear ()
{
    system("cls");
}

// objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
// parametros: nenhum
// retorno:a letra do alfabeto
char geraAlfabeto()
{
    int i;
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    i = rand() % 26;
    return (letras[i] - 32);
}

// objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
// parametros: nenhum
// retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    i = rand() % 9;
    return (numeros[i]);
}

// objetivo:verifica se a conta no formato 999.999-x e valido
// parametros: conta a ser verificado
// retorno:-2 se conta nao e valido

int verifica_conta_corrente(char conta[])
{
    int valido = -1;
    int con = 0;
    int conta_aux [7];
    for (int i = 0; i < numconta; i++){
        for (int c = 0; c < 9; c++){
            if (conta_corrente[i][c] == conta[c])
                con++;
            if (con==9)
                valido=i;
        }
        con=0;
    }
    conta_aux[0]= conta[0]-'0';
    conta_aux[1]= conta[1]-'0';
    conta_aux[2]= conta[2]-'0';
    conta_aux[3]= conta[4]-'0';
    conta_aux[4]= conta[5]-'0';         
    conta_aux[5]= conta[6]-'0';

    for (int i = 0; i < 6; i++)
        if (conta_aux[i]<0 || conta_aux[i]>9)
            valido=-2;

    if (conta[3]!='.')
        valido=-2;
    if (conta[7]!='-')
        valido=-2;

    
    if (conta[8] < 'A' || conta[8] > 'Z')
        valido=-2;

    return (valido);
}

// objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
// parametros: c onde armazera a conta gerada
// retorno:nenhum
void geraContaCorrente(char c[])
{
    int valido = 1;
    do {
        conta_corrente[numconta][0]= geraNumero();
        conta_corrente[numconta][1]= geraNumero();
        conta_corrente[numconta][2]= geraNumero();
        conta_corrente[numconta][3]= '.';
        conta_corrente[numconta][4]= geraNumero();
        conta_corrente[numconta][5]= geraNumero();
        conta_corrente[numconta][6]= geraNumero();
        conta_corrente[numconta][7]='-';
        conta_corrente[numconta][8]= geraAlfabeto();
        c[0]++;
        valido=verifica_conta_corrente(conta_corrente[numconta]);
    } while (valido==0);
}   

// objetivo:verifica se um cpf no formato 999.999.999-99 e valido
// parametros: cpf a ser verificado
// retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    int valido = -1, con = 0;
    int dig1 = 0, dig2 = 0, ccpf[12];
    // implemente aqui
    for (int i = 0; i < numconta; i++){
        for (int c = 0; c < 14; c++){
            if (cpfChar[i][c] == cpf[c])
                con++;
            if (con==14)
                valido=i;
        }
        con = 0;
    }
    ccpf[0] = cpf[0] - '0';
    ccpf[1] = cpf[1] - '0';
    ccpf[2] = cpf[2] - '0';
    ccpf[3] = cpf[4] - '0';
    ccpf[4] = cpf[5] - '0';
    ccpf[5] = cpf[6] - '0';
    ccpf[6] = cpf[8] - '0';
    ccpf[7] = cpf[9] - '0';
    ccpf[8] = cpf[10] - '0';
    ccpf[9] = cpf[12] - '0';
    ccpf[10] = cpf[13] - '0';

    for (int i = 1; i < 11; i++)
    {
        if(ccpf[i]==ccpf[0])
            con++;
        
        if(con>=10)
            valido=-2;
    }
    if ((cpf[3]!= '.') || (cpf[7] != '.') || (cpf[11] != '-'))
        valido = -2;

    for (int i = 0, i1 = 10, i2 = 2; i < 9; i++, i1--, i2++)
    {
        dig1 += ccpf[i] * i1;
        dig2 += ccpf[i] * i2;
    }
    dig1 = dig1 % 11;
    dig2 = dig2 % 11;
    if (dig1 < 2)
        dig1 = 0;
    else
        dig1 = 11 - dig1;
    
    if (dig2 < 2)
        dig2 = 0;
    else
        dig2 = 11 - dig2;

    if ((dig1 != ccpf[9]) || (dig2 != ccpf[10]))
        valido = -2;

    return (valido);
}

// objetivo:insere pontuacoes '.' e '- ' em um cpf
// parametros: cpf_origem o cpf recebido no format 99999999999
//             cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{
    // implemente aqui
    cpfChar[numconta][0] = cpf_origem[0];
    cpfChar[numconta][1] = cpf_origem[1];
    cpfChar[numconta][2] = cpf_origem[2];
    cpfChar[numconta][3] = '.';
    cpfChar[numconta][4] = cpf_origem[3];
    cpfChar[numconta][5] = cpf_origem[4];
    cpfChar[numconta][6] = cpf_origem[5];
    cpfChar[numconta][7] = '.';
    cpfChar[numconta][8] = cpf_origem[6];
    cpfChar[numconta][9] = cpf_origem[7];
    cpfChar[numconta][10] = cpf_origem[8];
    cpfChar[numconta][11] = '-';
    cpfChar[numconta][12] = cpf_origem[9];
    cpfChar[numconta][13] = cpf_origem[10];
    cpf_destino[0] = 0;
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

// objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: cpf onde sera armazenado o cpf valido
// retorno: nenhum
void gera_cpf_valido(char cpf[]) {
    // implemente aqui
    int valido = 0;
    char dig[11] = {};
    do {
        for (int i=0; i<9;i++)
            dig[i] = geraNumero();

        dig[9] = obtem_primeiro_digito_verificador(dig) + '0';
        dig[10] = obtem_segundo_digito_verificador(dig) + '0';

        insere_pontuacao_cpf(dig, cpf);
        valido = verifica_cpf_valido(cpfChar[numconta]);
    
    } while (valido != -1);
}
// funcao do menu cliente que exclui a conta corrente
void excluir(int vet) 
{
    
    for (int i = vet; i < numconta; i++){
        strcpy(cpfChar[i], cpfChar[i+1]);
        strcpy(conta_corrente[i], conta_corrente[i+1]);


        for (int c = 0; c < contSaques[i+1][1]; c++)
        {
            saquesRealizados[i][c] = saquesRealizados[i+1][c];
        }
        contSaques[i][0]= contSaques[i+1][0];
        contSaques[i][1]= contSaques[i+1][1];
    
    }
    numconta--;
}
// funcao que decompoe e escreve o valor por Extenso 
void Extenso(int saldo) 
{
    int a01, a02, a03, a04, a05, a06;
    if (saldo!=0) {
        a06 = (saldo % 1000000) / 100000;
        a05 = (saldo % 100000) / 10000;
        a04 = (saldo % 10000) / 1000;
        a03 = (saldo % 1000) / 100;
        a02 = (saldo % 100) / 10;
        a01 = (saldo % 10);

        if (a06 == 1)
        {
            if (a05 == 0 && a04 == 0)
                printf("CEM ");
            else
                printf("CENTO E ");
        } else if (a06 == 2)
            printf("DUZENTOS ");
        else if (a06 == 3)
            printf("TREZENTOS ");
        else if (a06 == 4)
            printf("QUATROCENTOS ");
        else if (a06 == 5)
            printf("QUINHENTOS ");
        else if (a06 == 6)
            printf("SEISCENTOS ");
        else if (a06 == 7)
            printf("SETECENTOS ");
        else if (a06 == 8)
            printf("OITOCENTOS ");
        else if (a06 == 9)
            printf("NOVECENTOS ");
        
        if ((a06!=1 && a06!=0) && (a05!=0 || a04!=0))
            printf("E ");

        if (a05 == 1)
        {
            if (a04 == 0)
                printf("DEZ ");
            else if (a04 == 1)
                printf("ONZE ");
            else if (a04 == 2)
                printf("DOZE ");
            else if (a04 == 3)
                printf("TREZE ");
            else if (a04 == 4)
                printf("QUATORZE ");
            else if (a04 == 5)
                printf("QUINZE ");
            else if (a04 == 6)
                printf("DEZESSEIS ");
            else if (a04 == 7)
                printf("DEZESSETE ");
            else if (a04 == 8)
                printf("DEZOITO ");
            else if (a04 == 9)
                printf("DEZENOVE ");
        }
        else if (a05 == 2)
            printf("VINTE ");
        else if (a05 == 3)
            printf("TRINTA ");
        else if (a05 == 4)
            printf("QUARENTA ");
        else if (a05 == 5)
            printf("CINQUENTA ");
        else if (a05 == 6)
            printf("SESSENTA ");
        else if (a05 == 7)
            printf("SETENTA ");
        else if (a05 == 8)
            printf("OITENTA ");
        else if (a05 == 9)
            printf("NOVENTA ");

        if ((a05 != 1 && a05 != 0) && a04 != 0)
            printf("E ");

        if (a05 != 1)
        {
            if (a04 == 1 && a05 != 0)
                printf("UM ");
            else if (a04 == 2)
                printf("DOIS ");
            else if (a04 == 3)
                printf("TRES ");
            else if (a04 == 4)
                printf("QUATRO ");
            else if (a04 == 5)
                printf("CINCO ");
            else if (a04 == 6)
                printf("SEIS ");
            else if (a04 == 7)
                printf("SETE ");
            else if (a04 == 8)
                printf("OITO ");
            else if (a04 == 9)
                printf("NOVE ");
        }
        if (a04 != 0 || a05 != 0 || a06 != 0) {
            if ((a03!=0 && a02==0 && a01==0))
                printf("MIL E ");
            else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                printf("MIL ");
            else if (a03==0 )
                printf("MIL E ");
        }
        if (a03 == 1)
        {
            if (a02 == 0 && a01 == 0)
                printf("CEM ");
            else
                printf("CENTO ");
        }
        if (a03 == 2)
            printf("DUZENTOS ");
        else if (a03 == 3)
            printf("TREZENTOS ");
        else if (a03 == 4)
            printf("QUATROCENTOS ");
        else if (a03 == 5)
            printf("QUINHENTOS ");
        else if (a03 == 6)
            printf("SEISCENTOS ");
        else if (a03 == 7)
            printf("SETECENTOS ");
        else if (a03 == 8)
            printf("OITOCENTOS ");
        else if (a03 == 9)
            printf("NOVECENTOS ");
        if (a03 != 0 && !(a02 == 0 && a01 == 0))
            printf("E ");

        if (a02 == 1) {
            if (a01 == 0)
                printf("DEZ ");
            else if (a01 == 1)
                printf("ONZE ");
            else if (a01 == 2)
                printf("DOZE");
            else if (a01 == 3)
                printf("TREZE ");
            else if (a01 == 4)
                printf("QUATORZE ");
            else if (a01 == 5)
                printf("QUINZE");
            else if (a01 == 6)
                printf("DEZESSEIS ");
            else if (a01 == 7)
                printf("DEZESSETE ");
            else if (a01 == 8)
                printf("DEZOITO ");
            else if (a01 == 9)
                printf("DEZENOVE ");
        }
        else if (a02 == 2)
            printf("VINTE ");
        else if (a02 == 3)
            printf("TRINTA ");
        else if (a02 == 4)
            printf("QUARENTA ");
        else if (a02 == 5)
            printf("CINQUENTA ");
        else if (a02 == 6)
            printf("SESSENTA ");
        else if (a02 == 7)
            printf("SETENTA ");
        else if (a02 == 8)
            printf("OITENTA ");
        else if (a02 == 9)
            printf("NOVENTA ");

        if (a02 != 0 && a02 != 1 && a01 != 0)
            printf("E ");
        if (a02 != 1)
        {
            if (a01 == 1)
                printf("UM ");
            else if (a01 == 2)
                printf("DOIS ");
            else if (a01 == 3)
                printf("TRES ");
            else if (a01 == 4)
                printf("QUATRO ");
            else if (a01 == 5)
                printf("CINCO ");
            else if (a01 == 6)
                printf("SEIS ");
            else if (a01 == 7)
                printf("SETE ");
            else if (a01 == 8)
                printf("OITO ");
            else if (a01 == 9)
                printf("NOVE ");
        }
    } else
        printf("ZERO REAIS ");
}
// funcao do menu saque
void Saques(int saque, int posicao) 
{
    int qnt_saque[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int saqueCopy = saque;
    for (int i = 0; i <8; i++)
    {
        qnt_saque[i] = saque / notas[i];
        saque %= notas[i];
        if (qnt_saque[i] > max_notas[i]) 
        {   //coloca a quantia disponivel e zera a quantia de cedulas, devolve o modulo
            saque += (qnt_saque[i] - max_notas[i]) * notas[i];
            qnt_saque[i] = max_notas[i];
            max_notas[i] = 0;
        }
        else
            max_notas[i] -= qnt_saque[i];
    }
    if (saque != 0) {
        total+=saqueCopy; // devolve o valor quando nao a cedulas suficientes para o saque
        for (int i = 0; i < 8; i++)
            max_notas[i] += qnt_saque[i], qnt_saque[i]=0;
        system("cls");
        printf("\nPara o valor de %d reais: ", saqueCopy);
        printf("\n Troco insuficiente...\n\n");
        system("pause");

    } else {
        printf("\nForam sacadas: \n");
        for (int i = 0; i < 8; i++)
            printf("( %d ) nota(s) de %d \n", qnt_saque[i] , notas[i]);
        printf("O Valor sacado eh de (%d): \n", saqueCopy);
        Extenso(saqueCopy);
        printf("REAIS\n\n");
        total-= saqueCopy;
        saquesRealizados[posicao][contSaques[posicao][1]] = saqueCopy;
        contSaques[posicao][0] += saqueCopy;
        contSaques[posicao][1]++;
    }
    
}

//______________________________________________________________//
int main()
{
    srand(time(NULL));
    // variaveis do menu
    int menu, cliente, relatorio;
    int verifica = 0, posicao = 0;
    char cpf[] = {0}, corrente[] = {0};
    // variaveis saque
    int saldo;

    max_notas[0] = 100;
    for (int i = 1; i < 8; i++)
        max_notas[i] = max_notas[i - 1] * 2; // alocando as notas mais rapidamente por serem o dobro uma da outra
    for (int i = 0; i < 8; i++)
        total += notas[i] * max_notas[i]; // valor maximo do caixa
    for (int i = 0; i < 50; i++){ // zerando saques
        saquesRealizados[i][0]=0;
        contSaques[i][0] = 0;
        contSaques[i][1] = 0;
    }

    do {
        printf("MENU PRINCIPAL\n\n");
        printf("1-Cliente \n");
        printf("2-Saque \n");
        printf("3-Relatorios \n");
        printf("4-Finalizar \n--> ");
        scanf("%d", &menu);
        
        switch (menu) {
            // menu cliente
        case 1: 
            do {
                clear();
                printf("MENU CLIENTE\n\n");
                printf("1-Incluir \n");
                printf("2-Mostrar \n");
                printf("3-Alterar \n");
                printf("4-Excluir \n");
                printf("5-Voltar \n--> ");
                scanf("%d", &cliente);
                clear();
            
                switch (cliente)
                {
                    // inclui conta corrente valida no banco
                case 1:
                    if (numconta <50) {
                        gera_cpf_valido(cpf);
                        geraContaCorrente(corrente);
                        printf("Novo cliente cadastrado!!\n");
                        printf("Conta corrente : %s\nCpf: %s\n", conta_corrente[numconta], cpfChar[numconta]);
                        numconta++;
                    } else
                        // limita o numero de contas a 50 usuarios
                        printf("Numero de Clientes execede o limite");
                    system("pause");
                    break;

                case 2:
                    // mostra todas as contas e cpfs cadastrados ate o momento
                    if (numconta!= 0)
                    {
                        for (int i = 0; i < numconta; i++){
                            printf("--------------------\n");
                            printf("Cliente %d\n\n", i+1);
                            printf("Conta: %s \n", conta_corrente[i]);
                            printf("CPF: %s\n", cpfChar[i]);
                            printf("Total sacado: %d\n", contSaques[i][0]);
                            printf("--------------------\n\n");
                        }
                    } else
                        // apresenta a ausencia de contas cadastradas
                        printf("nao ha CPF(s) cadastrados!!\n\n");
                    
                    system("pause");
                    break;

                case 3:
                    // altera uma conta corrente ou cpf cadastrado
                    clear();
                    printf("nos formatos '999.999.999-99' (do cpf) e '999.999-x' (da conta corrente)!\n");
                    printf("         Insira o numero da conta ou cpf que deseja ALTERAR\n--> ");
                    scanf("%s", alterarDados);
                    
                    // altera cpf
                    if(strlen(alterarDados) == 14)
                    {   
                        posicao = verifica_cpf_valido(alterarDados);
                        printf("\n\n%d\n\n", posicao);
                        if (saquesRealizados[posicao][0] == 0)
                        {
                            if (posicao== -1)
                            {
                                clear();
                                printf("\n\n [erro]\nCpf nao cadastrado\n");
                                system("pause");
                                break;
                            } else if (posicao== -2)
                            {
                                printf("\n\n [erro]\nCpf invalido\n");
                                system("pause");
                                break;
                            }
                            printf("\n\nQual sera o novo cpf?\n--> ");
                            scanf("%s", alterarDados);
                            verifica = verifica_cpf_valido(alterarDados);
                            
                            if (verifica == -1) 
                            {
                                strcpy(cpfChar[posicao], alterarDados);
                                printf("\n\nNovo cpf cadastrado\n");
                            } else if (verifica == -2)
                                printf("\n\n [erro]\nCPF invalido!\n");
                            else
                                printf("\n\n [erro]\nCPF ja existente\n");
                        } else
                            printf("\n\n [erro]\nEssa conta ja realizou saques\n");                 
    
                        // altera conta corrente
                    } else if (strlen(alterarDados) == 9) 
                    {   posicao = verifica_conta_corrente(alterarDados);
                        if (saquesRealizados[posicao][0] == 0)
                        {
                            if (posicao== -1)
                            {
                                printf("\n\n [erro]\nConta corrente nao cadastrada\n");
                                system("pause");
                                break;
                            } else if (posicao== -2)
                            {
                                printf("\n\n [erro]\nConta corrente invalido\n");
                                system("pause");
                                break;
                            }
                            printf("\n\nQual sera a nova conta?\n--> ");
                            scanf("%s", alterarDados);
                            verifica = verifica_conta_corrente(alterarDados);

                            if (verifica == -1) 
                            {
                                strcpy(conta_corrente[posicao], alterarDados);
                                printf("\n\nNova conta corrente cadastrado\n");
                            } else if (verifica == -2)
                                printf("\n\n [erro]\nConta Corrente invalida!\n");
                            else
                                printf("\n\n [erro]\nConta Corrente ja existente\n");
                        } else
                            printf("\n\n [erro]\nEssa conta ja realizou saques\n");                 
     

                    } else 
                        printf("\n\n [erro]\nDados fora do padrao requisitado!\n");

                    system("pause");
                    break;

                case 4:
                    // exlui conta corrente
                    clear();
                    printf("nos formatos '999.999-x' (da conta corrente)!\n");
                    printf("Insira o numero da conta que deseja EXCLUIR\n--> ");
                    scanf("%s", alterarDados);
                    
                    if(strlen(alterarDados) == 9)
                    {   
                        posicao = verifica_conta_corrente(alterarDados);
                        if (posicao== -1)
                            printf("\n\n [erro]\nconta nao cadastrada\n");
                        else if (posicao== -2)
                        {
                            printf("\n\n [erro]\nConta corrente invalido\n");
                            system("pause");
                            break;
                        }
                        else if (saquesRealizados[posicao][0] != 0)
                            printf("\n\n [erro]\nEssa conta ja realizou saques\n");   

                        else {
                            if (posicao >= 0)
                               excluir(posicao); 
                            printf("\n\nConta excluida com sucesso\n");
                        }
                        // verifica se a conta atende ao padrao 999.999-x
                    } else 
                        printf("\n\n [erro]\ndados fora do padrao requisitado!\n");

                    system("pause");
                    break;

                case 5:
                    break;

                default:
                    printf("\n[Escolha invalida]\nselecione novamente\n\n");
                    system("pause");
                    break;
                }
            } while(cliente!=5);
            break;

        case 2:
            // menu saque
            clear();
            if (numconta==0) 
                printf("[erro]\nNao ha contas cadastradas!!");
            else 
            {
                printf("Insira a conta que deseja realizar o saque\n--> ");
                scanf("%s", alterarDados);
                posicao = verifica_conta_corrente(alterarDados);

                if (posicao== -1)
                    printf("\n\n [erro]\nconta nao cadastrada\n");
                else if (posicao == -2)
                    printf("\n\n [erro]\nformato da conta invalido\n");
                else 
                {
                    printf("\n\nQuanto deseja sacar?\n--> ");
                    scanf("%d", &saldo);

                    if (total>=saldo)
                        Saques(saldo, posicao);
                    else
                        printf("\n [erro]\nSaldo do caixa insuficiente para o saque\n"); 
                }
            }
            system("pause");
            clear();
            break;
            

        case 3:
            // menu de relatorios
            do {
                clear();
                printf("MENU RELATORIOS\n\n");
                printf("1-Valores sacados\n");
                printf("2-Valor do saldo existente\n"); 
                printf("3-Quantidade de cedulas existentes\n");
                printf("4-Voltar ao menu principal\n--> ");
                scanf("%d", &relatorio);
                clear();
                switch (relatorio)
                {
                    case 1:
                    // apresenta a conta corrente, o cpf, e os saques realizados por todos os clientes
                        printf("------------------------------------------------------------------------\n");
                        printf("Relatorio 'Valores sacados'\n");
                        printf("------------------------------------------------------------------------\n\n");
                        if (numconta>0){
                            for (int i = 0; i < numconta; i++)
                            {
                                printf("%s  %s  ", conta_corrente[i], cpfChar[i]);
                                if (contSaques[i][0] != 0)
                                {
                                    printf("R$ %d\n", saquesRealizados[i][0]);
                                    
                                    for (int c = 1; c < contSaques[i][1]; c++)
                                        printf("                           R$ %d\n", saquesRealizados[i][c]);
                                    printf("                                          R$ %d\n\n", contSaques[i][0]);
                                } else 
                                    printf("Nao realizou saques\n\n");
                            }
                        } else
                        printf("Sem clientes cadastrados\n\n");
                        printf("------------------------------------------------------------------------\n");
                        printf("Sacado:\n");
                        printf("R$ %d ", 173600-total);
                        Extenso(173600-total);
                        printf("\n");
                        printf("------------------------------------------------------------------------\n");
                        system("pause");
                        break;
                    
                    case 2:
                        // apresenta o valor disponivel em caixa
                        printf("------------------------------------------------------------------------\n");
                        printf("Relatorio 'Valor do saldo existente '\n");
                        printf("------------------------------------------------------------------------\n");
                        printf("\nR$ %d  ", total);
                        Extenso(total);
                        printf("REAIS\n\n");
                        printf("------------------------------------------------------------------------\n");
                        system("pause");
                        break;
                    
                    case 3:
                        // apresenta a quantia de cedulas disponiveis em caixa
                        printf("------------------------------------------------------------------------\n");
                        printf("Relatorio 'Quantidade de cedulas existentes'\n");
                        printf("------------------------------------------------------------------------\n\n");
                        for (int i = 0; i < 8; i++)
                        {
                            printf("Cedula: %d quantidade: %d ",notas[i], max_notas[i] );
                            Extenso(max_notas[i]);
                            printf("CEDULAS\n");
                        }
                        printf("\n------------------------------------------------------------------------\n");
                        system("pause");
                        break;

                    case 4:
                        break;

                    default:
                        printf("\n [erro]\nopcao invalida\n");
                        system("pause");
                        break;
                }
                clear();
            }while (relatorio!=4);
            break;

        case 4:
            printf("\n\nFinalizando o programa...");
            return 0;
            break;

        default: 
            printf("\n [Escolha invalida]\nselecione novamente\n\n");
            system("pause");
            clear();
            break;
        }
    }while (1);
}
//______________________________________________________________//