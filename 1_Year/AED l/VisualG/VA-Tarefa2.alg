algoritmo "semnome"

//        Para o conjunto de 150 numeros, faça um algoritmo que:
//a) Informe o maior numero e a sua respectiva posicao dentro do vetor V;
//             b) Informe a soma dos tres menores numeros;
//             c) Informe a soma dos números primos;

arquivo "C:\Users\Sleche\Documents\Faculdade\VisualG\150n.txt"

var
   v:vetor[1..150] de inteiro
   m:vetor[1..3] de inteiro
   i, cont, maior, soma, posi:inteiro
   divisor, primo : inteiro
inicio
      //obter os numeros do arquivo e armazena-los no vetor v
m[1] <- 999
cont <- 1
para i de 1 ate 150 faca
   leia(v[i])
   se v[i] < m[1] entao
      m[3] <- m[2]
      m[2] <- m[1]
      m[1] <- v[i]
   fimse
   se v[i] > maior entao
      maior <- v[i]
      posi <- cont
   fimse
   primo <-0
   divisor <- 2
   enquanto divisor < v[i]  faca
      se v[i] mod divisor = 0 entao
         primo <- 1
      fimse
      divisor <- divisor + 1
   fimenquanto
   se primo = 0 entao
      soma <- soma + v[i]
   fimse
   cont <- cont + 1
fimpara
i <- m[1] + m[2] + m[3]
escreval("a) maior: ",maior," posição: ", posi)
escreval("b) soma menor: ", i)
escreval("c) soma: ", soma)
fimalgoritmo
