#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#define max 80

void Qk(const char *text) {
    const int compr_text = strlen(text);
    int comeco_linha = 0;

    
    while (comeco_linha < compr_text) 
    {
        int fim_linha = comeco_linha + max - 1; 

        //garante que o texto vai ser lido apenas ate o ultimo caracter
        if (fim_linha >= compr_text) 
            fim_linha = compr_text - 1;
        else 
        //Encontra o ultimo espaco em branco antes ou no limite de 80 caracteres, encerrando a linha
            while (fim_linha >= comeco_linha && text[fim_linha] != ' ') 
                fim_linha--;

        int espacosTotais = max - (fim_linha - comeco_linha + 1); // total de espacos necessarios para a centralizacoa
        int espacosEsq = espacosTotais / 2; // numero de espacos necessarios para a esquerda
        int espacosDire = espacosTotais - espacosEsq; // numero de espacos necessarios para a direita

        for (int i = 0; i < espacosEsq; i++) // imprime os espacos a esquerda
            putchar(' ');

        for (int i = comeco_linha; i <= fim_linha; i++) // imprimi o texto
            putchar(text[i]);

        for (int i = 0; i < espacosDire; i++) // imprime os espacos a direuta
            putchar(' ');

        putchar('\n');

        // reinicia a linha
        comeco_linha = fim_linha + 1;
    }
}

void Qj (char *text){
    const int compr_text=strlen(text);
    int comeco_linha = 0;

     while (comeco_linha < compr_text) {
        int fim_linha = comeco_linha + max - 1; 

        if (fim_linha >= compr_text)            
            fim_linha = compr_text - 1;
        else 
            while (fim_linha >= comeco_linha && text[fim_linha] != ' ')
            fim_linha--;

        int espacoTotal = max - (fim_linha - comeco_linha + 1);
        int extra = 0;

         if (fim_linha >= comeco_linha && fim_linha < compr_text - 1) 
            extra = espacoTotal % (fim_linha - comeco_linha);
        
        espacoTotal=0;
        for (int i = comeco_linha; i < fim_linha; i++)
            if (text[i] == ' ')
                espacoTotal++;

        int resto = 0;
        if (extra>=espacoTotal)
            resto = extra % espacoTotal;
        
        for (int i = comeco_linha; i <= fim_linha; i++) {
            putchar(text[i]);

            if (text[i] == ' ' && resto != 0) {
                putchar(text[i]);
                resto--;
            }   
            if (text[i] == ' ' && extra != 0) {
                putchar(text[i]);
                extra--;
            }   
        }
        printf("\n");
        // Atualizar o inicio da proxima linha
        comeco_linha = fim_linha + 1;
    }
}
                                                                                
void Qi(char *text) {
    const int compr_text = strlen(text);//comprimento do texto
    int comeco_linha = 0;
    
    
    while (comeco_linha < compr_text) {
        int fim_linha = comeco_linha + max - 1; //(max-1 indica o ultimo caracter da linha)
        // garante que o texto vai ser lido apenas ate o ultimo caracter
        if (fim_linha >= compr_text) 
            fim_linha = compr_text - 1;
        else 
        //Encontra o ultimo espaco em branco antes ou no limite de 80 caracteres, encerrando a linha
            while (fim_linha >= comeco_linha && text[fim_linha] != ' ')
            fim_linha--;
        
        // Imprime espacos a esquerda
        int espacoEsq = max - (fim_linha - comeco_linha + 1);
        for (int i = 0; i < espacoEsq; i++) 
            putchar(' ');
        
        for (int i = comeco_linha; i <= fim_linha; i++) 
            putchar(text[i]);
        
        putchar('\n');

        // Atualizar o inicio da proxima linha
        comeco_linha = fim_linha + 1;
    }
  
}

void Qh (char *text){
    const int compr_text = strlen(text);
    int comeco_linha = 0;

    while (comeco_linha < compr_text)
    {

        int fim_linha = comeco_linha + max;

        // Verifica se a linha atual excede o comprimento maximo.
        if (fim_linha > compr_text)
        {
            fim_linha = compr_text;
        }
        else
        {
            // Encontra o ultimo espa?o em branco dentro do limite.
            while (fim_linha > comeco_linha && text[fim_linha] != ' ')
            {
                fim_linha--;
            }
        }

        // Imprime a linha atual.
        for (int i = comeco_linha; i < fim_linha; i++)
        {
            putchar(text[i]);
        }

        putchar('\n');

        comeco_linha = fim_linha + 1;
    }
    
}

void g (char text[]){
    system("cls");
    int end = strlen(text), veri = 0;
    
    
    if (text[0] >= 'A' && text[0] <= 'Z')
         veri = 0;
        else if (text[0] >= 'a' && text[0] <= 'z'){
        text[0] -=32;
        veri=0;
         }
    
    for (int i = 1; i < end; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] =='?')
        {
           i= i+2;
            do {
                if (text[i] >= 'a' && text[i] <= 'z'){
                    text[i] -= 32;
                    veri =  1;
                }
                else if (text[i] >= 'A' && text[i] <= 'Z')
                    veri = 1;
                else 
                    i++;
                
            } while (veri == 0);
            veri = 0;
        } else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
    }
    printf("Texto formatado: Caixa-alta no inicio das frases\n");
    system("pause");
    system("cls");
}

void f (char text[]) {
    system("cls");
    int end = strlen(text);
    for (int i = 0; i < end; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
    }
    printf("Texto formatado: caixa-baixa\n");
    system("pause");
    system("cls");
}

void e (char text[]){
    system("cls");
    int end = strlen(text);
    for (int i = 0; i < end; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;
    }
    printf("Texto formatado: caixa-alta\n");
    system("pause");
    system("cls");
}

void d (char text[3200]){
    system("cls");
    char word_text[45], word_formated[45];
    char cpy[3200];
    int cont = 0, veri = 0;
    
    printf("Digita a palavra que sera substituida: ");
    scanf("%s", word_text);
    printf("Digita a palavra que substituira \"%s\": ", word_text);
    scanf("%s", word_formated);
    fflush(stdin);
    printf("\n");
                                                                            
    if (strlen(word_formated) > 50 || strlen(word_text) > 50)
    {
        printf("Palavra acima do limite de caracteres!!\n");
        system("pause");     
        system("cls");
        return;
    }
    for (int i = 0; word_formated[i] != '\0'; i++) { 
        if (!isalpha(word_formated[i])) { 
           printf("Insercao Invalida!!\n");
           system("pause");     
           system("cls");
        return;
           
        }
    }

    int end = strlen(text), n_word = strlen(word_text);
    int n_formated = strlen(word_formated);

    for (int i = 0; i < end; i++)
    {
        if ((text[i] == word_text[cont])  && (!isalpha(text[i-1-cont])))
            cont++;
        else
            cont = 0;
        if ((cont == n_word) && (!isalpha(text[i+1])) )  
        {
            i -= n_word-1; // come?ando pela primeira letra da palavra
            for (int j = 0; j <= i; j++)         // copiando o texto ate a palavra que sera alterada   
                cpy[j] = text[j]; 

            for (int j = 0; j < n_formated; j++) // copiando a palavra
                cpy[i+j] = word_formated[j];
            
            for (int j = i; j < end-n_word+n_formated; j++) // realocando o restante do texto pra copia
                cpy[j+n_formated] = text[j+n_word];
            i+=n_formated;
            end = strlen(text); // ajustando novamente o tamanho do texto

            for (int j = 0; j <= end-n_word+n_formated; j++) // passando pra posi??o original
                text[j] = cpy[j]; 

            cont = 0;
            veri = 1;
        } 
    }
    if ((veri == 1))
        printf("Palavras Substituidas com sucesso\n");
    else
        printf(" [Erro]\nPalavra %s nao foi encontrada no texto!\n", word_text);

    system("pause");     
    system("cls");
}

void c (char text[3200]){
    system("cls");
    char word_text[50], word_formated[50];
    char cpy[3200];
    int cont = 0;
    
    printf("Digita a palavra que sera substituida: ");
    scanf("%s", word_text);
    printf("Digita a palavra que substituira \"%s\": ", word_text);
    scanf("%s", word_formated);
    fflush(stdin);
    printf("\n");

    if (strlen(word_formated) > 50 || strlen(word_text) > 50)
    {
        printf("Palavra acima do limite de caracteres!!\n");
        system("pause");     
        system("cls");
        return;
    }
    for (int i = 0; word_formated[i] != '\0'; i++) { 
        if (!isalpha(word_formated[i])){
 
           printf("Insercao Invalida!!\n");
           system("pause");     
           system("cls");
        return;
           
        }
    }
    
    
    int end = strlen(text), n_word = strlen(word_text);
    int n_formated = strlen(word_formated);

    for (int i = 0; i < end; i++)
    {
        if ((text[i] == word_text[cont])  && (text[i-1-cont] < 'A' || text[i-1-cont] > 'z'))     // verifica as laterais pra saber se a palavra eh completa ou uma substring
            cont++;
        else
            cont = 0;
        if ((cont == n_word) && (text[i+1] < 'A' || text[i+1] > 'z') )  // criei uma "conta" para verificar se a uma letra dentre as maiusculas e as minusculas
        {
            i -= n_word-1; // come?ando pela primeira letra da palavra
            for (int j = 0; j <= i; j++)         // copiando o texto ate a palavra que sera alterada   
                cpy[j] = text[j]; 

            for (int j = 0; j < n_formated; j++) // copiando a palavra
                cpy[i+j] = word_formated[j];
            
            for (int j = i; j < end-n_word+n_formated; j++) // realocando o restante do texto pra copia
                cpy[j+n_formated] = text[j+n_word];
            i+=n_formated;
            end = strlen(text); // ajustando novamente o tamanho do texto

            for (int j = 0; j <= end-n_word+n_formated; j++) // passando pra posicao original
                text[j] = cpy[j]; 
            break; // para apos a primeira alteracao
        } 

    }
    
    if ((cont == n_word))
        printf("Palavra Substituida com sucesso\n");
    else
        printf(" [Erro]\nPalavra %s nao foi encontrada no texto!\n", word_text);

    system("pause");     
    system("cls");
}

void b (char text[]){
    system("cls");
    int cont = 0, repeti=0;
    char word[45];

    printf("qual a palavra?\n--> ");
    scanf("%s", word);
    fflush(stdin);
    printf("\n");

    int end = strlen(text), n_word = strlen(word); 
    for (int i = 0; i < end; i++)
    {
        if ((text[i] == word[cont])  && (!isalpha(text[i-1-cont])))
            cont++;
        else
            cont = 0;
        if ((cont == n_word) && (!isalpha(text[i+1])))  {
            repeti++;
            printf("(%d) Linha: %d, coluna: %d\n", repeti, (i / 80) + 1, ((i+1) - (n_word-1)) % 80);
        }
    }
    if (repeti > 0)
        printf("A palavra %s se repete [%d] vez(es)\n\n", word, repeti);
    else 
        printf("A palavra %s nao se repete\n\n", word);
    system("pause");     
    system("cls");
}

void a (char text[], char formated){
    system("cls");
    switch (formated)
    {
    case 'h':
        Qh(text);
        break;
    case 'i':
        Qi(text);
        break;
    case 'j':
        Qj(text);
        break;
    case 'k':
        Qk(text);
        break;
    default:
        Qh(text);
        break;
    }
    system("pause");
    system("cls");
}

char menu (char choise) {
    printf("a) Imprimir o texto formatado;\n\
          \nb) Dado uma palavra informar quantas vezes a palavra aparece e em qual(is) linha(s) e coluna(s) ela esta;\n\
          \nc) Substituir uma palavra do texto por outra fornecida pelo usuario. Apenas a primeira ocorrencia da\
          \n   palavra deve ser substituida.\n\
          \nd) Substituir uma palavra do texto por outra fornecida pelo usuario. Todas as ocorrencias da palavra\
          \ndevem ser substituidas;\n\
          \ne) Colocar o texto em caixa-alta, ou seja, todos seus caracteres em maiusculo;\n\
          \nf) Colocar o texto em caixa-baixa, ou seja, todos seus caracteres em minusculo;\n\
          \ng) Colocar em caixa-alta o primeiro caracter de cada inicio de frase;\n\
          \nh) Alinhar o texto a esquerda;\n\
          \ni) Alinhar o texto a direita; \n\
          \nj) Justificar o texto;\n\
          \nk) Centralizar o texto;\n\
          \nl) Encerrar o programa;\n--> ");
    scanf("%c", &choise);
    fflush(stdin);
    return choise;
}

void compact(char formated){
    system("cls");
    switch (formated)
    {
    case 'h':
        printf("Texto Formatado: Alinhado para esquerda\n");
        break;
    case 'i':
        printf("Texto Formatado: Alinhado para direita\n");
        break;
    case 'j':
        printf("Texto Formatado: Justificado\n");
        break;
    case 'k':
        printf("Texto Formatado: Centralizado\n");
        break;
    }
    system("pause");
    system("cls");
}
       
int main()
{
    char text[]="William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializacao deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia\
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    char choise, formated = 'h';
    setlocale(LC_ALL,"");
    do {
        choise = menu(choise);
        if (choise == 'h' || choise == 'i' || choise == 'j' || choise == 'k')
            formated = choise;

        switch (choise)
        {
        case 'a':
            a(text, formated);
            break;

        case 'b':
            b(text);
            break;

        case 'c':
            c(text);
            break;

        case 'd':
            d(text);
            break;

        case 'e':
            e(text);
            break;

        case 'f':
            f(text);
            break;

        case 'g':
            g(text);
            break;

        case 'h':
            compact(formated);
            break;

        case  'i':
            compact(formated);
            break;

        case 'j':
            compact(formated);
            break;

        case 'k':
            compact(formated);
            break;

        case 'l':
            printf("\nEncerrando o programa. . .");
            break;  
        
        default:
            system ("cls");
            printf(" [ERRO]\nEscolha uma opcao valida!!\n");
            break;
        }

    } while (choise != 'l');
    return 0;
}
