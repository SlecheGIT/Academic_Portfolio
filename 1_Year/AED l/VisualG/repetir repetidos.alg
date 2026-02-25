algoritmo "semnome"
// Função :
// Autor :
// Data : 31/05/2022
// Seção de Declarações 
var
   av:vetor[1..30] de inteiro
   b:vetor[1..30] de inteiro
   c:vetor[1..30] de inteiro
   d:vetor[1..30] de inteiro
   p, i, k, a:inteiro

inicio
p<-1

para i de 1 ate 3 faca
   escreva("a",i,": ")
    leia(av[i])
   escreva("b",i,": ")
    leia(b[i])
fimpara

   para i de 1 ate 3 faca
      para k de 1 ate 3 faca

       se (av[i]=b[k])entao
       d[p]<-b[k]
       p<-p+1
       fimse

      fimpara
   fimpara

          para i de 1 ate 6 faca
          c[i]<-d[i]
             para k de 1 ate 6 faca
                se (i<>k) entao
                  se c[i]=d[k] entao
                   d[k]<-0

                  fimse
                fimse
             fimpara
          fimpara
                
                 para i de 1 ate 6 faca
                 se c[i]<>0 entao
                escreva("esses numeros se repetem: ",c[i])
                 fimse
                 fimpara
fimalgoritmo
