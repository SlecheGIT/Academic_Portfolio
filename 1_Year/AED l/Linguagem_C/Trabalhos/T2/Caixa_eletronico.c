#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    bool pass = false;
    int menu, i; // variaveis de menu

    int cpf[12], d1 = 0, d2 = 0; // variaveis de cpf
    char cpfchar[12];

    int notas[] = {500, 150, 50, 20, 10, 5, 2, 1}; // variaveis de saque
    int a01, a02, a03, a04, a05, a06;
    int saque, qnt_saque[8];
    int max_notas[8], total = 0;

    max_notas[0] = 100;
    for (i = 1; i < 8; i++)
        max_notas[i] = max_notas[i - 1] * 2; // alocando as notas mais rapidamente por serem o dobro uma da outra
    for (i = 0; i < 8; i++)
        total += notas[i] * max_notas[i]; // valor maximo do caixa
    do {
        do {
            printf("\n|----------------|\n");
            printf("| MENU PRINCIPAL | ");
            printf("\n|----------------|\n");
            printf(" (1 - Saque)\n");
            printf(" (2 - Gerente)\n");
            printf(" (3 - Finalizar)\n --> ");
            scanf("%d", &menu);

            if ((menu < 1 || menu > 3)) {
                system("cls");
                printf("\n| OPCAO INVALIDA |\n");
            }            

        } while (menu < 1 || menu > 3);

        switch (menu)
        {
            // selecao de menu
        case 1:
            system("cls");
            printf("\n------------------------\n");
            printf("Para cancelar (DIGITE 0)");
            printf("\n------------------------\n");
            printf("\n* Somente os numeros *");
            printf("\nDigite seu CPF: ");
            

            do {
                d1 = 0, d2 = 0; //verificacao do CPF
                do {
                    scanf("%s", cpfchar);
                    if (atoi(cpfchar) == 0)
                        break;
                    
                    else if (strlen(cpfchar) != 11)
                    {
                        system("cls");
                        printf("\n------------------------\n");
                        printf("Para cancelar (DIGITE 0)");
                        printf("\n------------------------\n");
                        printf("\nO CPF deve conter 11 digitos!\nDigite Novamente: ");
                    }
                } while (strlen(cpfchar) != 11);
                if (atoi(cpfchar) == 0)
                    break;
                for (i = 0; i < 11; i++)
                {
                    cpf[i] = cpfchar[i] - '0';
                    if (cpf[i] != cpf[0])
                        pass = true;
                }

                for (int i1 = 10, i2 = 2, i = 0; (i < 9); i++, i1--, i2++)
                {
                    d1 += cpf[i] * i1;
                    d2 += cpf[i] * i2;
                }
                if ((d1 % 11) < 2)
                    d1=0;
                else
                    d1 = 11 - (d1 % 11);
                if ((d2 % 11) < 2)
                    d2=0;
                else
                    d2 = 11 - (d2 % 11);
                if (((d1 != cpf[9]) || (d2 != cpf[10])) || pass == false)
                {
                    system("cls");
                    printf("\n------------------------\n");
                    printf("Para cancelar (DIGITE 0)");
                    printf("\n------------------------\n");
                    printf("\nCPF Invalido\n\nDigite o CPF Novamente: ");
                    pass = false;
                }
                d1 = 0, d2 = 0;
            } while (pass != true);
            pass = false;
            system("cls");

            if (atoi(cpfchar) == 0)
            {  //retorna ao menu inicial
                printf("     Retornando ao menu...\n"), i = 0;
                system("pause");
                break;
            }
            printf(" *  CPF Aprovado  *\n ");

            i = 0;
            do {
                if (total != 0) {
                    printf("\n------------------------\n");
                    printf("Para cancelar (DIGITE 0)");
                    printf("\n------------------------\n");
                    do { //efetuacao do saque
                        printf("\n Insira o valor do saque:\n -->");
                        scanf("%d", &saque);

                        if (saque < 0)
                        {
                            system("cls"); 
                            printf("\n------------------------\n");
                            printf("Para cancelar (DIGITE 0)");
                            printf("\n------------------------");
                            printf("\n |   VALOR INVALIDO   |");
                            printf("\n Valor abaixo de zero! \n");
                        }
                        else if (saque > total)
                        {
                            system("cls");
                            printf("\n------------------------\n");
                            printf("Para cancelar (DIGITE 0)");
                            printf("\n------------------------\n");
                            printf("\n |   VALOR INVALIDO   |");
                            printf("\n Valor acima do limite\n disponivel no caixa!\n");
                            printf("\n LIMITE ATUAL: %d REAIS", total);
                        }
                    } while (saque < 0 || saque > total); //verificacao de validade
                    if (saque == 0) {
                        printf("\n Retornando ao menu...\n"), i = 0;
                        system("pause");
                        break;
                    }
                    total -= saque, d1 = saque; //atualizando valor disponivel em caixa
                    
                    for (i = 0; i < 8; i++)
                    {
                        qnt_saque[i] = d1 / notas[i];
                        d1 %= notas[i]; //modulo do valor sacado, e fornece o menor valor de cedulas possivel

                        if (qnt_saque[i] > max_notas[i]) 
                        {   //coloca a quantia disponivel e zera a quantia de cedulas, devolve o modulo
                            d1 += (qnt_saque[i] - max_notas[i]) * notas[i];
                            qnt_saque[i] = max_notas[i];
                            max_notas[i] = 0;
                        }
                        else
                            max_notas[i] -= qnt_saque[i]; //subtrai o valor sacado das notas
                    }
                    if (d1!=0) {
                        total+=saque; // devolve o valor quando nao a cedulas suficientes para o saque
                        for ( i = 0; i < 8; i++)
                            max_notas[i] += qnt_saque[i];
                        system("cls");
                        printf("\nPara o valor de %d reais: ", saque);
                        printf("\n Troco insuficiente...\n\n");
                        system("pause");
                        break;
                    }
                    system("cls");
                    printf("\n----------------------------------------\n\n");
                    printf("Para o valor de %d reais, Foram sacadas: \n", saque);
                    
                    for (i = 0; i < 8; i++)
                    {
                        switch (i)  //apresenta a quantia e valor de cada nota sacada
                        {
                        case 0:
                            if (qnt_saque[i] != 0) // quando igual a 0 valor nao aparece na saida
                                printf("\n| %d | -> Nota(s) de quinhentos reais (500)", qnt_saque[i]);
                            break;
                        case 1:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de cento e cinquenta reais (150) ", qnt_saque[i]);
                            break;
                        case 2:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de cinquenta reais (50)", qnt_saque[i]);
                            break;
                        case 3:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de vinte reais (20)", qnt_saque[i]);
                            break;
                        case 4:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de dez reais (10)", qnt_saque[i]);
                            break;
                        case 5:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de cinco reais (5)", qnt_saque[i]);
                            break;
                        case 6:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de dois reais (2)", qnt_saque[i]);
                            break;
                        case 7:
                            if (qnt_saque[i] != 0)
                                printf("\n| %d | -> Nota(s) de um real (1)", qnt_saque[i]);
                            break;
                        }
                    } //decomponhe o valor do saque para a escrita por extenso
                    printf("\n\nSaque total:\nR$ ");
                    a06 = (saque % 1000000) / 100000;
                    a05 = (saque % 100000) / 10000;
                    a04 = (saque % 10000) / 1000;
                    a03 = (saque % 1000) / 100;
                    a02 = (saque % 100) / 10;
                    a01 = (saque % 10);

                    if (a06 == 1){ 
                        if (a05 == 0 && a04 == 0) //centenas
                            printf("CEM ");
                        else
                            printf("CENTO E ");
                    }
                    if (a05 == 1)
                    {
                        if (a04 == 0) //dezenas
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
                    else if (a05 == 2) // dezenas a passo 10
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
                        printf("E ");// separacao

                    if (a05 != 1)
                    {
                        if (a04 == 1 && a05 != 0) // unidade
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
                        if ((a03!=0 && a02==0 && a01==0)) // milhares
                            printf("MIL E ");
                        else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                            printf("MIL ");
                        else if (a03==0 )
                            printf("MIL E "); // separacao
                    }
                    if (a03 == 1)
                    {
                        if (a02 == 0 && a01 == 0)
                            printf("CEM ");
                        else
                            printf("CENTO ");
                    }
                    if (a03 == 2)  // centenas
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
                        printf("E "); // separacao

                    if (a02 == 1) {
                        if (a01 == 0) // dezenas
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
                    else if (a02 == 2) // dezenas passo 10
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
                        printf("E "); // separacao
                    if (a02 != 1)
                    {
                        if (a01 == 1) // unidade
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
                    printf("\n\n----------------------------------------\n");

                    do {
                        printf("\n\nPara voltar ao menu (DIGITE 0)");
                        printf("\nPara Sacar novamente (DIGITE 1)");
                        printf("\nEscolha uma opcao acima: ");
                        scanf("%d", &i);
                        if ((i < 0 || i > 1))
                        {
                            system("cls");
                            printf("     |OPCAO INVALIDA|");
                        }
                    } while (i < 0 || i > 1); //verificacao de entradas, retorne ao menu ou saque novamente
                    system("cls");
                } else { //encerra a opcao de saque, quando nao a mais valor em caixa
                    printf("-->  CAIXA VAZIO!!! <--\n\n");
                    printf("   Retornando ao menu...\n"), i = 0;
                    system("pause");
                }
            } while (i);
            break;

        case 2: //menu gerente
            do { 
                system("cls");
                do{
                    printf("\n|----------------|\n");
                    printf("|  MENU GERENTE  | ");
                    printf("\n|----------------|\n\n");
                    printf("(1 - Valor Total Sacado)\n");
                    printf("(2 - Saldo Existente)\n");
                    printf("(3 - Cedulas Existentes)\n");
                    printf("(4 - Abastecer Caixa)\n");
                    printf("(5 - Voltar ao menu principal)\n --> ");
                    scanf("%d", &menu);
                    system("cls");
                    if (menu < 1 || menu > 5)
                        printf("\n|OPCAO INVALIDA|\n");
        
                }while (menu<1 || menu>5);
                // valor do saldo existente
                // valor total sacado
                if (menu==1)
                {
                    saque=173600-total;
                    printf("*---------------------------------------*\n\n");
                    printf("Valor total sacado: R$ %d \n\nRetirado do caixa:\n", saque); 
                } else if (menu==2) {
                    saque = total;
                    printf("*---------------------------------------*\n\n");
                    printf("Valor do saldo existente: R$ %d \n\nRestando no caixa:\n", saque);
                }
                if ((menu==1 || menu==2)) // decomponhe os valores de saldo e total sacado, para a escrita
                {   
                    if (saque!=0) {
                        a06 = (saque % 1000000) / 100000;
                        a05 = (saque % 100000) / 10000;
                        a04 = (saque % 10000) / 1000;
                        a03 = (saque % 1000) / 100;
                        a02 = (saque % 100) / 10;
                        a01 = (saque % 10);
                        if (a06 == 1)
                        {
                            if (a05 == 0 && a04 == 0)
                                printf("CEM ");
                            else
                                printf("CENTO E ");
                        }
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
                        printf("REAIS");
                    } else
                        printf("ZERO REAIS"); //quando o valor disponivel ou sacado e nulo
                        
                    printf("\n\n*---------------------------------------*\n");
                    printf("\n   Para voltar ao menu do gerente\n"); 
                    system("pause"); //retorna ao menu
                    system("cls");
                }
                switch (menu) {
                case 3:
                    // quantidade de cedulas existentes
                    system("cls");
                    printf("*-----------------------------------------------*\n\n");
                    printf("  Valor  | Cedulas\n  -------|--------");
                    for (i=0; i<8; i++) 
                    {    
                        printf("\n   %d   ", notas[i]);
                        if (i>=2)
                            printf(" ");
                        if (i>=5)
                            printf(" ");
                        printf("| ( %d ) ", max_notas[i]); //escreve o valor numerico das notas disponiveis
                        if (max_notas[i]!=0) {// decomponhe para a escrita por extenso
                            a06 = (max_notas[i] % 1000000) / 100000;
                            a05 = (max_notas[i] % 100000) / 10000;
                            a04 = (max_notas[i] % 10000) / 1000;
                            a03 = (max_notas[i] % 1000) / 100;
                            a02 = (max_notas[i] % 100) / 10;
                            a01 = (max_notas[i] % 10);

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
                            printf("ZERO "); // caso o valor seja nulo
                    }                    
                    printf("\n\n*-----------------------------------------------*\n\n");
                    printf("\n   Para voltar ao menu do gerente\n");
                    system("pause");// retorna ao menu gerente
                    system("cls");
                    break;
                case 4:
                //reabastece as cedulas
                    do{
                        do {
                        pass=false; //menu para reabastecer as cedulas
                        printf("*---------------------------------------*\n\n");
                        printf(" (500) - Cedulas de 500 \n");
                        printf(" (150) - Cedulas de 150 \n");
                        printf(" (50)  - Cedulas de 50 \n");
                        printf(" (20)  - Cedulas de 20 \n");
                        printf(" (10)  - Cedulas de 10 \n");
                        printf(" (5)   - Cedulas de 5 \n");
                        printf(" (2)   - Cedulas de 2 \n");
                        printf(" (1)   - Cedulas de 1 \n\n");
                        printf(" (0)   - Voltar ao menu gerente\n\n" );
                        printf("*---------------------------------------*\n\n --> ");
                        scanf("%d", &i);
                        system("cls");
                        if (i!=500 && i!=150 && i!=50 && i!=20 && i!=10 && i!=5 && i!=2 && i!=1 && i!= 0)
                            printf("   | OPCAO INVALIDA |   \n\n"); // verificacao do valor das notas
                        else
                            pass=true;
                        } while(pass==false);
                        if (i==0) // retorna ao menu gerente
                            break;
                        
                        if (i==500) // 
                            i=0; //seleciona o tipo de notas para 500
                        else if (i==150) 
                            i=1; //seleciona o tipo de notas para 150
                        else if (i==50)
                            i=2; //seleciona o tipo de notas para 50
                        else if (i==20)
                            i=3; //seleciona o tipo de notas para 20
                        else if (i==10)
                            i=4; //seleciona o tipo de notas para 10
                        else if (i==5)
                            i=5; //seleciona o tipo de notas para 5
                        else if (i==2)
                            i=6; //seleciona o tipo de notas para 2
                        else if (i==1)
                            i=7; //seleciona o tipo de notas para 1
                        if (max_notas[i] == (100*pow(2, i))){ //(100*pow(2, i)) calcula o limite de cedulas que podem ser depositadas
                            printf("*---------------------------------------*\n");
                            printf("\nAs cedulas de ( %d ) estao CHEIAS!\n\n", notas[i]);
                            printf("*---------------------------------------*\n");

                        }else {
                            do {
                                printf("\n   | Cedulas de %d |", notas[i]);  // apresenta a cedula selecionada
                                printf("\n Celulas Maximas : %d", d2= 100*pow(2, i)); // valor maximo da nota que pode ser alocada
                                printf("\n Cedulas restantes : %d\n", max_notas[i]); // cedulas disponiveis em caixa
                                printf("\nQuantas notas de %d quer abastecer?\n--> ", notas[i]);
                                scanf("%d", &d2);
                                if (d2 < 0) { // exclui entradas com valor negativo
                                    system("cls");
                                    printf("   | VALOR INVALIDO |\n");
                                    printf("Valor digitado NAO pode ser menor que zero!!\n");
                                } else if ((max_notas[i] + d2) > (100*pow(2, i)) ){ // exclue entradas que superam o limite
                                    system("cls");
                                    printf("   | VALOR INVALIDO |\n");
                                    printf("Valor digitado excede o limite de cedulas!!\n");
                                }
                            } while (d2 < 0 ||  ((max_notas[i] + d2) > (100*pow(2, i)) ));
                            system("cls");
                            printf("*---------------------------------------*\n");
                            if (d2!=0) { 
                                printf("\nForam armazenadas %d cedulas de %d\n", d2, notas[i]); // quantia armazenada
                                printf("Valor das cedulas armazenadas: %d\n", d2*notas[i]); //quantia total
                            }
                            else // valor nulo
                                printf("\nNao houve nenhuma cedula armazenada\n");
                            total += d2*notas[i];
                            max_notas[i] += d2; 
                            printf("\nCedulas totais de %d : ( %d )", notas[i], max_notas[i]);
                            printf("\nValor total de %d : ( %d ) \n\n", notas[i], max_notas[i]*notas[i]);
                            printf("*---------------------------------------*\n\n");
                            }   
                        i=1;    
                        system("pause");
                        system("cls");
                    } while(1);
                    break;

                case 5: // retorna ao menu inicial
                    printf("      Retornando ao menu...\n"), i = 0;
                    system("pause");
                    break;
                }
            } while (menu!=5); 
            break;

        case 3: // finaliza o progama
            system("cls");
            printf("Finalizando programa...\n");
            return 0;
        }
        system("cls");
    } while (1);
    return 0;
}