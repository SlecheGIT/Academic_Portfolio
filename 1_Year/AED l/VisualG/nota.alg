algoritmo "semnome"

//Fazer um algoritmo para corrigir provas de múltipla escolha.  Cada prova tem 10 questões e cada questão vale 1 ponto.
//O primeiro conjunto de dados a ser conhecido será o gabarito para a correção das provas.
//Os outros dados serão os números (RAs) de 100 alunos e suas respectivas respostas.

//Ex:
//gabarito: 			      "ECACEEDAEC"
//RA: 2502     RESPOSTAS:  "DBADCBCCAE"
//O aluno de RA 2502 acertou 1 questão na prova e sua nota será 1 ponto.


//O algoritmo deverá calcular a nota de cada aluno e responder questões.

//armezene o arquivo "dadosProvas.txt" em uma pasta e atualize o caminho "C:\Windows\Temp\" para a nova pasta
arquivo "C:\Users\Sleche\Documents\Faculdade\VisualG\dadosProvas.txt""

var
   gabarito:vetor[1..10] de caracter
   ra, nota:vetor[1..100] de inteiro
   respostas:vetor[1..1000] de caracter
   i, j, cont, c:inteiro
inicio
      //ler o gabarito
      c<-1
      para i de 1 ate 10 faca
            leia(gabarito[i])
      fimpara
      //ler cada RA seguido das respostas
      cont<-0
      para i de 1 ate 100 faca
           leia(ra[i])
           para j de 1 ate 10 faca
                cont<-cont+1
                leia(respostas[cont])
           fimpara
      fimpara
      //imprimir o gabarito
      escreval("")
      escreva("Gabarito: ")
      para i de 1 ate 10 faca
           escreva(" ",gabarito[i])
      fimpara
      escreval("")
      //imprimir RA seguido das respostas
      cont<-0
      escreval("RA     respostas")
      para i de 1 ate 100 faca
           escreva(ra[i])
           nota[c]<-0
           para j de 1 ate 10 faca
                cont<-cont+1
                escreva(" ",respostas[cont])
                se (resposta[cont] = gabarito[j])entao
                     nota[c] <- nota[c] + 1
                fimse
           fimpara
           
           escreva(" = ", nota[c])
           c<-c+1
           escreval("")
      fimpara
fimalgoritmo
